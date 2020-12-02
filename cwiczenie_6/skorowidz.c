/* tutaj jest funkcja wypisujaca skorowidz */

#include <stdio.h>

void wypisz_skorowidz(int **skoro,char **slowa, int ile_slow)
{
	int i = 0;
	int k;

	for(; i < ile_slow;i++)
	{
		if(skoro[i][0] == 0 )
		{
			printf("Slowo: \"%s\"  nie wystapilo w lini(ach) pliku.\n",slowa[i]);
		}
		else
		{
			printf("Slowo: \"%s\" wystapilo w lini(ach): \n",slowa[i]);

			k = 1;
			for(; k <= skoro[i][0]; k++)
			{
				printf(" %d ",skoro[i][k]);
			}

			printf("\n");
		}
	}

}

