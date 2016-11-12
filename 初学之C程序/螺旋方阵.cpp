#include<stdio.h>
int n,m,v[4]={0},a[100][100]={{0}},flag=0;
int step=0,sz[5]={0,1,0,-1},sp[5]={1,0,-1,0};
int form(int x,int y,int k,int z){
	int i,j,t;
	if(z==4&&a[y-1][x]) z=0;	
	if(k==m+n*n){
	    for(i=0;i<n;i++){
		    for(j=0;j<n;j++){
			    printf(j==n-1?"%d\n":"%d ",a[i][j]);
		    }
	    }
	    return 0;
    }
	if(x<0||y<0||x==n||y==n) return 0;
	for(t=0;t<4;t++){
		if(t<z-1) continue;
		if(x==0&&y==0&&flag==0){
			a[x][y]=m;
			flag=1;
			form(x,y,k+1,z);
		}
		x=x+sp[t],y=y+sz[t];
		if(x>=0&&x<=n-1&&y>=0&&y<=n-1&&a[y][x]==0){
			a[y][x]=k;
			z=t+1;
			form(x,y,k+1,z);
			break;
		}
		x=x-sp[t],y=y-sz[t];
	}
	return 0;
}
int main()
{
	scanf("%d %d",&m,&n);
	form(0,0,m,0);
	return 0;
}
