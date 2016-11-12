#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//按主函数中的调用，实现每个子函数。
char res[30000]={0};
int count(char stence[],char pstr1[]){
	int leng1,leng2,num=0,i;
	char temp[200]={0};
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
	if(p!=NULL){
		strcpy(p,p+leng1);
	    if(leng2-leng1>=0)stence[leng2-leng1]='\0';
	}
	return stence;
}
char * insert(char stence[],char pstr1[],char pstr2[]){
	int i,leng1,leng2,leng3,leng;
	char temp1[30000]={0},temp2[200]={0},temp3[200]={0},temp[30000]={0};
	char *p;
	leng1=strlen(pstr1),leng2=strlen(stence),leng3=strlen(pstr2);
	for(i=0;i<leng2||i<leng1||i<leng3;i++){
		if(i<leng2)temp1[leng2-i-1]=stence[i];
		if(i<leng3)temp2[leng3-i-1]=pstr2[i];
		if(i<leng1)temp3[leng1-i-1]=pstr1[i];
	}
	p=strstr(temp1,temp3);
	if(p!=NULL){
		strcpy(temp,p+leng1);
	    *(p+leng1)='\0';
	    strcat(temp1,temp2);
	    strcat(temp1,temp);
	}    
	leng=strlen(temp1);
	for(i=0;i<leng;i++){
		res[i]=temp1[leng-i-1];
	}
	return res;
}
char *replace(char stence[],char pstr1[],char pstr2[]){
	int i,leng1,leng2,leng3;
	char temp[30000]={0};
	leng1=strlen(pstr1),leng2=strlen(stence),leng3=strlen(pstr2);
	strcpy(res,stence);
	for(i=0;res[i+leng1-1]!='\0';){
		strncpy(temp,&res[i],leng1);
		temp[leng1]='\0';
		if(strcmp(temp,pstr1)==0){
			leng2=strlen(res);
			strcpy(temp,&res[i+leng1]);
			temp[leng2-leng1-i]='\0';
			res[i]='\0';
			strcat(res,pstr2);
			strcat(res,temp);
			i+=leng3;
		}
		else i++;
	}
	return res;
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
