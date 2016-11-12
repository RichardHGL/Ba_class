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
		for(x1=0;x1<=k1;x1++){
		    for(x2=x1;x2<=k1;x2++){
		        for(x3=x2;x3<=k1;x3++){
		            for(x4=x3;x4<=k1;x4++){
		    	        if(x1*x1+x2*x2+x3*x3+x4*x4==a[i]) {
			               sol++;
			               break;
		                }
		            }
		        }
		    }
		}
		printf("%d\n",sol);
	}
	return 0;
}
