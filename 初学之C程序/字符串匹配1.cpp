#include<stdio.h>
#include<string.h>
#include<math.h>
char a[60]={0},b[60]={0};
int q[10]={0},len1,len2,flag1=0;
char *harmony(char k[]){
	int len,i;
	len=strlen(k);
	for(i=0;i<len;i++) if(k[i]>='A'&&k[i]<='Z') k[i]+=32;
	return k;
}
int quanlist(int x,int y,int z){
	int i,sum=0,t=0,l1,l2;
	if(flag1) return 0;
	if(z==y){
	    for(i=0;i<z;i++) sum+=q[i];
	    if(sum==x+y){
	    	for(l1=0,l2=0,i=0;l1<len1,l2<len2;){
	    		if(a[l1]==b[l2]||b[l2]=='?') t++,l1++,l2++;
	    		else if(b[l2]=='*') l1+=q[i],l2++,t+=q[i],i++;
	    		else l1++,l2++;
	    	}
	    	if(t==len1){
				printf("YES\n");
				flag1=1;
			} 
	    }
	    if(flag1==0){
	    	return 0;
	    } 
	} 
	else for(i=0;i<=x+y;i++){
		q[z]=i;
		quanlist(x,y,z+1);
	}
	if(z==0&&flag1==0) printf("NO\n");
	return 0; 
}
int main()
{
	int i,j,k,t,num,flag,len,l1,l2,s;
	scanf("%s",a);
	len1=strlen(a);
	harmony(a);
	for(i=0;i<10;i++){
		scanf("%s",b);
		harmony(b);
		if(strcmp(a,b)==0){
			printf("YES\n");
			continue;
		}
		t=0,flag=0;
		len2=strlen(b);
		for(k=0,num=0;k<len2;k++){
			if(b[k]=='*') num++;
			if(k>=1&&b[k]=='*'&&b[k-1]=='*'){
				strcpy(&b[k-1],&b[k]);
				k--;
				num--,len2--;
			} 
		}
		if(num==0){	
			for(j=0;j<len2;j++) if(a[j]==b[j]||b[j]=='?') t++;
			if(t==len1){
				printf("YES\n");
				continue;
			}else{
				printf("NO\n");
				continue;
			}
		}
		if(len2>len1&&len2-len1>num){
			printf("NO\n");
			continue;
		}
		else if(len2>len1&&len2-len1==num){
			for(l1=0,l2=0;l1<len1&&l2<len2;){
				if(a[l1]==b[l2]||b[l2]=='?') t++,l1++,l2++;
				if(b[l2]=='*') l2++;
			} 
			if(t==len1){
				printf("YES\n");
				flag=1;
			}else {
				printf("NO\n");
				flag=1;
			}
		}
		if(flag) continue;
		if(num!=0){
		    s=fabs(len1-len2);
		    flag1=0;
		    quanlist(s,num,0);
		}
	}
	return 0;
}  
