#include<stdio.h>
int main()
{
	int i,j,k;
	int a[100]={0};
	for(i=1;i<=9;i++){
		for(j=0;j<=9;j++){
			k=i*1001+j*110;
			printf("%d\n",k);
		}
	}
	return 0;
} 
