// Program wypisuje argumenty wiersza polece�.
// Skompilowany program nale�y uruchomi� z wiersza polece� wpisuj�c (na przyk�ad):
// przyklad_8.exe poniedzialek wtorek sroda czwartek piatek sobota niedziela
#include <stdio.h>
int main(int argc, char *argv[])
{

    for(int i = 0; i < argc; i++)
        if (i == 0)
        {
            printf("Nazwa programu: %s\n", argv[i]);
            printf("Pozostale argumenty:\n");
        }
        else
            printf("%d: %s\n", i, argv[i]);


	return 0;
}

