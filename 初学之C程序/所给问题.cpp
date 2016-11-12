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
typedef struct{
   int * elem;
   int length;
   int Listsize;
}List;
int ListInsert_L(LinkList &L,int i,int e){//֮ǰ�ɹ����й���������������Ī�������в����� 
   int j=0;
   LNode* p=L;  
   while(p&&j<i-1){
        p=p->next;
		++j;
   }  
   if(!p||j>i-1) return ERROR;//�ұ�ʾ�ǰ������ϱ�ĵ��Ǿ��������� 
   LNode* s=(LinkList)malloc(sizeof(LNode));
   s->data=e;
   s->next=p->next;
   p->next=s;//֮ǰò������һ�������� 
   return OK;
}
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
		if(e==p->data){
			j++;
			break;
		} 
		if(e>p->data&&e<p->next->data){
			j++;
			break;
		}
	}
	ListInsert_L(L,j,e);
}
void InitList_L(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));
}
int main(){
    int i,k[10]={0},n;
    LinkList L,p,q;
    InitList_L(L),InitList_L(p),InitList_L(q);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&k[i]);
		if(i==0){
			ListInsert_L(L,1,k[0]);
		} 
		else sort_L(L,k[i]); 
    }
    p=L->next;
    for(i=1;i<=n;i++){
        printf(i==n?"%d\n":"%d ",p->data);
        p=p->next;
    }
}
