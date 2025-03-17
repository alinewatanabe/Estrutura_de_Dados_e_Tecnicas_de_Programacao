#include <stdio.h>

/* Enunciado - Faça um programa que leia uma data no seguinte formato:
 * D/M/A. O programa deve determinar se a data digitada válida ou não.
 * Lembre-se que Fevereiro tem 29 dias em anos bissextos e 28 dias em anos não
 * bissextos.
 *
 * Exemplos:
 *
 * Data: 22/02/2022
 * Data valida!
 *
 * Data: 29/02/2020
 * Data valida!
 *
 * Data: 29/02/2022
 * Data invalida!
 *
 * Data: 31/06/2022
 * Data invalida!
 *
 * Data: 31/13/2022
 * Data invalida!
 */

int main (int argc, char *argv[])
{
  int dia;
  int mes;
  int ano;


  printf("Data: ");
  scanf("%i/%2i/%i", &dia, &mes, &ano);


  if ((mes < 1) || (mes > 12) || (dia < 1) || (dia > 31) || ((dia >= 30) && ((mes == 04) || (mes == 06) || (mes == 9) || (mes == 11))) ){
   printf("Data invalida!");
  }
  
  else{
    if(((ano%4 == 0) || (ano%400 == 0)) && (ano%100 != 0)){
      printf("Data valida!");
    }

    else{
      if((mes == 02) && (dia >= 29)){
        printf("Data invalida!");
      }
      else{
        printf("Data valida!");
      }
    }
  }

  return 0;
}

