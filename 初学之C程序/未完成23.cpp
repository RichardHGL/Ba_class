#include<stdio.h>
int b[21]={0};
int a[21]={0};
int n;
int sort(int y){
    int k,t,i,j;
	for(i=n-y;i<n;i++){
	    b[i]=a[i];
	}
    for(i=n-y;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++) if(b[j]<b[k]) k=j;
        if(k!=i){
            t=b[i];
            b[i]=b[k];
            b[k]=t;
        }
    }
    return b[0];    
}
long long acu(int y){
	int i;
	unsigned long long sum=1;
	for(i=1;i<=y;i++) sum*=(long long)i;
	return sum;
}
long long getnum(int k,int y){
	int i=0,t=0;
	long long sum=0;
	sort(y);
	for(i=k;i<n;i++){
		if(a[k]!=b[i]) t++;
		else break;
	}
	sum=(long long)t*acu(y-1);
	//printf("%d*%lld,%d\n",t,acu(y-1),y-1);
	return sum;
}
long long digui(int x,int y){
	long long num=0, sum=0;
	if(x==n-1){
		return num;
	}
	else{
		sum=getnum(n-y,y);
	    num=sum+digui(n-y+1,y-1);
	}
}
int main()
{
	int i;
	unsigned long long num;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	num=digui(0,n)+1;
	printf("%lld\n",num);
	return 0;
}
