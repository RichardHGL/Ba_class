#include<stdio.h>
int main()
{
	int a[2002]={0},i,j;
	for(i=2;i<=2000;i++){
		a[i]=1;
	}
	for(i=2;i<=2000;i++){
		if(a[i]){
			printf("%d\n",i);
			for(j=2;i*j<=2000;j++){
				a[i*j]=0;
			}
		} 
	}
	return 0;
} 
