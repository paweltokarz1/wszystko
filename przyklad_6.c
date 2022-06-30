// U¿ycie funkcji fread i fwrite, ilustracja dok³adnoœci zapisu 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    FILE *file;
    char *file_name = "pi.dat";
    double pi = 2*acos(0);

    if ((file = fopen(file_name , "wb")) == NULL)
    {
        fprintf(stderr, "Blad otwarcia pliku %s do zapisu\n", file_name );
        exit(1);
    }

    // zapis liczby pi w postaci takiej jak¹ wyœwietla j¹ specyfikator %f (domyœlnie 6 miejsc po przecinku)
    fprintf (file, "%3f", pi);      //fprintf(file, "%.15f", pi ); - trzeba ustalaæ dok³adnoœæ

    // zapis liczby pi w z u¿yciem funkcji fwrite
    fwrite (&pi, sizeof(pi), 1, file) ;

    if (fclose(file) != 0)
		printf("Blad zamkniecia pliku!\n");


    if ((file = fopen(file_name , "rb")) == NULL)
    {
        fprintf(stderr, "Blad otwarcia pliku %s do odczytu\n", file_name );
        exit(1);
    }


    // odczyt liczby pi zapisanej przez fprintf
    fscanf (file, "%lf", &pi);
    fprintf(stdout, "(fprintf) pi= %.15f\n", pi);

    // odczyt liczby pi zapisanej przez fwrite
    fread (&pi, sizeof (pi), 1, file);
    fprintf (stdout, "(fwrite) pi= %.15f\n", pi);
    fclose (file);

return 0;
}


