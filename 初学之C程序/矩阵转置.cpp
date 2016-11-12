#include<stdio.h>  
int main()  
{  
    int n,m,i,j;  
    int a[20][20]={0},b[20][20]={0};  
    scanf("%d %d",&n,&m);  
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&a[i][j]);    
    for(i=0;i<n;i++) for(j=0;j<m;j++)   b[j][i]=a[i][j];  
    for(i=0;i<m;i++) for(j=0;j<n;j++) printf(j==n-1?"%d\n":"%d ",b[i][j]);    
    return 0;  
} 

