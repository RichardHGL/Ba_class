#include<stdio.h>
int main()
{
	unsigned long long num=0;
	int i;
	char a[8]={0};
	gets(a);
	for(i=0;i<8&&a[i]!='\0';i++){
		if(a[i]>='0'&&a[i]<='9') num=num*16+a[i]-48;
		else num=num*16+a[i]-55;
	}
	printf("%u\n",num);
	return 0;
} 
