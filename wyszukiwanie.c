/* kod na wysuzkiwanie slow w linii */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 8192

void dodaj (int **skoro, int index_slowa, int nr_linii);

void wyszukaj(FILE *plik, int ile_slow, int **skorowidz, char **slowa) 
{
	char buf[BUFSIZE];
	int d_slow;
	int literka;
	int ktora_linia = 0;


	while( fgets( buf, BUFSIZE, plik ) != NULL )
	{
		ktora_linia++;

		for(int i = 0; i < ile_slow; i++)
		{
			 d_slow = strlen(slowa[i]);
                         literka = 0;

			for(int j = 0; j < strlen(buf); j++)
			{
	
				if(literka < d_slow)
				{
					if(buf[j] == slowa[i][literka])
					{
						if(literka == 0)
						{
							if(j == 0)
							{
								literka++;
							}
							else 
							{
								if((buf[j-1] >= 'a' && buf[j-1] <= 'z') || (buf[j-1] >= 'A' && buf[j-1] <= 'Z'))
								{
									literka = 0;
								}
								else
								{
									literka++;
								}
							}
						
						}
						
						if(literka == d_slow-1)
                                                {
                                                        if(j == strlen(buf)-1)
                                                        {
                                                        	dodaj (skorowidz , i , ktora_linia);

							}
							else
							{
								if((buf[j+1] >= 'a' && buf[j+1] <= 'z') || (buf[j+1] >= 'A' && buf[j+1] <= 'Z'))
                                                                {
                                                                        literka = 0;
                                                                }
                                                                else
                                                                {
                                                                         dodaj (skorowidz , i , ktora_linia);
                                                                }

							}
                                                }

						literka++;
	
					}
					else
					{
						literka = 0;	

					}
				}
			}		
		
		}

	}	



	
}

void dodaj (int **skoro, int index_slowa, int nr_linii)
{
	int ile_linii = skoro[index_slowa][0];

	skoro[index_slowa] = realloc(skoro[index_slowa], sizeof(int)*(ile_linii + 1));
	/* chyba reallokuje pamiec poprzedniego zwiekszajac o jeden zarezerwowane miejsce */

	skoro[index_slowa][ile_linii+1] = nr_linii; /* zapisanie nr linii na ostatnie pole */

	skoro[index_slowa][0]++; /* zwiekszenie liczby nr linii w liczniku */

}
