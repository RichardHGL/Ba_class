#include<stdio.h>
int acu(int y){
	int i,sum=1;
	for(i=1;i<=y;i++) sum*=i;
	return sum;
}
int main()
{
	for(int i=0;i<=5;i++) printf("%d\n",acu(i));
	return 0;
}
