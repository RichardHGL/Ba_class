#include<iostream>
#include<stdlib.h>
#include<iomanip>
int showtime(int hour,int minute);
int output(int a);
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
		Weapon & operator =(Weapon & wp){
			return wp;
		}
		const Weapon & operator =(Weapon & wp)const{
			return wp;
		}
		void addw(int i,int j){
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
			for(int i=0;i<weapon_num;i++){
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
		worridor & operator =(worridor &wp){
			return wp;
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
			if(wp.strenth<=0) return 0;
			if(strenth<=0) return 0;
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
				cout<<endl; 
			}
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
				if(sodier[i].position==num){
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
			cout<<"flag raised in city "<<num;
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
		void escape(int tag);
		int born(int tag,int hour,int minute);
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
};
{
	//类成员区 
	int Head::born(int tag,int hour,int minute){
		int temp=number%5; 
		int cost1=0,num1=0,force1=0;
		if(tag==0) num1=R_rank[temp];
		else if(tag==1) num1=B_rank[temp];
		cost1=cost[num1];
		force1=force[num1];
		if(strenth<cost1) return 0;
		showtime(hour,minute);
		if(tag==0) cout<<" red ";
		else if(tag==1) cout<<" blue ";
		cut(cost1);
		addw(num1,cost1,force1,tag);
		output(num1);
		cout<<number<<" born"<<endl;//born 时编号为number 
		switch(num1){
			case 0:{
				cout<<"its loyaty is "<<sodier[number-1].loyaty<<endl;
				break;
			}
			case 1:{
				cout<<" its morale is "<<setiosflags(ios::fixed)
				<<setprecision(2)<<sodier[number-1].morale<<endl;
				break;
			}
		}
		return 0;
	}
	void Head::death(){
		for(int i=0,i<number;i++){
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
						if(arrived==2) return 1;
					}
					else{
						cout<<" marched to city "<<sodier[i].position<<" with ";
					}
					cout<<sodier[i].strenth<<" elements and force "<<sodier[i].force<<endl;
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
						if(arrived==2) return 1;
					}
					else{
						cout<<" marched to city "<<sodier[i].position<<" with ";
					}
					cout<<sodier[i].strenth<<" elements and force "<<sodier[i].force<<endl;
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
		if(tag==0) for(int i=0;i<number-1;i++){
			if(sodier[i].model==0||sodier[i].model==3){
				showtime(hour,minute);
				cout<<" red ";
				sodier[i].weapon_out();
			}
		}
		else if(tag==1) for(int i=number-1;i>=0;i--){
			if(sodier[i].model==0||sodier[i].model==3){
				showtime(hour,minute);
				cout<<" blue ";
				sodier[i].weapon_out();
			}
		}
	}
}
