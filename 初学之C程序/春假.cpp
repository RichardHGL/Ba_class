#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int s[10000]={0},year,n,i;
	s[1928]=1;
	for(i=1929;i<10000;i++){
		if(i%400==0||(i%4==0&&i%100!=0)){
			s[i]=(s[i-1]+2)%7;
		} 
		else s[i]=(s[i-1]+1)%7;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&year);
		switch(s[year]){
			case 0:printf("9\n");break;
			case 1:printf("6\n");break;
			case 2:printf("5\n");break;
			case 3:printf("5\n");break;
			case 4:printf("5\n");break;
			case 5:printf("5\n");break;
			case 6:printf("6\n");break;
		}
	}
	return 0;
}
