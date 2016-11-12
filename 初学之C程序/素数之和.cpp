#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,i,a,s,t;
    double k;    
     for(;;)
     {scanf("%d",&n);
     if(n==0)break;
     if(n==1)
     { printf("0\n"); }  
     if(n>=2)
     {  
        s=0;      
        for(a=2;a<=n;a++)
        {   
        i=2;
        k=a;
        k=sqrt(k);
        while((a%i!=0)&&(i<=k))
        {
             i++;
             t=1;
        }
        if(a%i==0)
        {  
             t=0;  
        }
        if((a==2)||(a==3)||(t==1)&&(i>=(int)k))
        {
           s=s+a;           
        }             
       }
        printf("%d\n",s);
      }
     }
     system("pause");
} 
