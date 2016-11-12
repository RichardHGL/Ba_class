#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main(){
	double a=0.0,b=0.0,c=0.0,x=0.0,y=0.0,x1=0.0,x2=0.0;
	cin>>a>>b>>c;
	if (a==0){ cout<<"该方程是一次方程：根为"; 
		if(b==0&&c!=0) cout<<"无解"<<endl;
		else if(b==0&&c==0) cout<<"无限解"<<endl;
		else cout<<"一个解，x="<<-(c/b)<<endl;
	}
	else{
		cout<<"该方程为二次方程："<<endl;
		x=0-b/(2*a);
		y=pow(b,2.0)-4*a*c;
		if(y<0) cout<<"无解"<<endl;
		else if(y==0) cout<<"仅一个解，解为：x="<<x;
		else{
			x1=x+sqrt(y)/(2*a);x2=x-sqrt(y)/(2*a);
			cout<<"两个解：x1="<<x1<<" x2="<<x2;
		}
	}
	return 0;
}
