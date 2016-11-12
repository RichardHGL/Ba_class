#include<iostream>
using namespace std;
class Cube{
	public: 
	    int calculate();
	    void setfactor(int a,int b,int c);
	private:
		int length,width,height;
}; 
int main(){
	int a=0,b=0,c=0;
	Cube myCube;
	cin>>a>>b>>c;
	myCube.setfactor(a,b,c);
	cout<<myCube.calculate();
	return 0; 
}
int Cube::calculate(){
	return length*height*width;
};
void Cube::setfactor(int a,int b,int c){
	length=a,width=b,height=c;
}
