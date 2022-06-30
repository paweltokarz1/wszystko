#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FILE_NAME "text.txt"
int main(void)
{
    FILE *fp;

    fp  = fopen(FILE_NAME, "r"); //otwarcie pliku w trybie tekstowym do odczytu
    if (fp == NULL)
    {
        printf("Nie mozna otworzyc pliku %s\n", FILE_NAME);
        exit(EXIT_FAILURE); // lub exit(1);
    }
    
   
        char ch;    
        // odczytujemy plik znak po znaku zamieniaj¹c ma³e litery na du¿e
        while((ch = fgetc(fp)) != EOF)
        {
           putchar(toupper(ch));
        }


    fclose(fp);
    return 0;
}

