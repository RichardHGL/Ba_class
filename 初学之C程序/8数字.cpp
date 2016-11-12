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
string queue[2000]={0};
int printout(int time){
	int i,j,k;
	for(k=0;k<=time;k++){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				printf("%d",queue[k].v[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
int exist(int time){
	int i,j,k,flag=2,num=0;
	for(i=0;i<time;i++){
		num=0;
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				if(queue[i].v[j][k]==a[j][k]) num++;
			}
		}
		if(num==9) return 1;
	}
	return 0;
}
int transport(int time){
	int i,j,k;
	printf("time=%d\n",time);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			queue[time].v[i][j]=a[i][j];
		}
	}
	if(judge()){
		printout(time);
		return 0;
	}
	else{
		p[0].m=e.m-1;p[0].n=e.n;
		p[1].m=e.m;p[1].n=e.n+1;
		p[2].m=e.m+1;p[2].n=e.n;
		p[3].m=e.m;p[3].n=e.n-1;
		for(i=0;i<4;i++){
			if(p[i].m>=0&&p[i].n>=0&&p[i].m<3&&p[i].n<3){
				a[e.m][e.n]=a[p[i].m][p[i].n];
				a[p[i].m][p[i].n]=0;
				e.m=p[i].m;e.n=p[i].n;
				//printf("exist?=%d\n",exist(time));
				if(exist(time)){
					for(j=0;j<3;j++){
						for(k=0;k<3;k++){
							a[j][k]=queue[time].v[j][k];
							if(queue[time].v[j][k]==0){
								e.m=j;e.n=k;
							}
						}
					}
					continue;
				}
				/*for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						printf("%d",a[i][j]);
					}
					printf("\n");
				}
				printf("m=%d n=%d\n",e.m,e.n);
				system("pause");*/
				transport(time+1);
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
	transport(0);
	return 0;
}
