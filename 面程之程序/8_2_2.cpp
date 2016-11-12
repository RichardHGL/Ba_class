#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int R_rank[10]={3,0,4,2,1};
int B_rank[10]={0,1,2,3,4};
int M=0;//司令部初始生命
int N=0;//城市个数
int R=0;//弓箭攻击力
int K=0;//lion掉落忠诚度
int T=0;//以s为单位进行观测的时间 
bool end_flag;
int cost[10]={0},forth[10]={0}; 
enum worrider{lion,dragon,ninja,iceman,wolf};//顺序表 
enum equipment{sword,bomb,arrow};
int showtime(int hour,int minute);
void output(int a);
class Weapon{
	public:
		int type;//武器种类 
		int force;//武器攻击力
		int time;//弓箭的使用次数 
		/*Weapon(int a,int b):type(a),force(b){
			if(a==2) time=3;
			else time=0;
		}*/
		//Weapon(const Weapon & wp):type(wp.type),force(wp.force),time(wp.time){}
		void operator =(Weapon & wp){
			type=wp.type;
			force=wp.force;
			time=wp.time;
		}
		const Weapon & operator =(Weapon & wp)const{
			return wp;
		}
		void add_w(int i,int j){
			type=i;
			if(i==2) time=3;
			else time=0;
			if(i==0) force=j;
			else force=0;
		}
};
class worridor{
	public:
		int type;//种族 
		int strenth;//生命值
		int loyaty;//lion专属忠诚度
		int force;//武士本身攻击力 
		int weapon_num;//武器数目，可变 
		int tag;//归属红方或蓝方 
		int num;//编号 
		Weapon weapon[4];//武器系列，-1为没有，012为正常值sword bomb arrow
		int position;//位于城镇的位置，红方从0开始，蓝方从N+1开始 
		double morale;//dragon专属士气
		int model;//0代表正常出战,1代表死亡，2代表逃跑,3代表到达目的地 
		/*worridor(){//初始化根据武士种类有异 
			type=0,strenth=0,loyaty=0,tag=0,
			weapon_num=0,morale=0.0;
			model=0;
		}*/
		void get_weapon(Weapon a[],int b){
			int i=0,j=0;
			if(b>0){
				for(i=0;i<b;i++){
					for(j=0;j<weapon_num;j++){
						if(weapon[j].type==a[i].type) break;
					}
					if(j==weapon_num){
						weapon[j].type=a[i].type;
						weapon[j].force=a[i].force;
						weapon[j].time=a[i].time;
						weapon_num++;
					}
				}
			} 
			
		} 
		int has_arrow(){
			for(int i=0;i<weapon_num;i++){
				if(weapon[i].type==2&&weapon[i].time>0) return weapon[i].time;
			}
			return 0;
		}
		void arrow_cost(){
			for(int i=0;i<weapon_num;i++){
				if(weapon[i].type==2&&weapon[i].time>0) weapon[i].time--;
			}
		}
		bool has_bomb(){
			//cout<<"boom "<<weapon_num<<endl;
			for(int i=0;i<weapon_num;i++){
				//cout<<i<<" "<<weapon[i].type<<endl;
				if(weapon[i].type==1) return true;
			}
			return false;
		}
		bool has_sword(){
			for(int i=0;i<weapon_num;i++){
				if(weapon[i].type==0&&weapon[i].force>0) return true;
			}
			return false;
		}
		int sword(int tag){//tag为0代表模拟,为1代表实战 
			int temp=0;
			if(has_sword()){
				for(int i=0;i<weapon_num;i++){
					if(weapon[i].type==0){
						temp=weapon[i].force;
						if(tag) weapon[i].force*=0.8;
						return temp;
					}
				}
				
			}
			return 0;
		}
		void lose_weapon(){
			for(int i=0;i<weapon_num;i++){
				if(weapon[i].type==0&&weapon[i].force<=0){
					for(int j=i+1;j<weapon_num;j++) weapon[j-1]=weapon[j];
					weapon_num--;
					i--;continue;
				}
				else if(weapon[i].type==2&&weapon[i].time<=0){
					for(int j=i+1;j<weapon_num;j++) weapon[j-1]=weapon[j];
					weapon_num--;
					i--;continue;
				}
			}
		}
		void operator =(worridor &wp){ //?如何引用 
			worridor temp;
			type=wp.type;
			strenth=wp.strenth;
			loyaty=wp.strenth;
			force=wp.force;
			weapon_num=0;
			tag=wp.tag;
			num=wp.num;
			get_weapon(wp.weapon,wp.weapon_num);
			position=wp.position; 
			morale=wp.morale;
			model=wp.model;
		}
		int battle_win(worridor wp2,int adv){
			if(wp2.strenth<=0&&strenth>0) return 1;
			if(strenth<=0&&wp2.strenth>0) return 2;
			if(tag==0){
				if(adv==0){
					int attack=force+sword(0);
					if(attack>=wp2.strenth) return 1;
					if(wp2.type==2) return 0;
					int b_attack=wp2.force/2+wp2.sword(0);
					if(b_attack>=strenth) return 2; 
				} 
				else if(adv==1){
					int attack=wp2.force+wp2.sword(0);
					if(attack>=strenth) return 2;
					if(type==2) return 0;
					int b_attack=force/2+sword(0);
					if(b_attack>=wp2.strenth) return 1;
				}
			}
			else if(tag==1){
				if(adv==0){
					int attack=wp2.force+wp2.sword(0);
					if(attack>=strenth) return 2;
					if(type==2) return 0;
					int b_attack=force/2+sword(0);
					if(b_attack>=wp2.strenth) return 1;
				} 
				else if(adv==1){
					int attack=force+sword(0);
					if(attack>=wp2.strenth) return 1;
					if(wp2.type==2) return 0;
					int b_attack=wp2.force/2+wp2.sword(0);
					if(b_attack>=strenth) return 2;
				}
			}
			return 0;
		}
		int battle(worridor &wp,int p,int adv,int hour,int minute){//0代表初态均死或无胜负
			int strenth1=strenth,strenth2=wp.strenth; 
			if(strenth<=0&&wp.strenth>0) return 2;
			else if(strenth>0&&wp.strenth<=0) return 1;
			else if(strenth<=0&&wp.strenth<=0) return 0;
			showtime(hour,minute);
			if(adv==0){
				int attack=force+sword(1);
				wp.gethurt(attack);
				cout<<" red ";
				output(type);
				cout<<" "<<num<<" attacked blue ";
				output(wp.type);
				cout<<" "<<wp.num<<" in city "<<p<<" with "<<strenth<<" elements"
				<<" and force "<<force<<endl;
				showtime(hour,minute);
				cout<<" blue ";
				output(wp.type);
				cout<<" "<<wp.num;
				if(wp.strenth<=0){
					cout<<" was killed in city "<<p<<endl;
					morale+=0.2;
					if(type==4) get_weapon(wp.weapon,wp.weapon_num);
					if(wp.type==0) strenth+=strenth2;
					if(type==1&&morale>=0.8){
						cout<<" red ";
						output(type);
						cout<<" "<<num<<" yelled in city "<<p<<endl;
					}
					return 1;
				}
				if(type==0) loyaty-=K;
				if(wp.type==2) return 0;
				int b_attack=wp.force/2+wp.sword(1);
				gethurt(b_attack);
				cout<<" fought back against red ";
				output(type);
				cout<<" "<<num<<" in city "<<p<<endl;
				if(strenth<=0){
					showtime(hour,minute);
					if(type==0) wp.strenth+=strenth1;
					if(wp.type==4) wp.get_weapon(weapon,weapon_num);
					cout<<" red ";
					output(type);
					cout<<" "<<num;
					cout<<" was killed in city "<<p<<endl;
					wp.morale+=0.2;
					return 2;
				}
				if(type==1) morale-=0.2;
				if(type==1&&morale>=0.8){
					cout<<" red ";
					output(type);
					cout<<" "<<num<<" yelled in city "<<p<<endl;
				}
				if(wp.type==0) wp.loyaty-=K;
			}
			if(adv==1){
				int attack=wp.force+wp.sword(1);
				gethurt(attack);
				cout<<" blue ";
				output(wp.type);
				cout<<" "<<wp.num<<" attacked red ";
				output(type);
				cout<<" "<<num<<" in city "<<p<<" with "<<wp.strenth<<" elements and force "
				<<wp.force<<endl;
				showtime(hour,minute);
				cout<<" red ";
				output(type);
				cout<<" "<<num;
				if(strenth<=0){
					if(wp.type==4){
						wp.get_weapon(weapon,weapon_num);
					} 
					if(type==0) wp.strenth+=strenth1;
					if(wp.type==1) wp.morale+=0.2;
					cout<<" was killed in city "<<p<<endl;
					if(wp.type==1&&wp.morale>=0.8){
						cout<<" blue ";
						output(wp.type);
						cout<<" "<<wp.num<<" yelled in city "<<p<<endl;
					}
					return 2;
				}
				if(wp.type==0) wp.loyaty-=K;
				if(type==2) return 0;
				cout<<" fought back against blue ";
				output(wp.type);
				cout<<" "<<wp.num<<" in city "<<p<<endl;
				int b_attack=force/2+sword(1);
				wp.gethurt(b_attack);
				if(wp.strenth<=0){
					if(type==4) get_weapon(wp.weapon,weapon_num);
					if(wp.type==0) strenth+=strenth2;
					showtime(hour,minute);
					cout<<" blue ";
					output(wp.type);
					cout<<" "<<wp.num;
					cout<<" was killed in city "<<p<<endl;
					return 1;
				}
				if(type==0) loyaty-=K;
				if(wp.type==1) wp.morale-=0.2;
				if(wp.type==1&&wp.morale>=0.8){
					cout<<" blue ";
					output(wp.type);
					cout<<" "<<wp.num<<" yelled in city "<<p<<endl;
				}
			}
			return 0;
		}
		int usebomb(worridor &wp,int p,int adv){
			//cout<<"adv="<<adv;
			if(wp.strenth<=0) return 0;
			if(strenth<=0) return 0;
			//cout<<"has_bomb"<<has_bomb()<<" winer:"<<battle_win(wp,adv)<<endl;
			if(has_bomb()&&battle_win(wp,adv)==2){
				strenth=0;wp.strenth=0;
				return 1;
			}
			return 0;
		}
		void gethurt(int a){
			strenth-=a;
		}
		void weapon_out(){
			output(type);
			cout<<" "<<num<<" has ";
			if(weapon_num==0) cout<<"no weapon";
			else{
				if(has_arrow()) cout<<"arrow("<<has_arrow()<<")";
				if(has_bomb()) cout<<",bomb";
				if(has_sword()) cout<<",sword("<<sword(0)<<")";
			}
			cout<<endl; 
		}
};
class City{
	public:
		int num;//城市位置 
		int strenth;//生命元数，可累积 
		int belongs;//0为红方，1为蓝方,-1代表无主 
		int people_n;
		int last_win;//上次赢家 
		worridor competitor[3];
		City(){
			num=0;strenth=0;belongs=-1;last_win=-1;
			people_n=0;
		}
		void setfactor(int a,int b,int c,int d,int e){
			num=a;
			strenth=b;
			belongs=c;
			people_n=d;
			last_win=e;
		}
		void locate(worridor sodier[],int number){
			for(int i=0;i<number;i++){
				if(sodier[i].position==num&&sodier[i].model==0){
					competitor[people_n]=sodier[i];
					people_n++;
				}
			}
		}
		void makebelongs(int tag,int hour,int minute){
			showtime(hour,minute);
			belongs=tag;
			if(tag==0) cout<<" red ";
			else if(tag==1) cout<<" blue ";
			cout<<"flag raised in city "<<num<<endl;
		}
		int adv_judge(){
			int adv=-1;
			if(belongs==0) adv=0;
			else if(belongs==1) adv=1;
			else if(belongs==-1&&num%2==1) adv=0;
			else if(belongs==-1&&num%2==0) adv=1;
			return adv;
		}
};
class Head{
	public:
		int lion,dragon,ninja,iceman,wolf;
		int strenth,number;
		int arrived;
		worridor sodier[200];
		Head(){
			lion=0;ninja=0;iceman=0;
			wolf=0;dragon=0;number=0;arrived=0;
		}
		void setfactor(int a=0);
		void cut(int a=0);
		void add(int a=0);
		void addw(int a=0,int strenth=0,int force=0,int tag=0);
		void escape(int tag,int hour,int minute);
		int born(int tag,int hour,int minute);
		void death(); 
		int forward(int tag,int hour,int minute);
		void report(int tag,int hour,int minute);
		void reward(int tag,int a[],int n){
			if(tag==0){
				for(int i=n-1;i>=0;i--){
					if(strenth>=8){
						sodier[i].strenth+=8;
						strenth-=8;
					}
					else break;
				}
			}
			else if(tag==1){
				for(int i=0;i<n;i++){
					if(strenth>=8){
						sodier[i].strenth+=8;
						strenth-=8;
					}
					else break;
				}
			}
		}
};//类成员区 
	int Head::born(int tag,int hour,int minute){
		int temp=number%5; 
		int cost1=0,num1=0,force1=0;
		if(tag==0) num1=R_rank[temp];
		else if(tag==1) num1=B_rank[temp];
		//cout<<num1;
		cost1=cost[num1];
		force1=forth[num1];
		//cout<<" cost1 "<<cost1<<" force1 "<<force1<<" tag "<<tag<<endl;
		if(strenth<cost1) return 0;
		showtime(hour,minute);
		if(tag==0) cout<<" red ";
		else if(tag==1) cout<<" blue ";
		cut(cost1);
		addw(num1,cost1,force1,tag);
		output(num1);
		cout<<" "<<number<<" born"<<endl;//born 时编号为number 
		switch(num1){
			case 0:{
				cout<<"Its loyaty is "<<sodier[number-1].loyaty<<endl;
				break;
			}
			case 1:{
				cout<<"Its morale is "<<setiosflags(ios::fixed)
				<<setprecision(2)<<sodier[number-1].morale<<endl;
				break;
			}
		}
		return 0;
	}
	void Head::death(){
		for(int i=0;i<number;i++){
			if(sodier[i].model==0&&sodier[i].strenth<=0){
				sodier[i].model=1;
			}
		}
	}
	void Head::escape(int tag,int hour,int minute){//判断某时刻是否有逃跑的狮子 
		if(lion>0){
			for(int i=0;i<number;i++){
				if(sodier[i].type==0&&sodier[i].loyaty<=0&&sodier[i].model==0){
					showtime(hour,minute);
					if(tag==0) cout<<" red ";
					else if(tag==1) cout<<" blue ";
					cout<<"lion "<<sodier[i].num<<" ran away"<<endl;
					sodier[i].model=2;
				}
			}
		}
	}
	int Head::forward(int tag,int hour,int minute){
		for(int i=0;i<number;i++){
			if(sodier[i].model==0){
				showtime(hour,minute);
				if(tag==0){
					cout<<" red ";
					output(sodier[i].type);
					cout<<" "<<sodier[i].num;
					if(sodier[i].position<=N) sodier[i].position++;
					if(sodier[i].type==3&&sodier[i].position%2==0){
						if(sodier[i].strenth-9>0){
							sodier[i].strenth-=9;
							sodier[i].force+=20;
						}
					}
					if(sodier[i].position==N+1){
						sodier[i].model=3;
						cout<<" reached blue headquarter with ";
						arrived++;
					}
					else{
						cout<<" marched to city "<<sodier[i].position<<" with ";
					}
					cout<<sodier[i].strenth<<" elements and force "<<sodier[i].force<<endl;
					if(arrived==2) return 1;
				}
				if(tag==1){
					cout<<" blue ";
					output(sodier[i].type);
					cout<<" "<<sodier[i].num;
					if(sodier[i].position>=1) sodier[i].position--;
					if(sodier[i].position==0){
						sodier[i].model=3;
						cout<<" reached red headquarter with ";
						arrived++;
					}
					else{
						cout<<" marched to city "<<sodier[i].position<<" with ";
					}
					cout<<sodier[i].strenth<<" elements and force "<<sodier[i].force<<endl;
					if(arrived==2) return 1;
				} 
			}
		}
		return 0;
	}
	void Head::setfactor(int a){
		strenth=a;
	}
	void Head::cut(int a){
		strenth-=a;
	}
	void Head::add(int a){
		strenth+=a;
	}
	void Head::addw(int a,int strenth_in,int force_in,int tag){
		sodier[number].type=a;
		sodier[number].strenth=strenth_in;
		sodier[number].force=force_in;
		sodier[number].num=number+1;
		sodier[number].tag=tag;
		sodier[number].model=0;
		int temp_force=force_in*0.2;
		switch(a){
			case 0: {
				lion++;
				sodier[number].weapon_num=0;
				sodier[number].loyaty=strenth;
			}break;
			case 1: {
				dragon++;
				sodier[number].weapon_num=1;
				sodier[number].weapon[0].add_w((number+1)%3,temp_force);
				sodier[number].morale=(double)strenth/(double)strenth_in;
			}break;
			case 2:{
				ninja++;
				sodier[number].weapon_num=2;
				sodier[number].weapon[0].add_w((number+1)%3,temp_force);
				sodier[number].weapon[1].add_w((number+2)%3,temp_force);
			} break;
			case 3:{
				iceman++;
				sodier[number].weapon_num=1;
				sodier[number].weapon[0].add_w((number+1)%3,temp_force);
			} break;
			case 4:{
				sodier[number].weapon_num=0;
				wolf++;
			} break; 
		}
		if(tag==0) sodier[number].position=0;
		else if(tag==1) sodier[number].position=N+1;
		number++;
	}
	void Head::report(int tag,int hour,int minute){
		if(tag==0) for(int i=number-1;i>=0;i--){
			if(sodier[i].model==0||sodier[i].model==3){
				showtime(hour,minute);
				cout<<" red ";
				sodier[i].weapon_out();
			}
		}
		else if(tag==1) for(int i=0;i<number;i++){
			if(sodier[i].model==0||sodier[i].model==3){
				showtime(hour,minute);
				cout<<" blue ";
				sodier[i].weapon_out();
			}
		}
	}

