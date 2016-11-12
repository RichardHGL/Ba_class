#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	long int time;
	char s1[100];
	char s2[100];
}pro;
int n,m;
pro s[1001]={0,0,0},pp;
int deletem(int z){
	int i,j,k;
	for(i=z+1;i<n;i++){
		s[i-1]=s[i];
	}
	n--;
	return 0;
}
int main(){
	int i,j,k;
	char o[100]={0};
	for(i=0;i<1000;i++){
		s[i].time=0;
	}
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d %s",&s[i].time,s[i].s1);
		getchar();
		scanf("%s",s[i].s2);
		getchar();
	}
	for(j=0;j<m;j++){
		scanf("%s",o);
		for(i=0;i<n;i++){
			if(strcmp(o,s[i].s1)==0){
				deletem(i);
			} 
		}
	}
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(s[j].time<s[k].time) k=j;
		}
		if(k!=i){
			pp=s[i];
			s[i]=s[k];
			s[k]=pp;
		}
	}
	for(i=0;i<n;i++){
		printf("%d %s %s\n",s[i].time,s[i].s1,s[i].s2);
	}
	return 0;
}
