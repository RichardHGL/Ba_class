#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 20
typedef enum{DG,UDG}GraphKind;
typedef int VRType;  //�����ϵ���� 
typedef int* InfoType;
typedef int VertexType;		//������������ 

//*---------------ͼ���ڽ������ʾ----------------- 
typedef struct ArcCell{
	VRType adj;
	InfoType *info;
}ArCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {		//ͼ�Ķ��� 
	VertexType vexs[MAX_VERTEX_NUM];		//�������� 
	AdjMatrix arcs;		//�ڽӾ��� 
	int vexnum,arcnum;		//ͼ�Ķ������ͻ��� 
	GraphKind kind;		//ͼ�������־ 
}MGraph;//���� 

typedef int Status;

Status LocateVex(MGraph G,VertexType v)
{//�ҵ�v��G�е�λ�� 
	int i;	
	for(i=0;i<G.vexnum;++i)
	{
		if(G.vexs[i]==v)
		return i;
	}
	return 0;
}//LocateVex 
Status CreateUDG(MGraph &G)//��������ͼ 
{
	int IncInfo;
	printf("�����붥������������������Ϣ��\n"); 
	scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);//���붥�����ͻ�����IncInfoΪ0�򲻺�������Ϣ 
	int i,j,k;
	printf("����������㣺\n");
	for(i=0;i<G.vexnum;++i) //���춥������ 
	scanf("%d",&G.vexs[i]);
	for(i=0;i<G.vexnum;++i)  //��ʼ���ڽӾ��� 
		for(j=0;j<G.vexnum;++j)
		{
			G.arcs[i][j].adj=0;
			G.arcs[i][j].info=NULL;
		}
	printf("��������ߵĶ���:\n"); 
	for(k=0;k<G.arcnum;++k) //�����ڽӾ��� 
	{
		VertexType v1,v2;
		scanf("%d%d",&v1,&v2);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j].adj=1;
		G.arcs[j][i].adj=1;
		if(IncInfo)
		scanf("%d",&(*G.arcs[i][j].info));
	}		
		printf("��������ͼ�ڽӾ���\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			printf("%d ",G.arcs[i][j].adj);
		}
		printf("\n");
	}
}// CreateUDG


Status CreateDG(MGraph &G)
{//��������ͼ 
	int IncInfo;
	printf("�����붥������������������Ϣ��\n"); 
	scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);//���붥�����ͻ�����IncInfoΪ0�򲻺�������Ϣ 
	int i,j,k;
	printf("����������㣺\n");
	for(i=0;i<G.vexnum;++i) //���춥������ 
		scanf("%d",&G.vexs[i]);
	for(i=0;i<G.vexnum;++i)  //��ʼ���ڽӾ��� 
		for(j=0;j<G.vexnum;++j)
		{
			G.arcs[i][j].adj=0;
			G.arcs[i][j].info=NULL;
		}
	printf("��������ߵĶ���:\n"); 
	for(k=0;k<G.arcnum;++k) //�����ڽӾ��� 
	{
		VertexType v1,v2;
		scanf("%d %d",&v1,&v2);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j].adj=1;
		if(IncInfo)
		scanf("%d",&(*G.arcs[i][j].info));
	}		
	printf("��������ͼ�ڽӾ���\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			printf("%d ",G.arcs[i][j].adj);
		}
		printf("\n");
	}	
} 


Status CreateGraph(MGraph &G)
{
	scanf("%d",&G.kind);
	switch(G.kind){
		case DG:return CreateDG(G);
		case UDG:return CreateUDG(G);
	}
	return 0;
}//CreateGraph


bool visited[MAX_VERTEX_NUM];
Status (*VisitFunc)(MGraph G,int v);
Status Visit(MGraph G,int v)
{
	printf("%d ",G.vexs[v]);
}

void DFS(MGraph G,int v)
{
	visited[v]=true;
	VisitFunc(G,v);
	for(int w=0;w<G.vexnum;++w)
	{
		if(G.arcs[v][w].adj==1 && !visited[w])
        DFS(G,w);
	}
}
void DFSTraverse(MGraph G)
{//��ȱ��� 
	VisitFunc = Visit;
	for(int v=0;v<G.vexnum;++v)
		visited[v]=false;//��ʼ���������� 
	for(int v=0;v<G.vexnum;++v)
	{
		if(!visited[v])
		DFS(G,v);
	}
}

//*-------------------���еĶ����Լ�����-------------------
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;//defination

Status InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
	exit(-1);
	Q.front->next=NULL;
	return 1;	
}//��ʼ������ 

Status QueueEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
	return 1;
	else 
	return 0;
}//�ж϶����Ƿ�Ϊ�� 

Status EnQueue (LinkQueue &Q,int e)
{
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)
	exit(-1);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return 1;
}//������� 

Status DeQueue (LinkQueue &Q,int &e)
{
	if(Q.front==Q.rear)
	return 0;
	QueuePtr p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
	Q.rear=Q.front;
	free(p);
	return 1; 
}//���� 
//----------------------------------------------* 

void BFSTraverse(MGraph G)
{
	int v;
	for(v=0;v<G.vexnum;++v)
	visited[v]=false;
	LinkQueue Q;
	InitQueue(Q);
	for(v=0;v<G.vexnum;++v)
	{
		if(!visited[v])
		{
			visited[v]=true;
			Visit(G,v);
			EnQueue(Q,v);
			while(!QueueEmpty(Q))
			{
				int u;
				DeQueue(Q,u);
				for(int w=0;w<G.vexnum;++w)
				{
					if(!visited[w])
					{
						visited[w]=true;
						Visit(G,w);
						EnQueue(Q,w);
					}
				}
			}
		}
	}
} 


int main ()
{
	MGraph G;
	printf("������Ҫ������ͼ���ͣ�����������ͼ������0������ͼ������1��\n"); 
	CreateGraph(G);
	printf("��ȱ��������\n");
	DFSTraverse(G);//��ȱ��� 
	printf("\n");
	printf("��ȱ��������\n");
	BFSTraverse(G);//��ȱ��� 
	system("pause");
	return 0;
}