//实操作函数区 
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
		switch(A.sodier[numb].weapon[0].type){
			case 0:cout<<"sword";break;
			case 1:cout<<"bomb";break;
			case 2:cout<<"arrow";break;
		}
		if(A.sodier[numb].weapon_num==1){
			if(A.sodier[numb].type!=1) cout<<endl;
			return 0;
		} 
		cout<<" and a ";
		switch(A.sodier[numb].weapon[0].type){
			case 0:cout<<"sword"<<endl;break;
			case 1:cout<<"bomb"<<endl;break;
			case 2:cout<<"arrow"<<endl;break;
		}
	}

City city[23];
int main(){
	int o,i;
	int R_we[100]={0},B_we[100]={0};
	cout<<"请输入进行测试的次数"<<endl;
	cin>>o;
	for(i=1;i<=o;i++){//进行o次模拟 
		cout<<"Case "<<i<<":"<<endl;
		//设定区 
			end_flag=false;
			Head Red,Blue;
			int t=0,flag1=1,flag2=1,min=0,temp=0;
			int cost1=0,cost2=0,num1=0,num2=0;
			int force[10]={0};
			int hour=0,minute=0;//time
		//初始输入和设定区 
			cout<<"请输入司令部初始生命，城市个数，弓箭攻击力，lion掉落忠诚度，观测终止时间:"<<endl;
			cin>>M>>N>>R>>K>>T;
			hour=T/60+1;
			minute=T%60; 
			cout<<"请输入按dragon 、ninja、iceman、lion、wolf 的顺序输入初始生命:"<<endl; 
			cin>>cost[1]>>cost[2]>>cost[3]>>cost[0]>>cost[4];
			min=getmin(cost);
			cout<<"请输入按dragon 、ninja、iceman、lion、wolf 的顺序输入初始攻击力:"<<endl; 
			cin>>forth[1]>>forth[2]>>forth[3]>>forth[0]>>forth[4];
			Red.setfactor(M),Blue.setfactor(M);
			for(int j=1;j<=N;j++) city[j].setfactor(j,0,-1,0,-1);
		//操作区 
			for(int j=0;j<hour&&!end_flag;j++){
				for(int k=0;k<60&&!end_flag;k++){
					if(j==hour-1&&k>=minute){
						end_flag=true;
						continue;
					}
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
							//cout<<Red.number<<"r b"<<Blue.number<<endl;
								for(int p=1;p<=N;p++){//重新统计每座城人数,并确定何人
									city[p].locate(Red.sodier,Red.number);
									city[p].locate(Blue.sodier,Blue.number);
									//system("pause");
									if(city[p].people_n==1){
										if(city[p].competitor[0].tag==0){
											Red.add(city[p].strenth);
											showtime(j,k);
											cout<<" red ";
											output(city[p].competitor[0].type);
											cout<<" "<<city[p].competitor[0].num<<" earned "<<
											city[p].strenth<<" elements for his headquater"<<endl; 
										} 
										else if(city[p].competitor[0].tag==1){
											Blue.add(city[p].strenth);
											showtime(j,k);
											cout<<" blue ";
											output(city[p].competitor[0].type);
											cout<<" "<<city[p].competitor[0].num<<" earned "<<
											city[p].strenth<<" elements for his headquater"<<endl;
										} 
										city[p].strenth=0;
									}
								}
								
								break;
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
											Red.sodier[city[p].competitor[0].num-1]=city[p].competitor[0];//城市带回司令部 
											Blue.sodier[city[p+1].competitor[1].num-1]=city[p+1].competitor[1];
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
											if(city[p+1].competitor[0].strenth<=0){
												cout<<" and killed blue ";//p+1城红方胜利 
												output(city[p+1].competitor[0].type);
												cout<<" "<<city[p+1].competitor[0].num;
											}
											Red.sodier[city[p].competitor[0].num-1]=city[p].competitor[0];//城市带回司令部 
											Blue.sodier[city[p+1].competitor[0].num-1]=city[p+1].competitor[0];
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
											Red.sodier[city[p-1].competitor[0].num-1]=city[p-1].competitor[0];//城市带回司令部 
											Blue.sodier[city[p].competitor[1].num-1]=city[p].competitor[1];
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
										output(city[p].competitor[0].type);
										cout<<" "<<city[p].competitor[0].num<<" shot";
										if(city[p-1].competitor[0].strenth<=0){
											cout<<" and killed red ";//p+1城红方胜利 
											output(city[p-1].competitor[0].type);
											cout<<" "<<city[p-1].competitor[0].num;
										}
										cout<<endl;
										Red.sodier[city[p-1].competitor[0].num-1]=city[p-1].competitor[0];//城市带回司令部 
										Blue.sodier[city[p].competitor[0].num-1]=city[p].competitor[0];
									}
								}
							}
							break;
						}
						case 38:{//炸弹预判
							int p=0;
							for(p=1;p<=N;p++){
								if(city[p].people_n==2){
									if(city[p].competitor[0].usebomb(city[p].competitor[1],p,city[p].adv_judge())){
										showtime(j,k);
										cout<<" red ";
										output(city[p].competitor[0].type);
										cout<<" "<<city[p].competitor[0].num<<" used a bomb and killed blue";
										output(city[p].competitor[1].type);
										cout<<" "<<city[p].competitor[1].num<<endl;
										Red.sodier[city[p].competitor[0].num-1]=city[p].competitor[0];//城市带回司令部 
										Blue.sodier[city[p].competitor[1].num-1]=city[p].competitor[1];
									}
									else if(city[p].competitor[1].usebomb(city[p].competitor[0],p,city[p].adv_judge())){
										showtime(j,k);
										cout<<" blue ";
										output(city[p].competitor[1].type);
										cout<<" "<<city[p].competitor[1].num<<" used a bomb and killed red";
										output(city[p].competitor[0].type);
										cout<<" "<<city[p].competitor[0].num<<endl;
										Red.sodier[city[p].competitor[0].num-1]=city[p].competitor[0];//城市带回司令部 
										Blue.sodier[city[p].competitor[1].num-1]=city[p].competitor[1];
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
									int temp=city[p].competitor[0].battle(city[p].competitor[1],p,city[p].adv_judge(),j,k);
									if(temp==1){
										showtime(j,k);
										cout<<" red ";
										output(city[p].competitor[0].type);
										cout<<" "<<city[p].competitor[0].num<<" earned "<<
										city[p].strenth<<" elements for his headquater"<<endl; 
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
										city[p].strenth<<" elements for his headquater"<<endl; 
										B_add+=city[p].strenth;
										B_reward[B_win]=p;
										B_win++;
										city[p].strenth=0;//生命元被拿走后清零
										if(city[p].last_win==1){
											if(city[p].belongs==-1) city[p].makebelongs(1,j,k);
											if(city[p].belongs==0) city[p].belongs=-1;
										}
										city[p].last_win=1;
									}
									city[p].competitor[0].lose_weapon();
									city[p].competitor[1].lose_weapon();
									Red.sodier[city[p].competitor[0].num-1]=city[p].competitor[0];//城市带回司令部 
									Blue.sodier[city[p].competitor[1].num-1]=city[p].competitor[1];
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
							cout<<" "<<Red.strenth<<" elements"<<" int red headquater"<<endl;
							showtime(j,k);
							cout<<" "<<Blue.strenth<<" elements"<<" int blue headquater"<<endl;
							break;
						}
						case 55:{//武士武器报告
							for(int p=0;p<Red.number;p++){
								if(Red.sodier[p].model==0) Red.sodier[p].lose_weapon();
							}
							for(int p=0;p<Blue.number;p++){
								if(Blue.sodier[p].model==0) Blue.sodier[p].lose_weapon();
							}
							Red.report(0,j,k);
							Blue.report(1,j,k);
							break;
						}
					}
				}
			}
		}	
	return 0;
}
