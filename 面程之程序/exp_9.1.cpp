/*（1）实现一个三维数组模版CArray3D，
可以用来生成元素为任意类型变量的三维数组，
使得下面程序输出结果是：
//0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19
,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,
37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,
//注意，只能写一个类模板，不能写多个。*/
#include <iostream>
#include<cassert>
using namespace std;
template<typename T>
class CArray3D{
	private:
		int l1,l2,l3;
		T ***item;
		//T **item1;
		//T *item2; 
	public:
		CArray3D(int a=2,int b=2,int c=2);
		~CArray3D();
		CArray3D(const CArray3D<T> &b);
		T** operator [](int i);
		const T** operator [](int i) const;
};

template<typename T>
T* CArray3D<T>::T**::operator [](int i){
	return 
}

template<typename T>
T CArray3D<T>::T*::operator [](int i){
	
} 

template<typename T>
CArray3D<T>::CArray3D(int a,int b,int c):l1(a),l2(b),l3(c){
	if(a<0||b<0||c<0){
		cout<<"error"<<endl;
	}
	else{
		item=new T[l1][l2][l3];
		for( int i = 0; i < l1; ++ i )
        	for( int j = 0; j < l2; ++j )
           		for( int k = 0; k < l3; ++k )
                	item[i][j][k] = 0;
	}
	
}
template<typename T>
CArray3D<T>::~CArray3D(){
	delete []item;
}
template<typename T>
CArray3D<T>::CArray3D(const CArray3D<T> &b){
	l1=b.l1;
	l2=b.l2;
	l3=b.l3;
	item=new T[l1][l2][l3];
	for( int i = 0; i < l1; ++ i )
        for( int j = 0; j < l2; ++j )
            for( int k = 0; k < l3; ++k )
                item[i][j][k] = b.item[i][j][k];
}
template<typename T>
int CArray3D<T>::getsize() const{
	return l1*l2*l3; 
}
template<typename T>
const T** CArray3D<T>::operator[] (int i)const{
	return item[i];
}
template<typename T>
T** CArray3D<T>::operator[] (int i){
	return item[i];
}
/*template<typename T>
const T* & CArray3D<T>::operator T* (){
	return item;
}
template<typename T>
const T* & CArray3D<T>::operator const T* ()const{
	return item;
}*/
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
