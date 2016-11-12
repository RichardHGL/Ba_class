#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<vector>
using std::vector;
#define MAXSTRING 100
#define BLOCK 5
#define PIECE 0.2000
struct pair{
	char first[MAXSTRING];
	char second[MAXSTRING];
};

int main(){
	char filename[]="source.txt"; 
	FILE *fp,*fp1,*fp2;
	char train_name[][20]={"trainset1.txt","trainset2.txt","trainset3.txt","trainset4.txt","trainset5.txt"};
	char test_name[][20]={"testset1.txt","testset2.txt","testset3.txt","testset4.txt","testset5.txt"};
	char name_v1[10]={0},name_v2[10]={0};
	int count=0,weight;
	int a1=0,a2=0;
	double sample;
	vector<pair > v[BLOCK];
	fp=fopen(filename,"rb");
		
	srand(time(0));
	while(!feof(fp))
	{
		pair temp;
		fscanf(fp, "%s %s\n", temp.first, temp.second);
		count++;
		sample=rand()/double(RAND_MAX);
		for(int i=0;i<BLOCK;i++){
			if(sample>=PIECE*i&&sample<=PIECE*(i+1)) {
				v[i].push_back(temp);
				break;
			}
		}
	}
	fclose(fp);
	printf("count=%d\n",count);
	
	for(int i = 0; i < BLOCK; i++){
		fp1=fopen(train_name[i],"wb");
		fp2=fopen(test_name[i],"wb");
		for(int j = 0; j < BLOCK; j++)
		{
			if(j==i){
				for(int k = 0; k < v[j].size(); k++)
				{
					fprintf(fp1,"%s %s %lf\n",v[j][k].first,v[j][k].second,1.00);
				}
			} 
			else{
				for(int k = 0; k < v[j].size(); k++)
				{
					fprintf(fp2,"%s %s %lf\n",v[j][k].first,v[j][k].second,1.00);
				}
			} 
		}
		fclose(fp1);
		fclose(fp2);
	}

	return 0;
}
