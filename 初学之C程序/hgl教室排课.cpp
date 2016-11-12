#include<stdio.h>
#include<string.h>
int size[]={0,120,40,85,50,100,140,70,100},a[5]={0};
int v[9]={0},sol=0;
void digui(int t,int clas[]){
	int i,j;
    if(t==5) {
    	for(j=1;j<=4;j++) printf(j==4?"%d\n":"%d ",clas[j]);
    	sol++;
    }
    else for(i=1;i<=8;i++){
    	if(v[i]==0){
    		if(a[t]<=size[i]){
    			clas[t]=i;
    			v[i]=1;
    			digui(t+1,clas);
    			v[i]=0;
    		}
    	}
    }
}
int main(){
	int clas[5]={0};
	scanf("%d %d %d %d",&a[1],&a[2],&a[3],&a[4]);
	digui(1,clas);
	if(sol==0) printf("-1");
	return 0;
}
