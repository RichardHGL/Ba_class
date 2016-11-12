#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[4][4]={0};
typedef struct{
	int m,n;
}place;
typedef struct{
	int v[4][4];
}string;
place e;
place p[5]={0};
int judge(){
	if(a[0][0]==1&&a[0][1]==2&&a[0][2]==3)
		if(a[1][0]==8&&a[1][1]==0&&a[1][2]==4)
			if(a[2][0]==7&&a[2][1]==6&&a[2][2]==5) return 1;
	return 0;
}
string queue1[2000]={0};
string queue2[2000]={0};
int printout(int time){
	int i,j,k;
	for(k=0;k<=time;k++){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				printf("%d",queue2[k].v[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
int rear=0;
int exist(){
	int i,j,k,num=0;
	for(i=0;i<rear;i++){
		num=0;
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				if(queue2[i].v[j][k]==a[j][k]) num++;
			}
		}
		if(num==9) return 1;
	}
	return 0;
}
int flag=0;
int transport(int time,int tag){
	int i,j,k;
	if(flag) return 0;
	printf("time=%d\n",time);
	//if(time%10==0&&time!=0) system("pause");
	for(j=0;j<3;j++){
		for(k=0;k<3;k++){
			printf("%d",a[j][k]);
		}
		printf("\n");
	}
	printf("m=%d n=%d\n",e.m,e.n);
	if(exist()){
		printf("exist!\n");
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				a[i][j]=queue2[time-1].v[i][j];
				if(queue2[time-1].v[i][j]==0){
					e.m=i;e.n=j;
				}
				//printf("%d",queue[time-1].v[i][j]);换一个新的方法回到先前状态 
			}
			printf("\n");
		}
		//system("pause");
		return 0;
	}
	else{
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				queue1[rear].v[i][j]=queue2[time].v[i][j]=a[i][j];
			}
		}
		rear++;
		if(judge()){
			flag=1;
			printf("%d\n",time);
			printout(time);
			system("pause");
			return 0;
		}
		else{
			p[0].m=e.m-1;p[0].n=e.n;
			p[1].m=e.m;p[1].n=e.n+1;
			p[2].m=e.m+1;p[2].n=e.n;
			p[3].m=e.m;p[3].n=e.n-1;
			for(i=0;i<4;i++){
				if(tag==0&&i==2) continue;
				else if(tag==2&&i==0) continue;
				else if(tag==3&&i==1) continue;
				else if(tag==1&&i==3) continue;
				if(p[i].m>=0&&p[i].n>=0&&p[i].m<3&&p[i].n<3){
					a[e.m][e.n]=a[p[i].m][p[i].n];
					a[p[i].m][p[i].n]=0;
					e.m=p[i].m;e.n=p[i].n;
					printf("改后\n");
					for(j=0;j<3;j++){
						for(k=0;k<3;k++){
							printf("%d",a[j][k]);
						}
						printf("\n");
					}
					printf("m=%d n=%d\n",e.m,e.n);
					system("pause");
					transport(time+1,i);
				}
			}
		}
	} 
	return 0;
}
int main(){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==0){
				e.m=i;
				e.n=j;
			}
		}
	}
	transport(0,4);
	return 0;
}
