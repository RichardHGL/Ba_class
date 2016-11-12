#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,x,y,a,k,i,t,m;
    scanf("%d%d",&n,&m);
    char c=65;
    k=pow(m,n)-1;
    i=0;
      while(i<=k)
      {   	
            c=65;  
	        x=i;
	        a=1;
			t=n-a+1;		            
            while(a<=n)
			{              
				while(t>=1)
                {   
        	  		y=x%m,x=x/m;
        	  		t--;
            	}
        		printf("%c",c+y);
        		if(t==0)
        		{ 
                           x=i;
                }
				a++;
				t=n-a+1;
        	}        	
           printf("\n");
           i++;
      }
     system("pause");
     return 0;
}
