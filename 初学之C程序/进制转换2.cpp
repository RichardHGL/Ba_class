#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,i,t;
    long a,x,y;
    double k,m;
    scanf("%ld",&a);
    k=log(16.0),m=log((double)a);
    n=(int)(m/k)+1;
    i=1;
    x=a;
    t=n-i+1;                
    for(i=1;t>=1;)
    {     
       x=a;
       while(t>=1)				
          {   
  	  		y=x%16,x=x/16;
  	  		t--;
   	      }
       switch(y)
       {
          case 10:printf("A");break;
          case 11:printf("B");break;
          case 12:printf("C");break;
          case 13:printf("D");break;
          case 14:printf("E");break;
          case 15:printf("F");break;
          default :printf("%d",y);
        } 
       i++;
       t=n-i+1;
   	  }
   	  if(a==0)
   	  {
          printf("0");
      }    
      printf("\n");
      system("pause");        
      return 0;
}



 
