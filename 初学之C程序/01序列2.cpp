#include<stdio.h>
int main()
{
	int i,a[6]={0},x,t,p;
	for(i=0;i<64;i++){
		x=i;
		p=0;
		for(t=0;t<=5;t++){
			a[t]=x%2;
			x=x/2;
			if(a[t]%2) p++;
		}
		if(p%2){
		   	for(t=5;t>=0;t--){
		   		printf("%d",a[t]);
		   	}
			printf("\n");
		}	
	}
	return 0;
} 
