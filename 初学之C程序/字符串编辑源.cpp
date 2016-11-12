#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//按主函数中的调用，实现每个子函数。
int count(char stence[],char pstr1[]){
	int leng1,leng2,num=0,i;
	char temp[100]={0};
	leng1=strlen(pstr1),leng2=strlen(stence);
	for(i=0;i<=leng2-leng1;){
		strncpy(temp,&stence[i],leng1);
		if(strcmp(pstr1,temp)==0) num++,i+=leng1;
		else i++;
	}
	return num;
}
char *del(char stence[],char pstr1[]){
	char *p;
	int leng1,leng2;
	leng1=strlen(pstr1),leng2=strlen(stence);
	p=strstr(stence,pstr1);
	strcpy(p,p+leng1);
	stence[leng2-leng1]='\0';
	return stence;
}
char * insert(char stence[],char pstr1[],char pstr2[]){
	int i,leng1,leng2,leng3,leng;
	char temp1[300]={0},temp2[100]={0},temp3[100]={0},temp[200]={0},res[300]={0};
	char *p;
	leng1=strlen(pstr1),leng2=strlen(stence),leng3=strlen(pstr2);
	for(i=0;i<leng2;i++){
		temp1[leng2-i-1]=stence[i];
		if(i<leng3)temp2[leng3-i-1]=pstr2[i];
		if(i<leng1)temp3[leng1-i-1]=pstr1[i];
	}
	puts(temp1),puts(temp2),puts(temp3);
	p=strstr(temp1,temp3);
	strcpy(temp,p+leng1);
	*(p+1)='\0';
	puts(temp),puts(stence);
	strcat(temp1,temp2);
	puts(temp1);
	strcat(temp1,temp);
	puts(temp1);
	puts(stence);
	leng=strlen(temp1);
	for(i=0;i<leng;i++){
		res[i]=temp1[leng-i-1];
	}
	puts(res);
	strcpy(stence,res);
	stence[leng]='\0';
	puts(stence);
	return stence;
}
char *replace(char stence[],char pstr1[],char pstr2[]){
	int i,leng1,leng2,leng3;
	char temp[100]={0};
	leng1=strlen(pstr1),leng2=strlen(stence),leng3=strlen(pstr2);
	for(i=0;stence[i+leng1]!='\0';){
		strncpy(temp,&stence[i],leng1);
		temp[leng1]='\0';
		if(strcmp(temp,pstr1)==0){
			strcpy(temp,&stence[i+leng1]);
			temp[leng2-leng1-i]='\0';
			stence[i]='\0';
			strcat(stence,pstr2);
			strcat(stence,temp);
			i+=leng3;
		}
		else i++;
	}
	return stence;
}
int main(void) {
    char stence[200], cmd[100], * pstr1, * pstr2;
    int i=3;
    gets(stence),gets(cmd);
    pstr1=cmd+2;
    while(1){
        if(cmd[i] == ' '){
            cmd[i]='\0', pstr2=cmd+i+1;
            break;
        }else if(cmd[i] == '\0'){
            pstr2=NULL;
            break;
        }
        i++;
    }
    switch(cmd[0]){
    case 'C': printf("%d\n", count(stence, pstr1));break;
    case 'D': printf("%s", del(stence, pstr1)); break;
    case 'I': printf("%s\n", insert(stence, pstr1, pstr2));break;
    case 'R': printf("%s\n", replace(stence, pstr1, pstr2));
    }
    return 0;
}
