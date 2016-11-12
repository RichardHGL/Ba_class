#include<stdio.h>
#include<string.h>
int number(char a[]){
	int i,n=0;
	for(i=0;a[i]!=' ';i++){
		n=n*10+a[i]-'0';
	}
	printf("%d\n",n);
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
	int sum,num,temp1,temp2,i,j,len;
	for(i=0;i<=3;i++){
		gets(a[i]);
		b[i]=number(a[i]);
		c[i]=summer(a[i]);
		printf("%d %d\n",b[i],c[i]);
	}
	return 0;
}
