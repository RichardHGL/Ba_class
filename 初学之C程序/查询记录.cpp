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
int transport(char *temp){
	int leng=strlen(temp),i;
	for(i=0;i<leng;i++){
		if(temp[i]>=65&&temp[i]<=90) temp[i]+=32;
	}
	return 0;
}
int compare(char *temp,const char *key){
	int leng1=strlen(key),i=-1;
	int leng2=strlen(temp);
	if(leng1==leng2) for(i=0;i<leng1;i++){
		if(temp[i]==key[i]);
		else break;
	}
	if(i==leng1) return 1;
	else return 0;
}
int query_by_name_fuzzy(const book_manager_t *mgr,const char *key){
	int num=0,i,flag=0;
	char temp[2000]={0},temp1[2000]={0};
	strcpy(temp,key);
	transport(temp);
	for(i=0;i<mgr->size;i++){
		flag=0;
		strcpy(temp1,mgr->data[i].name);
		transport(temp1);
		if(compare(temp,temp1)) flag=1;
		else if(strstr(temp1,temp)) flag=1;
		if(flag==1){
			num++;
			printf("%s\n",mgr->data[i].isbn);
			printf("%s\n",mgr->data[i].name);
			printf("%s\n",mgr->data[i].author);
			printf("%s\n",mgr->data[i].publisher);
			printf("%d\n",mgr->data[i].year);
			printf("\n");
		}
	}
	return num;
}
int main(){
	return 0;
}
