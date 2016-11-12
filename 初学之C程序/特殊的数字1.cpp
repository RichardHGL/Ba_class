#include<stdio.h>
#include<math.h>
int main()
{
	int i,a[3]={0},x,t,k;
	for(i=100;i<1000;i++){
		x=i;
		for(t=0;t<=2;t++){
			a[t]=x%10;
			x=x/10;
		}
		k=pow((double)a[0],3.0)+pow((double)a[1],3.0)+pow((double)a[2],3.0);
		if(i==k) printf("%d\n",i);
	}
	return 0;
}
