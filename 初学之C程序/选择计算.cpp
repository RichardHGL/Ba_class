#include<stdio.h>
int main()
{
	int x,y,z,s,t,q,i;
	scanf("%d %d %d",&x,&y,&z);
	switch(z){
		case 1:{s=x+y;printf("%d\n",s);break;}
		case 2:{s=x-y;printf("%d\n",s);break;}
        case 3:{s=x*y;printf("%d\n",s);break;}
        case 4:{s=x/y;printf("%d\n",s);break;}
        case 5:{s=x%y;printf("%d\n",s);break;}
        case 6:{if(x>y) t=y;
	            else t=x;
	            for(i=1;i<=t-1;i++){	
		            if((x%i==0)&&(y%i==0)){
                        s=i;
		            }  
	            }
		        printf("%d\n",s);break;}
        case 7:{if(x>y) t=y;
	           else t=x;
	           for(i=1;i<=t-1;i++){
		           if((x%i==0)&&(y%i==0)){
		    	       q=i;
		           }
	           }
	           s=x*y/q;
		       printf("%d\n",s);break;}	
	      }
	return 0;
}
