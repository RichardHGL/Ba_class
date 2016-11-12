#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long int a[100][2]={0},num[20]={0},ar=0;
int b[25]={0,1,2,3,4,5,6,7,8,9,0,11,22,33,44,55,66,77,88,99};
long long int func(int x){
	int i,j,k;
	long long int res=1;
	if(x==1||x==2) res=9;
	else{
		for(i=1;i<=(x+1)/2-1;i++)res*=10;
		res*=9;
	}
	return res; 
}
long long int plus(int stage){
	long long int y=1;
	int i;
	for(i=1;i<=stage-1;i++) y*=10;
	y+=1;
	return y; 
}
long long int end(long long int s,int stage,int flag){
    long long int res=0;
    int t;
    if(flag==1&&stage==1) res=b[s];
    else if(flag==1&&stage==2) res=b[s]*11;
	else if(stage==1&&flag==0) res=b[s+1];
	else if(stage==2&&flag==0) res=b[s+1]*11;
    else{
    	if(flag==0) ar=(a[stage-1][0])/9;
    	else if(flag==1) ar=ar/10;
    	t=s/ar+1;
    	if(flag==1) t--;
    	s=s%ar;
    	res=t*plus(stage)+10*end(s,stage-2,1);
    }
    return res;
} 
int main()
{
	long long int N,s,j;
	int i,stage;
	for(i=1;i<=17;i++){
		a[i-1][0]=func(i);
		for(j=1;j<=i;j++) num[i]+=a[j-1][0];
	}
	scanf("%lld",&N);
	for(i=1;i<=19;i++){
		if(N==0) break;
		if(N>=num[i-1]&&N<num[i]) break;
	}
	stage=i;
	s=N-num[i-1];
	printf("%lld\n",end(s,stage,0));
	return 0;
} 
