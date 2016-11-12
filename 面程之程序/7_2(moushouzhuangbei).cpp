#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
class worridor{
	public:
		int type;//种族 
		int strenth;//生命值
		int loyaty;//lion专属忠诚度
		int weapon_num;//武器数目，可变 
		int weapon[4];//武器系列，-1为没有，012为正常值 
		double morale;//dragon专属士气
		worridor(){
			type=0,strenth=0,loyaty=0,
			weapon_num=0,weapon[0]=-1,morale=0.0;
		}
};
class Head{
	public:
		int lion,dragon,ninja,iceman,wolf;
		int strenth,number;
		worridor sodier[200];
		Head(){
			lion=0;ninja=0;iceman=0;
			wolf=0;dragon=0;number=0;
		}
		void setfactor(int a=0);
		void cut(int a=0);
		void addw(int a=0,int strenth=0);
};
void Head::setfactor(int a){
	strenth=a;
}
void Head::cut(int a){
	strenth-=a;
}
void Head::addw(int a,int strenth_in){
	sodier[number].type=a;
	sodier[number].strenth=strenth_in;
	switch(a){
		case 0: {
			lion++;
			sodier[number].loyaty=strenth;
		}break;
		case 1: {
			dragon++;
			sodier[number].weapon_num=1;
			sodier[number].weapon[0]=(number+1)%3;
			sodier[number].morale=(double)strenth/(double)strenth_in;
		}break;
		case 2:{
			ninja++;
			sodier[number].weapon_num=1;
			sodier[number].weapon[0]=(number+1)%3;
			sodier[number].weapon[1]=(number+2)%3;
		} break;
		case 3:{
			iceman++;
			sodier[number].weapon_num=1;
			sodier[number].weapon[0]=(number+1)%3;
		} break;
		case 4:{
			wolf++;
		} break; 
	}
	number++;
}
int min(int a,int b){
	int x=a;
	x=(b<a?b:a);
	return x;
}
int getmin(int cost[]){
	int x=min(cost[0],cost[1]);
	x=min(x,cost[2]);
	x=min(x,cost[3]);
	x=min(x,cost[4]);
	return x;
}
void output(int a){
	switch(a){
		case 0: cout<<"lion";break;
		case 1: cout<<"dragon";break;
		case 2: cout<<"ninja";break;
		case 3: cout<<"iceman";break;
		case 4: cout<<"wolf";break; 
	}
}
void getnum(int a,Head A){
	switch(a){
		case 0: cout<<A.lion;break;
		case 1: cout<<A.dragon;break;
		case 2: cout<<A.ninja;break;
		case 3: cout<<A.iceman;break;
		case 4: cout<<A.wolf;break; 
	}
}
int out_weapon(Head A,int numb){
	if(A.sodier[numb].weapon_num==0) return 0;
	cout<<"it has a ";
	switch(A.sodier[numb].weapon[0]){
		case 0:cout<<"sword";break;
		case 1:cout<<"bomb";break;
		case 2:cout<<"arrow";break;
	}
	if(A.sodier[numb].weapon_num==1){
		if(A.sodier[numb].type!=1) cout<<endl;
		return 0;
	} 
	cout<<" and a ";
	switch(A.sodier[numb].weapon[0]){
		case 0:cout<<"sword"<<endl;break;
		case 1:cout<<"bomb"<<endl;break;
		case 2:cout<<"arrow"<<endl;break;
	}
}
enum worrider{lion,dragon,ninja,iceman,wolf};
enum equipment{sword,bomb,arrow};
int main(){
	int o,i;
	int R_we[100]={0},B_we[100]={0};
	cout<<"请输入进行测试的次数"<<endl; 
	cin>>o;
	for(i=1;i<=o;i++){
		cout<<"Case "<<i<<":"<<endl;
		Head Red,Blue;
		int n=0,t=0,flag1=1,flag2=1,min=0,temp=0;
		int R_rank[10]={3,0,4,2,1};
		int B_rank[10]={0,1,2,3,4};
		int cost[10]={0},cost1=0,cost2=0,num1=0,num2=0;
		cout<<"请输入基地初始生命:"<<endl;
		cin>>n;
		cout<<"请输入按dragon 、ninja、iceman、lion、wolf 的顺序输入初始生命:"<<endl; 
		cin>>cost[1]>>cost[2]>>cost[3]>>cost[0]>>cost[4];
		min=getmin(cost);
		Red.setfactor(n),Blue.setfactor(n);
		while(flag1||flag2){
			if(flag1){
				if(Red.strenth>=min){
					temp=t%5;
					while(1){
						num1=R_rank[temp];
						cost1=cost[num1];
						if(Red.strenth>=cost1){
							Red.cut(cost1);
							Red.addw(num1,cost1);
							if(t<10)cout<<"00"<<t<<" Red ";
							else if(t<100) cout<<"0"<<t<<" Red ";
							else cout<<t<<" Red ";
							output(num1);
							cout<<" ";
							cout<<Red.number<<" with strenth "<<cost1<<",";
							getnum(num1,Red);
							cout<<" ";
							output(num1);
							cout<<" in red headquarter"<<endl;
							out_weapon(Red,t);
							switch(num1){
								case 0:{
									cout<<"its loyaty is "<<Red.sodier[t].loyaty<<endl;
									break;
								}
								case 1:{
									cout<<",and its morale is "<<setiosflags(ios::fixed)<<setprecision(2)<<Red.sodier[t].morale<<endl;
									break;
								}
							}
							break;
						}
						else{
							temp=(temp+1)%5;
						} 
					}
					
				}
				else{
					if(t<10)cout<<"00"<<t<<" Red headquarter stops making warriors"<<endl;
					else if(t<100)cout<<"0"<<t<<" Red headquarter stops making warriors"<<endl;
					else cout<<t<<" Red headquarter stops making warriors"<<endl;
					flag1=0;
				}
			}
			if(flag2){
				if(Blue.strenth>=min){
					temp=t%5;
					while(1){
						num2=B_rank[temp];
						cost2=cost[num2];
						if(Blue.strenth>=cost2){
							Blue.cut(cost2);
							Blue.addw(num2,cost2);
							if(t<10)cout<<"00"<<t<<" Blue ";
							else if(t<100) cout<<"0"<<t<<" Blue ";
							else cout<<t<<" Blue ";
							output(num2);
							cout<<" ";
							cout<<Blue.number<<" with strenth "<<cost2<<",";
							getnum(num2,Blue);
							cout<<" ";
							output(num2);
							cout<<" in Blue headquarter"<<endl;
							out_weapon(Blue,t);
							switch(num2){
								case 0:{
									cout<<"its loyaty is "<<Blue.sodier[t].loyaty<<endl;
									break;
								}
								case 1:{
									cout<<",and its morale is "<<setiosflags(ios::fixed)<<setprecision(2)<<Blue.sodier[t].morale<<endl;
									break;
								}
							}
							break;
						}
						else{
							temp=(temp+1)%5;
						}
					}
				}
				else{
					if(t<10)cout<<"00"<<t<<" Blue headquarter stops making warriors"<<endl;
					else if(t<100)cout<<"0"<<t<<" Blue headquarter stops making warriors"<<endl;
					else cout<<t<<" Blue headquarter stops making warriors"<<endl;
					flag2=0;
				}
			}
			t++; 
		}
	}
	return 0;
}
