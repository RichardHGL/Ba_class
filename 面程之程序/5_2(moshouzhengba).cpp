#include<iostream>
using namespace std;
class Head{
	public:
		int lion,dragon,ninja,iceman,wolf;
		int strenth,number;
		Head(){ 
			lion=0;ninja=0;iceman=0;
			wolf=0;dragon=0;number=0;
		}
		void setfactor(int a=0);
		void cut(int a=0);
		void addw(int a=0);
		//addw_R(int a=0);
};
void Head::setfactor(int a){
	strenth=a;
}
void Head::cut(int a){
	strenth-=a;
}
void Head::addw(int a){
	switch(a){
		case 0: lion++;break;
		case 1: dragon++;break;
		case 2: ninja++;break;
		case 3: iceman++;break;
		case 4: wolf++;break; 
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
enum worrider{lion,dragon,ninja,iceman,wolf};
int main(){
	int o,i;
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
							Red.addw(num1);
							cout<<"00"<<t<<" Red ";
							output(num1);
							cout<<" ";
							cout<<Red.number<<"with strenth"<<cost1<<",";
							getnum(num1,Red);
							cout<<" ";
							output(num1);
							cout<<" in red headquarter"<<endl;
							break;
						}
						else{
							temp=(temp+1)%5;
						} 
					}
					
				}
				else{
					cout<<"00"<<t<<" Red headquarter stops making warriors"<<endl;
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
							Blue.addw(num2);
							cout<<"00"<<t<<" Blue ";
							output(num2);
							cout<<" ";
							cout<<Blue.number<<"with strenth"<<cost1<<",";
							getnum(num2,Blue);
							cout<<" ";
							output(num2);
							cout<<" in Blue headquarter"<<endl;
							break;
						}
						else{
							temp=(temp+1)%5;
						}
					}
				}
				else{
					cout<<"00"<<t<<" Blue headquarter stops making warriors"<<endl;
					flag2=0;
				}
			}
			t++; 
		}
	}
	return 0;
}
