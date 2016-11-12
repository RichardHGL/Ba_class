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
#define MAXSTRING 100
#define SHOW_WINDOWS 10
#define MAX_DIM 256
using namespace std;

typedef float real;
real *vec;
vector <string > new_name;
long long int num_vertices, vector_dim;
string rank[SHOW_WINDOWS];
std::vector<double> presition,recall;
typedef pair<string, string> Edge;
std::vector<Edge> train_set, test_set;
char test_file[MAXSTRING], train_file[MAXSTRING], vec_file[MAXSTRING];

/*struct Edge{
	string v1; 
	string v2;
	bool operator < (const Edge b) const{
		if(v1 < b.v1) return true;
		else if(v1 == b.v1){
			if(v2 < b.v2) return true;
		}
		return false;
	}
	bool operator == (const Edge c) const{
		if(v1 == c.v1 && v2 == c.v2) return true;
		else return false;
	}
};*/

bool judge(const Edge s1, const Edge s2){
	if(s1.first < s2.first) return true;
	else if(s1.first == s2.first){
		if(s1.second < s2.second) return true;
	}
	return false;
}

void deal(real vector[],char q_name[]){
	real rank_value[SHOW_WINDOWS] = {0};
	real result = 0;
	int base = 0;
	Edge temp;
	temp.first = q_name;
	
	for(int count = 0; count < num_vertices; count++)
	{
		if(new_name[count] == string(q_name)) 
			continue;
		temp.second = new_name[count];
		if(binary_search(train_set.begin(), train_set.end(), temp)) 
			continue;
		result = 0;
		base = count * vector_dim;
		
		for(int i = 0; i < vector_dim; i++) 
			result += vector[i] * vec[base+i];
		
		for(int k = 0; k < SHOW_WINDOWS ; k++){
			if(result > rank_value[k]){
				for(int i = SHOW_WINDOWS - 1; i > k; i--) rank[i] = rank[i-1];
				rank[k] = new_name[count];
				rank_value[k] = result;
				break;
			}
		}
	}
}

void query(char q_name[])
{
	real vector[vector_dim];
	double len=0.0;
	std::vector<string>::iterator pr = find(new_name.begin(), new_name.end(), string(q_name));
	if(pr != new_name.end()){
		int base = (pr - new_name.begin()) * vector_dim;
		for(int i = 0; i < vector_dim; i++) vector[i] = vec[base+i];
	}
	else{
		srand(time(0));
		for(int i = 0; i < vector_dim; i++) vector[i] = (rand() / (real)RAND_MAX - 0.5) / vector_dim;
		len = 0;
		for(int b = 0; b < vector_dim; b++) len += vector[b] * vector[b];
		len = sqrt(len);
		for(int b = 0; b < vector_dim; b++) vector[b] /= len;
	}
	deal(vector, q_name);
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
	
	double weight = 0.0;
	long long int count = 0;
	fp=fopen(train_file, "rb");
	if (fp == NULL) {
		printf("train file not found\n");
		exit(1);
	}
	char name_v1[MAXSTRING]={0}, name_v2[MAXSTRING]={0};
	Edge temp;
	while(count < num_edges){
		fscanf(fp, "%s %s %lf\n", name_v1, name_v2, &weight);
		temp.first = name_v1;
		temp.second = name_v2;
		train_set.push_back(temp);
		count++;
	}
	fclose(fp);
	std::sort(train_set.begin(), train_set.end(), judge);
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
	char name_v1[MAXSTRING]={0}, name_v2[MAXSTRING]={0};
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
		fscanf(fp, "%s %s %lf\n", name_v1, name_v2, &weight);
		temp.first = name_v1;
		temp.second = name_v2;
		test_set.push_back(temp);
		count++;
	}
	fclose(fp);
	
	std::sort(test_set.begin(), test_set.end(), judge);
}

void print_sort_train(){
	FILE * fp = fopen("My_sort_train.txt","wb");
	long long int temp = train_set.size();
	for(long long int i = 0; i < temp; i++){
		fprintf(fp, "%s %s\n", train_set[i].first.c_str(), train_set[i].second.c_str());
	}
	fclose(fp);
}

