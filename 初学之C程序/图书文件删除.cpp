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
int book_manager_delete(book_manager_t *mgr,char *isbn){
	int i;
	for(i=0;i<mgr->size;i++){
		if(strcmp(mgr->data[i].isbn,isbn)==0){
			for(;i<mgr->size-1;i++){
				mgr->data[i]=mgr->data[i+1];
			}
			mgr->size--;
			realloc(mgr->data,mgr->size*sizeof(book_record_t));
			return 0;
		}
	}
	if(i==mgr->size) return -1;
}
int main(){
	int i;
	book_manager_t *mgr;
	char isbn[100]={0};
	mgr->data=(book_record_t*)malloc(100*sizeof(book_record_t));
	printf("请输入图书记录数目:");
	scanf("%d",&mgr->size);
	for(i=0;i<mgr->size;i++){
		mgr->data[i].isbn=(char*)malloc(100*sizeof(char));
		mgr->data[i].name=(char*)malloc(100*sizeof(char));
		mgr->data[i].author=(char*)malloc(100*sizeof(char));
		mgr->data[i].publisher=(char*)malloc(100*sizeof(char));
		printf("请输入第%d本书信息:",i+1);
		scanf("%s %s %s %s %d",mgr->data[i].isbn,mgr->data[i].name,mgr->data[i].author,mgr->data[i].publisher,mgr->data[i].year);
		printf("%s %s %s %s %d",mgr->data[i].isbn,mgr->data[i].name,mgr->data[i].author,mgr->data[i].publisher,mgr->data[i].year);
	}
	printf("请输入需要删除的图书isbn:",i+1);
	scanf("%s",isbn);
	book_manager_delete(mgr,isbn);
	for(i=0;i<mgr->size;i++){
		printf("%s %s %s %s %d",mgr->data[i].isbn,mgr->data[i].name,mgr->data[i].author,mgr->data[i].publisher,mgr->data[i].year);
	}	
	return 0;
}
