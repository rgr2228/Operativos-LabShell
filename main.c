/*
    ejemplo.c
    Ejemplo de uso de la funcion separaItems
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

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
  }
  else{
    printf("No ha ingresado argumentos validos\n");
  }

  //código de función udea-pwd
  /*if (getcwd(expresion, sizeof(expresion)) == NULL)
      printf("Error");
    else
      printf("current working directory is: %s\n", expresion);
      */
      

  //código de función udea-echo
  /*
  if(strcmp(items[0], "udea-echo")==0){
    printf("%s\n",items[1]);
  }*/


  //código de función udea-time
  /*
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ("La hora es: %s",asctime(timeinfo));
  */

  //código de función udea-exit
  //exit(0);
  

      liberaItems (items);
  }


  

  return 0;
}