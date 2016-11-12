#include<stdio.h>
int main()
{
    int fail=0,win=0,val,n,i;
    double is,b,c,d;
    long a;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        val=b*0.2+c*0.1+d*0.7+0.5;
        if(val>=90) win++;
        if(val<60) fail++;
        printf("%d %d\n",a,val);
    }
    printf("%d\n",win);
    printf("%d\n",fail);
    return 0;
}

