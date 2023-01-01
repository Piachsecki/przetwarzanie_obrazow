#include "obslugaplikow.h"


/************************************************************************************
 * Funkcja wczytuje obraz PGM z pliku do tablicy       	       	       	       	    *
 *										    *
 * \param[in] plik_we uchwyt do pliku z obrazem w formacie PGM			    *
 * \param[out] obraz_pgm tablica, do ktorej zostanie zapisany obraz		    *
 * \param[out] wymx szerokosc obrazka						    *
 * \param[out] wymy wysokosc obrazka						    *
 * \param[out] szarosci liczba odcieni szarosci					    *
 * \return liczba wczytanych pikseli						    *
 ************************************************************************************/

int czytaj(FILE *plik_we,t_obraz *o1) {
  char buf[DL_LINII];      /* bufor pomocniczy do czytania naglowka i komentarzy */
  int znak;                /* zmienna pomocnicza do czytania komentarzy */
  int koniec=0;            /* czy napotkano koniec danych w pliku */
  int i,j;
  
  /*Sprawdzenie czy podano prawidłowy uchwyt pliku */
  if (plik_we==NULL) {
    fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n");
    return(0);
  }

  /* Sprawdzenie "numeru magicznego" - powinien być P2 */
  if (fgets(buf,DL_LINII,plik_we)==NULL)   /* Wczytanie pierwszej linii pliku do bufora */
    koniec=1;                              /* Nie udalo sie? Koniec danych! */

  if ( (buf[0]!='P') || ((buf[1]!='2') && (buf[1]!='3')) || koniec) {  /* Czy jest magiczne "P2" czy P3 */
    fprintf(stderr,"Blad: To nie jest plik PGM\n");
    return(0);
  }
  
  o1->znak=buf[1];

  /* Pominiecie komentarzy */
  do {
    if ((znak=fgetc(plik_we))=='#') {         /* Czy linia rozpoczyna sie od znaku '#'? */
      if (fgets(buf,DL_LINII,plik_we)==NULL)  /* Przeczytaj ja do bufora                */
	koniec=1;                   /* Zapamietaj ewentualny koniec danych */
    }  else {
      ungetc(znak,plik_we);                   /* Gdy przeczytany znak z poczatku linii */
    }                                         /* nie jest '#' zwroc go                 */
  } while (znak=='#' && !koniec);   /* Powtarzaj dopoki sa linie komentarza */
                                    /* i nie nastapil koniec danych         */

    
  //czyscimy pamiec przed pobraniem obrazu pgm lub ppm zeby wykonywac to na nowym obrazie, a nie na jakims poprzednim
  if(o1->r !=NULL)
  {
  	for(i=0;i<=o1->wymy;i++)
  	{
  		free(o1->r[i]);
  	}
  free(o1->r);
  }
    if(o1->g !=NULL)
  {
  	for(i=0;i<=o1->wymy;i++)
  	{
  		free(o1->g[i]);
  	}
  free(o1->g);
  }
  
    if(o1->b !=NULL)
  {
  	for(i=0;i<=o1->wymy;i++)
  	{
  		free(o1->b[i]);
  	}
  free(o1->b);
  }



  if(o1->obraz_pgm !=NULL)
  {
  	for(i=0;i<=o1->wymy;i++)
  	{
  		free(o1->obraz_pgm[i]);
  	}
  free(o1->obraz_pgm);
  }

  /* Pobranie wymiarow obrazu i liczby odcieni szarosci musimy pobrac wymiary i odcien*/
  if (fscanf(plik_we,"%d %d %d",&o1->wymx,&o1->wymy,&o1->szarosci)!=3) 
  {
    fprintf(stderr,"Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
    return(0);
  }
  
  //alokacja pamieci dla obrazu pgm
  if(o1->znak =='2')
  {

  o1->obraz_pgm = (int**)malloc(o1->wymy*sizeof(int*));
  for(i=0;i<o1->wymy;i++)
  {
  	o1->obraz_pgm[i]=(int*)malloc(o1->wymx *sizeof(int));
  }
  /* Pobranie obrazu i zapisanie w tablicy obraz_pgm*/
  for(i=0;i<o1->wymy;i++) 
  {
  	for(j=0;j<o1->wymx;j++)
  	{
  		if(fscanf(plik_we,"%d", &(o1->obraz_pgm[i][j]))!=1)
  		{
  			fprintf(stderr, "Podane wymiary sa nieodpowiednie\n");
  			return(0);
  		}
  	}
  }
  }
  //alokacja pamieci obrazu ppm
  else if(o1->znak =='3')
  {
    o1->r= (int**)malloc(o1->wymy*sizeof(int*));
    o1->g = (int**)malloc(o1->wymy*sizeof(int*));
    o1->b= (int**)malloc(o1->wymy*sizeof(int*));
  for(i=0;i<o1->wymy;i++)
  {
  	o1->r[i]=(int*)malloc(o1->wymx *sizeof(int));
  	o1->g[i]=(int*)malloc(o1->wymx *sizeof(int));
  	o1->b[i]=(int*)malloc(o1->wymx *sizeof(int));
  }
  
  /* Pobranie obrazu i zapisanie*/
  for(i=0;i<o1->wymy;i++) 
  {
  	for(j=0;j<o1->wymx;j++)
  	{
  		if(fscanf(plik_we,"%d %d %d", &(o1->r[i][j]), &(o1->g[i][j]), &(o1->b[i][j]) )!=3) //pobieramy konkretne wartosci pixeli
  		{
  			fprintf(stderr, "Podane wymiary sa nieodpowiednie\n");
  			return(0);
  		}
  	}
  }
  
  }
  
  
  return (o1->wymx)*(o1->wymy);   /* Czytanie zakonczone sukcesem    */
	
	} /* Zwroc liczbe wczytanych pikseli */


/* Wyswietlenie obrazu o zadanej nazwie za pomoca programu "display"   */
void wyswietl(char *n_pliku) {
  char polecenie[DL_LINII];      /* bufor pomocniczy do zestawienia polecenia */

  strcpy(polecenie,"display ");  /* konstrukcja polecenia postaci */
  strcat(polecenie,n_pliku);     /* display "nazwa_pliku" &       */
  strcat(polecenie," &");
  printf("%s\n",polecenie);      /* wydruk kontrolny polecenia */
  system(polecenie);             /* wykonanie polecenia        */
}



 
 void zapis(FILE *plik_wy, t_obraz *o1)
{
	int i, j;
	if(o1->znak=='2')
	{
	fprintf(plik_wy, "P2\n");
	fprintf(plik_wy, "%d %d\n", o1->wymx,o1-> wymy); //zapisujemy do pliku poszczegolne wymiary i odcieni i poszczegolne wartosci pixeli
	fprintf(plik_wy, "%d\n",o1-> szarosci);
	
	for(i=0;i<o1->wymy; i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			fprintf(plik_wy,"%d ", o1->obraz_pgm[i][j]);
		}
		
		fprintf(plik_wy, "\n");
	}
	}
	else
	{
	fprintf(plik_wy, "P3\n");
	fprintf(plik_wy, "%d %d\n", o1->wymx,o1-> wymy); //zapisujemy do pliku poszczegolne wymiary i odcieni i poszczegolne wartosci pixeli
	fprintf(plik_wy, "%d\n",o1-> szarosci);
	
	for(i=0;i<o1->wymy; i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			fprintf(plik_wy,"%d %d %d ", o1->r[i][j], o1->g[i][j], o1->b[i][j]);
		}
		
		fprintf(plik_wy, "\n");
	}
	}

}

int sprawdzenie(FILE *plik_we,t_obraz *o1)
{   
    if(o1->znak=='3')
    	return 1;
    else if(o1->znak=='2')
    	return 2;
  
}
