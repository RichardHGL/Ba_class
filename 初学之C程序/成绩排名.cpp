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
	int m=0,n=0,temp1=0,temp2=0,i=0,j=0,len;
	scanf("%d %d",&n,&m);
	if(n==0||m==0){
		printf("None");
		return 0;
	}
	for(i=0;i<=n;i++){
		gets(a[i]);
		b[i]=number(a[i]);
		c[i]=summer(a[i]);
	}
	for(i=1;;i++){
		j=i+1;
		len=strlen(a[i]);
		for(;j<len+1;j++){
			if(c[j]>c[i]){
				temp1=c[i];
				c[i]=c[j];
				c[j]=temp1;
				temp2=b[i];
				b[i]=b[j];
				b[j]=temp2;
			}
		}
		if(i>len) break; 
	}
	for(i=1;i<=n;i++){
		if(i<=n-1) printf("%d ",b[i]);
		else printf("%d\n",b[i]);
	}
	return 0;
}
