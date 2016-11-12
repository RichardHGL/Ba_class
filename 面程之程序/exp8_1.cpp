#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:    
    double r,i;
public:    
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    Complex operator=(const char a[]){
		int p=0;
		r=atoi(a);
		for(p=0;a[p]!='+';p++);
		i=atoi(&a[p+1]);
	}
// 在此处补充你的代码
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
