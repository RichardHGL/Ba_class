#include<stdio.h>  
int a[13][13]={0},v[13][13]={0},n,q;  
int b[13]={0};  
int conflict(int x,int y){  
    int i,j;  
    for(i=0;i<x;i++){  
        if(b[i]==y) return 1;
        if(b[i]+i==x+y) return 1;
        if(b[i]-i==y-x) return 1;
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
        for(i=0;i<n;i++){
        	if(conflict(x,i)) continue;
        	else{
        		b[x]=i;
        		queen(x+1);
        	}
        }
    }  
    return 0;   
}  
int main()  
{  
    int i;   
    scanf("%d",&n);  
    queen(0);  
    printf("%d\n",q);  
    return 0;  
} 
