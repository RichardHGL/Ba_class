#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n, x, y, a, k, i, t;
    n = 6;
    k = 63;
    i = 0;
    while(i<=k){                   	  
	    x = i;
	    a = 1;
		t = n-a+1;		            
        while(a <= n){              
				while(t >= 1){   
        	  		y = x%2,x = x/2;
        	  		t--;
            	}
        		printf("%d",y);
        		if(t == 0){ 
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
