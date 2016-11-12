#include <iostream>
#include<cassert>
using namespace std;
template<typename T3>
class CArray3D{
	template<typename T2>
	class CArray2D{
		template<typename T1>
		class CArray1D{
			private:
				int l3;
				T1* item;
			public: 
				CArray1D(int a=2):l3(a){
					if(a<0) cout<<"1D error"<<endl;
					else item=new T1[l3];
				}
				CArray1D(const CArray1D<T1> &b):l3(b.l3){
					for(int i=0;i<l2;i++)  item[i]=b.item[i];
				};
				~CArray1D(){
					delete []item;
				}
				T1 & operator [](int i){
					return item[i];
				}
				const T1 & operator [](int i)const{
					return item[i];
				}
		};
		private:
			int l2,l3;
			CArray1D<T2>** item;
		public:
			CArray2D(int a=2,int b=2):l2(a),l3(b){
				if(a<0||b<0) cout<<"2D error"<<endl;
				else{
					item=new CArray1D<T2>*[l2];
					for(int i=0;i<l2;i++)  item[i]=new CArray1D<T2>(l3);
				}
			}
			~CArray2D(){
				delete []item;
			};
			CArray2D(const CArray2D<T2> &b):l2(b.l2),l3(b.l3){
				for(int i=0;i<l2;i++)  item[i]=new CArray1D<T2>(l3);
				for(int i=0;i<l2;i++)  item[i]=b.item[i];
			};
			CArray1D<T2> & operator [](int i){
				return *item[i];
			}
			const CArray1D<T2> & operator [](int i) const{
				return *item[i];
			}
	};
	private:
		int l1,l2,l3;
		CArray2D<T3>** item;
	public:
		int getsize()const{
			return l1*l2*l3;
		};
		CArray3D(int a=2,int b=2,int c=2):l1(a),l2(b),l3(c){
			if(a<0||b<0||c<0) cout<<"3D error"<<endl;
			else{
				item=new CArray2D<T3>*[l1];
				for (int i=0;i<l1;i++) item[i]=new CArray2D<T3>(l2,l3);
			}
		};
		~CArray3D(){
			delete []item;
		};
		CArray3D(const CArray3D<T3> &b):l1(b.l1),l2(b.l2),l3(b.l3){
			for (int i=0;i<l1;i++) item[i]=new CArray2D<T3>(l2,l3);
			for( int i=0;i<l1;i++) item[i] = b.item[i];
		}
		CArray2D<T3> & operator [](int i){
			return *item[i];
		}
		const CArray2D<T3> & operator [](int i) const{
			return *item[i];
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
