/* dodawanie lini do skorowidza jesli zostanie znaleziona */


/* tu jest jakis kod */

#include <stdlib.h>


void (int **skoro, int index_slowa, int nr_linii)
{
	int ile_linii = skoro[index_slowa][0];

	skoro[index_slowa] = realloc(skoro[index_slowa], sizeof(int)*(ile_linii + 1));
	/* chyba reallokuje pamiec poprzedniego zwiekszajac o jeden zarezerwowane miejsce */

	skoro[index_slowa][ile_linii+1] = nr_linii; /* zapisanie nr linii na ostatnie pole */

	skoro[index_slowa][0]++; /* zwiekszenie liczby nr linii w liczniku */



}
