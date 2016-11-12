#include<stdio.h>
int getlength(char *s){
	int i=0;
	while(s[i]!='\0') i++;
	return i;
}
void insert(char *s,char *t,int pos){
	int lengs,lengt,i,j;
	lengs=getlength(s);
	lengt=getlength(t);
	for(i=lengs;i>=pos-1;i--){
		s[i+lengt]=s[i];
	} 
	for(i=pos-1,j=0;i<pos-1+lengt;i++,j++) s[i]=t[j];
}
int main(){
	char s[100]={0},t[10]={0};
	int pos;
	scanf("%s",s);
	scanf("%s",t);
	scanf("%d",&pos);
	insert(s,t,pos);
	printf("%s",s);
	return 0;
} 
