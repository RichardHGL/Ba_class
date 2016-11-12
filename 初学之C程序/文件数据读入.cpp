#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char *isbn;
	char *name;
	char *author;
	char *publisher;
	int year;
}book_record_t;
typedef struct{
	book_record_t *data;
	int size;
}book_manager_t;
int book_manager_load(book_manager_t *mgr,char *file_name){//可通过创建一个临时
	int i=0;//的book_record_t来读然后写到要求的数组里即可
	char ch;
	char string[2000]={0};
	FILE *fp;
	if((fp=fopen(file_name,"r"))==NULL) exit(-1);
	fscanf(fp,"%d",&mgr->size);
	mgr->data=(book_record_t*)malloc(mgr->size*sizeof(book_record_t));
	for(i=0;i<mgr->size;i++){
		if(feof(fp)){
			fclose(fp);
			return -1;
		}
		mgr->data[i].isbn=(char*)malloc(2000*sizeof(char));
		mgr->data[i].name=(char*)malloc(2000*sizeof(char));
		mgr->data[i].author=(char*)malloc(2000*sizeof(char));
		mgr->data[i].publisher=(char*)malloc(2000*sizeof(char));
		fscanf(fp,"%c",&ch);
		fscanf(fp,"%c",&ch);
		fgets(mgr->data[i].isbn,2000,fp);
		fgets(mgr->data[i].name,2000,fp);
		fgets(mgr->data[i].author,2000,fp);
		fgets(mgr->data[i].publisher,2000,fp);
		fscanf(fp,"%d",&mgr->data[i].year);
	}
	fclose(fp);
	return 0;
}
int main(){
	char file_name[100]="test.txt";
	book_manager_t *mgr=(book_manager_t*)malloc(sizeof(book_manager_t));
	book_manager_load(mgr,file_name);
	return 0;
}
