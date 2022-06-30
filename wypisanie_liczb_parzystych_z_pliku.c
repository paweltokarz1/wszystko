//Program wczytuje liczby z pliku random_int.txt i wypisuje tylko parzyste.

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    int m;
    if ((fp = fopen("random_int.txt", "r" )) == NULL)
    {
        fprintf(stderr,"Blad otwarcia pliku!!!");
        exit(1);
    }

    while (fscanf(fp, "%d", &m) == 1)
        if (m % 2 == 0)
            printf ("%d\n", m);

    fclose(fp);
    return 0;
}
