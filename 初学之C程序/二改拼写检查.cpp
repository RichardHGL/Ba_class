#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int N,j,i,p,m;
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
            for(j=0;std[i][j]!='\0'&&sim[i]<leng;j++){
                if(check[j]==std[i][j]) sim[i]++;
            }
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
        	for(j=0;std[i][j]!='\0'&&check[j]!='\0';j++){
                if(check[j]==std[i][j]) {
                sim[i]++;
                }
                else {
                	 if(len[i]>leng){
                	 	for(;std[i][j+1]!='\0';j++){
                	 		if(check[j]==std[i][j+1]) sim[i]++;
                	 	}
                	 }
                	 if(len[i]<leng){
                	 	for(;std[i][j]!='\0';j++){
                	 		if(check[j-1]==std[i][j]) sim[i]++;
                	 	}
                	 }
				     if(len[i]>leng&&sim[i]==leng-1) {
				     sim[i]=22;
				     }
				     break;
					 if(sim[i]==leng) {
					 sim[i]=leng-1;
					 printf("*");
				     }
			    }
				if(len[i]>leng&&sim[i]==leng) {
				     sim[i]=leng-1;
				     }		
			}
        }
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

