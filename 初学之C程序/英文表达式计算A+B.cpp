#include<stdio.h>
#include<string.h>
int getVal(char num[]){
    int i=-1,t;
    char numbers[][15]={{"zero"},{"one"},{"two"},
            {"three"},{"four"},{"five"},
            {"six"},{"seven"},{"eight"},{"nine"}};
    for(t=0;t<=9;t++){
        if(!strcmp(num,numbers[t])){
            i=t;
            break;
        }
    }
    return i;
}
int main()
{
    char expre[200];
    int i,id,p;
    int number=0,sum=0;
    char tempstr[20]={0};
    int len;
    gets(expre),strlwr(expre),len=strlen(expre);
    for(i=0;i<len;i++){
        while(expre[i++]==' ');
        if(expre[i-1]=='+'||expre[i-1]=='='){
            sum+=number;
            number=0;
            continue;
        }
        i=i-1;
        for(p=0;expre[i]!=' ';i++,p++){
            tempstr[p]=expre[i];
        }
        tempstr[p]='\0';
        number=10*number+getVal(tempstr);
    }
    printf("%d\n",sum);
    return 0;
}
