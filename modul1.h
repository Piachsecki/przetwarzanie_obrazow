#ifndef MODUL1_H
#define MODUL1_H
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <assert.h>
#include"struktura.h"


void negatyw (t_obraz *o1, char kolor);
void konturowanie (t_obraz *o1, char kolor);
void progowanie (t_obraz *o1, float procent, char kolor);
void rozmycie_pionowe(t_obraz *o1, char kolor);

#endif

