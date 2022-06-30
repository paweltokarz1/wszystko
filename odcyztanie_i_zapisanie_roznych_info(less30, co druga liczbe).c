#include <stdio.h>
#include <stdlib.h>
#include <string.h>// Pliki tekstowe
#include <time.h>

int main(void){
   
/*(1) Sprawdü dzia≥anie programu*/

FILE *plik, *nowy_plik;
  
 int m,z,n, suma=0, i=1;
  if ((plik = fopen("DANE.txt", "r" )) == NULL)
    {
        fprintf(stderr,"Blad otwarcia pliku!!!");
        exit(1);
    }
    if ((nowy_plik=fopen("WYNIKI.TXT","w"))==NULL) { 
      fprintf(stderr, "\nNie mozna otworzyc pliku do zapisu.\n");  
      exit(EXIT_FAILURE);
  }
   fscanf(plik, "%d", &m);
   
   while (fscanf(plik, "%d", &m )==1){
	   if(m<30){
	
	fprintf(nowy_plik,"%d ", m);
	
}
}

fprintf(nowy_plik,"\n");
fseek(plik,0,SEEK_SET);

while (fscanf(plik, "%d", &z )==1){
	if(i%2==1){
		fprintf(nowy_plik,"%d ", z);
	}
	i++;
}


fprintf(nowy_plik,"\n");
fseek(plik,0,SEEK_SET);

while (fscanf(plik, "%d", &n )==1){
	suma +=n;
	
	
}
fprintf(nowy_plik,"%d ", suma);
  
fclose(plik);
fclose(nowy_plik);
  

   
return 0;
}

