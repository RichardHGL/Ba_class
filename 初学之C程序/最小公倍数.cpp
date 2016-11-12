#include<stdio.h>
int main()
{
	unsigned int s,m,n,t,x,i;
	scanf("%d %d",&m,&n);
	if(m>n) t=m;
	else t=n;
	for(i=1;i<=t-1;i++){
		if((m%i==0)&&(n%i==0)){
			x=i;
		}
	}
	s=m*n/x;
	printf("%d",s);
	return 0;
}
