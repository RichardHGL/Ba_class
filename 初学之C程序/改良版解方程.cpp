#include<stdio.h>
#include<math.h>
int main()
{
	long n,a[100],x1,x2,x3,x4,sol,k1,i,t;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		k1=sqrt(a[i]);
		sol=0;
		for(x1=k1;x1>=0;x1--){
			if(x1*x1==a[i]) {
			   sol++;
			   continue;
		    }
		    if(4*x1*x1<a[i]) break;
		    t=0;
		    for(x2=0;x2<=x1;x2++){
		    	if(t) break;
		    	if(x1*x1+x2*x2==a[i]){
			    sol++;
			    break;
		        }
		        for(x3=0;x3<=x2;x3++){
		        	if(t) break;
		    	    if(x1*x1+x2*x2+x3*x3==a[i]) {
			           sol++;
			           break;
			           t=1;
		            }
		            for(x4=0;x4<=x3;x4++){
		    	        if(x1*x1+x2*x2+x3*x3+x4*x4==a[i]) {
			               sol++;
			               break;
		                }
		                if(x1*x1+x2*x2+x3*x3+x4*x4>=a[i]) t=1;
		            }
		        }
		    }
		}
		printf("%d\n",sol);
	}
	return 0;
}
	    
