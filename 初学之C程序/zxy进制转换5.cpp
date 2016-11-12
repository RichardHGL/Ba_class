#include <stdio.h>
#include <string.h>
char binstrs[][5]={
         "0000",        
		 "0001",         
		 "0010",         
		 "0011",         
		 "0100",        
		 "0101",         
		 "0110",         
		 "0111",         
		 "1000",         
		 "1001",         
		 "1010",         
		 "1011",         
		 "1100",         
		 "1101",
		 "1110",      
		 "1111"}; 
int getDecInt(char hex){     
	 return (hex>'9'?(hex-55):(hex-'0'));  
}
void putHEX1(char hex){ 
     int n=getDecInt(hex);
	 if(n>7) printf("1%d",n-8);
	 else printf("%d",n);  
} 
void putHEX2(char hex1, char hex2){
     char bstr[]={"000000000"};
	 int i,n;     
	 strcpy(&bstr[1],binstrs[getDecInt(hex1)]);      
	 strcpy(&bstr[5],binstrs[getDecInt(hex2)]);     
	 for(i=0;i<3;i++){
	      n=4*bstr[i*3+0]+2*bstr[i*3+1]+bstr[i*3+2]-336;
          if(n==0&&i==0) continue;         
		  printf("%d",n);      
	 }  
} 
void putHEX3(int index, char hex1, char hex2, char hex3){     
        char bstr[]={"000000000000"};     
		int i,n;     
		strcpy(&bstr[0],binstrs[getDecInt(hex1)]);     
		strcpy(&bstr[4],binstrs[getDecInt(hex2)]);    
		strcpy(&bstr[8],binstrs[getDecInt(hex3)]);     
		for(i=0;i<4;i++){         
		    n=4*bstr[i*3+0]+2*bstr[i*3+1]+bstr[i*3+2]-336;         
		    if(index==0&&n==0&&i==0) continue;         
		    printf("%d",n);
        }  
} 
int main()
{     
     int n, i,j;     
	 char hexstr[100000];     
	 int len,m,l,stidx;     
	 scanf("%d", &n);   
	 for(i=0;i<n;i++){         
	     scanf("%s",hexstr);         
	     len=strlen(hexstr);         
	     m=len%3;         
	     l=len/3;         
	     if(m==1) putHEX1(hexstr[0]);         
	     if(m==2) putHEX2(hexstr[0],hexstr[1]);         
	     for(j=0;j<l;j++){              
	         stidx=j*3+m;             
	         putHEX3(stidx, hexstr[stidx],hexstr[stidx+1],hexstr[stidx+2]);         
	     }         
	     printf("\n");     
	 }     
	 return 0; 
}
