#include<iostream>
#include<string.h>
using namespace std;

class birth{
	public:
		birth(int a=0,int b=0,int c=0){
			year=a,month=b,day=c;
		};
		birth(const birth &newbirth);
		//~birth();
		inline void setbirth(int a,int b,int c){
			year=a,month=b,day=c;
		};
		void showbirth();
	private:
		int year,month,day;
};
/*void birth::setbirth(int a,int b,int c){
	year=a,month=b,day=c;
}*/
void birth::showbirth(){
	cout<<year<<"-"<<month<<"-"<<day; 
}
/*birth::birth(int a,int b,int c):
    year(a),month(b),day(c){
}*/
birth::birth(const birth &newbirth){
	year=newbirth.year;
	month=newbirth.month;
	day=newbirth.day;
}
//birth::~birth(){
//}

class People{
	public:
		People(int a=0,int b=0,int c=0);
		//~People();
		void setfactor(int a,int b,int c);
		void setbirth(int a,int b,int c);
		void showbirth();
		void show();
	private:
		int number,gender,id;
	//public:
		birth birthday;
};
void People::setfactor(int a,int b,int c){
	number=a,gender=b,id=c;
}
void People::setbirth(int a,int b,int c){
	birthday.setbirth(a,b,c);
}
void People::showbirth(){
	birthday.showbirth();
}
void People::show(){
	cout<<number<<"       "<<gender<<"     "; 
	showbirth();
	cout<<" "<<id<<endl;
}
People::People(int a,int b,int c){
    number=a,gender=b,id=c;
}
//People::~People(){
//}

int main(){
	int n,i;
	cout<<"请输入总人数：";
	cin>>n;
	int a=0,b=0,year=0,month=0,day=0;
	int c=0;
	People myPeople[100];
	cout<<"注：男女分别用01表示"<<endl;
	cout<<"number gender   birthday   id"<<endl;
	for(i=1;i<=n;i++){
		cin>>a>>b>>year>>month>>day;
		cin>>c;
		myPeople[i-1].setfactor(a,b,c);
		myPeople[i-1].setbirth(year,month,day);
	}
	cout<<"number gender   birthday   id"<<endl;
	for(i=1;i<=n;i++){
		myPeople[i-1].show();
	}
	return 0;
}



