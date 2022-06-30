// Pliki tekstowe

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
   
/*(1) Sprawdü dzia≥anie programu*/

FILE *plik, *nowy_plik;
  
 int m, count=1, holder;
 
 //otwarcie pliku do czytania
  if ((plik = fopen("DANE.txt", "r" )) == NULL)
    {
        fprintf(stderr,"Blad otwarcia pliku!!!");
        exit(1);
    }
    
//otwarcie pliku do zapisu    
    if ((nowy_plik=fopen("WYNIKI.TXT","w"))==NULL) { 
      fprintf(stderr, "\nNie mozna otworzyc pliku do zapisu.\n");  
      exit(EXIT_FAILURE);
  }
  
  
  
   fscanf(plik, "%d", &m);
   holder = m;
   
   while (fscanf(plik, "%d", &m)==1){
	   if(m%2==0){
	
	fprintf(nowy_plik,"%d:%d\n ", count, holder);
	count++;
}
holder = m;
}

  
  
fclose(plik);
fclose(nowy_plik);
  

   
return 0;
}

