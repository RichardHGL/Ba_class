#include<stdio.h>
#include<stdio.h>
int main()
{
	int a[10000]={0};
	int i,j,s=0,temp,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[j]>a[i]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("%d\n",a[0]);
	printf("%d\n",a[n-1]);
	printf("%d\n",s);
}
