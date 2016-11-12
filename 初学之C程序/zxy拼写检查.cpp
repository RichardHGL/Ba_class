#include<stdio.h> 
#include<string.h> 
int cmpEqLenStr(char str1[], char str2[], int len) {
     int i, beSimilar=0;
     char temp[22];
     for (i = 0; i < len; i++){  
	      strcpy(temp, str1);
	      temp[i] = str2[i];  
	      if (strcmp(temp, str2) == 0){
	           beSimilar = 1;
	           break; 
	      }  
	} 
	return beSimilar;
}
int cmpLLenStr(char str1[], char str2[], int len){
        int i, beSimilar=0;
        char temp[22];
		for (i = 0; i < len; i++) {
		     strcpy(temp, str1);
		     strcpy(&temp[i], &temp[i + 1]); 
		     if (strcmp(temp, str2) == 0) {
		           beSimilar = 1;
			       break; 
			} 
		} 
		return beSimilar; 
} 
int main()
{      
     int n; 
	 int i, lword, lstr; 
	 char word[100][22]; 
     char str[22];
     scanf("%s", str);
     scanf("%d", &n);
     for (i = 0; i < n; i++)
	     scanf("%s", word[i]); 
	 for (i = 0; i < n; i++) {
          if (strcmp(str, word[i]) == 0) {
             printf("%s", str); 
			 return 0;
          }
     }
     lstr = strlen(str);
     for (i = 0; i < n; i++) { 
         lword = strlen(word[i]); 
		 if (lstr == lword) {
			   if (cmpEqLenStr(str, word[i], lstr)) {
	                 printf("%s", word[i]); 
                     break;
               } 
         } else if (lstr == (lword + 1)) { 
	                  if (cmpLLenStr(str, word[i], lstr)) {
	                       printf("%s", word[i]);
                           break;             
	                  }          
         } else if (lstr == (lword - 1)) {
                     if (cmpLLenStr(word[i], str, lword)) { 
		                  printf("%s", word[i]); 
						  break; 
		             }  
         } 
     } 
     if (i >= n)   
	      printf("NOANSWER"); 
		  return 0; 
} 


