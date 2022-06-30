// Pliki tekstowe

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
   
/*(1) Sprawdü dzia≥anie programu*/

FILE *plik;
  
 int m;
  if ((plik = fopen("DANE.txt", "r" )) == NULL)
    {
        fprintf(stderr,"Blad otwarcia pliku!!!");
        exit(1);
    }
   

//czytanie danych z pliku tekstowego
  while (fscanf(plik, "%d", &m)==1)
            printf ("%d\n", m);

  
  
fclose(plik);
  

   
return 0;
}

