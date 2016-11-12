#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<time.h>
#include<numeric>
#include<utility>
#include<string>
#define MAXSTRING 500
#define SHOW_WINDOWS 10
using namespace std;

int rank[SHOW_WINDOWS];
std::vector<double> presition,recall;
typedef pair<int, int> Edge;
std::vector<Edge> train_set, test_set;
char test_file[MAXSTRING] = "trainset_2000.txt", train_file[MAXSTRING] = "testset_2000.txt";
char output_file[MAXSTRING] = "result_2000.txt";

struct PE_relation{
	int name;
	vector<int> friends;
	vector<int> times;
};
vector<PE_relation> Mytr;

bool judge(const Edge s1, const Edge s2){
	if(s1.first < s2.first) return true;
	else if(s1.first == s2.first){
		if(s1.second < s2.second) return true;
	}
	return false;
}

bool compare(const PE_relation p1, const PE_relation p2){
	if(p1.name < p2.name) return true;
	return false;
}

int pass_find(int name){
	for(int i = 0; i < Mytr.size(); i++){
		if(Mytr[i].name == name) return i;
	}
	return -1;
}

int binary_find(int low, int high, int name){
	if(low == high){
		if(Mytr[low].name== name) return low;
		else return -1;
	}
	int res;
	int mid = (low + high)/2;
	if(Mytr[mid].name == name){
		return mid;
	}
	else if(Mytr[mid].name < name){
		return binary_find(mid + 1, high, name);
	} 
	else{
		return binary_find(low, mid, name);
	}
}

void friends_insert(int pos, int name){
	for(int i = 0; i < Mytr[pos].friends.size(); i++){
		if(Mytr[pos].friends[i] == name){
			Mytr[pos].times[i]++;
			return ;
		}
	}
	Mytr[pos].friends.push_back(name);
	Mytr[pos].times.push_back(1);
}

void Get_train_set()
{
	FILE * fp=fopen(train_file, "rb");
	char str[2 * MAXSTRING + 10000] = {0};
	long long int num_edges = 0;
	
	if (fp == NULL) {
		printf("train file not found\n");
		exit(1);
	}
	while (fgets(str, sizeof(str), fp)) num_edges++;
	fclose(fp);
	
	long long int count = 0;
	fp=fopen(train_file, "rb");
	if (fp == NULL) {
		printf("train file not found\n");
		exit(1);
	}
	Edge temp;
	int z1= 0 , z2 = 0;
	while(count < num_edges){
		if (count % 1000 == 0){
			printf("Reading edges: %.3lf%%%c", count / (double)(num_edges + 1) * 100, 13);
			fflush(stdout);
		}
		fscanf(fp, "%d %d\n", &temp.first, &temp.second);//放入训练的边集 
		train_set.push_back(temp);
		count++;
		
		z1 = pass_find(temp.first);//在关系集内查找该边两节点的位置 
		z2 = pass_find(temp.second);
		if(z1 == -1){
			PE_relation temp1;
			temp1.name = temp.first;
			temp1.friends.push_back(temp.second);
			temp1.times.push_back(1);
			Mytr.push_back(temp1);
		}
		else friends_insert(z1, temp.second);
		if(z2 == -1){
			PE_relation temp1;
			temp1.name = temp.second;
			temp1.friends.push_back(temp.first);
			temp1.times.push_back(1);
			Mytr.push_back(temp1);
		}
		else friends_insert(z2, temp.first);
	}
	fclose(fp);
	std::sort(train_set.begin(), train_set.end(), judge);
	std::sort(Mytr.begin(), Mytr.end(), compare);
}

void Get_test_set()
{
	FILE * fp=fopen(test_file, "rb");
	if (fp == NULL) {
		printf("test file not found\n");
		exit(1);
	}
	char str[2 * MAXSTRING + 10000] = {0};
	long long int num_edges = 0;
	
	while (fgets(str, sizeof(str), fp)) num_edges++;
	fclose(fp);
	
	double weight = 0.0;
	long long int count = 0;
	Edge temp;
	fp=fopen(test_file, "rb");
	if (fp == NULL) {
		printf("test file not found\n");
		exit(1);
	}
	while(count < num_edges){
		if (count % 100 == 0){
			printf("Reading edges: %.3lf%%%c", count / (double)(num_edges + 1) * 100, 13);
			fflush(stdout);
		}
		fscanf(fp, "%d %d\n", &temp.first, &temp.second);
		test_set.push_back(temp);
		count++;
	}
	fclose(fp);
	
	std::sort(test_set.begin(), test_set.end(), judge);
}

