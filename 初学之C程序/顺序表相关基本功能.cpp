#include<stdio.h>
#include<stdlib.h>
typedef enum
{
     OK=1,
     ERROR=0,
     OVERFLOW=-2
}Status;
typedef struct{
   int * elem;
   int length;
   int Listsize;
}List;
int InitList_sq(List &L){
   L.elem=(int*)malloc(100*sizeof(int));
   if(!L.elem) exit(OVERFLOW);
   L.length=0;
   L.Listsize=100;
   return OK;
}
//int GetElem_sq(List L,int i) L.elem[i-1]
int ListInsert_sq(List &L, int i,int e){
   int *q,*p;
   if(i<1||i>L.length+1) return ERROR;
   q=&(L.elem[i-1]);
   for(p=&(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p;
   *q=e;
   ++L.length;
   return OK;
}
int ListDelete_sq(List &L, int i,int &e){
   int *q,*p;
   if(i<1||i>L.length+1) return ERROR;
   if(L.length>=L.Listsize){
   	   int * newbase=(int*)realloc(L.elem,(L.Listsize+1000)*sizeof(int));
   	   if(!newbase)exit(OVERFLOW);
   	   L.elem=newbase;
   	   L.Listsize+=1000;
   }
   p=&(L.elem[i-1]);
   e=*p;
   q=L.elem+L.length-1;
   for(++p;p<=q;++p) *(p-1)=*p;
   --L.length;
   return OK;
}
int LocateElem_sq(List L,int e){
   int i=1;
   int *p=L.elem;
   while(i<=L.length&&*(p++)!=e) ++i;
   if(i<=L.length) return i;
   else return 0;
}
int main(){
	int i,n,e,j;
	List La;
	InitList_sq(La);
	printf("请输入所需元素个数:");
	scanf("%d",&n);
	La.length=n;
	for(i=0;i<n;i++){
		printf("第%d个元素:",i+1);
		scanf("%d",&La.elem[i]);
	}
	printf("请输入需要插的元素和位置:");
	scanf("%d %d",&e,&j);
	ListInsert_sq(La,j,e);
	for(i=0;i<n+1;i++){
		printf(i==n?"%d\n":"%d ",La.elem[i]);
	}//检查用 
	printf("请输入需要删的位置和元素:");
	scanf("%d %d",&j,&e);
	ListDelete_sq(La,j,e);
	for(i=0;i<n;i++){
		printf(i==n-1?"%d\n":"%d ",La.elem[i]);
	}//检查用
	printf("请输入要查找的元素：");
	scanf("%d",&e);
	printf("%d\n",LocateElem_sq(La,e));
	for(i=0;i<n;i++){
		printf(i==n-1?"%d\n":"%d ",La.elem[i]);
	}//检查用
	return 0;
} 
