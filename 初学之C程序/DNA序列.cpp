#include<stdio.h>
int main()
{
    int N,i,j,a,c,g,t;
    char p[10][100]={0},q[100]={0};
    scanf("%d",&N);
    for(i=0;i<=N-1;i++){
        for(j=0;;){
            scanf("%s",&p[i]);
            break;
        }
    }
    for(j=0,i=0;p[i][j]!=0;j++){
    	a=0;c=0;g=0;t=0;
        for(i=0;i<=N-1;i++){
            if(p[i][j]=='A') a++;
            else if(p[i][j]=='C') c++;
            else if(p[i][j]=='G') g++;
            else if(p[i][j]=='T') t++;
        }
        if((a>=c)&&(a>=g)&&(a>=t)) q[j]='A';
        else if((c>a)&&(c>=g)&&(c>=t)) q[j]='C';
        else if((g>a)&&(g>c)&&(g>=t)) q[j]='G';
        else if((t>a)&&(t>c)&&(t>g)) q[j]='T';
        i=0;
    }
    for(j=0,i=0;q[j]!=0;j++){
        printf("%c",q[j]);
    }
    printf("\n");    
    return 0;
}
