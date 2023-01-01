#ifndef STRUKTURA_H //przed wielokrotnym czytaniem, 2 razy zeby nie czytal biblioteki 
#define STRUKTURA_H
#include<stdio.h>
#include<stdlib.h>

#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */


typedef struct obraz
{
	int znak; //znak magiczny- P2/P3
	int wymx;
	int wymy;
	int szarosci;
	int **obraz_pgm;
	int **r;
	int **g;
	int **b;

}t_obraz;

void inicjuj(t_obraz *o1);
#endif
