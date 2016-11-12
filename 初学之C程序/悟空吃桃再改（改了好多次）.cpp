#include<stdio.h>
#include<string.h>
int n,m,t=0;//丢掉桃子，问题在此 
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
int digui(int x){
	int i,j,flag;
	if(x==m){
		t++;
		for(i=0;i<m;i++){
			resu[t][i]=a[i];
		}
		return 0;
	} 
	else for(i=0;i<n;i++){
		flag=0;
		if(v[i]==0){
			a[x]=i;
			if(x>=1){
				if(a[x-1]==0&&a[x]==3||a[x-1]==3&&a[x]==0) continue;
			    if(a[x-1]==2&&a[x]==5||a[x-1]==5&&a[x]==2) continue;
			    for(j=0;j<x;j++){
		    	    if(a[x]==a[j]){
		    	    	flag=1;
		    	    	break;
		    	    }
			        if(a[j]>=1) if(a[x]==a[j]-1||a[x]==a[j]+1){
			        		       flag=1;
			        		       break;
			        	        }
			        if(a[j]==0&&a[x]==a[j]+1){
			        	flag=1;
			        	break;
			        }	        
			    }
			    if(flag) continue;
			}
			v[i]=1;
			if(i==0) v[1]=1;
			else v[i-1]=1,v[i+1]=1;
			digui(x+1);
			v[i]=0;
			if(i==0) v[1]=0;
			else v[i-1]=0,v[i+1]=0;
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
	//printf("%d\n",t);
	return 0;
}
