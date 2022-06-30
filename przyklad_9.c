//Program wypisuje kolejno  na standardowe wyjœcie pliki, 
//których nazwy   przekazywane s¹ jako argumenty do funkcji main().
#include<stdio.h>
#include<stdlib.h>
void filecopy(FILE *,FILE * );

int main(int argc, char *argv[]){
 
FILE *fp;
char *program = argv[0];

if (argc==1)
 	filecopy(stdin, stdout);
 
else {
		while(--argc>0){
   		if ((fp=fopen(*++argv,"r"))==NULL) { 
    		fprintf(stdout,"%s:nie mo¿na otworzyc: %s",   program, *argv);
    		exit(1);
    		}
   		filecopy(fp, stdout);
        printf("\n********************************************************\n");
   		fclose(fp); 
  		} 
	} 
   
return 0;
}

void filecopy(FILE *ifp, FILE *ofp ){
	int c;
	while((c=fgetc(ifp))!=EOF)
		fputc(c,ofp);
}

