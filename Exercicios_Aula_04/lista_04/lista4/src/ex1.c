/* Enunciado: Desenvolva um programa capaz de ler n valores inteiros e os
 *  insira em um array. A leitura deve ser feita em uma única linha, separando 
 *  os valores por espaço. A leitura deve ser encerrada quando um 
 *  valor -100 é lido. Após a leitura ser realizada, o programa deve utilizar 
 *  o procedimento exibe_array para exibir o array em uma única linha 
 *  e entre colchetes.
 *
 *  Exemplos:
 *    Digite os valores para o array: 1 2 3 4 5 6 7 8 -100
 *    [1, 2, 3, 4, 5, 6, 7, 8]
 *
 *    Digite os valores para o array: 1 2 3 4 -100
 *    [1, 2, 3, 4]
 *
 */

#include <stdio.h>

#define ARRAY_MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
int le_array(int array[]);
void exibe_array(int array[], int tam_array);


/************ PROGRAMA PRINCIPAL ************/
int main (int argc, char *argv[]){

int vetor[ARRAY_MAX] = {};
int tam;

printf("Digite os valores para o array: ");
tam = le_array(vetor);
exibe_array(vetor,tam);
}

/************ ******** ********* ************/

int le_array(int array[]){
  int entrada = 0;
  int i = 0;

  while(entrada != -100){
    scanf("%i", &entrada);
    if(entrada != -100){
      array[i] = entrada;
      i++;
    }
  }

  return i;
}

void exibe_array(int array[], int tam_array){
  printf("[");
  for(int i = 0; i < tam_array; i++){
    printf("%i", array[i]);
    if(i == tam_array - 1){
      continue;
    }
    printf(", ");
  }
  printf("]");
}