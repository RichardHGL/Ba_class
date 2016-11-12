#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int dx[9]={0,0,1,-1,1,-1,1,-1},dy[9]={1,-1,0,0,1,-1,-1,1};
int n,m,v1[100][100]={0},v2[100][100]={0};
int z=0;
char a[100][100]={0};
long long int iss[1000]={0};
int max(int x,int y){
	int z=x;
	if(y>x) z=y;
	return z;
}
int digui(int x,int y){
	int i;
	if(v2[x][y]==0){
		z++;
		v2[x][y]=1;
	}
	printf("%d %d\n",x,y);
	for(i=0;i<8;i++){
		if(x+dx[i]>=0&&y+dy>=0&&x+dx[i]<n&&y+dy[i]<m&&v1[x+dx[i]][y+dy[i]]==0)
		if(a[x+dx[i]][y+dy[i]]=='I'){
			v1[x+dx[i]][y+dy[i]]=1;
			digui(x+dx[i],y+dy[i]);
		    v1[x+dx[i]][y+dy[i]]=0;
		} 
	}
	return z;
}
int main()
{   
    int isn=0,i,j,t,res;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]=='I'&&v2[i][j]==0) {
				v1[i][j]=1;
				iss[isn]=digui(i,j);
				z=0;
				isn++;
			}
		}
	}
	if(isn==0) printf("0 0");
	else {
		res=iss[0];
		for(i=1;i<isn;i++) res=max(res,iss[i]);
		printf("%d %d\n",isn,res);
	}
	system("pause");
	return 0;
}
