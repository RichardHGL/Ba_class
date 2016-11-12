#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int i=0,j=0,k=0,x=0,up=0,scan;
	int a[1000]={0},b[1000]={0},c[1000]={0};
	a[0]=2;
	for(i=2,j=1;i<=1000;i++){
		if(c[i]==0) a[j++]=i;
		else continue;
		for(k=1;i*k<=1000;k++) c[i*k]=1;
	}
	cin>>x;
	scan=x;
	k=0;
	if(x==1) cout<<"1=1"<<endl;
	else{
		for(i=0;a[i]<=scan;i++){
			while(x%a[i]==0){
				x/=a[i];
				b[k++]=a[i];
				//cout<<"k="<<k<<endl;
			}
			if(x==1) break;
		}
		cout<<scan<<"=";
		for(i=0;i<k;i++){
			if(i==k-1) cout<<b[i]<<endl;
			else cout<<b[i]<<"*";
		}
	}
	return 0;
}


