#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main(){
	double a=0.0,b=0.0,c=0.0,x=0.0,y=0.0,x1=0.0,x2=0.0;
	cin>>a>>b>>c;
	if (a==0){ cout<<"�÷�����һ�η��̣���Ϊ"; 
		if(b==0&&c!=0) cout<<"�޽�"<<endl;
		else if(b==0&&c==0) cout<<"���޽�"<<endl;
		else cout<<"һ���⣬x="<<-(c/b)<<endl;
	}
	else{
		cout<<"�÷���Ϊ���η��̣�"<<endl;
		x=0-b/(2*a);
		y=pow(b,2.0)-4*a*c;
		if(y<0) cout<<"�޽�"<<endl;
		else if(y==0) cout<<"��һ���⣬��Ϊ��x="<<x;
		else{
			x1=x+sqrt(y)/(2*a);x2=x-sqrt(y)/(2*a);
			cout<<"�����⣺x1="<<x1<<" x2="<<x2;
		}
	}
	return 0;
}
