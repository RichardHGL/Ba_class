#include<stdio.h>
int a[54][1000]={0};
int main()
{
	int n,index[55]={0},i,j,t;
	for(i=1;i<=9;i++){
		for(j=0;j<=9;j++){
			for(t=0;t<=9;t++){
				index[2*i+2*j+t]++;
				a[2*i+2*j+t][index[2*i+2*j+t]]=i*10001+j*1010+t*100;
			}
		}
	}
	for(i=1;i<=9;i++){
		for(j=0;j<=9;j++){
			for(t=0;t<=9;t++){
				index[2*i+2*j+2*t]++;
				a[2*i+2*j+2*t][index[2*i+2*j+2*t]]=i*100001+j*10010+t*1100;
			}
		}
	}
	scanf("%d",&n);
	//if(n==54) printf("999999\n");
	for(i=1;i<=index[n];i++){
		printf("%d\n",a[n][i]);
	}
	return 0;
}
