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
		printf("%d %d\n",x,(x+1)/2-1);
		for(i=1;i<=(x+1)/2;i++)res*=10;
		res*=9;
	}
	return res; 
}
long long int end(long long int N,int stage,int flag){
    long long int res;
    int s,t;
    //if(flag==1) res=0; else 
    if(N<=8&&N>=0&&flag==0) res=b[N+1];
	else if(N>=9&&N<=17) res=b[N+2];
    else{
    	if(flag==0) ar=(num[stage]-num[stage-1])/9;
    	if(flag==1) ar=(num[stage]-num[stage-1])/10;
    	s=N-num[stage-1];
    	t=s/ar+1;
    	if()
    	s=s%(num[stage-2]-num[stage-3]+1);
    	if(stage>=4&&s<=num[stage-2]&&s!=0) s+=num[stage-3];
		//if(s==0) flag=1;
    	if(s>0) s--;
    	//printf("%d %d s=%d\n",flag,stage,s);
		//printf("#==%f\n",t*(pow(10.0,double(stage-1))+1));
    	res=t*(pow(10.0,double(stage-1))+1)+10*end(s,stage-2,1);
    }
    return res;
}
int main()
{
	long long int N;
	int i,j,stage;
	for(i=1;i<=15;i++){
		a[i-1][0]=func(i);
		printf("%lld ",a[i-1][0]);
		for(j=1;j<=i;j++) num[i]+=a[j-1][0];
		printf("%lld\n",num[i]);
	}
	scanf("%lld",&N);
	for(i=1;i<=19;i++){
		if(N==0) break;
		if(N>=num[i-1]&&N<num[i]) break;
	}
	stage=i;
	ar=(num[i]-num[i-1])/9;
	printf("%lld\n",end(N,stage,0));
	return 0;
} 
