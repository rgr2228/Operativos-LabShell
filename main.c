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

int main()
{
  char **items;
  int i, num, background;
  char expresion[TAM];

  char path[25]="/bin/";
  while (1)
  {
    printf("\nudea-shell:$ ");
    fgets(expresion, TAM, stdin);

    num = separaItems(expresion, &items, &background);


    if (num > 0)
    {
      if (strcmp(items[0], "udea-pwd") == 0)
      {
        if (getcwd(expresion, sizeof(expresion)) == NULL)
          printf("Error");
        else
          printf("current working directory is: %s\n", expresion);
      }
      if (strcmp(items[0], "udea-echo") == 0)
      {
        for (i = 1; i < num; i++)
          printf("%s ", items[i]);
        printf("\n");
      }
      if (strcmp(items[0], "udea-time") == 0)
      {
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        printf("La hora es: %s", asctime(timeinfo));
      }
      if(strcmp(items[0], "udea-exit") == 0){
        exit(0);
      }
      if(strcmp(items[0], "udea-clr") == 0){
        printf("\033[H\033[J");
      }
      if(strcmp(items[0], "udea-cd") == 0){
        char s[100];
        printf("%s\n", getcwd(s, 100));
        chdir(items[1]);
        printf("%s\n", getcwd(s, 100)); 
      }
      else{        
        int estado;
        pid_t chid;
        int ret;
        if((chid = fork()) == 0){
          char *args[num+1];
          strcat(path,items[0]);
          args[0] = path;
          for(int i=1;i<num;i++){
            args[i]=items[i];
            printf("%s",items[i]);
            printf("\n%s",args[i]);
          }
          args[num]= NULL;
          ret = execv(path,args); 
          if(ret<0){
          printf("Ha ocurrido un error ejecutando el programa\n");
        }
          printf("ret= %d",ret);
          liberaItems(args);
        }
        if(!background){
          wait(&estado);
        }
      }
    }
    else
    {
      printf("No ha ingresado argumentos validos\n");
    }
    liberaItems(items);
  }

  return 0;
}