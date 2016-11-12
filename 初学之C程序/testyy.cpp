#include<stdio.h>
#include<string.h>
int a[13]={0},i,n,j=0;
int v[13]={0},b[13]={0};
int sort(int a[]){
    int k,t; 
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[k]) k=j;
        if(k!=i){
            t=a[i];
            a[i]=a[k];
            a[k]=t;
        } 
    }
    return a[0];    
}
int digui(int a[],int t){
    if(t==n) {  
        for(int i=0;i<n;i++)   printf(i!=n-1?"%d ":"%d\n",b[i]);  
        return 0 ;  
    }  
    for(int i=0;i<n;i++) if(v[i]==0) {  
        v[i]=1;  
        b[t]=a[i];  
        digui(a,t+1);  
        v[i]=0;  
    }
}
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)    scanf("%d",&a[i]);
    sort(a);
    digui(a,0);
    return 0;
}
