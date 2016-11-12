#include<stdio.h>
#include<string.h>
int n,m,t=0;
enum color{red, orange, yellow, green, cyan, blue, purple, white, black, pink};
int a[11]={0},v[11]={0};
int resu[1000][10]={{0}};
void output(int x){
	int i;
	for(i=0;i<m;i++){
		switch(resu[x][i]){
			case 0:printf("red");break;
			case 1:printf("orange");break;
			case 2:printf("yellow");break;
			case 3:printf("green");break;
			case 4:printf("cyan");break;
			case 5:printf("blue");break;
			case 6:printf("purple");break;
			case 7:printf("white");break;
			case 8:printf("black");break;
			case 9:printf("pink");break;
		}
		printf(i==m-1?"\n":" ");
	}
}
int cblind(int x){
	int flag=0;
	if(x>=1){
		if(a[x]==0&&a[x-1]==3) v[0]=2,flag=1;
		if(a[x]==3&&a[x-1]==0) v[3]=2,flag=1;
		if(a[x]==2&&a[x-1]==5) v[2]=2,flag=1;
		if(a[x]==5&&a[x-1]==2) v[5]=2,flag=1;
	}
	return flag;
}
int fblind(int x){
	if(x>=1){
		if(a[x-1]==0&&v[3]==2) v[3]=0;
		if(a[x-1]==3&&v[0]==2) v[0]=0;
		if(a[x-1]==2&&v[5]==2) v[5]=0;
		if(a[x-1]==5&&v[2]==2) v[2]=0;
	}
	return 0;
}
int warn(int x){
	if(x>=1) v[x-1]=1,v[x+1]=1;
	else v[1]=1;
	//printf("%d %d %d %d %d %d\n",v[0],v[1],v[2],v[3],v[4],v[5]);
	return 0;
}
int cwarn(int x){
	if(x>=1) v[x-1]=0,v[x+1]=0;
	else v[1]=0;
	//printf("%d %d %d %d %d %d^^\n",v[0],v[1],v[2],v[3],v[4],v[5]);
	return 0;
}
int digui(int x){
	int i,j,flag=0,temp;
	if(x==m){
		t++;
		for(i=0;i<m;i++){
			//printf(i==m-1?"%d\n":"%d ",a[i]);
			resu[t][i]=a[i];
		}
		return 0;
	} 
	else for(i=0;i<n;i++){
		if(v[i]==0){
			a[x]=i;
			if(cblind(x)){
				flag=1;
				continue;
			} 
			v[i]=1;
			printf("**%d %d**\n",x,a[x]);
			warn(a[x]);
			digui(x+1);
			v[i]=0;
			printf("!%d %d %d %d %d %d\n",v[0],v[1],v[2],v[3],v[4],v[5]);
			if(flag) fblind(x); 
			cwarn(a[x]);
			for(j=0;j<x;j++) warn(a[j]);
			if(x==0) for(j=0;j<n;j++) v[j]=0;
	    }
	}
	return 0;
}
int main()
{
	int i;
	scanf("%d %d",&n,&m);
	digui(0);
	if(t==0){
		printf("-1");
		return 0;
	}
	else for(i=1;i<=t;i++){
		output(i);
	}	
	printf("%d\n",t);
	return 0;
} 
