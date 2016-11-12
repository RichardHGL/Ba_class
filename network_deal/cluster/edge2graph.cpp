#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define MAXSTRING 10000
using namespace std;
struct vertex{
	int number;
	vector<int> foe;
	vector<double> weight;
};
vector<int> ver_n;//vertices
vector<vertex > List;
char test_file[MAXSTRING], output_file[MAXSTRING], rclass_file[MAXSTRING];
long long int num_edges = 0;

void get_ver(){
	FILE * fp = fopen(test_file, "rb");
	if (fp == NULL) {
		printf("test file not found\n");
		exit(1);
	}
	char str[2 * MAXSTRING + 10000] = {0};
	
	while (fgets(str, sizeof(str), fp)) num_edges++;
	fclose(fp);
	
	long long int count = 0;
	double weight = 0.0;
	int first = 0, second = 0;
	
	fp = fopen(test_file, "rb");
	while(count < num_edges){
		fscanf(fp, "%d %d %lf\n", &first, &second, &weight);
		if (count % 1000 == 0){
			printf("Reading edges: %.3lf%%%c", count / (double)(num_edges + 1) * 100, 13);
			fflush(stdout);
		}
		if(find(ver_n.begin(), ver_n.end(), first) == ver_n.end()) ver_n.push_back(first);
		if(find(ver_n.begin(), ver_n.end(), second) == ver_n.end()) ver_n.push_back(second);
		count++;
	}
	fclose(fp);
	sort(ver_n.begin(),ver_n.end());
}

int binary_find(int ver, long long int low, long long int high){
	if(low == high){
		if(ver_n[low]== ver) return low + 1;
		else return -1;
	}
	int res;
	long long int mid = (low + high)/2;
	if(ver_n[mid] == ver){
		res = mid + 1;
	} 
	else if(ver_n[mid] < ver){
		res = binary_find(ver, mid + 1, high);
	}
	else{
		res = binary_find(ver, low, mid);
	}
	return res;
}

void get_foe(){//得到节点个数及节点的敌人 
	FILE * fp=fopen(test_file, "rb");
	
	long long int count = 0;
	int last = -1;
	double weight = 0.0;
	int first = 0, second = 0;
	vertex temp;
	while(count < num_edges){
		fscanf(fp, "%d %d %lf\n", &first, &second, &weight);
		if (count % 1000 == 0){
			printf("Reading edges: %.3lf%%%c", count / (double)(num_edges + 1) * 100, 13);
			fflush(stdout);
		}
		if(last == -1){
			temp.number = binary_find(first, 0, ver_n.size() - 1);
		}
		else if(last != first){
			List.push_back(temp);
			vector<int>().swap(temp.foe);
			vector<double>().swap(temp.weight);
			temp.number = binary_find(first, 0, ver_n.size() - 1);
		}
		temp.foe.push_back( binary_find(second, 0, ver_n.size() - 1) );
		temp.weight.push_back(weight);
		last = first;
		count++;
	}
	List.push_back(temp);
	fclose(fp);
} 

void out_put(){
	FILE * fp = fopen(output_file,"wb");
	FILE * fp1 = fopen(rclass_file,"wb");
	int length = 0;
	int it = 0;
	fprintf(fp, "%d %lld\n", ver_n.size(), num_edges);
	for(int i = 0, k = 1; i < List.size(); i++, k++){
		while(k < List[i].number){
			fprintf(fp, "\n");
			fprintf(fp1, "%d\n", ver_n[k-1]);
			k++;
		}
		fprintf(fp1, "%d\n", ver_n[k-1]);
		if (i % 1000 == 0){
			printf("Reading edges: %.3lf%%%c", i / (double)(List.size() + 1) * 100, 13);
			fflush(stdout);
		}
		length = List[i].foe.size();
		for(int j = 0; j < length; j++){
			if(j < length - 1) fprintf(fp, "%d %lf ", List[i].foe[j], List[i].weight[j]);
			else fprintf(fp, "%d %lf\n", List[i].foe[j], List[i].weight[j]);
		}
	}
	fclose(fp);
	fclose(fp1);
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

int main(int argc, char **argv){
	int i;
	if ((i = ArgPos((char *)"-source", argc, argv)) > 0) strcpy(test_file, argv[i + 1]);
	if ((i = ArgPos((char *)"-output", argc, argv)) > 0) strcpy(output_file, argv[i + 1]);
	if ((i = ArgPos((char *)"-rclass", argc, argv)) > 0) strcpy(rclass_file, argv[i + 1]);
	get_ver();
	get_foe();
	out_put();
	return 0;
}
