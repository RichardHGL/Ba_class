#include<stdio.h>
#include<string.h>
int dx[8]={1,-1,0,0,1,-1,1,-1},dy[8]={0,0,1,-1,1,-1,-1,1};
int n,m,v1[100][100]={0},M,p[1000]={0},v2[100][100]={0};
int num=0;
char a[100][100]={0};
int max(int x,int y){
	int z=x;
	if(y>x) z=y;
	return z;
}
int digui(int x,int y,int z,int flag){
	int i,flag2=1;
	//printf("1");
	for(i=0;i<8;i++){
		if(x+dx[i]>=0&&y+dy>=0&&x+dx[i]<n&&y+dy[i]<m){
			if(v1[x][y]==0||flag) if(v1[x+dx[i]][y+dy[i]]==0&&a[x+dx[i]][y+dy[i]]=='I') flag2=0;
		} 
	}	
    if(flag2==0) for(i=0;i<8;i++){
		if(a[x][y]=='I'&&v1[x][y]==0&&flag!=1){//没进来 
			z++;
			printf("*");
			v1[x][y]=1;
			v2[x][y]=1;
		} 
		if(x+dx[i]>=0&&y+dy>=0&&x+dx[i]<n&&y+dy[i]<m){
			digui(x+dx[i],y+dy[i],z,0);
			printf("#");
			v1[x+dx[i]][y+dy[i]]=0;
		} 
	}
	printf("#");
	if(flag2&&flag==0){
		p[num]=z;
		num++;
		printf("%d\n",z);
		printf("*$");
		return z;
	}
	printf("#\n");
	printf("%d %d %d\n",p[0],p[1],p[2]);
    if(flag){//没进来 
    	M=p[0];
    	for(i=1;p[i]!=0;i++){
    		M=max(M,p[i]); 
    	}
    	printf("%d\n",M);
    	printf("&&&&&");
    	printf("%d %d %d\n",p[0],p[1],p[2]);
    	return M;
    }
    printf("&");
	return 0;
}
int main()
{   
    int isn=0,i,j,t,res;
    long int iss[10000]={0};
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]=='I'&&v2[i][j]==0) {
				v1[i][j]=1,v2[i][j]=1;
				for(t=0;t<1000;t++) p[t]=0;
				num=0;
				iss[isn]=digui(i,j,1,1);
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
	return 0;
}
