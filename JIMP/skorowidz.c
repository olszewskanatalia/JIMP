/* tutaj jest funkcja wypisujaca skorowidz */

#include <stdio.h>

void wypisz_skorowidz(int **skoro,char **slowa, int ile_slow)
{
	for(int i = 0; i < ile_slow;i++)
	{
		if(skoro[i][0] == 0 )
		{
			printf("Slowo: %s , nie wystapilo w zadnej linii pliku.\n",slowa[i]);
		}
		else
		{
			printf("Slowo: %s , wystapilo w lini(ach): \n",slowa[i]);

			for(int k = 1; k <= skoro[i][0]; k++)
			{
				printf(" %d ",skoro[i][k]);
			}

			printf("\n");
		}
	}

}

