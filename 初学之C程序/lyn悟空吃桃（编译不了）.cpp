#include<stdio.h>
#include<math.h>
int solutions;
typedef enum peach_colour{no,red,orange,yellow,green,cyan,
blue,purple,white,black,pink} peach;
int peach_result[11]={0};
int peach_state[11]={1};
char peach_name[11][7]={"no","red","orange","yellow","green","cyan",
"blue","purple","white","black","pink"};
int alarm(int index,peach p){
    int flag=0;
    if(index!=1&&fabs(peach_result[index-1]-p)==1)flag=1;
    return flag;
}
int blind(int index,peach p){
    int flag=0;
    flag=(peach_result[index-1]==red)&&(p==green);
    flag=flag||((peach_result[index-1]==green)&&(p==red));
    flag=flag||((peach_result[index-1]==blue)&&(p==yellow));
    flag=flag||((peach_result[index-1]==yellow)&&(p==blue));
    return flag;
}
int suitable(int m)
{
    int i,flag=1;
    for(i=1;i<=m;i++){
        if(peach_state[peach_result[i]]==2){
            flag=0;
            break;
        }
    }
    return flag;
}
void peachs(int n,int m,int index){
    peach p;
    int i;
    for(p=red;p<=n;p++){
        if(peach_state[p]||alarm(index,p))continue;
        peach_result[index]=p;   
        peach_state[p]=(blind(index,p))?2:1;   //扔了也相当于拿出来吃了，peach_state不能等于0.记为2来区分。
        if(index==m){
            if(suitable(m)){
                for(i=1;i<=m;i++){
                    printf("%s ",peach_name[peach_result[i]]);
                    solutions++;
                }
                printf("\n");
            }
        }
        else peachs(n,m,index+1);
        peach_state[p]=0;
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    peachs(n,m,1);
    if(solutions==0)printf("-1");
    return 0;
} 
