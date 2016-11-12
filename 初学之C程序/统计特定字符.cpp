#include<stdio.h>
int tj(char *s){
	int i=0;
	int t[100]={0};
	while(s[i]!='\0'){
		if(s[i]>='A'&&s[i]<='Z'){
			t[s[i]-65]++;
		}
		else if(s[i]>='0'&&s[i]<='9') t[s[i]-48+26]++;
		i++;
	}
	for(i=0;i<36;i++){
		if(t[i]!=0&&i<26)printf("其中，%c有%d个：",65+i,t[i]);
		if(t[i]!=0&&i>=26) printf("其中，%c有%d个：",48+i-26,t[i]);
	}
	return 0;
}
int main(){
	char s[100];
	scanf("%s",s);
	tj(s);
	return 0;
}
