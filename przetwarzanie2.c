#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include "modul1.h"
#include "obslugaplikow.h"
#include "struktura.h"


int main() {
  t_obraz obraz1;
  inicjuj(&obraz1);
  int odczytano;
  FILE *plik;
  char nazwa[20]; 
  int num = 1; // przypisuje jakas wartosc poczatkowa, aby funkcja while wykonala sie
  float procent;
  char kolor;
  while(num!=0)
  {
  	printf("Menu pracy nad plikiem pgm\n");
  	printf("Wpisz 0 aby zakonczyc program:\n");
  	printf("1 opcja - wczytaj\n");
  	printf("2 opcja - zapis\n");
  	printf("3 opcja - wyswietl\n");
  	printf("4 opcja - negatyw\n");
  	printf("5 opcja - progowanie\n");
  	printf("6 opcja - konturowanie\n");
  	printf("7 opcja - rozmycie pionowe\n");
  	printf("Podaj jedna z opcji: ");
  	scanf("%d", &num);
  	
  	switch (num)
  	{
  	case 1:
  	{	
 		printf("Podaj nazwe pliku:\n");
 		scanf("%s",nazwa);
 		plik=fopen(nazwa,"r");
		if ( plik != NULL ) 
		{       
			odczytano = czytaj(plik,&obraz1);
			fclose(plik);
		}
  	}	
  	break;
  	
  	case 2:
  	{
  		if (odczytano != 0)
  		{
 		printf("Podaj nazwe pliku:\n");
  		scanf("%s",nazwa);
  		plik=fopen(nazwa,"w");
  		zapis(plik, &obraz1);
  		}
  	}
  	break;
  	
   	case 3:
  	{
 		if (odczytano != 0)
    		wyswietl(nazwa);
    	 else
    {
    printf("nie wczytano pliku !!\n");
    }
  	}
  	break;
  	
    	case 4:
  	{
 		if (odczytano != 0)
 		{
 			if(sprawdzenie(plik, &obraz1)==1)
 			{
			printf("Podaj weglug jakiego koloru chcesz przetworzyc funkcje: r/g/b\n");
			scanf("%c", &kolor); //2x scanf, poniewaz 1x scanf nie zczytuje tego koloru
			scanf("%c", &kolor);
			negatyw(&obraz1, kolor);
 			plik = fopen("tmp.ppm", "w");
 			zapis(plik, &obraz1);
 			fclose(plik);
 			wyswietl("tmp.ppm");
			}
			else if(sprawdzenie(plik, &obraz1)==2)
			{
			negatyw(&obraz1, kolor);
 			plik = fopen("tmp.pgm", "w");
 			zapis(plik, &obraz1);
 			fclose(plik);
 			wyswietl("tmp.pgm");
 			}
 		}
 		else
 		{
  			printf("Nie wczytano podanego pliku\n");
 		}
  	}
  	break;
  	
    	case 5:
  	{
 		if (odczytano != 0)
 		{
 			printf("Podaj wartosc procentowa wedlug ktorego ma zostac zrobione progowanie\n");
 			scanf("%f", &procent);
			if(sprawdzenie(plik, &obraz1)==1)
 			{
			printf("Podaj weglug jakiego koloru chcesz przetworzyc funkcje: r/g/b\n");
			scanf("%c", &kolor);
			scanf("%c", &kolor);
			progowanie(&obraz1, procent, kolor);
 			plik = fopen("tmp.ppm", "w");
 			zapis(plik, &obraz1);
 			fclose(plik);
 			wyswietl("tmp.ppm");
			}
			else if(sprawdzenie(plik, &obraz1)==2)
			{
			progowanie(&obraz1,procent, kolor);
 			plik = fopen("tmp.pgm", "w");
 			zapis(plik, &obraz1);
 			fclose(plik);
 			wyswietl("tmp.pgm");
 		}
 		else
 		{
  			printf("Nie wczytano podanego pliku\n");
 		}
  	}
  	}
  	break;
 
    	case 6:
  	{
 		if (odczytano != 0)
 		{

 			if(sprawdzenie(plik, &obraz1)==1)
 			{
			printf("Podaj weglug jakiego koloru chcesz przetworzyc funkcje: r/g/b\n");
			scanf("%c", &kolor);
			scanf("%c", &kolor);
			konturowanie(&obraz1, kolor);
 			plik = fopen("tmp.ppm", "w");
 			zapis(plik, &obraz1);
 			fclose(plik);
 			wyswietl("tmp.ppm");
			}
			else if(sprawdzenie(plik, &obraz1)==2)
			{
			konturowanie(&obraz1, kolor);
 			plik = fopen("tmp.pgm", "w");
 			zapis(plik, &obraz1);
 			fclose(plik);
 			wyswietl("tmp.pgm");
 			}
 			}
 		
 		else
 		{
  			printf("Nie wczytano podanego pliku\n");
 		}
  	}
  	break;

    	case 7:
  	{
 		if (odczytano != 0)
 		{
 			if(sprawdzenie(plik, &obraz1)==1)
 			{
			printf("Podaj weglug jakiego koloru chcesz przetworzyc funkcje: r/g/b\n");
			scanf("%c", &kolor);
			scanf("%c", &kolor);
			rozmycie_pionowe(&obraz1, kolor);
 			plik = fopen("tmp.ppm", "w");
 			zapis(plik, &obraz1);
 			fclose(plik);
 			wyswietl("tmp.ppm");
			}
			else if(sprawdzenie(plik, &obraz1)==2)
			{
			rozmycie_pionowe(&obraz1, kolor);
 			plik = fopen("tmp.pgm", "w");
 			zapis(plik, &obraz1);
 			fclose(plik);
 			wyswietl("tmp.pgm");
 		}
 		}
 		else
 		{
  			printf("Nie wczytano podanego pliku\n");
 		}
  	}
  	break;


	
	default:
	
	{
		if(num!=0)
        	printf("Błedna wartosc\n");
        }
        
  
  }
  
  
  }
  
  
// zabezpieczamy dane tworzac plik tymczasowy tmp ktory zapisuje nam poczatkowo obraz po przejsciu przez dana funckje, pozniej go jednak usuwamy za pomoca system("rm tmp.pgm");

	if( access( "tmp.pgm",F_OK  ) == 0 )
	system("rm tmp.pgm");
	else if(access( "tmp.ppm",F_OK  ) == 0 )
	system("rm tmp.ppm");
	

  return odczytano;

}
