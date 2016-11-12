#include<stdio.h>
#include<math.h>
int main()
{
	int x[1000]={0},i,N;
	double a,b,d,s,S;
	for(N=1,i=0;;){
		scanf("%d",&x[i]);
		if(x[i]==0){
			break;
		}
		N++;
		i++;
	}
	for(i=0,s=0;i<=N-2;i++){
		s=s+x[i];
	}
	a=s/(N-1);
	for(i=0,S=0;i<=N-2;i++){
		d=(x[i]-a)*(x[i]-a);
		S=S+d;
	}
	b=sqrt(S/(N-2));
	printf("%.4lf\n%.4lf\n",a,b);
	return 0;
} 
