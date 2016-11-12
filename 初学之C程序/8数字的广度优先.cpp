#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXQSIZE 4000
typedef struct{
	int m,n;
}place;
typedef struct{
	int v[4][4];
	int time;
	int m,n;
}string;
place e;
place p[5]={0};
typedef struct{
	string * base;
	int front;
	int rear;
}SqQueue;
int InitQueue(SqQueue &Q){
	Q.base=(string *)malloc(MAXQSIZE * sizeof(string));
	if(!Q.base) exit(-1);
	Q.front=Q.rear=0;
	return 0;
}
int QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}
int EnQueue(SqQueue &Q, string e){
	if((Q.rear+1)%MAXQSIZE==Q.front) return -1;
	Q.base[Q.rear]=e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return 0;
}
int DeQueue(SqQueue &Q, string &e){
	if(Q.front==Q.rear) return -1;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return 0;
}
SqQueue Queue;
int a[4][4]={0};
int judge(string temp){
	if(temp.v[0][0]==a[0][0]&&temp.v[0][1]==a[0][1]&&temp.v[0][2]==a[0][2])
		if(temp.v[1][0]==a[1][0]&&temp.v[1][1]==a[1][1]&&temp.v[1][2]==a[1][2])
			if(temp.v[2][0]==a[2][0]&&temp.v[2][1]==a[2][1]&&temp.v[2][2]==a[2][2]) return 1;
	return 0;
}
string queue[4000]={0};
int rear=0;
int printout(string temp){
	int i,j;
	printf("time=%d\n",temp.time);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d",temp.v[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int exist(string temp){
	int i,j,k,flag=2,num=0;
	for(i=0;i<=rear-1;i++){
		num=0;
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				if(queue[i].v[j][k]==temp.v[j][k]) num++;
			}
		}
		if(num==9) return 1;
	}
	return 0;
}
int main(){
	int i,j,result=0;
	string temp,temp2;
	InitQueue(Queue);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			Queue.base[0].v[i][j]=a[i][j];
			if(a[i][j]==0){
				Queue.base[0].m=i;
				Queue.base[0].n=j;
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	Queue.base[0].time=0;
	EnQueue(Queue,Queue.base[0]);
	while(QueueLength(Queue)>0){
		DeQueue(Queue,temp);
		if(judge(temp)){
			result=temp.time;
			break;
		}
		if(exist(temp)) continue;
		queue[rear++]=temp;
		p[0].m=temp.m-1;p[0].n=temp.n;
		p[1].m=temp.m;p[1].n=temp.n+1;
		p[2].m=temp.m+1;p[2].n=temp.n;
		p[3].m=temp.m;p[3].n=temp.n-1;
		for(i=0;i<4;i++){
			if(p[i].m>=0&&p[i].n>=0&&p[i].m<3&&p[i].n<3){
				temp2=temp;
				temp2.v[temp.m][temp.n]=temp.v[p[i].m][p[i].n];
				temp2.v[p[i].m][p[i].n]=0;
				temp2.m=p[i].m;temp2.n=p[i].n;
				if(exist(temp2)) continue;
				temp2.time=temp.time+1;
				EnQueue(Queue,temp2);
			}
		}
	}
	if(result>0) printf("%d\n",result-1);
	else printf("%d\n",result-1);
	return 0;
}
