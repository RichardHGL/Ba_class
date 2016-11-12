#include<stdio.h>
int main()
{
	long int a[34][34]={0}; 
	int n,j,i;
	scanf("%d",&n);
	a[0][0]=1;
	a[1][0]=1;
	a[1][1]=1;
	for(i=2,j=0;i<=n-1;i++){
		a[i][0]=1;
		a[i][i]=1;
		for(j=1;j<=i-1;j++){
			a[i][j]=a[i-1][j-1]+a[i-1][j];	
		}
        j=0;	
	}
	for(i=0;i<=n-1;i++){
		for(j=0;j<=i;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;	
}
