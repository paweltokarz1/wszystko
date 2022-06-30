// Argumenty wywo³ania programu

#include <stdio.h>
#define P1

void linia(int);
 
int main(int argc, char *argv[]){

/*(1) Sprawdziæ dzia³anie programu dla P1, P2, P3*/ 

#ifdef P1
linia(1);
//Przyklad 1 ////////////////////////////////////////////

int i;
printf("Parametry programu:\n");
for (i=0;i<=argc;i++)
  printf("\n %d: %s\n",i, argv[i]);
#endif

//Przyklad 2 //////////////////////////////////////////
#ifdef P2
linia(2);
printf("Parametry programu:\n");
while(argc>0){
   printf("%s\n",*argv);
   argc--;
   argv++;
} 
#endif

//Przyklad 3 ////////////////////////////////////////////
#ifdef P3
linia(3);
printf("Parametry programu:\n");
while( *++argv !=NULL)
  printf("%s\n",*argv);    
#endif 

return 0;
}

void linia(int k){
if (k>0) printf("\n\n______________ %d ________________\n\n",k);
else printf("\n\n___________________________________\n\n");
}
