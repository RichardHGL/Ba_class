#include<stdio.h>
#include<stdlib.h>
#define MAXQSIZE 100
typedef struct{
	int * base;
	int front;
	int rear;
}SqQueue;
int InitQueue(SqQueue &Q){
	Q.base=(int *)malloc(MAXSIZE * sizeof(int));
	if(!Q.base) exit(-1);
	Q.front=Q.rear=0;
	return 0;
}
int QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXQSIZE;
}
int EnQueue(SqQueue &Q, int e){
	if((Q.rear+1)%MAXSIZE==Q.front) return -1;
	Q.base[Q.rear]=e;
	Q.rear = (Q.rear+1)%MAXSIZE;
	return 0;
}
int DeQueue(SqQueue &Q, int &e){
	if(Q.front==Q.rear) return -1;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return 0;
}
SqQueue Queue;
int main(){
	InitQueue(Queue);
	return 0;
}
