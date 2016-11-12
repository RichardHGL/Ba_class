#include<stdio.h>
#include<stdlib.h>
int n,v[2000]={0};
long long a[2000]={0};
int max(int x,int y){
    int z=x;
    if(x<y) z=y;
    return z;
}
int sort(long long a[],int v[]){
	int i,j,t2,k;
	long long t1;
	for(i=0;i<2*n-1;i++){
		k=i;
		for(j=i+1;j<2*n;j++) 
		    if(a[j]<a[k]) k=j;
		if(k!=i){
			t1=a[i],t2=v[i];
			a[i]=a[k],v[i]=v[k];
			a[k]=t1,v[k]=t2;
		}
	}			
	for(i=0;i<2*n;i++) printf("%d %lld %d\n",i,a[i],v[i]);
	return v[0];
}
int main()
{
	int num[2001]={0},Mnum=0,i;
	long long b,c;
    scanf("%d",&n);
    for(i=0;i<=2*n-2;i++){
    	scanf("%lld %lld",&b,&c);
    	a[i]=b,v[i]=1;
    	i++;
		a[i]=c,v[i]=-1;
    	//printf("%d %d %d %d\n",a[i-1],v[i-1],a[i],v[i]);
    }
	//for(i=0;i<2*n;i++) printf("%d %d %d\n",i,a[i],v[i]);
    sort(a,v);
    for(i=0;i<=2*n-1;i++){
    	num[i+1]=num[i]+v[i];
    	printf("%d %d %d\n",num[i+1],v[i],v[i+1]);
    	Mnum=max(Mnum,num[i+1]);
    	printf("%d\n",Mnum);
    }
    printf("%d\n",Mnum);
    //for(i=0;i<2*n;i++) printf("%d %d\n",i,v[i]);
    system("pause");
    return 0;
}
