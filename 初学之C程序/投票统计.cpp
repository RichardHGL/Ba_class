#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int data;
	int time;
}pro;
int main(){
	int n,i,j,up=0,temp,k;
	pro s[10000]={0,0},pp;
	for(i=0;i<10000;i++){
		s[i].data=0;
		s[i].time=0;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&temp);
		if(i==1){
			s[up].data=temp;
			s[up].time++;
			up++;
		}
		if(i>1){
			for(j=0;j<up;j++){
				if(temp==s[j].data){
					s[j].time++;
					break;
				}	
			}
			if(j>=up){
				s[up].data=temp;
				s[up].time++;
				up++;
			} 
		} 
	}
	for(i=0;i<up-1;i++){
		k=i;
		for(j=i+1;j<up;j++){
			if(s[j].time>s[k].time) k=j;
		}
		if(k!=i){
			pp=s[i];
			s[i]=s[k];
			s[k]=pp;
		}
	}
	//for(i=0;i<up;i++) printf("zzdata=%d time=%d up=%d\n",s[i].data,s[i].time,up);
	if(s[0].time>s[1].time) printf("%d",s[0].data);
	else if(s[0].time==s[1].time) printf("nobody");
	return 0;
}
