/* tutaj bedzie kod glowny */

#include <stdio.h>
#include <stdlib.h>

#include "skorowidz.h"
#include "wyszukiwanie.h"



int main( int argc, char ** argv)
{

	int ile_linii;
	int ile_slow = argc - 2;
	char ** slowa = malloc((argc - 1)*sizeof(char*));
	int **skorowidz;

	for(int i = 0; i < argc-1; i++)
	{
		slowa[i] = argv[1+i];
	}

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;
	
	if( ile_slow == 0 ) {
		fprintf( stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0] );
		return EXIT_FAILURE;
	}

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}

	/* przypisanie ilosci wierszy ( liczby slow)*/
	skorowidz = malloc(ile_slow * sizeof (int)); 
	
	for( int i = 0; i < ile_slow; i++)
	{
		skorowidz[i] = malloc(1 * sizeof(int));
		/* rezerwacja pamieci dla kolumn */
		/* poczatkowa to liczba wszystkich odszukanych linii*/
		skorowidz[i][0] = 0;
		/* na poczatku 0 odszukanych linii */
	}




	/*funkcja szukaj slow*/

	/* funkcja wypisz skorowidz */



	for( int i = 0; i < ile_slow; i++)
	{
		free(skorowidz[i]);		/* zwolnieni pamieci kolumn */
	}
	free(slowa); /*zwolnieni pamieci wierszy */


	

	return EXIT_SUCCESS;
}
