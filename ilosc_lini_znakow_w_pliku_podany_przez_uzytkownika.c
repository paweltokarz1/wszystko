// Pliki tekstowe

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	
	FILE *plik_r, *plik_rb;
   	char nazwa[10];
    printf("Podaj nazwe pliku: ");
    gets(nazwa);
    plik_r = fopen(nazwa, "r");
    plik_rb = fopen(nazwa, "rb");
    
    int znaki=0, linie=0;
    
    char ch;    

//ilosc wierszy i znakow w pliku
        while((ch = fgetc(plik_r)) != EOF)
        {
        	znaki++;
           if(ch == '\n' || ch == '\0')
           linie++;
        }
        printf("Ilosc znakow to: %d\n", znaki);
        if(ch != 0 && linie == 0)
        linie= 1;
        printf("Ilosc lini to: %d\n", linie);
       
       fclose(plik_r);
       fclose(plik_rb);
    
    

   
return 0;
}

