#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,y,m,x;
    char c;
    scanf("%d %d",&n,&m);
    for(y=0;y<=n-1;y++){
        for(x=0;x<=m-1;x++){
            c=65+abs(x-y); 
            printf("%c",c);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}        
