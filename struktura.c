#include "struktura.h"


void inicjuj(t_obraz *o1)
{
o1->obraz_pgm=NULL;
o1->wymx=0;
o1->wymy=0;
o1->szarosci=0;
o1->r=NULL;
o1->g=NULL;
o1->b=NULL;
}
//zerujemy wszystkie wartosci poniewaz jak nie sa one wyzerowane to biora one i wskazuja na losowe wartosci - program wyrzuca blad podczas dzialania programy=u
