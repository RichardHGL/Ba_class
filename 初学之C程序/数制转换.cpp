    #include <cstdio>
    #include <cstring>
     
    int len,m,n=0,a[1111],b[1111];
    char s[1111];
    int division(){
        int p=0;
        for(int i=len-1;i>=0;i--){
            p=p*10+a[i]; 
            a[i]=p/m;
            p=p%m;            
        }    
        if(a[len-1]==0) len--;
        b[n]=p;n++;  
        return 0;  
    }    
    int main(){
        scanf("%s%d",s,&m);
        len=strlen(s);
        for(int i=0;i<len;i++) a[i]=s[len-i-1]-48;
        while (len>0) division();
        for(int i=n-1;i>=0;i--) printf("%d",b[i]);
        printf("\n");
        
        return 0;
    }    

