#include<stdio.h>
#include<string.h>
#include<math.h>
int n,m,t=0;
enum color{red, orange, yellow, green, cyan, blue, purple, white, black, pink};
int a[11]={0},v[11]={0};
int resu[10]={0};
void output(){
	int i;
	for(i=0;i<m;i++){
		switch(resu[i]){
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
int judge(){
	int i,j,flag=0;
	for(i=0;i<m;i++){
		if(flag) break;
		if(cblind(i)) flag=1;
		for(j=0;j<m;j++){
			if(j==i) continue;
			else if(a[j]==a[i]){
				flag=1;
				break;
			}
		}
		for(j=0;j<m-1;j++){
			if(fabs(a[j]-a[j+1])==1){
				flag=1;
				break;
			}
		}
	}
	return flag;
}
int digui(int x){
	int i,j,flag=0,temp;
	if(x==m){		
		if(judge()==0){
			for(i=0;i<m;i++){
			    //printf(i==m-1?"%d\n":"%d ",a[i]);
			    resu[i]=a[i];
		    }
			output();
			t++;
		}
		return 0;
	} 
	else for(i=0;i<n;i++){
		if(v[i]==0){
			a[x]=i;
			v[i]=1;
			digui(x+1);
			v[i]=0;
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
	//printf("%d\n",t);
	return 0;
}
