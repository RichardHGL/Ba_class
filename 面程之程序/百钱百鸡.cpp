#include<iostream>
using namespace std;
int main(){
	int sol=1;
	int i=0,j=0,k=0;
	for(i=99;i>=3;i-=3){
		for(j=33;j>=1;j--){
			if(i+j>100) continue;
			if(i/3+j*3>100) continue;
			if(i+j==100&&i/3+j*3==100){
				cout<<"����"<<sol++<<":";
				cout<<"����0ֻ��"<<"ĸ��"
					<<j<<"ֻ��"<<"С��"<<i<<"ֻ"<<endl;
			} 
			for(k=20;k>=1;k--){
				if(i+j+k>100) continue;
				if(i/3+j*3+k*5>100) continue;
				if(i+j+k==100&&i/3+j*3+k*5==100){
					cout<<"����"<<sol++<<":";
					cout<<"����"<<k<<"ֻ,"<<"ĸ��"
					<<j<<"ֻ��"<<"С��"<<i<<"ֻ"<<endl;
				} 
			}
		}
	}
	return 0;
}
