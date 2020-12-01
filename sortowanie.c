#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 

#define BUFSIZE 8192

int
main( int argc, char **argv ) {
  	
	int i = 3;  /* i - dla wpisanych danych przy wywolaniu, */ 
		    /* zaczynamy od 3 bo przy wywolaniu trzecie w kolejnosci wpisujemy slowa do wyszukania w tekscie*/
	int j = 0;  /* licznik dla nowej tablicy */

	int czy_zawiera; /* bedzie potrzebne przy funkcjionalnosci 2 */ 

	char *str[BUFSIZE]; /* nowa tablica utworzyna z podanych argumentow */

	char *slowa; /* przetrzymuje slowa (potrzebne do petli)*/

	int ktora_linia;

	char buf[BUFSIZE];

	int funkcjonalnosc= argc > 1 ? atoi(argv[1]) : 0; /* cyfra 1 lub 2 */

        FILE *in= argc > 2 ? fopen( argv[2], "r" ) : stdin;

        if( funkcjonalnosc == 0 ){
		fprintf( stderr, "%s: błąd: proszę podac funkcjoalnosc ( 1 lub 2 )\n", argv[0] );
                return EXIT_FAILURE;
        }

        if( in == NULL ) {
                fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[2] );
                return EXIT_FAILURE;
        }



	for(i = 3; i < argc; i++){ /* petla bierze slowa podane na wejsciu (zaczynajac od trzeciego) do wyszukania  */
		slowa = argv[i];   /* i zapisuje w nowej tablicy str[]*/
		str[j] = slowa;
		j++;
	}		

	
	if( funkcjonalnosc == 1 ){ /* wyswietla linijki ktore maja conajmniej jedno z podanych na wejsciu slow */

		ktora_linia= 0;
		
		while( fgets( buf, BUFSIZE, in ) != NULL ) {
                	ktora_linia++;
		
		for( j = 0; j < argc - 3; j++){  /* petla sprawdza czy ktores slowo podane na wejsciu wystapilo  */
	
                	if( strstr( buf, str[j] ) != NULL ){
                        	printf("%d. ", ktora_linia); /* wypisuje nr linijki */
                        	printf( "%s", buf );
                	}
			if ( str[j] = str[j + 1]) /* jezeli podamy dwa takie same slowa na wejsciu to nie wypisuj dwa razy */
				break;
			
		}
        	}
	}
	


	if( funkcjonalnosc == 2 ){ /* wyswietla liniki w ktorych sa wszystkie podane slowa */


                ktora_linia= 0;

                while( fgets( buf, BUFSIZE, in ) != NULL ) {
                        ktora_linia++;
                 for( j = 0; j < argc - 3; j++){
	    	
                        if( strstr( buf, str[j] ) == NULL ) {   /* sprawdza czy dane slowo jest w linijce,  */
								/* jezeli nie to przechodzi dalej*/
                        	czy_zawiera = 1; 
				break;
			}
                        else czy_zawiera = 0;
                        
		 }
		 
		  if( czy_zawiera == 0 ){			/* wypisuje tylko te liniejki w ktorych byly wszytskie podane slowa*/
		  	printf("%d. ", ktora_linia);
                  	printf( "%s", buf );
		  }

                }
        }


	if ( funkcjonalnosc != 1 && funkcjonalnosc != 2 )			/* jezeli poday cos innego niz 1 lub 2 wyswietla tekst */
		printf("zly argument :( aby wywolac program podaj 1 lub 2\n"); 


        
	
	return EXIT_SUCCESS;
}