bool exist(string temp){
	for(int i = 0 ; i < SHOW_WINDOWS; i++){
		if(temp == rank[i]){
			return true;
		}
	}
	return false;
}

void test_query()
{
	long long int scale = test_set.size(), last_count = 0, count = 0;
	int zero = 0;
	char pre[MAXSTRING]={0}, now[MAXSTRING]={0};
	
	while(count < scale)
	{
		strcpy(now,test_set[count].first.c_str());
		if (count % 100 == 0){
			printf("Reading edges: %.3lf%%%c", count / (double)(scale + 1) * 100, 13);
			fflush(stdout);
		}
		if(count==0){
			query(now);
			zero = 0;
		}
		if(count){
			if(strcmp(pre,now)){
				presition.push_back(zero / double(10.0));
				recall.push_back(zero / double(count - last_count));
				last_count = count;
 				query(now);
				zero=0;
			}
		}
		if(exist(test_set[count].second)) zero++;
		strcpy(pre, now);
		count++;
	}
	if(count!=last_count){
		presition.push_back(zero / double(10.0));
		recall.push_back(zero / double(count - last_count));
	}
}

/*void test_get_train(){
	Edge temp2;
	char name1[MAXSTRING], name2[MAXSTRING];
	
	while(true){//²âÊÔ²éÕÒtrain_set 
		scanf("%s %s", name1, name2);
		temp2.first = name1;
		temp2.second = name2;
		std::vector<Edge >::iterator ra = find(train_set.begin(), train_set.end(), temp2);
		if(ra && ra != train_set.end()){
			printf("YES and it's %d\n", ra - train_set.begin());	
		} 
		else printf("NO\n");
		if(binary_search(train_set.begin(), train_set.end(), temp2)) printf("YES\n");
		else printf("NO\n");
	}
}*/

void evalue()
{
	char ch;
	FILE * fp=fopen(vec_file, "rb");
	int base=0;
	char name[MAXSTRING];
	fscanf(fp, "%lld %lld", &num_vertices, &vector_dim);
	printf("%lld %lld\n", num_vertices, vector_dim);	
	vec = (real *)malloc((long long )num_vertices * vector_dim * sizeof(real));
	printf("Begin inputing embedding file.\n"); 
	for (int a = 0; a < num_vertices; a++)
	{
		fscanf(fp, "%s%c", name, &ch);
		new_name.push_back(string(name));
		base = a * vector_dim;
		for (int b = 0; b < vector_dim; b++) fread(&vec[base+b], sizeof(real), 1, fp);
	}
	fclose(fp);
	printf("Begin getting test file.\n");
	Get_test_set();
	printf("Begin getting train file.\n");
	Get_train_set();
	printf("Begin dealing evaluing.\n");
	test_query();
	
	printf("AVG presition=%lf\n", accumulate(presition.begin(), presition.end(),0.00) / presition.size());
	printf("AVG recall=%lf\n", accumulate(recall.begin(), recall.end(), 0.00) / presition.size());
	free(vec);
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
	if (argc == 1){
		printf("Evalue the embedding on the 1st/2nd/all file of vector trained.\n");
		printf("Options:\n");
		printf("\t-train <file>\n");
		printf("\t\tThe trainset file\n");
		printf("\t-test <file>\n");
		printf("\t\tThe testset file\n");
		printf("\t-embedding <file>\n");
		printf("\t\tThe embedding file\n");
		return 0; 
	}
	if ((i = ArgPos((char *)"-train", argc, argv)) > 0) strcpy(train_file, argv[i + 1]);
	if ((i = ArgPos((char *)"-test", argc, argv)) > 0) strcpy(test_file, argv[i + 1]);
	if ((i = ArgPos((char *)"-embedding", argc, argv)) > 0) strcpy(vec_file, argv[i + 1]);
	evalue();
	return 0;
}
