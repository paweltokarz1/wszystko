// Pliki tekstowe

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
   
/*(1) Sprawdü dzia≥anie programu*/

FILE *plik;
  //otwarcie pliku do zapisu
 if ((plik=fopen("DANE.TXT","w"))==NULL) { 
      fprintf(stderr, "\nNie mozna otworzyc pliku do zapisu.\n");  
      exit(EXIT_FAILURE);
  }
   
  int i;
  srand((unsigned int)time(0));

  for (i=0;i<20;i++) 
     fprintf(plik,"%d ", rand()%100); //wpisanie liczb
  
fclose(plik);
  
printf("\nWylosowane liczby zapisano w pliku DANE.TXT. Sprawdz jego zawartosc.\n");
   
return 0;
}

