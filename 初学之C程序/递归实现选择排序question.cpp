#include<stdio.h>
int n,tot,min;
int last[101];
int mpsort(int a[],int x){
	int i,j,k,t;
	if(x==n) {
		for(i=1;i<=n;i++)
		last[i]=a[i];
        return tot;
    }
	k=x;
	min=a[x];
	for(i=x+1;i<=n;i++)
		if(min>a[i]) {
		     k=i;
		     min=a[k];
		}
	if(k!=x){
		t=a[x];
		a[x]=a[k];
		a[k]=t;
		tot++;
		for(i=1;i<n;i++) printf("%d ",a[i]);
		printf("%d\n",a[n]);
		tot=mpsort(a,x+1);
	printf("%d<->%d:",x,k);
	for(i=1;i<n;i++) printf("%d ",a[i]);
	printf("%d\n",a[n]);
	}
	tot=mpsort(a,x+1);
	return tot;
}
int main()
{
	int a[101]={0},i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
    }
    tot=mpsort(a,1);
    printf("Total steps:%d\n",tot);
    printf("Right order:");
    for(i=1;i<n;i++) printf("%d ",last[i]);
	printf("%d\n",last[n]);
	return 0;
}
