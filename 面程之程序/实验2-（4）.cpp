#include <iostream>
#include <math.h>
#include<stdlib.h>
using namespace std;
int main(){
	double a=0.0,b=0.0,c=0.0,S=0.0,p=0.0,temp=0.0;
	cin>>a>>b>>c;
	if(a+b<=c||a+c<=b||b+c<=a) cout<<"������������"<<endl;
	else{
		cout<<"����������"<<endl;
		p=(a+b+c)/2;
		temp=p*(p-a)*(p-b)*(p-c);
		S=sqrt(temp);
		cout<<"�����Ϊ��S="<<S<<endl;
	}
	return 0;
}
