#include<iostream>
#include<stdlib.h>
#include<iterator>
#include<algorithm>
#include<string.h>
#include<list>
#include<stdio.h>
using namespace std;
list<int> l[200];
int pure(int x){
	return x;
}
void ShowList(list<int>& listTemp){
    cout << listTemp.size() << endl;
    for (list<int>::iterator it = listTemp.begin(); it != listTemp.end(); ++it){
        cout << *it << ' ';
    }
    cout << endl;
}
void deal(char a[]){
	char ch;
	int i=0,j=0;
	char temp[20]={0};
	int mid=0,mid2=0;
	while(a[i]!=' ') i++;
	strncpy(temp,a,i);
	if(strcmp(temp,"new")==0){
		mid=atoi(&a[i+1]);
		list<int> l[mid];
	}
	else if(strcmp(temp,"add")==0){
			mid=atoi(&a[i+1]);
			j=i+1;
			while(a[j]!=' ')j++;
			mid2=atoi(&a[j+1]);
			l[mid].push_back(mid2);
	}
	else if(strcmp(temp,"merge")==0){
		mid=atoi(&a[i+1]);
		j=i+1;
		while(a[j]!=' ')j++;
		mid2=atoi(&a[j+1]);
		l[mid].splice(l[mid].end(),l[mid2],l[mid2].begin(),l[mid2].end());
	}
	else if(strcmp(temp,"unique")==0){
		mid=atoi(&a[i+1]);
		l[mid].sort();
		l[mid].unique();
	}
	else if(strcmp(temp,"out")==0){
		mid=atoi(&a[i+1]);
		l[mid].sort();
		copy(l[mid].begin(),l[mid].end(),ostream_iterator<int>(cout," "));
		cout<<endl;
	}
}
int main(){
	int n;
	cin>>n;
	char instruct[20]={0};
	getchar();
	for(int i=0;i<n;i++){
		gets(instruct);
		puts(instruct);
		deal(instruct);
	}
	return 0;
}
