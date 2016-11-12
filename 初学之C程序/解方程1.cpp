#include<stdio.h>
#include<math.h>
int main()
{
	int n,a[100],x1,x2,x3,x4,sol,k,i,t;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		k=sqrt(a[i]);
		sol=0;
		t=0;
	    for(x1=k/2;x1<=k;x1++){
			         if(x1*x1==a[i]) {
			         sol++;
			         break;
			         }
			         if(x1*x1>a[i]) break;
			         if(t){
			         	while(x1*x1+x2*x2+x3*x3+x4*x4<a[i]) x1++;
			         	t=0;
			         }
		          for(x2=sqrt(a[i]-x1*x1);x2>=0;x2--){
		          	  if(t) break;
		          	  while(x2>x1) x2--;
		          	  if(x1*x1+x2*x2==a[i]) {
			             sol++;
			             t=1;
			             break;
			          }
		              for(x3=sqrt(a[i]-x1*x1-x2*x2);x3>=0;x3--){
		              	if(t) break;
		              	while(x3>x2) x3--;
		              	 if(x1*x1+x2*x2+x3*x3==a[i]) {
			                 sol++;
			                 t=1;
			                 break;
			            }
		                  for(x4=sqrt(a[i]-x1*x1-x2*x2-x3*x3);x4>=0;x4--){
		                  	  while(x4>x3) x4--;
		                  	  if(x1*x1+x2*x2+x3*x3+x4*x4<a[i]){
		                  	  	t=1;
		                  	  	break;
		                  	  }
		            	      else if(x1*x1+x2*x2+x3*x3+x4*x4==a[i]) {
		            	           sol++;
		            	           t=1;
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
