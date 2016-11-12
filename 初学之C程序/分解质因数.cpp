#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,p=1,i,k1,k2,t,j,x,h;
	int su[2000]={2},ins[100]={0};
	for(i=3;i<=10000;i++){
		k2=sqrt(i);
		j=2;
		while(i%j&&j<=k2){
			j++;
		}
		if(j==k2+1){
			su[p]=i;
			p++;
		}
	}
	scanf("%d %d",&a,&b);
	getchar();
	for(i=a;i<=b;i++){
		x=i;
		t=x;
		p=0;
		h=0;
		for(;x!=1;){
			if(!(x%su[p])&&h<15) {
				ins[h++]=su[p];
				x=x/su[p];
			}
			else p++;
		}
		printf("%d=%d",t,ins[0]);
		for(j=1;j<h;j++){
			printf("*%d",ins[j]);
		}
		printf("\n");
	}
	return 0;
} 
