#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,x,y,a,k,i,t,m;
    scanf("%d%d",&n,&m);
    char c[8]={0};
    k=pow((double)m,(double)n)-1;
    for(i=0;i<=k;i++){
       x=i;
       for(a=1;a<=n;a++){   
  		   y = x%m,x = x/m;
           c[a-1]=y+65;
   	    }
        for(a=n;a>=1;a--){
            printf("%c",c[a-1]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}                         
                        
