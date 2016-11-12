#include<stdio.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#define MAXSIZE 30
using namespace std;
string input = "P_A_record.txt";
vector<int> split(string str, char delta){
	vector<int> res_vec;
	size_t pos = 0, new_pos = 0;
	string temp;
	int temp2 = 0;
	while(true){
		new_pos = str.find(delta, pos);
		if(new_pos != string::npos){
			temp = str.substr(pos, new_pos - pos);
			temp2 = atoi(temp.c_str()) + 1;
			res_vec.push_back(temp2);
			pos = new_pos + 1;
		}
		else{
			new_pos = str.size();
			temp = str.substr(pos, new_pos - pos);
			temp2 = atoi(temp.c_str()) + 1;
			res_vec.push_back(temp2);
			break;
		}
	}
	return res_vec;
}

void divide_sparse_matrix(int lim_year){
	string textline;
	char output1[MAXSIZE], output2[MAXSIZE];
	sprintf(output1, "trainset_%d.txt", lim_year);
	sprintf(output2, "testset_%d.txt", lim_year);
	ifstream ins(input.c_str(), ios::binary);
	ofstream out1(output1, ios::binary);
	ofstream out2(output2, ios::binary);
	int year;
	vector<int > res;
	long long int count = 0;
	char ch;
	while(getline(ins, textline, '\n')){
		ins>>year>>ch;
		res = split(textline,' ');
		for(int i = 0; i < res.size(); i++){
			for(int j = 0; j < res.size(); j++){
				if(i != j){
					if(year <= lim_year) out1<<res[i]<<' '<<res[j]<<' '<<1<<'\n';
					else out2<<res[i]<<' '<<res[j]<<' '<<1<<'\n';
				}
			}
		}
		count++;
		if(count % 1000 == 0) printf("%lld\n", count);
	}
}
int main(){
	int i;
	scanf("%d", &i);
	divide_sparse_matrix(i);
	return 0;
} 
