/* kod na wysuzkiwanie slow w linii */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFSIZE 8192

void dodaj (int **skoro, int index_slowa, int nr_linii);

void wyszukaj(FILE *plik, int ile_slow, int **skorowidz, char **slowa) 
{
	char buf[BUFSIZE];
	int d_slow;
	int literka;
	int ktora_linia = 0;
	char * znaki = (char *) malloc (3);
	strcpy(znaki, ",.)(]}{[-_+=!?&%$#@;:><");
	int ile_z = strlen(znaki);


	while( fgets( buf, BUFSIZE, plik ) != NULL )
	{
		ktora_linia++;

		for(int i = 0; i < ile_slow; i++)
		{
			d_slow = strlen(slowa[i]);
                        bool na_poczatku = true;
		      	int n_buf = strlen(buf);
			char *nowy;
			bool na_koncu = true;

		       	/*sprawdzenie czy jest na poczatku*/
			
			if(buf[0]==slowa[i][0])
			{
				if(n_buf >= d_slow)
				{
					for(int k = 1; k < d_slow; k++)
					{
						if(buf[k] != slowa[i][k])
						{	
							na_poczatku = false;
							break;
						}	

					}
					if(d_slow < n_buf && na_poczatku == true) 
					{
						if(!((buf[d_slow]>='a' && buf[d_slow]<= 'z' )|| (buf[d_slow]>='A' && buf[d_slow]<='Z')))
						{
							/*jest na poczatku*/ /*dodaj*/ /*continue*/
							
							  dodaj (skorowidz,i, ktora_linia); 

							
							continue;

						}
					 	na_poczatku = false;
					}
					if(d_slow == n_buf && na_poczatku == true)
					{
						/*jest w linii jedno wlasnie to slowo*/ /*dodaj*/ /*contiune*/
						
						 dodaj (skorowidz,i, ktora_linia); 
			
                                                
						continue;

					}
				}
			}	

			/*tutaj jak dojdzie to znaczy ze nie jest to pierwsze slowo */

			/*sprawdzenie czy slowo jest na koncu */


			else if(buf[n_buf - 2] == slowa[i][d_slow - 1])
			{
				
				if(n_buf > d_slow)
				{
				
				

					int p = n_buf -2;
					int h = d_slow -1;	
					for(; h>=0;)
					{
						if(buf[p] != slowa[i][h])
						{
							na_koncu = false;
							break;
						}
						p--;
						h--;
					}
					

					if(na_koncu== true)
					{	
					 if(!((buf[p]>='a' && buf[p]<= 'z' )|| (buf[p]>='A' && buf[p]<='Z')))
	                                  {
                   	                       /*jest na koncu*/ /*dodaj*/ /*continue*/

						  dodaj (skorowidz,i, ktora_linia); 
						  continue;

                                           }
					}       

					
					
				}	
			
			}

			/*skoro nie jest ani na poczatku ani na koncu to musi byc otoczone innymi znakami*/
			else
			{
					
					nowy = (char*) malloc (2+d_slow);
					
					strcat(nowy, " ");
					strcat(nowy, slowa[i]);
					strcat(nowy, " ");


					if((strstr(buf, nowy))!= NULL)
					{	
						/*znaleziono slowo*/
						/*dodaj*/ 
							
						dodaj (skorowidz,i, ktora_linia); 
						continue;
					}
					int nowy_roz = strlen(nowy);
					for(int y= 0; y<ile_z; y++)
					{
						nowy[nowy_roz -1] = znaki[y];
						if((strstr(buf, nowy))!=NULL)
						{
							dodaj(skorowidz, i, ktora_linia);
							break;
						}
					}
		
			
					free(nowy);
				
			}
		}		

	
	}	

	free(znaki);
		
	fclose(plik);
}

void dodaj (int **skoro, int index_slowa, int nr_linii)
{
	int ile_linii = skoro[index_slowa][0];


	skoro[index_slowa][ile_linii+1] = nr_linii; /* zapisanie nr linii na ostatnie pole */

	skoro[index_slowa][0]++; /* zwiekszenie liczby nr linii w liczniku */

}
