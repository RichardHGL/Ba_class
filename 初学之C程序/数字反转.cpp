#include<stdio.h>
#include<math.h>
int main()
{
	int a[10]={0},x=0,i;
	long N, j;
	scanf("%ld",&N);
	j=fabs(N);
	for(;;){
		j=j/10;
		x++;
		if(j==0) break;
	}
	j=fabs(N);
	for(i=0;i<=x-1;i++){
		a[i]=j%10;
		j=j/10;
	}
	for(i=0;i<=x-1;i++){
		if(a[i]!=0){
			break;			
		}
    }
    if(N<0){
    	printf("-");
    }
	for(;i<=x-1;i++){
		printf("%d",a[i]);
	}
	if(N==0){
		printf("0\n");
	}
	return 0;
}
