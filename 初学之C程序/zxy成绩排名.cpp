#include<stdio.h>
#include<string.h>
int sort(int index[],int sum[]){
	int i=0,j=0,k,len,temp1,temp2;
	for(i=0;index[i]!='\0';i++){
		j=i+1;
		for(;index[j]!='\0';j++){
			if(sum[j]>sum[i]){
				temp1=sum[i],temp2=index[i];
				sum[i]=sum[j],index[i]=index[j];
				sum[j]=temp1,index[j]=temp2;
			}	
		}
	}
	for(i=0;index[i]!='\0';i++){
        printf("%d ",index[i]);
	}
	return 0;
}
int main()
{
	int index[10000]={0},score[100]={0},sum[10000]={0};
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	if(n==0||m==0){
		printf("None\n");
		return 0;
	}
	for(i=0;i<n;i++){
		scanf("%d",&index[i]);
		sum[i]=0;
		for(j=0;j<m;j++){
			scanf("%d",&score[j]);
			sum[i]+=score[j];
		}
	}
	sort(index,sum);
	return 0;
}

