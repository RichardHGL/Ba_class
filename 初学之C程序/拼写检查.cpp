#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int N,j,i,p,m,k1,k2;
    char check[25]={0},std[100][25]={0};
    int sim[100]={0},len[100]={0};
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
            for(j=0;std[i][j]!='\0';j++){
                if(check[j]==std[i][j]) sim[i]++;
            }
        }
        else if(fabs(len[i]-leng)>1) {
                 sim[i]=0;
        } 
        else {
        	for(j=0;std[i][j]!='\0';j++){
            if(check[j]==std[i][j]) sim[i]++;
            else if(!strcmp(&check[j],&std[i][j+1])||!strcmp(&check[j+1],&std[i][j])){
            	sim[i]=leng-1;
            	break;
                   }
            }
        }
    }
    p=0;
    m=sim[0];
    for(i=0;i<N;i++){
        if(fabs(sim[i]-leng)>1) continue;
        k1=fabs(len[i]-leng);
        k2=fabs(len[p]-leng);
        if(sim[i]==leng&&len[i]==leng){
            puts(std[i]);
            return 0;
        }
        if(sim[i]==leng-1&&m!=leng-1){
            m=leng-1;
            p=i;
        }
    }
    if(m==leng-1) puts(std[p]);
    else printf("NOANSWER");
    return 0;    
}
