#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
typedef struct Student {  
    int id;//ѧ��  
    char name[20];//����  
    char classname[20];//�༶  
    int gpa;//ѧ�ּ�  
}_STUDENT;
//getData����  
//mySort����
void *getData(_STUDENT* p){
	int num,i,a,b;
	double total=0,score=0,k;
	scanf("%d %s %s %d",&p->id,p->name,p->classname,&num);
	for(i=1;i<=num;i++){
		scanf("%d %d",&a,&b);
		total+=a*b,score+=b;
	}
	k=total/score;
	if(k-int(k)<0.5)p->gpa=k;
	else p->gpa=k+1;
}
int mySort(_STUDENT ary[],int n,char str[]){
	int flag,k,i,j;
	_STUDENT temp;
	if(strcmp(str,"MAX")==0) flag=1;
	else if(strcmp(str,"MIN")==0) flag=0;
	if(flag==1){
		for(i=0;i<n-1;i++){
			k=i;
			for(j=i+1;j<n;j++){
				if(ary[j].gpa>ary[k].gpa) k=j;
				if(ary[j].gpa==ary[k].gpa&&ary[j].id<ary[k].id)k=j;
			}
			if(k!=i){
				temp=ary[i];
				ary[i]=ary[k];
				ary[k]=temp;
			}
		}
	}
	else if(flag==0){
		for(i=0;i<n-1;i++){
			k=i;
			for(j=i+1;j<n;j++){
				if(ary[j].gpa<ary[k].gpa) k=j;
				if(ary[j].gpa==ary[k].gpa&&ary[j].id<ary[k].id)k=j;
			}
			if(k!=i){
				temp=ary[i];
				ary[i]=ary[k];
				ary[k]=temp;
			}
		}
	}
	return 0;
} 
int main()  
{  
    int n, i, j;  
    char str[10];  
    _STUDENT ary[110];  
    scanf("%d %s", &n, str);
    for ( i = 0; i < n; i ++ ){//��ʵ�ֵĺ���������һ��ѧ�������ݼ���GPA������ŵ��ṹ�������
        getData(&ary[i]);  
    }  //��ʵ�ֵ�������������ֵΪ��
    //��n��Ԫ�ؽṹ������ary����str�����Ĺ�����н������������±��0��ʼ
    mySort( ary, n, str );
    for ( i = 0; i < n; i ++ ){  
        printf("%d %s %s %d\n", ary[i].id, ary[i].name, ary[i].classname, ary[i].gpa );  
    }    
    return 0;  
} 
