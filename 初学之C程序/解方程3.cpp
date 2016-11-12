#include<stdio.h>
#include<math.h>
int main()
{
	int x1,x2,x3,x4,n,i,y;
	unsigned int a[32768]={0};
	for(i=1;i<=32768;i++){
		a[i]=0;
	}
	    for(x1=0;x1<=181;x1++){
	    	if(4*x1*x1>32768) break;
		    for(x2=x1;x2<=181;x2++){
			    if(x1*x1+3*x2*x2>32768) break;
		    	for(x3=x2;x3<=181;x3++){
		    		if(x1*x1+x2*x2+2*x3*x3>32768) break;
		    		for(x4=x3;x4<=181;x4++){
		    			if(x1*x1+x2*x2+x3*x3+x4*x4<=32768){
		    				a[x1*x1+x2*x2+x3*x3+x4*x4]++;
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
