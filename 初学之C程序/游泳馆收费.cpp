#include<stdio.h>
int main()
{
	int a,b,tot=0,n,i,pr;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(b<=20&&b>=10){
			if(a) pr=30;
		else if(b>=12&&b<=16) pr=8;
		else pr=10;
		tot+=pr;
		}	
	}
	printf("%d\n",tot);
	return 0; 
}
