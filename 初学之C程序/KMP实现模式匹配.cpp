#include<stdio.h>
#include<string.h>
int lenga,lengb;
int next[100]={0};
int cnext(char b[],int next[]){
	next[0]=-1;
	int i=0,j=-1,k;
	while(i<lengb){
		if(j==-1||b[i]==b[j]){
			i++;j++;next[i]=j;
		}
		else j=next[j];
	}
	for(k=0;k<lengb;k++){
		printf(k==lengb-1?"%d\n":"%d ",next[k]);
	}
	return 0;
}
int Index_KMP(char a[],char b[],int pos){
	int i=pos,j=0;
	while(i<lenga&&j<lengb){
		if(a[i]==b[j]||j==-1){
			i++;j++;
		}
		else j=next[j];
	}
	if(j>=lengb) return i-lengb;
	else return -1;
}
int main(){
	int pos;
	char a[100]={0},b[20]={0};
	scanf("%s",a);
	scanf("%s",b);
	scanf("%d",&pos);
	lenga=strlen(a);lengb=strlen(b);
	cnext(b,next);
	printf("hello\n");
	if(Index_KMP(a,b,pos)!=-1) printf("pos=%d",Index_KMP(a,b,pos));	
	else printf("没有找到该串");
	return 0;
}
