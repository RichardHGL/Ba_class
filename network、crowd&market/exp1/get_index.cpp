#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iostream> 
#include<string>
#include<string.h>
#define MAXSTRING 10000
using namespace std;
string author_file = "AMiner-Author.txt";
string output = "author_index.txt";
int main(){
	string textline;
	ifstream in(author_file.c_str(), ios::in);
	ofstream out(output.c_str(), ios::binary);
	while(getline(in, textline, '\n')){
		if(textline.size()<4) continue;
		if(textline.find("#n") != string::npos){
			out<<textline.substr(3, textline.size() - 3)<<'\n';
		}
	}
}
