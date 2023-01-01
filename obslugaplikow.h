#ifndef OBSLUGAPLIKOW_H
#define OBSLUGAPLIKOW_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struktura.h"

#define MAX 512            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */

int czytaj(FILE *plik_we,t_obraz *o1);
void wyswietl(char *n_pliku);
void zapis(FILE *plik_wy, t_obraz *o1);
int sprawdzenie(FILE *plik_we, t_obraz *o1);
#endif
