#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 20
typedef enum{DG,UDG}GraphKind;
typedef int VRType;  //顶点关系类型 
typedef int* InfoType;
typedef int VertexType;		//顶点向量类型 

//*---------------图的邻接数组表示----------------- 
typedef struct ArcCell{
	VRType adj;
	InfoType *info;
}ArCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {		//图的定义 
	VertexType vexs[MAX_VERTEX_NUM];		//顶点向量 
	AdjMatrix arcs;		//邻接矩阵 
	int vexnum,arcnum;		//图的顶点数和弧数 
	GraphKind kind;		//图的种类标志 
}MGraph;//定义 

typedef int Status;

Status LocateVex(MGraph G,VertexType v)
{//找到v在G中的位置 
	int i;	
	for(i=0;i<G.vexnum;++i)
	{
		if(G.vexs[i]==v)
		return i;
	}
	return 0;
}//LocateVex 
Status CreateUDG(MGraph &G)//构造无向图 
{
	int IncInfo;
	printf("请输入顶点数、弧数和其他信息：\n"); 
	scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);//输入顶点数和弧数，IncInfo为0则不含其他信息 
	int i,j,k;
	printf("请输入各顶点：\n");
	for(i=0;i<G.vexnum;++i) //构造顶点向量 
	scanf("%d",&G.vexs[i]);
	for(i=0;i<G.vexnum;++i)  //初始化邻接矩阵 
		for(j=0;j<G.vexnum;++j)
		{
			G.arcs[i][j].adj=0;
			G.arcs[i][j].info=NULL;
		}
	printf("请输入各边的顶点:\n"); 
	for(k=0;k<G.arcnum;++k) //构造邻接矩阵 
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
		printf("建立无向图邻接矩阵：\n");
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
{//构造有向图 
	int IncInfo;
	printf("请输入顶点数、弧数和其他信息：\n"); 
	scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);//输入顶点数和弧数，IncInfo为0则不含其他信息 
	int i,j,k;
	printf("请输入各顶点：\n");
	for(i=0;i<G.vexnum;++i) //构造顶点向量 
		scanf("%d",&G.vexs[i]);
	for(i=0;i<G.vexnum;++i)  //初始化邻接矩阵 
		for(j=0;j<G.vexnum;++j)
		{
			G.arcs[i][j].adj=0;
			G.arcs[i][j].info=NULL;
		}
	printf("请输入各边的顶点:\n"); 
	for(k=0;k<G.arcnum;++k) //构造邻接矩阵 
	{
		VertexType v1,v2;
		scanf("%d %d",&v1,&v2);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j].adj=1;
		if(IncInfo)
		scanf("%d",&(*G.arcs[i][j].info));
	}		
	printf("建立有向图邻接矩阵：\n");
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
{//深度遍历 
	VisitFunc = Visit;
	for(int v=0;v<G.vexnum;++v)
		visited[v]=false;//初始化访问数组 
	for(int v=0;v<G.vexnum;++v)
	{
		if(!visited[v])
		DFS(G,v);
	}
}

//*-------------------队列的定义以及操作-------------------
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
}//初始化队列 

Status QueueEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
	return 1;
	else 
	return 0;
}//判断队列是否为空 

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
}//进入队列 

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
}//出队 
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
	printf("请输入要建立的图类型：（建立有向图则输入0，无向图则输入1）\n"); 
	CreateGraph(G);
	printf("深度遍历结果：\n");
	DFSTraverse(G);//深度遍历 
	printf("\n");
	printf("广度遍历结果：\n");
	BFSTraverse(G);//广度遍历 
	system("pause");
	return 0;
}
