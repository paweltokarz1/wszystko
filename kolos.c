#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	
	FILE *plik1;
	FILE *plik2;
	char tab1[16];
	char tab2[16];
	
	if ((plik1 = fopen("countries1.txt" , "r")) == NULL)
    {
        fprintf(stderr, "Blad otwarcia pliku %s do odczytu\n", "countries1.txt" );
        exit(1);
    }
    if ((plik2 = fopen("countries2.txt" , "r")) == NULL)
    {
        fprintf(stderr, "Blad otwarcia pliku %s do odczytu\n", "countries2.txt" );
        exit(1);
    }
	
  
        while(!feof(plik1) || !feof(plik2)){
       	fscanf(plik1,"%s", tab1);
       	fscanf(plik2,"%s", tab2);
       	if(strcmp(tab1,tab2)==0){
       		printf("%s = %s\n",tab1,tab2);
       		}
		   if(strcmp(tab1,tab2)==1){
       		printf("%s > %s\n",tab1,tab2);
		   }
		   if(strcmp(tab1,tab2)==-1){
       		printf("%s < %s\n",tab1,tab2);
		   }
	
       	}
            
   	fclose(plik1);
	fclose(plik2);
	
	
	return 0;
}
