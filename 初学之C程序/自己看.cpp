for(j=0;std[i][j]!='\0';j++){
                if(check[j]==std[i][j]) sim[i]++;
                else if(!strcmp(&check[j],&std[i][j+1])){
            	       sim[i]=leng-1;
            	         break;
                }
                else if(!strcmp(&check[j+1],&std[i][j])){
                	
                }
            }
            
            
            
            	for(j=0;std[i][j]!='\0';j++){
                if(check[j]==std[i][j]) sim[i]++;
                else if(!strcmp(&check[j],&std[i][j+1])||!strcmp(&check[j+1],&std[i][j])){
                	   printf("%d %d\n",sim[i],j);
            	       sim[i]=leng-1;
            	         break;
                }
            }
            
            
            
            if(!strcmp(&check[j],&std[i][j+1])&&j<leng){
            	       sim[i]=leng-1;
            	         break;
                }
				else if(!strcmp(&check[j+1],&std[i][j])){
            	       sim[i]=leng-1;
            	         break;
				}
