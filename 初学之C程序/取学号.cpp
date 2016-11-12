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
int main()
{
	char a[10][10]={0},num,i;
	for(i=0;i<=3;i++){
		gets(a[i]);
	    num=number(a[i]);
    }
    return 0;
}
