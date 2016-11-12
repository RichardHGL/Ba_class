#include<cstdio>  
#include<algorithm>  
using namespace std;  
int a[13],d[13],v[13]={0},n;  
int dfs(int x){  
    if(x==n) {  
        for(int i=0;i<n;i++)   printf(i!=n-1?"%d ":"%d\n",d[i]);  
        return 0 ;  
    }  
    for(int i=0;i<n;i++) if(v[i]==0) {  
        v[i]=1;  
        d[x]=a[i];  
        dfs(x+1);  
        v[i]=0;  
    }  
}  
int main(){  
    scanf("%d",&n);  
    for(int i=0;i<n;i++) scanf("%d",&a[i]);  
    sort(a,a+n);  
    dfs(0);  
}  
