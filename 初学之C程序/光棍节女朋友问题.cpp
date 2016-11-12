#include<stdio.h>
int main()
{
	int i=9;
	for(;i<=10000;){
	    for(;;){
		    if(i%5==4)
		       if(i%4==3)
		          if(i%3==2)
		             if(i%2==1){
		             i+=10;
					 break;
		             }
		    i+=10;    
	   }
	   printf("%d\n",i-10);
    }
	return 0;
} 
