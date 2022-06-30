// Program pobiera znaki z standardowego wej�cia i dopisuje je do pliku
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    int ch;
    if ((fp = fopen("temp.txt", "a" )) == NULL)  // otwarcie pliku tekstowego w trybie do dopisywania
    {
        printf ("Blad otwarcia pliku!!! ");
        exit(1);
    }
    printf("\nWprowadz nowe znaki: ");
	//zasymuluj znak EOF wciskaj�c  enter (zwolnienie bufora) 
	//oraz kombinacj� klawiszy Ctrl+Z  
    while ((ch = fgetc(stdin)) != EOF)
        fputc(ch, fp);

    fclose(fp);
    return 0;
}
