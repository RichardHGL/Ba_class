#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m, n, i=0;
	double s=0.0;
	scanf("%d  %d",&m,&n);
	i=m;
	s=0;
	while(i<=n){
         if(i%2!=0){       
         s=s+1.0/(2*i-1);
         }
         else {
         s=s-1.0/(2*i-1);     
         }
         i++;
    }
    printf("%.4lf\n",s);
    system("pause");
    return 0;
}                
