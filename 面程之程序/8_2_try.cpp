#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include"setings.h"
using namespace std;
int R_rank[10]={3,0,4,2,1};
int B_rank[10]={0,1,2,3,4};
int M=0;//司令部初始生命
int N=0;//城市个数
int R=0;//弓箭攻击力
int K=0;//lion掉落忠诚度
int T=0;//以s为单位进行观测的时间 
bool end_flag;
int cost[10]={0},force[10]={0}; 
enum worrider{lion,dragon,ninja,iceman,wolf};//顺序表 
enum equipment{sword,bomb,arrow};
int showtime(int hour,int minute);
int output(int a);
int showtime(int hour,int minute){
		if(hour<10) cout<<"00"<<hour;
		else if(hour<100) cout<<"0"<<hour;
		else cout<<hour;
		cout<<":";
		if(minute<10) cout<<"0"<<minute;
		else cout<<minute;
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
}
City city[23]={0};
int main(){
	int o,i;
	int R_we[100]={0},B_we[100]={0};
	cout<<"请输入进行测试的次数"<<endl;
	cin>>o;
	for(i=1;i<=o;i++){//进行o次模拟 
		cout<<"Case "<<i<<":"<<endl;
		{//设定区 
			Head Red,Blue;
			int t=0,flag1=1,flag2=1,min=0,temp=0;
			int cost1=0,cost2=0,num1=0,num2=0;
			int force[10]={0};
			int hour=0,minute=0;//time
		}
		{//初始输入和设定区 
			cout<<"请输入司令部初始生命，城市个数，弓箭攻击力，lion掉落忠诚度，观测终止时间:"<<endl;
			cin>>M>>N>>R>>K>>T;
			hour=T/60+1;
			cout<<"请输入按dragon 、ninja、iceman、lion、wolf 的顺序输入初始生命:"<<endl; 
			cin>>cost[1]>>cost[2]>>cost[3]>>cost[0]>>cost[4];
			min=getmin(cost);
			cout<<"请输入按dragon 、ninja、iceman、lion、wolf 的顺序输入初始生命:"<<endl; 
			cin>>force[1]>>force[2]>>force[3]>>force[0]>>force[4];
			Red.setfactor(M),Blue.setfactor(M);
			for(int j=1;j<=N;j++) city[j].setfactor(j,0,-1,0,-1);
		}
		{//操作区 
			for(int j=0;j<hour&&!end_flag;j++){
				for(int k=0;k<60&&!end_flag;k++){
					switch(k){
						case 0:{//武士产生
							Red.born(0,j,k);
							Blue.born(1,j,k);
							break;
						}
						case 5:{//lion逃跑 
							Red.escape(0,j,k);
							Blue.escape(1,j,k); 
							break;
						}
						case 10:{//逼近敌方并报告此时每位武士的生命值和攻击力 
							flag1=Red.forward(0,j,k);
							if(flag1){
								showtime(j,k);
								cout<<" blue headquater was taken"<<endl;
							}
							flag2=Blue.forward(1,j,k);
							if(flag2){
								showtime(j,k);
								cout<<" red headquater was taken"<<endl;
							}
							if(flag1||flag2){
								end_flag=true;
								break;
							}
							for(int p=1;p<=N;p++){//移动后每座城人数清零，然后重新统计 
								city[p].people_n=0;
							}
							break;
						}
						case 20:{//产出生命元
							for(int p=1;p<=N;p++) city[p].strenth+=10;
							break;
						}
						case 30:{//独居一城者得生命元 
								for(int p=1;p<=N;p++){//重新统计每座城人数,并确定何人 
									city[p].locate(Red.sodier,Red.number);
									city[p].locate(Blue.sodier,Blue.number);
								}
								if(city[p].people_n==1){
									if(city[p].competitor[0].tag==0) Red.add(city[p].strenth);
									else if(city[p].competitor[0].tag==1) Blue.add(city[p].strenth);
								}break;
						}
						case 35:{//弓箭预判 
							for(int p=1;p<=N-1;p++){
								if(city[p].people_n>=1){//有红方则红方在 competitor[0],红方弓箭手射击 
									if(city[p].competitor[0].tag==0&&city[p].competitor[0].has_arrow()){
										if(city[p+1].people_n==2){//两人蓝排后 
											city[p+1].competitor[1].gethurt(R);
											city[p].competitor[0].arrow_cost(); 
											city[p].competitor[0].lose_weapon();
											showtime(j,k);
											cout<<" red ";
											output(city[p].competitor[0].type);
											cout<<" "<<city[p].competitor[0].num<<" shot";
											if(city[p+1].competitor[1].strenth<=0){
												cout<<" and killed blue ";//p+1城红方胜利 
												output(city[p+1].competitor[1].type);
												cout<<" "<<city[p+1].competitor[1].num;
											}
											cout<<endl;
										}
										else if(city[p+1].people_n==1&&city[p].competitor[0].tag==1){//一人 
											city[p+1].competitor[0].gethurt(R);
											city[p].competitor[0].arrow_cost(); 
											city[p].competitor[0].lose_weapon();
											showtime(j,k);
											cout<<" red ";
											output(city[p].competitor[0].type);
											cout<<" "<<city[p].competitor[0].num<<" shot";
											if(city[p+1].competitor[1].strenth<=0){
												cout<<" and killed blue ";//p+1城红方胜利 
												output(city[p+1].competitor[1].type);
												cout<<" "<<city[p+1].competitor[1].num;
											}
											cout<<endl;
										}
									}
								}
							}
							for(int p=N;p>=2;p--){//蓝方弓箭手射击 
								if(city[p].people_n==2){
									if(city[p].competitor[1].has_arrow()){//两人蓝排后
										if(city[p-1].people_n>=1&&city[p-1].competitor[0].tag==0){
											city[p-1].competitor[0].gethurt(R);
											city[p].competitor[1].arrow_cost(); 
											city[p].competitor[1].lose_weapon();
											showtime(j,k);
											cout<<" blue ";
											output(city[p].competitor[1].type);
											cout<<" "<<city[p].competitor[0].num<<" shot";
											if(city[p-1].competitor[0].strenth<=0){
												cout<<" and killed red ";//p+1城红方胜利 
												output(city[p-1].competitor[0].type);
												cout<<" "<<city[p-1].competitor[0].num;
											}
											cout<<endl;
										}
									}
								}
								if(city[p].people_n==1&&city[p].competitor[0].tag==1&&city[p].competitor[0].has_arrow()){
									if(city[p-1].people_n>=1&&city[p-1].competitor[0].tag==0){
										city[p-1].competitor[0].gethurt(R);
										city[p].competitor[0].arrow_cost(); 
										city[p].competitor[0].lose_weapon();
										showtime(j,k);
										cout<<" blue ";
										output(city[p].competitor[1].type);
										cout<<" "<<city[p].competitor[0].num<<" shot";
										if(city[p-1].competitor[0].strenth<=0){
											cout<<" and killed red ";//p+1城红方胜利 
											output(city[p-1].competitor[0].type);
											cout<<" "<<city[p-1].competitor[0].num;
										}
										cout<<endl;
									}
								}
							}
							break;
						}
						case 38:{//炸弹预判
							for(int p=1;p<=N;p++){
								if(city[p].people_n==2){
									if(city[p].competitor[0].usebomb(city[p].competitor[1],p,city[p].adv_judge())){
										showtime(j,k);
										cout<<" red ";
										output(city[p].competitor[0].type);
										cout<<" "<<city[p].competitor[0].num<<" used a bomb and killed blue";
										output(city[p].competitor[1].type);
										cout<<" "<<city[p].competitor[1].num;
									}
									else if(city[p].competitor[1].usebomb(city[p].competitor[0],p)){
										showtime(j,k);
										cout<<" blue ";
										output(city[p].competitor[1].type);
										cout<<" "<<city[p].competitor[1].num<<" used a bomb and killed red";
										output(city[p].competitor[0].type);
										cout<<" "<<city[p].competitor[0].num;
									}
								}
							}
							break;
						}
						case 40:{//战斗** 
							int R_add=0,B_add=0;
							int R_reward[23]={-1},B_reward[23]={-1};
							int R_win=0,B_win=0;
							for(int p=1;p<=N;p++){
								if(city[p].people_n==2){
									int temp=city[p].competitor[0].battle(city[p].competitor[1],p,city[p].adv_judge,j,k);
									if(temp==1){
										showtime(j,k);
										cout<<" red ";
										output(city[p].competitor[0].type);
										cout<<" "<<city[p].competitor[0].num<<" earned "<<
										city[p].strenth<<"for his headquater"<<endl; 
										R_add+=city[p].strenth;
										R_reward[R_win]=p;
										R_win++;
										city[p].strenth=0;//生命元被拿走后清零
										if(city[p].last_win==0){
											if(city[p].belongs==-1) city[p].makebelongs(0,j,k);
											if(city[p].belongs==1) city[p].belongs=-1;
										}
										city[p].last_win=0;
									}
									else if(temp==2){
										showtime(j,k);
										cout<<" blue ";
										output(city[p].competitor[1].type);
										cout<<" "<<city[p].competitor[1].num<<" earned "<<
										city[p].strenth<<"for his headquater"<<endl; 
										B_add+=city[p].strenth;
										B_reward[B_win]=p;
										B_win++;
										Blue.add(city[p].strenth);
										city[p].strenth=0;//生命元被拿走后清零
										if(city[p].last_win==1){
											if(city[p].belongs==-1) city[p].makebelongs(1,j,k);
											if(city[p].belongs==0) city[p].belongs=-1;
										}
										city[p].last_win=1;
									}
								}
							}
							Red.reward(0,R_reward,R_win);
							Blue.reward(1,B_reward,B_win);
							Red.add(R_add);
							Blue.add(B_add);
							Red.death();
							Blue.death();
							break;
						}
						case 50:{//司令部报告生命元 
							showtime(j,k);
							cout<<Red.strenth<<" elements"<<" int red headquater"<<endl;
							showtime(j,k);
							cout<<Blue.strenth<<" elements"<<" int red headquater"<<endl;
							break;
						}
						case 55:{//武士武器报告
							for(int p=0;p<Red.number;p++){
								if(Red.sodier[p].model==0) Red.sodier[p].lose_weapon();
							}
							for(int p=0;p<Blue.number;p++){
								if(Blue.sodier[p].model==0) Blue.sodier[p].lose_weapon()
							}
							Red.report(0,j,k);
							Blue.report(1,j,k);
							break;
						}
					}
				}
			}
		}	
	}
	return 0;
}
