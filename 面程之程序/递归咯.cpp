#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int number,time;
int result[11]={0};
char record[1000][11]={0};
int count=0;
int temp[11]={0};
int v[11]={0};
int fun(int n){
	if(n==1||n==0) return 1;
	//printf("%d\n",n);
	int num=1,i;
	for(i=2;i<=n;i++){
		num*=i;
	}
	return num;
}//计算阶乘 
int fun2(int n, int k){
	int num=fun(n),num1=fun(k),num2=fun(n-k);
	//printf("%d %d %d\n",num,num1,num2);
	return num/(num1*num2);
}//计算排列数Cnk
int digui(int t,int p){
	int mid=0,i;
	if(t==time&&p==number){
		int j=0;
		for(j=0;j<time;j++){
			//printf("j=%d %d\n",j,temp[j]);
			record[count][j]=temp[j]+'0';
		}
		count++;
		return 0;
	}
	else if(t<time){
		for(i=1;i<=10;i++){
			if(v[i-1]==1) continue;
			mid=p+fun2(time-1,t)*i;
			if(mid>number) return 0;
			temp[t]=i;
			v[i-1]=1;
			digui(t+1,mid);
			v[i-1]=0;
		}
	}
}
void sort(){
	printf("count= %d\n",count);
	int i,j,k=0;
	char temp2[11]={0};
	for(j=1;j<count;j++){//类似选择排序 
		if(strcmp(record[j],record[k])<0) k=j;
	}
	puts(record[k]);
}
int main(){
	scanf("%d %d",&time,&number);
	//for(int i=1;i<=time;i++){
	//	printf("%d= %d\n",i,fun2(time-1,i-1));
	//}
	//system("pause");
	digui(0,0);
	sort();
	return 0;
} 
