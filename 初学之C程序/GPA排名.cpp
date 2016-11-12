#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
typedef struct Student {  
    int id;//学号  
    char name[20];//姓名  
    char classname[20];//班级  
    int gpa;//学分绩  
}_STUDENT;
//getData函数  
//mySort函数
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
    for ( i = 0; i < n; i ++ ){//你实现的函数，读入一个学生的数据计算GPA，并存放到结构体变量中
        getData(&ary[i]);  
    }  //你实现的排序函数，返回值为空
    //对n个元素结构体数组ary按照str描述的规则进行进行排序，数组下标从0开始
    mySort( ary, n, str );
    for ( i = 0; i < n; i ++ ){  
        printf("%d %s %s %d\n", ary[i].id, ary[i].name, ary[i].classname, ary[i].gpa );  
    }    
    return 0;  
} 
