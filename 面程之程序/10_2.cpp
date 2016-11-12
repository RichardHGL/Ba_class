#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
template<typename T1,typename T2,class T3=greater<T1> >//设置默认直接写等于,less 和greater 在函数库里有 
class MyMultimap{
	multimap<T1,T2,T3> temp;
	public:
		void insert(const pair<T1,T2> &p){temp.insert(p);} 
		typedef typename multimap<T1,T2,T3>::iterator iterator;//迭代器的使用必须先确定类型 
		iterator begin(){
			return temp.begin();
		}
		iterator end(){
			return temp.end();
		}
		void Set(const T1 &a,const T2 &b){
			iterator iter=begin(),iter2=end();
			for(;iter!=iter2;iter++){
				if(iter->first==a) (*iter).second=b;//.的优先级高于*,->可以达到和(*).一样的效果 
			}
		}
		iterator find(const T1 &first_in){
			iterator iter=temp.begin(),iter2=temp.end();
			for(;iter!=iter2;iter++){
				if((*iter).first==first_in){
					break;
				}
			}
			return iter;
		}
		iterator find(const T2 &second_in){
			iterator iter=temp.begin(),iter2=temp.end();
			for(;iter!=iter2;iter++){
				if(*iter.second==second_in){
					break;
				}
			}
		}
		void clear(){
			temp.clear();
		}
};
template<typename T1, typename T2>
ostream & operator << (ostream &out,const pair<T1,T2> e){//辨认通过参数表来辨认，而不是奇怪的:: 
	out<<"("<<e.first<<","<<e.second<<")";
	return out;
}
struct Student
{
    string name;
    int score;
};

template<class T>
void Print(T first,T last) {
        for(;first!= last; ++ first)
                cout << * first << ",";
        cout << endl;
}
int main()
{
        Student s[] = { {"Tom",80},{"Jack",70},{"Jone",90},{"Tom",70},{"Alice",100} };
        MyMultimap<string,int> mp;
        for(int i = 0; i<5; ++ i)
            mp.insert(make_pair(s[i].name,s[i].score));
        Print(mp.begin(),mp.end()); //按姓名从大到小输出

        mp.Set("Tom",78); //把所有名为"Tom"的学生的成绩都设置为78
        Print(mp.begin(),mp.end());


        MyMultimap<int,string,less<int> > mp2;
        for(int i = 0; i<5; ++ i)
            mp2.insert(make_pair(s[i].score,s[i].name));

        Print(mp2.begin(),mp2.end()); //按成绩从小到大输出
        mp2.Set(70,"Error");          //把所有成绩为70的学生，名字都改为"Error"
        Print(mp2.begin(),mp2.end());
        cout << "******" << endl;

        mp.clear();
        
        string name;
        string cmd;
        int score;
        while(cin >> cmd ) {
            if( cmd == "A") {
                cin >> name >> score;
                if(mp.find(name) != mp.end() ) {
                    cout << "erroe" << endl;
                }
                mp.insert(make_pair(name,score));
            }
            else if(cmd == "Q") {
                cin >> name;
                MyMultimap<string,int>::iterator p = mp.find(name);
                if( p!= mp.end()) {
                    cout << p->second << endl;
                }
                else {
                    cout << "Not Found" << endl;
                }
            }
        }
        return 0;
}

