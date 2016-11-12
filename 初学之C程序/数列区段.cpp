#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m, n, s1, s2, s, i;
	s1=0;
	s2=0;
	scanf("%d  %d",&m,&n);
	i=1;
    while(i<=m-1){
    	if(i%2!=0){
    		s1=1/(2*i-1)+s1;    		
    	}
    	if(i%2==0){
    	    s1=-1/(2*i-1)+s1;
        }
        i++;
	}
	//printf("%d\n",s1);
	i=1;
	while(i<=n){
    	if(i%2!=0){
    		s2=1/(2*i-1)+s2;    		
    	}
    	if(i%2==0){
    	s2=-1/(2*i-1)+s2;
        }
        i++;
	}
	//printf("%d\n",s2);
	s=s2-s1;
	printf("%.4f\n",s);
	system("pause");
	return 0;
}
