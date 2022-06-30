// Program ilustruj�cy swobodne "poruszanie" si� po pliku.
// Wy�wietla zwarto�� pliku w odwrotnej kolejno�ci zamieniaj� ma�e litery na du�e.

#include <stdio.h>
#include <stdlib.h>         
#include <ctype.h>
#define CNTL_Z '\032'		// znacznik EOF w plikach tekstowych WINDOWS
int main(void)
{
	char ch;
	FILE *file;
	long count, end;
	// tryb binarny tylko do odczytu
	if ((file = fopen("persons.txt", "rb")) == NULL)
	{
		printf("Nie moge otworzyc pliku %s\n", file);
		exit(1);
	}

	fseek(file, 0L, SEEK_END);// przejd� do ko�ca pliku
	end = ftell(file);

	for (count = 1L; count <= end; count++)
	{
		fseek(file, -count, SEEK_END);	// id� do ty�u
		ch = fgetc(file);
		
		if (ch != CNTL_Z && ch != '\r') // znaki obecne w pliku w sytemie WINDOWS
			putchar(toupper(ch));
	}
	putchar('\n');
	fclose(file);
	return 0;
}
