#include<stdio.h>
int main()
{
	int A,B,C,D,i,t,a[3]={0},x;
    for(i=0;i<=7;i++){
    	A=0;
    	B=0;
    	C=0;
    	D=0;
    	x=i;
    	a[0]=x%2;
    	x=x/2;
    	a[1]=x%2;
    	x=x/2;
    	a[2]=x%2;
    	x=x/2;
		if(a[0]==1){
			A=1;
		}
		else B=2;
		if(a[1]==1){
			C=1;
		}
		else D=3;
		if(((A==1)&&(a[2]==0))||((D==3)&&(a[2]==1))){
			continue;
		}
		if(a[2]==1){
			D=2;
		}
		else A=3;
		if((A==B)||(A==C)||(A==D)||(B==C)||(B==D)||(C==D)){
			t=0;
		}
		else t=1;
		if(t==1) break;	
    }
    if(A==0)  A=10-B-C-D;
    else if(B==0) B=10-A-C-D;
    else if(C==0) C==10-A-B-D;
    else D=10-A-B-C;
    printf("A=%d,B=%d,C=%d,D=%d\n",A,B,C,D);
    return 0;   			
}
