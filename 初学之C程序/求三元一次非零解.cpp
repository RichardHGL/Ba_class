#include<stdio.h>
int main()
{
	int a,b,c,x,y,z,sol=0;
	scanf("%d %d %d",&a,&b,&c);
	for(x=-100;x<=100;x++){
		for(y=-100;y<=100;y++){
			for(z=-100;z<=100;z++){
				if(x==0&&y==0&&z==0) continue;
				if(a*x+b*y+c*z==0){
				    sol++;
				    printf("%d %d %d\n",x,y,z);
				} 
			}
		}
	}
	if(sol==0) printf("no solution");
	return 0;
}
