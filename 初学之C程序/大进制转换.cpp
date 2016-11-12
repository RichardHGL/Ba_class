#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int m,len,i,y=0,j=0;
	long long int k=0;
	char s[320]={0},r[1100]={0},x;
	scanf("%s %d",&s,&m);
	len=strlen(s);
	//printf("%d %s\n",len,s);
	for(j=0;j<1100;j++){
		y=0;
		for(i=0;i<len;i++){
	        x=(s[i]-'0'+y*10)/m+'0';
	        if(i<len-1) y=(s[i]-'0'+y*10)%m;
	        if(i==len-1) r[j]=(s[i]-'0'+y*10)%m+'0';
	        s[i]=x;
        }
        if(s[0]=='0'){
	        len--;
	        strcpy(s,&s[1]);
	        s[len]='\0';
        }
        //if(j<=3) printf("%d %S %c\n",len,s,r[j]);
        if(len==0) break;
	}
	for(;j>=0;j--) printf("%C",r[j]);
	printf("\n");
	return 0;
} 
