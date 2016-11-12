#include<stdio.h>
#include<math.h>
int main()
{
	int n,a[100],x1,x2,x3,x4,sol,k,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		k=sqrt(a[i]);
		sol=0;
	    for(x1=k/2;x1<=k;x1++){
		          if(x1*x1>a[i]) break;
			      if(x1*x1==a[i]) {
			         sol++;
			         break;
			      }
		          for(x2=0;x2<=x1;x2++){
		          	  if(x1*x1+x2*x2>a[i]) break;
		          	  if(x1*x1+x2*x2==a[i]) {
			         sol++;
			         break;
			      }
		              for(x3=0;x3<=x2;x3++){
		              	if(x1*x1+x2*x2+x3*x3>a[i]) break;
		              	if(x1*x1+x2*x2+x3*x3==a[i]) {
			         sol++;
			         break;
			      }
		                  for(x4=0;x4<=x3;x4++){
		                  	  if(x1*x1+x2*x2+x3*x3+x4*x4>a[i]) break;
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
