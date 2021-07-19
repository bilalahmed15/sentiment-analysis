// bilal ahmed 19I-1874

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define esc 27
int main() {
	while(1){

   int i,j,a;
    char positive_words[5000][50];
    char negative_words[5000][50];
    char stop_words[5000][50];

    char words[5000][50];
    char input[5000];
    
    FILE * file;
    	
    int pos=0,neg=0;
    int ctr_pos=0;
    int ctr_neg=0;
    int ctr_stop=0;
    
    printf("enter a review -- Press return to exit:\n");
    scanf(" %[^\n]%*c",input);


    if(input[0]==27){
    return 0;
    }
    while(input[i]!='\0'){
        if(ispunct(input[i])){
        input[i]=' ';
        }
	else{
	input[i]=input[i];
	}
	i++;
	}
    while(input[j]!='\0'){
	a=input[j];
	input[j]=tolower(a);
	j++;
	
	}
    for(int i=0;input[i]!='\0';i++){
    input[i]=tolower(input[i]);
    }
   
    
    

   

  file = fopen( "positive-words.txt" , "r");
    if (file) {while (fscanf(file, "%s", positive_words[ctr_pos])!=EOF)
            ctr_pos++;
        fclose(file);}

  file = fopen( "negative-words.txt" , "r");
    if (file) {while (fscanf(file, "%s", negative_words[ctr_neg])!=EOF)
            ctr_neg++;
        fclose(file);
        
        }  

  file = fopen( "stopwords.txt" , "r");
    if (file) {while (fscanf(file, "%s", stop_words[ctr_stop])!=EOF)
            ctr_stop++;
    fclose(file);}


     int no_ofowrds=0;

	for(int i=0 ; input[i]!='\0' ;i++ ){
		if(i==0){

    		for(int j=0 ;input[i]!=' ' ;j++,i++){
    			words[no_ofowrds][j] = input[i];

	 }
 	no_ofowrds++;
    }

  if(input[i]==' ') {
    i++;
    for(int j=0 ;input[i]!=' ';j++,i++){
        words[no_ofowrds][j] = input[i]; 

      if( input[i]=='\0'){
           break;
         }
      }
    no_ofowrds++;
    i--;
  }
}
	
  int w=0,t=0;
    
   for(int i=0;i<no_ofowrds;i++){
     for(int j=0;j<127;j++){
    			
       if(strcmp(&words[i][0],&stop_words[j][0])==0){
      	i+1;
      		
          }
        else{
      	  continue;
        }
      	}
      i++;

    } 
    
    
    for(int i=0;i<no_ofowrds;i++){
    	for(int j=0;j<2052;j++){
    			
    	  if(strcmp(&words[i][0],&positive_words[j][0])==0){
      		pos++;
      		
      }
   }
   i++;

    }
    
     
    for(int i=0;i<no_ofowrds;i++){
    	for(int j=0;j<4831;j++){
    			
    	  if(strcmp(&words[i][0],&negative_words[j][0])==0){
      		neg++;
      		
         	}
      	}
   i++;
   	

    }
   
    
    if(pos>neg){
      printf("positive santiment\n");
      
      }
    else if(neg>pos){
      printf("negative santiment\n");
   
      }
    else{
     printf("neutral santiment\n");
      }
    }
    return 0;
   } 
