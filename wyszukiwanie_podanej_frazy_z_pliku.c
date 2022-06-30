/* Program wyszukuje w pliku o podanej nazwie wiersze, które
zawieraj¹ podan¹ frazê oraz wypisuje te wiersze na ekran. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
char *my_gets_s(char *str, int n);
int main(void)
{
    FILE *fp;

    char line[SIZE], word[SIZE], file_name[40];
    printf ("Podaj nazwe pliku do odczytu: ");
    my_gets_s(file_name, 40);       // wpisz np. text.txt

    if ((fp = fopen (file_name, "r")) == NULL)
    {
        fputs("Blad otwarcia pliku!!!\n", stderr);
        exit(1);
    }

    printf ("Podaj szukany napis: ");
    my_gets_s(word, SIZE);

    while (fgets(line, SIZE, fp) != NULL)
    {
        if (strstr (line, word) != NULL)
        fputs(line, stdout); // wypisuje linie na standardowe wyjœcie
    }

    fclose(fp);
    return 0;
}
char *my_gets_s(char *str, int n)
{
	char * p;
	int i = 0;
	p = fgets(str, n, stdin);           // korzystamy z funkcji fgets, stdin - standardowe wejœcie np. klawiatura
	if (p) // to siê nie wykona jezeli p != NULL
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			str[i] = '\0';
		else // gdy str[i] == '\0'
			while (getchar() != '\n') // czyszczenie bufora
				continue;
	}
	return p;
}