int co_friend_number(int pos1, int pos2){
	int res = 0;
	for(int i = 0; i < Mytr[pos1].friends.size(); i++){
		for(int j = 0; j < Mytr[pos2].friends.size(); j++){
			if(Mytr[pos1].friends[i] == Mytr[pos2].friends[j])
				res += Mytr[pos1].times[i] + Mytr[pos2].times[j] - 1;
		}
	}
	return res;
}

void deal(int name){
	int rank_value[SHOW_WINDOWS] = {0};
	int rank_key = 0;
	int pos = binary_find(0, Mytr.size(), name);
	for(int count = 0; count < Mytr.size(); count++){
		if(Mytr[count].name == name) continue;
		rank_key = co_friend_number(pos, count);
		for(int k = 0; k < SHOW_WINDOWS ; k++){
			if(rank_key > rank_value[k]){
				for(int i = SHOW_WINDOWS - 1; i > k; i--) rank[i] = rank[i-1];
				rank[k] = Mytr[count].name;
				rank_value[k] = rank_key;
				break;
			}
		}
	}
}

void write_relation(){
	FILE * fp = fopen("relation_ssss.txt", "wb");
	long long int length = Mytr.size();
	int length1 =0;
	for(int i = 0; i < length; i++){
		fprintf(fp, "%d\n",Mytr[i].name);
		length1 = Mytr[i].friends.size();
		for(int j = 0; j < length1; j++){
			if(j < length1 - 1) fprintf(fp, "%d ", Mytr[i].friends[j]);
			else fprintf(fp, "%d\n", Mytr[i].friends[j]);
		}
		for(int j = 0; j < length1; j++){
			if(j < length1 - 1) fprintf(fp, "%d ", Mytr[i].times[j]);
			else fprintf(fp, "%d\n", Mytr[i].times[j]);
		}
	}
	fclose(fp);
} 

bool exist(int temp){
	for(int i = 0 ; i < SHOW_WINDOWS; i++){
		if(temp == rank[i]){
			return true;
		}
	}
	return false;
}

void evalue(){
	int pre = 0, now = 0, last_count = 0, count = 0, zero = 0;
	printf("Begin reading train_edge_file.\n");
	Get_train_set();
	//write_relation();
	//printf("%d\n", Mytr.size());
	printf("Begin reading test_edge_file.\n");
	Get_test_set();
	int scale = test_set.size();
	printf("Begin evalue.\n");
	for(int count = 0; count < scale; count++){
		if(binary_find(0, Mytr.size(), test_set[count].first) == -1) continue;
		if(binary_find(0, Mytr.size(), test_set[count].second) == -1) continue;
		now = test_set[count].first;
		if (count % 1000 == 0){
			printf("Evalue: %.3lf%%%c", count / (double)(scale + 1) * 100, 13);
			fflush(stdout);
		}
		if(count==0){
			deal(now);
			zero = 0;
		}
		if(count){
			if(pre != now){
				presition.push_back(zero / double(SHOW_WINDOWS));
				recall.push_back(zero / double(count - last_count));
				last_count = count;
 				deal(now);
				zero=0;
			}
		}
		if(exist(test_set[count].second)) zero++;
		pre = now;
		count++;
	}
	if(count!=last_count){
		presition.push_back(zero / double(SHOW_WINDOWS));
		recall.push_back(zero / double(count - last_count));
	}
	FILE * fp = fopen(output_file, "wb");
	fprintf(fp, "AVG presition=%lf\n", accumulate(presition.begin(), presition.end(),0.00) / presition.size());
	fprintf(fp, "AVG recall=%lf\n", accumulate(recall.begin(), recall.end(), 0.00) / recall.size());
	fclose(fp);
}

int ArgPos(char *str, int argc, char **argv) {
	int a;
	for (a = 1; a < argc; a++) if (!strcmp(str, argv[a])) {
		if (a == argc - 1) {
			printf("Argument missing for %s\n", str);
			exit(1);
		}
		return a;
	}
	return -1;
}

int main(int argc, char **argv)
{
	int i;
	if(argc == 1){
		printf("Use default option:\n");
		printf("trainfile	--- trainset_2000.txt.\n");
		printf("testfile	--- testset_2000.txt.\n");
		printf("outputfile	--- result_2000.txt.\n");
		printf("------------------------------------\n");
	}
	if ((i = ArgPos((char *)"-train", argc, argv)) > 0) strcpy(train_file, argv[i + 1]);
	if ((i = ArgPos((char *)"-test", argc, argv)) > 0) strcpy(test_file, argv[i + 1]);
	if ((i = ArgPos((char *)"-output", argc, argv)) > 0) strcpy(output_file, argv[i + 1]);
	evalue();
	return 0;
}
