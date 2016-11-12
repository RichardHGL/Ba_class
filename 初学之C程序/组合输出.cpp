#include<stdio.h>
#include<string.h>
int a[13]={0},n,m;
int v[13]={0};
int digui(int x,int t){
	int i,j;
    if(t==m) {
        for(i=0;i<m;i++) printf(i<m-1?"%d ":"%d\n",a[i]); 
		return 0;
	}
    else for(i=x;i<n-m+t+1;i++) if(v[i]==0){
            if(i+1<a[t-1]) continue;
			v[i]=1;
            a[t]=i+1;
            digui(x+1,t+1);
            v[i]=0;
    }      
    return a[0];
}
int main()
{
	int i;
    scanf("%d %d",&n,&m);
    digui(0,0);
    return 0;
}
