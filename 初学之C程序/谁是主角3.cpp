#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	long int data;
	int time;
}pro;
pro s[50000]={0,0};
int main(){
	long int n,i,j,up=0,temp,k,x;
	x=2^3;
	printf("%d\n",x);
	x=x^3^3;
	printf("%d\n",x);
	x=x^2^5;
	printf("%d\n",x);
	int flag=0;
	for(i=0;i<50000;i++){
		s[i].data=0;
		s[i].time=0;
	}
	printf("%d\n",2^3^3);
	scanf("%ld",&n);
	for(i=1;i<=n;i++){
		scanf("%ld",&temp);
		flag=0;
		if(i==1){
			s[up].data=temp;
			s[up].time++;
			up++;
		}
		else if(i>1){
			for(j=0;j<up;j++){
				if(temp==s[j].data){
					s[j].time=0;
					for(k=j+1;k<up;k++){
						s[k-1]=s[k];
					}
					up--;
					flag=1;
					break;
				}	
			}
			if(flag==0){
				s[up].data=temp;
				s[up].time++;
				up++;
			}
		}
	}
	printf("%ld\n",s[0].data);
	return 0;
}
