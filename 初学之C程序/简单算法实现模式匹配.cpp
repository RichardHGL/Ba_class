#include<stdio.h>
#include<string.h>
int lenga,lengb;
int Index(char a[],char b[],int pos){
	int i=pos,j=0;
	while(i<lenga&&j<lengb){
		if(a[i]==b[j]){
			i++;j++;
		}
		else{
			i=i-j+2;j=1;
		}
	}
	if(j>=lengb) return i-lengb;
	else return -1;
}
int main(){
	char a[100]={0},b[20]={0};
	int pos;
	scanf("%s",a);
	scanf("%s",b);
	scanf("%d",&pos);
	lenga=strlen(a);lengb=strlen(b);
	if(Index(a,b,pos)!=-1) printf("pos=%d",Index(a,b,pos));	
	else printf("没有找到该串");
	return 0;
} 
