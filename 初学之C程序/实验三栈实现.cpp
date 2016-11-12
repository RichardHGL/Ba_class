#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
typedef struct{
	char *base;
	char *top;
	int stacksize;
}CharStack;
typedef struct{
	int *base;
	int *top;
	int stacksize;
}IntStack;
int InitCharStack(CharStack &s){
	s.base=(char *)malloc(100*sizeof(char));
	if(!s.base) exit(-1);
	s.top=s.base;
	s.stacksize=100;
	return 0;
}
int InitIntStack(IntStack &s){
	s.base=(int *)malloc(100*sizeof(int));
	if(!s.base) exit(-1);
	s.top=s.base;
	s.stacksize=100;
	return 0;
}
int popi(IntStack &s1,int &temp1){
	if(s1.top==s1.base)return -1;
	temp1=*--s1.top;
	return 1;
}
int popc(CharStack &s2,char &temp2){
	if(s2.top==s2.base)return -1;
	temp2=*--s2.top;
	return 1;
}
int push(IntStack &s1,int temp){
	if(s1.top-s1.base>=s1.stacksize){
		s1.base=(int*)realloc(s1.base,(s1.stacksize+100)*sizeof(int));
		if(!s1.base)
	exit(-2);
	s1.top=s1.base+s1.stacksize;
	s1.stacksize+=100;
    }
    *s1.top++=temp;
    return 1;
}
int recognize(char s[]){
	int s1length=0,s2length=0;
	IntStack s1;InitIntStack(s1);
	CharStack s2;InitCharStack(s2);
	int i,leng,j,res=0,flag=0;
	int * p;
	char * q;
	leng=strlen(s);
	//printf("%d\n",leng);
	for(j=0;j<leng;j++){
		if(s[j]>='0'&&s[j]<='9'){
				res=res*10+(s[j]-'0');
			    if(s[j+1]<'0'||s[j+1]>'9'){
				    *s1.top=res;
				    s1.top++;
				    s1length++;
			    } 
		}
		else{
			if(s[j]=='(') flag=1;
			*s2.top=s[j];
			s2.top++;
			s2length++;
			res=0;
		}  
	}
	printf("���������ջ��");
	for(i=0,p=s1.base;i<s1length;i++,p++){
		printf(i==s1length-1?"%d\n":"%d ",*p);
	}
	printf("���������ջ��");
	for(i=0,q=s2.base;i<s2length;i++,q++){
		printf(i==s2length-1?"%c\n":"%c ",*q);
	}
	return flag;
}
int judge(char *s,char t){
	int x1,x2;
	switch(*s){
		case '*':x1=2;break;
		case '/':x1=2;break;
		case '+':x1=1;break;
		case '-':x1=1;break;
		case '(':x1=3;break;
		case ')':x1=0;break;
	}
	switch(t){
		case '*':x2=2;break;
		case '/':x2=2;break;
		case '+':x2=1;break;
		case '-':x2=1;break;
		case '(':x2=3;break;
		case ')':x2=0;break;
	}
	if(x1>x2) return 2;
	else if(x1==x2) return 1;
	else return 0;
}
int process(char *s){
	int flag;
	switch(*s){
		case '*':flag=4;break;
		case '/':flag=3;break;
		case '+':flag=2;break;
		case '-':flag=1;break;
	}
	return flag;
}
int deal(char *q,int *p,int flag){
	int res;
	switch(flag){
		case 4:{res=*(p-1)*(*p);
			//printf("%d*%d=%d\n",*(p-1),*p,res);
			break;
		}
		case 3:{res=(*(p-1)/(*p));
		    //printf("%d/%d=%d\n",*(p-1),*p,res);
			break;
		}
		case 2:{res=(*(p-1)+(*p));
		    //printf("%d+%d=%d\n",*(p-1),*p,res);
			break;
		}
		case 1:{res=(*(p-1)-(*p));
		    //printf("%d-%d=%d\n",*(p-1),*p,res);
			break;
		}
	}
	return res;
}
int printfsss(IntStack s1, CharStack s2){
	int * p=s1.base;char * q=s2.base;
	printf("ջ������Ԫ�أ�");
	for(;p<s1.top;p++) printf("%d ",*p);
	printf("\n");
	printf("վ�ڷ���Ԫ��:");
	for(;q<s2.top;q++) printf("%c ",*q);
	printf("\n");
	return 0;
}
int change(char s[]){
	int i,leng,p,j,k;
	int n,res;
	char temp[100]={0};
	for(i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			p=i;
			res=atoi(&s[i]);
			while((s[i]>='0'&&s[i]<='9')||s[i]=='.'||s[i]=='e') i++;
		}
		if(s[i]=='(' ){//С�����ڵݹ����ֵ 
			char t[100]={0};
			for(j=0,k=i+1;s[k]!=')';j++,k++){
				t[j]=s[k];
			}
			t[j]='\0';
			strcpy(temp,&s[k+1]);
			char stemp[100]={0};
			res=calculate(t);
			numtoasc(calculate(t),stemp);
			strcpy(&s[i],stemp);
			p=i;
			strcpy(&s[i+strlen(stemp)],temp);
			i=i+strlen(stemp);
			printf("%s\n",s);
		}
		if(s[i]=='^'){
			i++;
			n=atoi(&s[i]);
			while((s[i+1]>='0'&&s[i+1]<='9')||s[i+1]=='.'||s[i+1]=='e') i++;
			//printf("res1=%f\n",res);
			res=pow(res,n);
			printf("res2=%f\n",res);
			strcpy(temp,&s[i+1]);
			char stemp[100]={0};
			numtoasc(res,stemp);
			strcpy(&s[p],stemp);
			strcpy(&s[p+strlen(stemp)],temp);
			puts(s);
			i=p+strlen(stemp)-1;
			//system("pause");
		}
	} 
	return 0;
}
int calculate(char s[]){
	int leng,res=0,j,temp1,i,k,temp;
	IntStack s1;InitIntStack(s1);
	CharStack s2;InitCharStack(s2);
	char temp2;
	int * p;
	char * q;
	leng=strlen(s);
	for(j=0;j<leng;j++){
	//	printf("start=%d\n",j);
		if(s[j]>='0'&&s[j]<='9'){
				res=res*10+(s[j]-'0');
			    if(s[j+1]<'0'||s[j+1]>'9'){
				    *s1.top=res;
				    p=s1.top;
				    s1.top++;
			    } 
		}
		else{//printf("����%c\n",s[j]);
			if(s2.top-s2.base>=1){
				//printf("��ʱ������%c judge=%d res=%d\n",s[j],judge(q,s[j]),res);
				if(s[j]=='(' ){
					//printf("^^^\n");
					char t[100]={0};
					for(i=0,k=j+1;s[k]!=')';i++,k++){
						t[i]=s[k];
					}
					//puts(t);
					t[i]='\0';
					//puts(t);
					push(s1,calculate(t));
					j=k;//printfsss(s1,s2);
					res=0;
					continue;
				}
				if(judge(q,s[j])<1){
					res=0;
					//printf("5555\n");
					q=s+j;j++;
					while(s[j]>='0'&&s[j]<='9'){
						res=res*10+(s[j]-'0');
			            if(s[j+1]<'0'||s[j+1]>'9'){
				            *s1.top=res;
				            //printf("res=%d\n",res);
				            p=s1.top;
				            s1.top++;
				            //printf("top=%d\n",*p);
			            }
						j++; 
					}
					p=s1.top-1;
					temp=deal(q,p,process(q));
					//printf("temp=%d\n",temp);
					popi(s1,temp1);
					popi(s1,temp1);
					push(s1,temp);
					//printfsss(s1,s2);
					res=0;
					continue;
				}
				if(judge(q,s[j])>=1&&s1.top-s1.base>1){
					//printf("ssss\n");
					p=s1.top-1;q=s2.top-1;
					temp=deal(q,p,process(q));
					//printf("temp=%d\n",temp);
					popi(s1,temp1);
					popi(s1,temp1);
					push(s1,temp);
					popc(s2,temp2);
					//printfsss(s1,s2);
				}
			}
			res=0;
			*s2.top=s[j];
			q=s2.top;
			s2.top++;
			//printfsss(s1,s2);
		}
		//printf("end=%d\n",j);  
	}
	if(s1.top-s1.base==2&&s2.top-s2.base==1){
		q=s2.top-1;
		p=s1.top-1;
		return deal(q,p,process(q));
	}
	//printf("%d\n",deal(q,p,process(q)));
	return 0;
}
int main(){
	char s[200]={0};
	int flag,result;
	//printf("�����������ʽ��\n");
	scanf("%s",s);
	//recognize(s);
	result=calculate(s);
	printf("%d\n",result);
	return 0;
}
