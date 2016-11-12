#include<stdio.h>
int main()
{
	int M,m,t,a[1000]={0},y,i,j;
	double x,s=0.0;
	for(i=0;;i++){
		scanf("%d",&a[i]);
		s=s+a[i];
		if(a[i]==0) break;
	}
    y=i-1;
	for(j=1;j<=y;j++){
		for(i=0;i<=y-j;i++){
		if(a[i]>a[i+1]){
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	  }
    }
    m=a[0];
    M=a[y];
    x=s/(y+1);
    if(a[0]==0){
    	printf("0\n");
    }
    else printf("%d\n%d\n%.4lf\n",m,M,x);
    return 0;
}
