#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,y,i,t,m;
    scanf("%d %d",&n,&m);
    char c;
    y=1;
    n>=1;
    m>=1;
    n<=24;
    m<=24;	            
    while(y<=n)
    {          
        t=65+y-1;
        i=1;    
       while((t>=66)&&(i<=m))
       {   
          c=t;
	      printf("%c",c);
          t--;
          i++;
   	    }
       while(i<=m)
        {
           c=t;
 	  	   printf("%c",c);
 	  	   t++;
 	  	   i++;       
        }        	
        printf("\n");
        y++;
     }
     system("pause");
     return 0;
}
