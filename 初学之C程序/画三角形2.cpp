#include<stdio.h>
#include<math.h>
int main()
{
	char c=65;
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++){
		for(j=0;j<=2*i;j++){
			c=fabs(i-j)+65;
			printf("%c",c);
		}
		printf("\n");
	}
	return 0;	
}
