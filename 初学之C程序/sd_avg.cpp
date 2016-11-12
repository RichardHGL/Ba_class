#include<stdio.h>
#include<math.h>
int main(){
	int n,i=0;
	double mean,sd,total=0;
	double a[10]={0};
	scanf("%d",&n);
	printf("n=%d\n",n);
	for(i=0;i<n;i++){
		printf("i=%d\n",i);
		scanf("%lf",&a[i]);
		total+=a[i];
		printf("total=%f\n",total);
	}
	mean=total/n;
	printf("the avg is %f\n",mean);
	total=0;
	for(i=0;i<n;i++){
		total+=pow((a[i]-mean),2.0);
	}
	sd=sqrt(total)/n;
	printf("the sd is %f\n",sd);
	return 0;
} 
