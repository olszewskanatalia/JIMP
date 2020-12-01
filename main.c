/* tutaj bedzie kod glowny */
/* test */
#include <stdio.h>
#include <stdlib.h>

#include "skorowidz.h"
#include "wyszukiwanie.h"



int main( int argc, char ** argv)
{

	int ile_linii;
	int ile_slow = argc - 2;
	char ** slowa = malloc((argc - 1)*sizeof(char*));
	
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

	/*funkcja szukaj slow*/

	/* funkcja wypisz skorowidz */


	free(slowa);


	

	return EXIT_SUCCESS;
}
