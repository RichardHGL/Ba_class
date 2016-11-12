#include<stdio.h>
#include<string.h> 
struct time{
int h;
int mi;
int se;
};
struct logtype {
int no;
struct time in;
struct time out;
char ID[20];
}a[1000],b[1000];
struct result {
char ID[20];
struct time used;
struct time rest;
}p[1000],temp;
int gettime(int q,int w,int e,int r,int t,int y){
int s;
s=3600*(r-q)+60*(t-w)+y-e;
return s;
}
void tran(int x,int y){
	int ust=x,rst=72000-x;
	p[y].used.h=ust/3600,p[y].rest.h=rst/3600;
	rst=rst%3600,ust=ust%3600;
	p[y].used.mi=ust/60,p[y].rest.mi=rst/60;
	rst=rst%60,ust=ust%60;
	p[y].used.se=ust,p[y].rest.se=rst;
}
void sort(int t){
	int i,j,k;
	for(i=0;i<=t-1;i++){
		k=i;
		for(j=i+1;j<=t;j++) if(strcmp(p[j].ID,p[k].ID)<0) k=j;
		if(k!=i){
			temp=p[i],p[i]=p[k],p[k]=temp;
		}
	}
}
int main()
{
	int n,t=0,flag1=0,flag2,i,j;
	struct time c[1000]={0,0,0};
	int d[1000]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d:%d:%d %d:%d:%d %s",&a[i].no,&a[i].in.h,&a[i].in.mi,&a[i].in.se,&a[i].out.h,&a[i].out.mi,&a[i].out.se,a[i].ID);
	}
	for(i=0;i<n;i++){
		flag2=0;
		if(t==0&&flag1==0){
		    d[t]=gettime(a[i].in.h,a[i].in.mi,a[i].in.se,a[i].out.h,a[i].out.mi,a[i].out.se);
		    strcpy(p[t].ID,a[i].ID);
		    flag1=1,flag2=1;
		} 
	    else if(flag1==1)for(j=0;j<=t;j++){
			if(strcmp(p[j].ID,a[i].ID)==0){
				d[j]+=gettime(a[i].in.h,a[i].in.mi,a[i].in.se,a[i].out.h,a[i].out.mi,a[i].out.se);
				flag2=1;
				break;
			}
		} 	
	    if(flag2==0){
			t++;
			d[t]=gettime(a[i].in.h,a[i].in.mi,a[i].in.se,a[i].out.h,a[i].out.mi,a[i].out.se);
		    strcpy(p[t].ID,a[i].ID);
		}
	}//得到了一组时间，下面转化格式，设计转换子程序然后输出。 
	for(i=0;i<=t;i++){
		tran(d[i],i);
	}
	sort(t);
	for(i=0;i<=t;i++){
		printf("%s %d:%d:%d %d:%d:%d\n",p[i].ID,p[i].used.h,p[i].used.mi,p[i].used.se,p[i].rest.h,p[i].rest.mi,p[i].rest.se);
	}
	return 0;
}
