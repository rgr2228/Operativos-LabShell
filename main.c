/*
    ejemplo.c
    Ejemplo de uso de la funcion separaItems
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

#define TAM 100

int main ()
{
  char ** items;
  int i, num, background;
  char expresion[TAM];
while(1){
  printf ("udea-shell:$ ");
  fgets (expresion, TAM, stdin);
  printf("%s",expresion);


  num = separaItems (expresion, &items, &background);

  printf ("Numero de parametros: %d\n", num);

  if (num>0)
  {
    for (i=0; i<num; i++)
      printf ("%d \"%s\"\n", i+1, items[i]);

    printf ("Background: %d\n", background);

    liberaItems (items);
  }
}
  return 0;
}