#include<stdio.h>
#include<string.h>
char tabe(char x[],int k){
	int num=0,y,i,len=4;
	char b[4]={0};
	for(i=0;i<k&&x[i]!='\0';i++){
		if(x[i]>='0'&&x[i]<='9') {
		num=num*16+x[i]-48;
		//printf("%d\n",x[i]-48);
		}
		else {
		num=num*16+x[i]-55;
		//printf("%d\n",x[i]-55);
		}
	}
	for(y=num,i=4;i>0;i--){
		b[i-1]=y%8+48;
		y=y/8;
		//printf("%d %d\n",i-1,b[i-1]);
	}
	if(b[0]=='0'&&b[1]!='0'){
	    for(i=0;i<3;i++){
		    b[i]=b[i+1];
	    }
	    len=3;
	    //printf("&");
    }
	else if(b[0]=='0'&&b[1]=='0'){
		for(i=0;i<2;i++){
			b[i]=b[i+2];
		}
		len=2;
		//printf("*");
	}
	//printf("%d %d\n",len,i);
	for(i=0;i<len;i++){
		printf("%c",b[i]);
	}
	return b[0];
}
int main(){
	char a[3]={0};
	int len;
	gets(a);
	    len=strlen(a);
	    if(len%3==1){
		    if(a[0]>='1'&&a[0]<='7') printf("%c",a[0]);
		    if(a[0]>='8') printf("1%d",(a[0]-48)%8);
		    if(a[0]>='A') printf("1%d",a[0]-63);
		printf("\n");
	    }
	    if(len%3==2){
		    tabe(a,2);
		    printf("\n");
	    }
	    if(len%3==0){
		    tabe(a,3);
			printf("\n");
		}		    
	return 0;
}
