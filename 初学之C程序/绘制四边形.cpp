#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,k,j;
	scanf("%d",&n);
	   for(i=0;i<2*n-1;i++){
	   	   k=i;
	   	   j=1;
	   	   if(k>=n) k=2*n-2-i;
	   	   if(k<n){
	   	   	  for(j=1;j<=2*n-1;j++){
	   	   	  	  if(j!=n-k&&j!=n+k) printf(" ");
	   	   	  	  else printf("*");
	   	   	  }
	   	   	  printf("\n");
	       }
	   }
	return 0;
}
