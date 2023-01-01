#include "modul1.h"



void negatyw(t_obraz *o1, char kolor)
{
  int i,j;
  if(o1->znak=='2')
 	{
  	for(i=0; i<o1->wymy; i++)
  	{
    		for(j=0; j<o1->wymx; j++)
  		{
  			o1->obraz_pgm[i][j]=o1->szarosci-o1->obraz_pgm[i][j];
 	 	}
  	}
  }
  else  if(o1->znak=='3')
  {
  switch(kolor)
  {
  case 'r':
  {
     for(i=0; i<o1->wymy; i++)
     {
     for(j=0; j<o1->wymx; j++)
     {
     	o1->r[i][j]=o1->szarosci-o1->r[i][j];
     }
     }
  }
   break;
      case 'g':
   {
     for(i=0; i<o1->wymy; i++)
     {
     for(j=0; j<o1->wymx; j++)
     {
     	o1->g[i][j]=o1->szarosci-o1->g[i][j];
     }
     }
  }
   break;
      case 'b':
   {
     for(i=0; i<o1->wymy; i++)
     {
     for(j=0; j<o1->wymx; j++)
     {
     	o1->b[i][j]=o1->szarosci-o1->b[i][j];
     }
     }
  }
   break;
  }
  
  }
}




void konturowanie(t_obraz *o1,char kolor) 
{
  int i,j;
  if(o1->znak=='2')
 	{
 		for(i=0;i<o1->wymy;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			if(i<o1->wymy-1 && j<o1->wymx-1)
			o1->obraz_pgm[i][j] = abs(o1->obraz_pgm[i+1][j] -o1->obraz_pgm[i][j])+ abs(o1->obraz_pgm[i][j+1] -o1->obraz_pgm[i][j]);

	}

  }
  }
	else if(o1->znak =='3')
  {
  switch(kolor)
  {
  case 'r':
  {
	for(i=0;i<o1->wymy;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			if(i<o1->wymy-1 && j<o1->wymx-1)
			o1->r[i][j] = abs(o1->r[i+1][j] -o1->r[i][j])+ abs(o1->r[i][j+1] -o1->r[i][j]);
			
		}
	}
  }
   break;
      case 'g':
   {
	for(i=0;i<o1->wymy;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			if(i<o1->wymy-1 && j<o1->wymx-1)
			o1->g[i][j] = abs(o1->g[i+1][j] -o1->g[i][j])+ abs(o1->g[i][j+1] -o1->g[i][j]);
			
		}
	}
  }
   break;
      case 'b':
   {
	for(i=0;i<o1->wymy;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			if(i<o1->wymy-1 && j<o1->wymx-1)
			o1->b[i][j] = abs(o1->b[i+1][j] -o1->b[i][j])+ abs(o1->b[i][j+1] -o1->b[i][j]);
			
		}
	}
   }
   break;
  }
  
  }
  }






void progowanie(t_obraz *o1, float procent, char kolor)
{
	int i, j;
	int prog = (o1->szarosci*procent)/100;
	if(o1->znak=='2')
	{

	
	for(i=0;i<o1->wymy;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			if(o1->obraz_pgm[i][j] <= prog)
			o1->obraz_pgm[i][j] = 0;
			else
			o1->obraz_pgm[i][j] = o1->szarosci;
		}
	}
	}
	else if(o1->znak =='3')
	{
  switch(kolor)
  {
  case 'r':
  {
	for(i=0;i<o1->wymy;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			if(o1->r[i][j] <= prog)
			o1->r[i][j] = 0;
			else
			o1->r[i][j] = o1->szarosci;
		}
	}
  }
   break;
      case 'g':
   {
	for(i=0;i<o1->wymy;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			if(o1->g[i][j] <= prog)
			o1->g[i][j] = 0;
			else
			o1->g[i][j] = o1->szarosci;
		}
	}
  }
   break;
      case 'b':
   {
	for(i=0;i<o1->wymy;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			if(o1->b[i][j] <= prog)
			o1->b[i][j] = 0;
			else
			o1->b[i][j] = o1->szarosci;
		}
	}
  }
   break;
  }
  
  }
}
		
 





void rozmycie_pionowe(t_obraz *o1, char kolor)
{
  int i,j;
  if(o1->znak=='2')
 	{
 		for(i=1;i<o1->wymy-1;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			o1->obraz_pgm[i][j] = 1.0/3*(o1->obraz_pgm[i-1][j]+o1->obraz_pgm[i][j]+o1->obraz_pgm[i+1][j]) ;
		}
	}

  }
  else  if(o1->znak=='3')
  {
  switch(kolor)
  {
  case 'r':
  {
	for(i=1;i<o1->wymy-1;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			o1->r[i][j] = 1.0/3*(o1->r[i-1][j]+o1->r[i][j]+o1->r[i+1][j]) ;
		}
	}
  }
   break;
      case 'g':
   {
	for(i=1;i<o1->wymy-1;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			o1->g[i][j] = 1.0/3*(o1->g[i-1][j]+o1->g[i][j]+o1->g[i+1][j]) ;
		}
	}
  }
   break;
      case 'b':
   {
	for(i=1;i<o1->wymy-1;i++)
	{
		for(j=0;j<o1->wymx;j++)
		{
			o1->b[i][j] = 1.0/3*(o1->b[i-1][j]+o1->b[i][j]+o1->b[i+1][j]) ;
		}
	}
  }
   break;
  }
  
  }
  }






