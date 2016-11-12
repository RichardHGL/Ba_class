#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int parseDistance(char tinfo[500]){
    int i=0,dist=0;
    while(tinfo[i]>='9'||tinfo[i]<='0') i++;
    for(;tinfo[i]>='0'&&tinfo[i]<='9';i++){
        dist=10*dist+tinfo[i]-'0';
    }
    return dist;
}
int getCumulatedDist(int dist,char type){
    int sum=0;
    switch(type){
        case 'F' :sum+=dist*2;break;
        case 'B' :{if(dist%2) sum=dist*1.5+1;
                   else sum=dist*1.5;
        }break;
        case 'Y' :{if(dist<=500)  sum=500;
                   else sum=dist;
        }break;        
    }
    return sum;    
}
char*format(char str[]){
	int length,t,i;
	length=strlen(str);
	for(i=0;str[i]!='\0';i++){
		if(str[length-1]==' '){
			t=length-1;
			while(str[t]==' ') t--;
			str[t+1]='\0';
		}
		if(str[0]==' '&&i==0){
			while(str[i]==' ') i++;
			strcpy(str,&str[i]);
            i=0;
		}
		if(str[i]==' '){
			t=i;
			for(;str[++i]==' ';);
			if(i-t>1) strcpy(&str[t+1],&str[i]);
			i=t+1;
		}
	}
	return str;
}
int main()
{
    char travelinfo[500]={0},clas;
    long sumdist=0;
    int i,length;
    do{ 
        gets(travelinfo);
        format(travelinfo);
        length=strlen(travelinfo);
        if(length==0) continue;// ÅÅ³ý»Ø³µ 
        if(travelinfo[0]=='\0') continue;
        if(!strcmp(travelinfo,"#")) break;
        if(!strcmp(travelinfo,"0")){
            printf("%ld\n",sumdist);
            sumdist=0;
            continue;
        }
        clas=travelinfo[length-1];
        sumdist+=getCumulatedDist(parseDistance(travelinfo),clas);
    }while(1);
    return 0;    
}
