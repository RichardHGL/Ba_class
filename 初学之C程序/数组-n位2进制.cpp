#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n, x, y, a, k, i, p[12]={0};
    scanf("%d",&n);
    k = pow(2.0,(double)n)-1;	
    for(i=0;i<=k;i++){
        x = i;                      
        for(a=1;a<=n;a++){   
  		   y = x%2,x = x/2;
           p[a-1]=y;
   	    }
       	for(a=n;a>=1;a--){
           printf("%d",p[a-1]);
        }       
       	printf("\n");
    }
    system("pause");
    return 0;
}
