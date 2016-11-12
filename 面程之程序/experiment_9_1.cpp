#include <iostream>
#include<cassert>
using namespace std;
template<typename T>
class CArray3D{
	private:
		int l1,l2,l3;
		T*** item;
	public:
		int getsize()const{
			return l1*l2*l3;
		};
		CArray3D(int a=2,int b=2,int c=2):l1(a),l2(b),l3(c){
			item=new T**[l1];
			for(int i=0;i<l1;i++){
				item[i]=new T*[l2];
			}
			for(int i=0;i<l1;i++){
				for(int j=0;j<l2;j++){
					item[i][j]=new T[l3];
				}
			}
		};
		~CArray3D(){
			delete []item;
		};
		CArray3D(const CArray3D<T> &b):l1(b.l1),l2(b.l2),l3(b.l3){
			for( int i=0;i<l1;i++){
				for(int j=0;j<l2;j++){
					for(int k=0;k<l3;k++){
						item[i][j][k]=b.item[i][j][k];
					}
				}
			}
		}
		T**  operator [](int i){
			return item[i];
		}
		T** operator [](int i) const{
			return item[i];
		}
};
// 在此处补充你的代码
int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
	return 0;
}
