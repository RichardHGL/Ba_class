#include<stdio.h>
int main()
{
	int f[21]={0},i,s=0,n;
	f[1]=1;
	f[2]=1;
	for(i=3;i<=20;i++){
		f[i]=f[i-1]+f[i-2];
	}
	for(;;){
         s=0;
		 scanf("%d",&n);
	     if(n>=1){
         for(i=1;i<=n;i++){
		      s=s+f[i];
	       }
	    printf("%d\n",s);
        }
       else break;
    }
    return 0;
}
	
