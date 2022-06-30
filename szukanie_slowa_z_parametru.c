#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
	
	FILE *plik;
	char line[100];
	int i = 1;
	
	if(argc!=3){
  	fprintf(stderr, "\nUWAGA nie podano argumentow.\nWywolaj z parametrami:\n%s \t1:nazwa pliku 1 \t2:nazwa pliku 2\n\n", argv[0]);           
  	exit(1);
  }
  
  if((plik=fopen(argv[1],"r"))==NULL){ 
  fprintf(stdout,"\nNie mo¿na otworzyc pliku: %s", argv[1]);
  exit(2);
  }
  
  printf("\nPlik %s otwarty do odczytu.\n", argv[1]);
  
  while (fgets(line, 99, plik) != NULL)
    {
        if (strstr (line, argv[2]) != NULL){
		printf("%d ", i);
        fputs(line, stdout); 
		}// wypisuje linie na standardowe wyjœcie
		i++;
    }
  
  
  
  if(fclose(plik)!=0)
   fprintf(stderr, "Blad zamkniecia pliku %s.\n", *(argv+1));           




return 0;
	
}
