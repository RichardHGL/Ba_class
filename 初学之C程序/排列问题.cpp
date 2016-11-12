#include<stdio.h>
int n,m,v[16]={0};
int a[15]={0};
int getball(int t){
	int i,j;
	if(t==m) {
	    for(j=0;j<m;j++) printf(j<m-1?"%d ":"%d\n",a[j]);
	    return 0;
	}
    else{ 
	    for(i=1;i<=n;i++) if(v[i]==0){
    		     v[i]=1;
    		     a[t]=i;
    		     getball(t+1);
    		     v[i]=0;
    	    }
    }
	return a[0]; 	
}
int main()
{
	scanf("%d %d",&n,&m);
	getball(0);
	return 0;
}
