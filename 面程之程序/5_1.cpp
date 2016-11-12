#include<iostream>
using namespace std;
class base{
	public:
    	int k;
    	base(int n=0);
};
base::base(int n){
	k=n;
}
class Big{
	public:
	    int v; base b;
	    void setv(int a=0);
		void setb(int a=0);
		Big(int a=0);
	    Big(const Big &a2);
// 在此处补充你的代码
};
Big::Big(int a){
	//base b1(a);
	//b=b1;
	b.k=a;
	v=a;
}
Big::Big(const Big &a2){
	v=a2.v,b.k=a2.b.k;
}
void Big::setv(int a){
	v=a;
}
void Big::setb(int a){
	b.k=a;
}
int main() {
    Big a1(5); Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}
