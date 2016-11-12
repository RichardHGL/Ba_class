#include<stdio.h>
#include<string.h>
char a[200]={'0'}, b[200]={'0'};
    int len1,len2,len3,len4;
int max(int x,int y){
    int z=x;
    if(x<y) z=y;
    return z;
}
int min(int x,int y){
    int z=x;
    if(y<x) z=y;
    return z;
}
char plus(int x){
    char c[200]={'0'};
    int t=0,i;
    for(i=1;i<=len3;i++){
        for(;i<=len4;i++){
            c[len3-i]=a[len1-i]+b[len2-i]-'0'+t;
            if(c[len3-i]>'9') {
                t=1;
                c[len3-i]-=10;
            }
            else t=0;
        }
        if(x==2) break;
        if(x==0) c[len3-i]=a[len1-i]+t;
        if(x==1) c[len3-i]=b[len2-i]+t;
        if(c[len3-i]>'9') {
                t=1;
                c[len3-i]-=10;
        }
        else t=0;
    }
    if(c[0]!='0') for(i=0;i<len3;i++) printf("%c",c[i]);
    else for(i=1;i<len3;i++) printf("%c",c[i]);
    printf("\n");
    return c[0];
}
int main()
{
    scanf("%s",&a[1]); 
    scanf("%s",&b[1]);
    len1=strlen(a),len2=strlen(b);
    len3=max(len1,len2);
    len4=min(len1,len2);
    if(len1<len2){
        plus(1);    
    }
    else if(len1>len2){
        plus(0);
    }
    else if(len1==len2){
        plus(2);
    }
    return 0;
}
