#include<stdio.h>//前一种买进价换后一种卖出价 
#include<math.h>
#include<string.h>
struct table{
	char name[4];
	double buy;
	double sell;
}p[20]={{"AUD",524.19,544.68},{"CAD",550.4,572.5},{"CHF",658.62,685.06},
       {"DKK",107.93,112.27},{"EUR",805.33,837.66},{"GBP",954.38,992.69},
	   {"HKD",77.51,78.43},{"JPY",5.6842,5.9064},{"KRW",0.556,0.603},
	   {"MOP",73.36,78.64},{"NOK",94.66,98.46},{"NZD",483.02,505.41},
	   {"PHP",13.26,14.22},{"RUB",17.9,19.17},{"SGD",466.56,485.29},
	   {"THB",18.25,19.57},{"USD",600.93,608.21},{"RMB",100,100}};
int main()
{
	int i,x=20,y=20,s;
	char a[4]={0},b[4]={0};
	double result;
	scanf("%d",&s);
	scanf("%s",a);
	scanf("%s",b);
	for(i=0;i<18;i++){
		if(strcmp(a,p[i].name)==0) x=i;
		if(strcmp(b,p[i].name)==0) y=i;
		if(x!=20&&y!=20) break;
	}
    //printf("%d %d %f %f %d\n",x,y,p[x].buy,p[y].sell,s);
	if(x==y) result=s;
	else result=s*p[x].buy/p[y].sell;
	//printf("%f\n",result);
	//if((result-(int)result)<0.000001) printf("%d\n",s);
    printf("%.2f\n",result);
	return 0;
}
