#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char*format(str[]){
	int length;
	length=strlen(str);
	for(i=0;str[i]!='/0';i++){
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
