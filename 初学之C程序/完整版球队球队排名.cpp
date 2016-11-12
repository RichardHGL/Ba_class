#include<stdio.h>
#include<string.h>
#include<math.h>
struct team{
	char name[51];
	int score;
	int goal;
	int ball;
}b[21],gua;
int main()
{
	int n,m,temp1,temp2,i,j,k,t,t1,t2,len;
	char name1[51]={0},name2[51]={0};
	char a[120]={0};
	for(i=0;i<20;i++) b[i].goal=0,b[i].score=0,b[i].ball=0;
	scanf("%d",&n);getchar();
	for(i=0;i<n;i++) gets(b[i].name);
	scanf("%d",&m);getchar();
	for(i=0;i<m;i++){
		gets(a);
		temp1=0,temp2=0;
		len=strlen(a);
		for(j=0;j<len;j++) if(a[j]==':') break;
		for(t=j-1;'0'<=a[t]&&a[t]<='9';t--);
		strcpy(name1,a);
		name1[t]='\0',t++;
		for(;t<j;t++) temp1=10*temp1+a[t]-'0';
		for(t1=0;t1<n;t1++) if(strcmp(name1,b[t1].name)==0) break;
		for(t=j+1;'0'<=a[t]&&a[t]<='9';t++){
			temp2=10*temp2+a[t]-'0';
		} 
		strcpy(name2,&a[t+1]);
		for(t2=0;t2<n;t2++) if(strcmp(name2,b[t2].name)==0) break;
		b[t2].goal+=temp2-temp1;b[t1].goal+=temp1-temp2;
		b[t2].ball+=temp2,b[t1].ball+=temp1;
		if(temp1>temp2) b[t1].score+=3;
		else if(temp2>temp1) b[t2].score+=3;
		else b[t1].score++,b[t2].score++;
	}
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(b[j].score>b[k].score) k=j;
			if(b[j].score==b[k].score&&b[j].goal>b[k].goal) k=j;
			if(b[j].score==b[k].score&&b[j].goal==b[k].goal&&b[j].ball>b[k].ball) k=j;
			if(b[j].score==b[k].score&&b[j].goal==b[k].goal&&b[j].ball==b[k].ball){
				for(t1=0;t1<50;t1++) if((b[k].name[t1]<=90&&b[k].name[t1]>=65)||(b[k].name[t1]<=122&&b[k].name[t1]>=97)) break;
				for(t2=0;t2<50;t2++) if((b[j].name[t2]<=90&&b[j].name[t2]>=65)||(b[j].name[t2]<=122&&b[j].name[t2]>=97)) break;
				if(strcmp(&b[j].name[t2],&b[k].name[t1])<0) k=j;
			} 
		}
		if(k!=i){
			gua=b[i],b[i]=b[k],b[k]=gua;
		}
	}
	//for(i=0;i<13;i++) printf("%s %d %d %d\n",b[i].name,b[i].score,b[i].goal,b[i].ball);
	for(i=0;i<n;i++) printf("%s\n",b[i].name);
	return 0;
}
