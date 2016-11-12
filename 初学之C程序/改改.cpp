#include<stdio.h>
#include<string.h>
#include<math.h>
int sim[100]={0};
int leng,i;
int func1(char x[],char y[]){
	int j;
	for(j=0;x[j]!='\0'&&sim[i]<leng;j++){
        if(y[j]==x[j]) sim[i]++;
    }
    return sim[i];
}
int func2(char x[],char y[]){
	int j,t=0;
	for(j=0;x[j]!='\0'&&sim[i]<leng;j++){
        if(y[j]==x[j]) sim[i]++;
        else {
        t=1;
		break;
	    }
    }
    if(t){
    	if(!strcmp(&y[j+1],&x[j])) sim[i]=leng-1;
    }
    return sim[i];
}
int main()
{
    int N,j,p,m;
    char check[25]={0},std[100][25]={0};
    int len[100]={0};
    int leng;
    gets(check);
    leng=strlen(check);
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++){
        sim[i]=0;
        gets(std[i]);
        len[i]=strlen(std[i]);
        if(len[i]==leng){
            func1(std[i],check);
            if(fabs(sim[i]-leng)>1){
            	sim[i]=22;
            	continue;
            }
        }
        else if(fabs(len[i]-leng)>1) {
                 sim[i]=22;
                 continue;
        }
        else {
             if(len[i]>leng){
             	 sim[i]=func2(check,std[i]);
             }
             if(len[i]<leng){
             	 sim[i]=func2(std[i],check);
             }
        }
        printf("%d\n",sim[i]);
    }
    p=0;
    m=sim[0];
    for(i=0;i<N;i++){
    	if(sim[i]==leng){
        	puts(std[i]);
        	return 0;
        }
        if(fabs(sim[i]-leng)>1) continue;
        if(sim[i]==leng-1&&m!=leng-1){
            m=leng-1;
            p=i;
        }
    }
    if(m==leng-1) puts(std[p]);
    else printf("NOANSWER");
    return 0;    
}
