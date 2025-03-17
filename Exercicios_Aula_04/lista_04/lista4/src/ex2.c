/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler n valores inteiros e os insira em um 
 * array. A leitura deve ser feita de acordo com o programa feito no ex1. 
 * Após a leitura, desenvolva a função calcula_media e calcula_dvp 
 * para calcular a média e o desvio padrão dos valores informados. 
 * O programa principal deve receber os valores lidos pelo array e retornar a 
 * média e o desvio padrão no seguinte formato: MÉDIA +- DVP
 *
 * Exemplos:
 *    Digite os valores para o array: 1 2 3 4 5 6 7 -100
 *    4.00 +- 1.7
 *
 *    Digite os valores para o array: 1 1 1 1 1 1 1 1 1 1 1 -100
 *    1.00 +- 0.0
 *
 *    Digite os valores para o array: 10 20 1 40 50 90 100 -100
 *    44.43 +- 29.8
 *
 */

#include <stdio.h>
#include <math.h> // A biblioteca math tem pow e sqrt

#define ARRAY_MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
int array[];
int le_array(int array[]);
float calcula_media(int array[], int tam_array);
float calcula_dvp(int array[], int tam_array);

/************ PROGRAMA PRINCIPAL ************/
int main (int argc, char *argv[]){
  int a[ARRAY_MAX] = {};
  int tam;
  float md;
  float dvp;

  tam = le_array(a);
  md = calcula_media(a,tam);
  dvp = calcula_dvp(a,tam);

  // printf("Desvio = %.1f\n\n", dvp);
  printf("%.2f +- %.1f",md,calcula_dvp(a,tam));

  return 0;
}
/************ ******** ********* ************/

float calcula_dvp(int array[], int tam_array){
  float dvp;
  float soma2;

  for (int i = 0; i < tam_array; i++){
    soma2 += pow(array[i] - calcula_media(array,tam_array),2);
  }
  dvp = sqrt(soma2/(float)(tam_array));

  return dvp;
}

int le_array(int array[]){
  int entrada = 0;
  int i = 0;

  printf("Digite os valores para o array: ");


  while(entrada != -100){
    scanf("%i", &entrada);
    if(entrada != -100){
      array[i] = entrada;
      i++;
    }
  }

  return i;
}

float calcula_media(int array[], int tam_array){
 float soma = 0;
 float media;

  for (int i = 0; i < tam_array; i++){
    soma += array[i];
  }

  media = soma/tam_array;
  // printf("\n\nMedia = %.2f", media);

  return media;
}