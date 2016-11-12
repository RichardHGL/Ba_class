#include<stdio.h>
#include<string.h>
int number(char a[]){
	int i,n;
	n=0;
	for(i=0;a[i]!=' ';i++){
		n=n*10+a[i]-'0';
	}
	return n;
}
int summer(char a[]){
	int i=0,n=0,len,sum;
	len=strlen(a);
	if(i==0){
	    while(a[i]!=' ') i++;
	}
	i++;
	sum=0;
	for(;i<len;i++){
	    n=0;
	    for(;a[i]!=' '&&i<len;i++){
		    n=n*10+a[i]-'0';
	    }
	    sum+=n;
    }
    return sum;
}
int main()
{
	char a[10000][100]={0};
	int b[10000]={0},c[10000]={0};
	int m=0,n=0,temp1=0,temp2=0,i=0,j=0,k;
	scanf("%d %d",&n,&m);
	getchar();
	if(n==0||m==0){
		printf("None\n");
		return 0;
	}
	for(i=0;i<n;i++){
		gets(a[i]);
		b[i]=number(a[i]);
		c[i]=summer(a[i]);
	}
	for(i=0;j<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(c[j]>c[k]) k=j;
			if(k>i){
				temp1=c[k],temp2=b[k];
				c[k]=c[i],b[k]=b[i];
				c[i]=temp1,b[i]=temp2;
			}
		} 
	}	
	for(i=0;i<n;i++){
		printf("%d %d\n",b[i],c[i]);
		//if(i<n-1) printf("%d ",b[i]);
		//else printf("%d\n",b[i]);
	}
	return 0;
}
