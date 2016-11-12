#include<stdio.h>
#include<stdlib.h>
typedef enum
{
     OK=1,
     ERROR=0,
     OVERFLOW=-2
}Status;
typedef struct Elemtype{
	float coef;//ϵ�� 
	int expn;//ָ�� 
}Elemtype;
typedef struct LNode{
    Elemtype data;
    struct LNode* next;
}LNode, * LinkList;
void InitList_L(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
}
int ListDelete_L(LinkList &L,int i,int &e){
    int j=0;
    LNode *p=L,*q;
    while(p->next&&j<i-1){
      p=p->next;++j;
    }
    if(!(p->next)||j>i-1) return ERROR;
    q=p->next;
    p->next=q->next;
    e=q->data.expn;
    free(q);
    return OK;
}
int op(LinkList La,LinkList Lb,LinkList &Lc,int flag,int &n){
	LNode *p,*q,*r;
	int i=1,j;
	p=La->next;q=Lb->next;r=Lc;
	if(flag==1){//�ӷ� 
		while(p&&q){
		LNode* s=(LNode*)malloc(sizeof(LNode));
		s->next=NULL;
		    if(p->data.expn>q->data.expn){
			    s->data.expn=p->data.expn;
			    s->data.coef=p->data.coef;
			    p=p->next;
			    i++;
		    }
		    else if(p->data.expn<q->data.expn){
			    s->data.expn=q->data.expn;
			    s->data.coef=q->data.coef;
			    q=q->next;
			    i++;
		    }
		else{
			s->data.expn=q->data.expn;
			s->data.coef=p->data.coef+q->data.coef;
			p=p->next;q=q->next;
			n--;
			if(s->data.coef==0) n--;
			else i++;
		}
		if(s->data.coef!=0){
			r->next=s;
		    r=s;
		}
	    }
	if(p)r->next=p;
	else if(q)r->next=q;
	}
	else if(flag==0){//���� 
		while(p&&q){
		LNode* s=(LNode*)malloc(sizeof(LNode));
		s->next=NULL;
		    if(p->data.expn>q->data.expn){
			    s->data.expn=p->data.expn;
			    s->data.coef=p->data.coef;
			    p=p->next;
			    i++;
		    }
		    else if(p->data.expn<q->data.expn){
			    s->data.expn=q->data.expn;
			    s->data.coef=0-q->data.coef;
			    q=q->next;
			    i++;
		    }
		else if(p->data.expn==q->data.expn){
			s->data.expn=q->data.expn;
			s->data.coef=p->data.coef-q->data.coef;
			p=p->next;q=q->next;
			n--;
			if(s->data.coef==0) n--;
			else i++;
		}
		if(s->data.coef!=0){
			r->next=s;
		    r=s;
		}
	    }
	    if(p)r->next=p;
	    else if(q)r->next=q;
	}
	return OK; 
}
int ListInsert_L(LinkList &L,int i,float coef,int expn){
   int j=0;
   LNode* p=L;  
   while(p&&j<i-1){
        p=p->next;
		++j;
   }  
   if(!p||j>i-1) return ERROR;
   LNode* s=(LinkList)malloc(sizeof(LNode));
   s->data.coef=coef;s->data.expn=expn;
   s->next=p->next;
   p->next = s;
   return OK;
}
int sort_L(LinkList L,float coef,int expn){
	int j=1;
	LNode* p;
	p=L->next;
	for(;p;p=p->next,j++){
		if(j==1&&expn>p->data.expn) break;
		if(!p->next){
			j++;
			break;
		}
		if(expn==p->data.expn){
			j++;
			break;
		} 
		if(p->next&&expn<p->data.expn&&expn>p->next->data.expn){
			j++;
			break;
		}
	}
	ListInsert_L(L,j,coef,expn);
}
int main(){
	int i,expn,flag;
	float coef;
	LNode *La,*Lb,*Lc,*p;
	InitList_L(La);InitList_L(Lb);InitList_L(Lc);
	int na,nb,n;
	printf("������a��b��Ԫ�ظ�����");
	scanf("%d %d",&na,&nb);
	for(i=0;i<na;i++){//������a 
	    printf("������a�е�%d��Ԫ������",i+1);
		scanf("%f %d",&coef,&expn);
		if(i==0){
			ListInsert_L(La,1,coef,expn);
		} 
		else sort_L(La,coef,expn);
	}
	printf("�Ա�a���������");//�����a������ָ������������м��飻 
	for(i=0,p=La->next;i<na;i++,p=p->next){
		if(i==0) printf("a=%f*x^%d",p->data.coef,p->data.expn);
		else printf(p->data.coef>0?"+%f*x^%d":"%f*x^%d",p->data.coef,p->data.expn);
	}
	printf("\n");
	for(i=0;i<nb;i++){//������b 
	    printf("������b�е�%d��Ԫ������",i+1);
		scanf("%f %d",&coef,&expn);
		if(i==0){
			ListInsert_L(Lb,1,coef,expn);
		} 
		else sort_L(Lb,coef,expn);
	}
	printf("�Ա�b���������");//�����b������ָ������������м��飻
	for(i=0,p=Lb->next;i<nb;i++,p=p->next){
		if(i==0) printf("b=%f*x^%d",p->data.coef,p->data.expn);
		else printf(p->data.coef>0?"+%f*x^%d":"%f*x^%d",p->data.coef,p->data.expn);
	}
	printf("\n");
	printf("ִ�мӷ�����1��ִ�м�������0:");
	scanf("%d",&flag);
	n=na+nb;
	op(La,Lb,Lc,flag,n);
	printf("��������%d\n",n);
	if(flag==1) for(i=0,p=Lc->next;i<n;i++,p=p->next){
		if(i==0){
			printf("�ӷ���");
			printf("a+b=%f*x^%d",p->data.coef,p->data.expn);
		} 
		else printf(p->data.coef>0?"+%f*x^%d":"%f*x^%d",p->data.coef,p->data.expn);
	}
	if(flag==0 )for(i=0,p=Lc->next;i<n;i++,p=p->next){
		if(i==0){
			printf("����:");
		    printf("a-b=%f*x^%d",p->data.coef,p->data.expn);
		} 
		else printf(p->data.coef>0?"+%f*x^%d":"%f*x^%d",p->data.coef,p->data.expn);
	}
	return 0;
}
