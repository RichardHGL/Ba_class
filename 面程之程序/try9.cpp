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
				/*CArray1D(int a){
					l3=a;
					item=new T1[l3];
				}
				~CArray1D{
					delete[]item;
				}*/
				T1& operator[](int i){
					return item[i];
				}
				CArray1D(int dim1){
					l3 = dim1;
					item = new T1[l3];
				}
				~CArray1D(){
					delete[]item;
				}
				/*T1& operator[](int i){
					return item[i];
				}*/
		};
		private:
			int l2,l3;
			CArray1D<T2>** item;
		public:
			CArray2D(int a,int b){
				l2=a,l3=b;
				item=new CArray1D<T2>*[l2];
				for(int i=0;i<l2;i++)  item[i]=new CArray1D<T2>(l3);
			}
			~CArray2D(){
				delete []item;
			};
			CArray1D<T2>& operator[](int i){
				return *item[i];
			}
	};
	private:
		int l1,l2,l3;
		CArray2D<T3>** item;
	public:
		CArray3D(int a,int b,int c){
			l1=a,l2=b,l3=c;
			item=new CArray2D<T3>*[l1]; 
			for (int i=0;i<l1;i++) item[i]=new CArray2D<T3>(l2,l3);
		}
		~CArray3D(){
			delete []item;
		}
		CArray2D<T3>& operator[](int i){
			return *item[i];
		}
};
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
