#include<stdio.h>
#include<string.h>
char tabel(char x[],int k,int t){
	int num=0,y,i,len=4;
	char b[4]={'0','0','0',};
	for(i=0;i<k;i++){
		if(x[i]>='0'&&x[i]<='9') num=num*16+x[i]-48;
		else num=num*16+x[i]-55;
	}
	for(y=num,i=4;i>0;i--){
		b[i-1]=y%8+48;
		y=y/8;
	}
	if(t==0&&k!=3){
	    if(b[0]=='0'&&b[1]!='0'){
	        for(i=0;i<3;i++){
		        b[i]=b[i+1];
	        }
	        len=3;
        }
    	else if(b[0]=='0'&&b[1]=='0'){
	    	for(i=0;i<2;i++){
		    	b[i]=b[i+2];
		    }
		    len=2;
	    }
	}
	for(i=0;i<len;i++){
		if(i==0&&b[0]=='0'&&t==0) continue;
		printf("%c",b[i]);
	}
	return b[0];
}
int main()
{
	int n,i,len,j,t;
	char a[100000]={0};
	scanf("%d",&n);
	getchar();
	for(j=0;j<n;j++){
	    gets(a);
	    len=strlen(a);
	    if(len%3==1){
		    if(a[0]>='1'&&a[0]<='7') printf("%c",a[0]);
		    if(a[0]>='8'&&a[0]<='9') printf("1%c",a[0]-8);
		    if(a[0]>='A') printf("1%c",a[0]-15);
		    for(i=1;i<len;i+=3){
			    tabel(&a[i],3,1);
		    }
	    }
	    else if(len%3==2){
		    tabel(a,2,0);
		    for(i=2;i<len;i+=3){
			     tabel(&a[i],3,1);
		    }
	    }
	    else if(len%3==0){
		    tabel(a,3,0);
		    for(i=3;i<len;i+=3){
			     tabel(&a[i],3,1);
			}	
	    }
		printf("\n");
	}
	return 0;	
}
