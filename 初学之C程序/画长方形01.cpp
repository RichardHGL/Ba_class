#include<stdio.h>
#include<math.h>
int main()
{
	char a[25][18]={0};
	int i,j;
	for(i=0;i<=24;i++){
		for(j=0;j<=17;j++){
			a[i][j]=fabs(i-j)+65;
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
