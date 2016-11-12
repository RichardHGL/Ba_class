#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char * format2(char str[]){ 
      int len, i, p,temp; 
      len=strlen(str); 
	  for(p=i=0; i<len; i++){ 
	      if(str[i]==' '){ 
          temp=i; 
          while(++i<len && str[i]==' '); 
          if(temp>0 && i!=len){ 
		  str[p++]=' ';              
		  } 
          i--; 
         }else {
		      str[p++]=str[i]; 
         } 
	  } 
    str[p]='\0'; 
	return str; 
}
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
int main()
{
    char travelinfo[500]={0},clas;
    long sumdist=0;
    int i,length;
    do{ 
        gets(travelinfo);
        //puts(travelinfo); 
        format2(travelinfo);
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
