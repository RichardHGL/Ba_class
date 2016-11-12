#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	long int data;
	int time;
}pro;
int main(){
	long int n,i,j,up=0,temp;
	pro s[100000]={0,0};
	for(i=0;i<100000;i++){
		s[i].data=0;
		s[i].time=0;
	}
	//printf("%ld %ld\n",s[0].data,s[0].time);
	scanf("%ld",&n);
	for(i=1;i<=n;i++){
		scanf("%ld",&temp);
		if(i==1){
			s[up].data=temp;
			s[up].time++;
			up++;
			//printf("data=%ld time=%ld up=%ld\n",s[up-1].data,s[up-1].time,up);
		}
		if(i>1){
			for(j=0;j<up;j++){
				if(temp==s[j].data){
					s[j].time++;
					//printf("zzdata=%ld time=%ld up=%ld\n",s[j].data,s[j].time,up);
					break;
				}	
			}
			if(j>=up){
				s[up].data=temp;
				s[up].time++;
				up++;
				//printf("zzdata=%ld time=%ld up=%ld\n",s[up-1].data,s[up-1].time,up);
			} 
		} 
	}
	for(i=0;i<=up;i++){
		if(s[i].time==1){
			printf("%ld",s[i].data);
			break;
		} 
	}
	return 0;
}
