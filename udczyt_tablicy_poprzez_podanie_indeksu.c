// Program ilustrujacy swobodne "poruszanie" sie po pliku binarym 
//oraz u¿ycie funkcji fread i fwrite
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int main(void)
{
	double numebrs[SIZE];
	double value;
	const char *file_name = "numbers.dat";
	int i;
	long position;
	FILE *file;
	/* tworzy tablice wartosci typu double */
	for (i = 0; i < SIZE; i++)
		numebrs[i] = 50 * (i*i) + (1.0 * 2 * i)/(i+1);

	// wyœwietlamy nasz¹ tablicê w celach kontrolnych:
	printf("-----------Tablica:-------------\n");
    for(i = 0; i < SIZE; i++)
        printf("[%d] %10.2f\n", i, numebrs[i]);
    printf("-------------------------------\n");


	if ((file = fopen(file_name , "wb")) == NULL)
	{
		fprintf(stderr, "Blad otwarcia pliku %s do zapisu\n", file_name );
		exit(1);
	}

	/* zapisuje tablice do pliku w formacie binarnym	*/
	fwrite(numebrs, sizeof(double), SIZE , file);

	if (fclose(file) != 0)
		printf("Blad zamkniecia pliku!\n");
//-------------------------------------------------------------
	if ((file = fopen(file_name, "rb")) == NULL)
	{
		fprintf(stderr,
			 "Blad otwarcia pliku %s do dostepu swobodnego\n", file_name);
		exit(1);
	}
	/* odczytuje z pliku wybrane pozycje */
	printf("Podaj indeks z przedzialu 0-%d.\n", SIZE -1);
	scanf("%d", &i);
	while (i >= 0 && i < SIZE)
	{
		position = (long) i * sizeof(double);	// oblicza pozycje
		fseek(file, position, SEEK_SET);		// przechodzi w odpowiednie miejsce
		fread(&value, sizeof(double), 1, file);
		printf("Wartosc pod tym indeksem to %10.2f\n", value);
		printf("Kolejny indeks (wyjscie poza przedzial konczy program):\n");
		scanf("%d", &i);
	}
	if (fclose(file) != 0)
		printf("Blad zamkniecia pliku!\n");
	return 0;
}

