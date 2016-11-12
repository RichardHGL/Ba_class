#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int data;
	int time;
}pro;
int main(){
	int n,i,j,up=0,temp;
	pro s[10000]={0,0};
	for(i=0;i<10000;i++){
		s[i].data=0;
		s[i].time=0;
	}
	printf("%d %d\n",s[0].data,s[0].time);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&temp);
		if(i==1){
			s[up].data=temp;
			s[up].time++;
			up++;
			printf("data=%d time=%d up=%d\n",s[up-1].data,s[up-1].time,up);
		}
		if(i>1){
			for(j=0;j<up;j++){
				if(temp==s[j].data){
					s[j].time++;
					printf("data=%d\n",s[j].data);
					printf("zzdata=%d time=%d up=%d\n",s[j].data,s[j].time,up);
					break;
				}	
			}
			if(j>=up){
				s[up].data=temp;
				s[up].time++;
				up++;
				printf("zzdata=%d time=%d up=%d\n",s[up-1].data,s[up-1].time,up);
			} 
		} 
	}
	for(i=0;i<=up;i++){
		if(s[i].time==1) printf("%lld",s[i].data);
	}
	return 0;
}
