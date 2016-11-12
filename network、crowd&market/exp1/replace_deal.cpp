#include<stdio.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#define MAXSTRING 2000
using namespace std;
vector<string> author;
string file_name = "AMiner-Paper.txt";
string output = "P_A_record.txt";
string index_file = "author_index.txt";

void get_index(){
	ifstream ind(index_file.c_str(), ios::binary);
	string text;
	while(getline(ind, text, '\n')){
		author.push_back(text);
	}
	std::sort(author.begin(), author.end());
}

int binary_search(int low, int high, string s){
	if(low == high){
		if(author[low] == s) return low;
		else return -1;
	}
	int mid = (low + high) / 2;
	if(author[mid] == s) return mid;
	else if(author[mid] > s) return binary_search(low, mid, s);
	else return binary_search(mid + 1, high, s);
}

vector<int> split(string str, char delta){
	vector<int> res_vec;
	size_t pos = 0, new_pos = 0;
	string temp;
	int temp2 = 0;
	while(true){
		new_pos = str.find(delta, pos);
		if(new_pos != string::npos){
			temp = str.substr(pos, new_pos - pos);
			temp2 = binary_search(0, author.size() - 1, temp);
			if(temp2 != -1) res_vec.push_back(temp2);
			pos = new_pos + 1;
		}
		else{
			new_pos = str.size();
			temp = str.substr(pos, new_pos - pos);
			temp2 = binary_search(0, author.size() - 1, temp);
			if(temp2 != -1) res_vec.push_back(temp2);
			break;
		}
	}
	return res_vec;
}

int main(){
	get_index();
	ifstream ins(file_name.c_str(), ios::in);
	ofstream outs(output.c_str(), ios::binary);
	string textline;
	vector<int> temp;
	long long int record = 0;
	bool flag = false;
	while(getline(ins, textline, '\n')){
		if(textline.size() > 500 ) continue;
		if(textline.find("#@") != string::npos){
			if(textline.size() < 5 || textline.find(';') == string::npos) {
				flag = true;
				continue;
			}
			temp = split(textline.substr(3, textline.size() - 3), ';');
			if(temp.size() < 2){
				flag = true;
				continue;
			}
			for(int i = 0; i < temp.size(); i++){
				if(i == 0) outs<<temp[i];
				else outs<<' '<<temp[i];
			}
			outs<<'\n';
			record++;
			if(record % 1000 == 0) printf("%lld\n", record);
		}
		if(textline.find("#t") != string::npos){
			if(flag){
				flag = false;
				continue;
			}
			outs <<  textline.substr(3, textline.size() - 3)<< '\n';
		}
	}
	return 0;
}
