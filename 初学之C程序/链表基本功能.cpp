#include<stdio.h>
#include<stdlib.h>
typedef enum
{
     OK=1,
     ERROR=0,
     OVERFLOW=-2
}Status;
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void InitList_L(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));
}
int GetElem_L(LinkList L, int i, int &e){
   int j=1;
   LNode *p;
   p=L->next;
   while(p&&i<j){
       p=p->next;++j;
   }
   if(!p||j>i) return ERROR;
   e=p->data;
   return OK;
}
int ListDelete_L(LinkList L,int i,int &e){
    int j=0;
    LNode *p=L,*q;
    while(p->next&&j<i-1){
      p=p->next;++j;
    }
    if(!(p->next)||j>i-1) return ERROR;
    q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    return OK;
}
int LocateElem_L(LinkList L,int e){
    int i=1,j=0;
    LNode *p=L->next;
    while(p&&p->data!=e){
        p=p->next;
		i++;
    }
    if(p&&p->data==e) return i;
    else return 0;
}
int ListInsert_L(LinkList &L,int i,int e){//之前成功运行过，改了主程序结果莫名就运行不了了 
   int j=0;
   LNode* p=L;  
   while(p&&j<i-1){
        p=p->next;
		++j;
   }  
   if(!p||j>i-1) return ERROR;
   LNode* s=(LinkList)malloc(sizeof(LNode));
   s->data=e;
   s->next=p->next;
   p->next = s;
   return OK;
}
/*int tryL(LinkList &L,int i,int e){//与Insret 类似 
   int j=0;
   LNode* p=L;
   while(p&&j<i-1){p=p->next;++j;}
   if(!p||j>i-1) return ERROR;
   LNode* s=(LinkList)malloc(sizeof(LNode));
   s->data=e;
   s->next=p->next;
   p->next=s;
   return OK;
}*/
int sort_L(LinkList L,int e){
	int j=1;
	LNode* p=(LNode*)malloc(sizeof(LNode));
	p=L->next;
	for(;p;p=p->next,j++){
		if(j==1&&e<p->data) break;
		if(!p->next){
			j++;
			break;
		} 
		if(e>p->data&&e<p->next->data){
			j++;
			break;
		}
	}
	printf("**\n");
	ListInsert_L(L,j,e);
}
int main(){
	int i,n,j,e;
	LNode* p=(LNode*)malloc(sizeof(LNode));
	LinkList L;
	InitList_L(L);
	printf("请输入所需元素个数:");
	scanf("%d",&n);
	for(i=0,p=L;i<n;i++){
		LNode* q=(LNode*)malloc(sizeof(LNode));
		q->next=NULL;
		q->data=0;
		printf("第%d个元素:",i+1);
		scanf("%d",&q->data);
		p->next=q;
		p=q;
		
	}
	for(i=0,p=L->next;i<n;i++){
		printf(i==n-1?"%d\n":"%d ",p->data);
		p=p->next;
	}
	printf("请输入需要删的位置和元素:");
	scanf("%d %d",&j,&e);
	ListDelete_L(L,j,e);
	for(i=0,p=L->next;i<n-1;i++){
		printf(i==n-2?"%d\n":"%d ",p->data);
		p=p->next;
	}
	printf("请输入要插入的位置和元素:");
	scanf("%d %d",&j,&e);
	ListInsert_L(L,j,e);
	for(i=0,p=L->next;i<n;i++){
		printf(i==n-1?"%d\n":"%d ",p->data);
		p=p->next;
	}
	printf("请输入要查找的元素：");
	scanf("%d",&e);
	printf("%d\n",LocateElem_L(L,e));
	return 0;
}
/*int main(){//上次写的关于按序插入元素 
    int i,k[10]={0};
    LinkList L,p,q;
    InitList_L(L),InitList_L(p),InitList_L(q);
    for(i=0;i<9;i++){
        scanf("%d",&k[i]);
		if(i==0){
			ListInsert_L(L,1,k[0]);
			printf("!!!\n");
		} 
		else sort_L(L,k[i]); 
    }
    for(i=1;i<=9;i++){
    	//ListInsert_L(L,i,i);
    	tryL(L,i,i);
    }
    printf("&&");
    p=L->next;
    printf("%d\n",p->data);
    for(i=1;i<=9;i++){
        printf(i==9?"%d\n":"%d ",p->data);
        p=p->next;
    }
}*/
