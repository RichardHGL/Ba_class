#include<stdio.h>
#include<math.h>
int main()
{
	int x1, x2, x3, x4,n,i,y,t;
	unsigned int a[32769]={0};
	for(i=0;i<32768;i++){
		a[i]=0;
	}
	for(x1=0;x1<=90;x1++){
		for(x2=x1;x2<=104;x2++){
		    for(x3=x2;x3<=128;x3++){
		    	for(x4=x3;x4<=181;x4++){
		    		t=x1*x1+x2*x2+x3*x3+x4*x4;
		    		if(t<=32768){
		    		   a[t]++;
		    		}
		    		else break;
		    	}
		    }
		}
    }
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&y);
		printf("%d\n",a[y]);
	}
	return 0;
}

