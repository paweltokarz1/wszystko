#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FILE_NAME_IN "text.txt"
#define FILE_NAME_OUT "text_out.txt"
int main(void)
{
    FILE *fp_in, *fp_out;

    fp_in  = fopen(FILE_NAME_IN, "r"); //otwarcie pliku w trybie tekstowym do odczytu
    fp_out = fopen(FILE_NAME_OUT, "w"); //otwarcie pliku w trybie tekstowym do zapisu

    if (fp_in == NULL)
    {
        printf("Nie mozna otworzyc pliku %s\n", FILE_NAME_IN);
        exit(EXIT_FAILURE); 

    }
    if (fp_out == NULL)
    {
        printf("Nie mozna otworzyc pliku %s\n", FILE_NAME_OUT);
        exit(EXIT_FAILURE); 
    }
    
    {
        int ch;     // mo¿e to byæ te¿ char ch;
        // odczytujemy plik znak po znaku zamieniaj¹c ma³e litery na du¿e
        // i zapsiujemy je do nowgo pliku
        while((ch = fgetc(fp_in)) != EOF)
        {
           fputc(toupper(ch), fp_out);
        }
        printf("Kopiowanie zakonczone!");
    }


    fclose(fp_in);
    fclose(fp_out);
    return 0;
}

