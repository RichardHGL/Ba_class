#include<stdio.h>
int min(int x,int y){
    int z;
    if(x<y) z=x;
    else z=y;
    return z;
} 
int main()
{
    int m,n,i,j,z,p;
    int a[51][100]={0};
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++){
        j=1;
        p=1;
        z=a[j][i];
        for(;j<n;j++){
            if(a[j+1][i]<=z&&a[j+1][i]!=0) p=j+1;
            if(z&&a[j+1][i])
            z=min(z,a[j+1][i]);
            else if(z||a[j+1][i]){
            if(z==0) p=j+1;
            z=z+a[j+1][i];
            }
            else {
            z=0;
            } 
        }
        if(z==0) p=0;
        printf("%d ",p);
    }
    printf("\n");
    return 0;
}
