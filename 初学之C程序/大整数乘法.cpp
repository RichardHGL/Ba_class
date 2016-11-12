#include<stdio.h>
#include<string.h>
int main()
{
	int i,len1,len2,len,j;
	char a[100]={0},b[100]={0},d[300]={0};
	int c[300]={0},a1[100]={0},b1[100]={0};
	scanf("%s",a);
	scanf("%s",b);
	len1=strlen(a);
	len2=strlen(b);
	for(i=len1;i>=1;i--) a1[i]=a[len1-i]-'0';
	for(i=len2;i>=1;i--) b1[i]=b[len2-i]-'0';
	for(i=1;i<=len1;i++){
		for(j=1;j<=len2;j++) if(i+j-1>=0) c[i+j-1]+=(a1[i])*(b1[j]);
	}
	for(i=1;i<=len2+len1-1;i++) if(c[i]>=10){
		c[i+1]+=c[i]/10;
		c[i]=c[i]%10;
	}
	if(c[i]!=0) len=len2+len1;
	else len=len2+len1-1;
	for(i=0;i<len;i++) d[i]=c[len-i]+'0';
	printf("%s\n",d);
	return 0;
}
