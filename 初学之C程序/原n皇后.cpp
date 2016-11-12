#include<stdio.h>  
int a[13][13]={0},v[13][13]={0},q=0,dx[9]={1,1,-1,-1,0,0,1,-1},dy[9]={1,-1,1,-1,1,-1,0,0},n;  
int b[13]={0};  
int limit(int x,int y){  
    int i,j;  
    for(i=0;i<8;i++){  
        for(j=1;x+j*dx[i]>=0&&x+j*dx[i]<n&&y+j*dy[i]>=0&&y+j*dy[i]<n;j++){  
                if(a[x+j*dx[i]][y+j*dy[i]]==0){  
                    a[x+j*dx[i]][y+j*dy[i]]=1;  
                    v[x+j*dx[i]][y+j*dy[i]]=1;  
                }  
        }  
    }  
    return 0;  
}  
int queen(int x){  
    int i,j,t;  
    int v2[13][13]={0};  
    if(x==n){  
        q++;  
        return 0;  
    }  
    else{         
        for(i=0;i<n;i++) if(a[x][i]==0){  
            a[x][i]=1;  
            b[x]=i;  
            limit(x,i);  
            for(t=0;t<n;t++) for(j=0;j<n;j++) v2[t][j]=v[t][j],v[t][j]=0;           
            queen(x+1);  
            a[x][i]=0;  
            for(t=0;t<n;t++) for(j=0;j<n;j++){  
                if(v2[t][j]==1) a[t][j]=0;  
            }  
        }  
    return 0;   
    }  
}  
int main()  
{  
    int i;   
    scanf("%d",&n);  
    queen(0);  
    printf("%d\n",q);  
    return 0;  
} 
