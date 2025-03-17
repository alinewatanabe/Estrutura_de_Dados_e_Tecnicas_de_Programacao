/* Enunciado:
 *  Desenvolva um programa capaz de ler dois vetores com três elementos
 *  inteiros cada. A leitura deve ser feita em uma única linha para cada vetor,
 *  com os elementos separados por espaços. Após a leitura, o programa
 *  deve exibir o produto escalar entre os vetores digitados no formato
 *  exemplificado abaixo. O cálculo do produto escalar deve obrigatoriamente
 *  ser feito pela função produto_escalar, que recebe como referência os
 *  dois arrays e retorna um valor inteiro referente ao resultado do produto
 *  escalar.
 *
 *  Exemplos:
 *      Digite o primeiro array: 1 2 3
 *      Digite o segundo array: 3 2 1
 *      [1, 2, 3] . [3, 2, 1] = 10
 *      
 *      Digite o primeiro array: 10 20 30
 *      Digite o segundo array: -10 2 5
 *      [10, 20, 30] . [-10, 2, 5] = 90
 *
 */

#include <stdio.h>
#include <math.h>

#define ARRAY_MAX 3 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
int produto_escalar(int array[], int array2[]);
int le_array(int array[]);
int exibe_produto_escalar(int array[]);

/*Programa Principal*/
int main (int argc, char *argv[]){
  int v1[ARRAY_MAX] = {};
  int v2[ARRAY_MAX] = {};
  int a;

  le_array(v1);
  le_array(v2);
  a = produto_escalar(v1,v2);
  printf("Produto Escalar = %i", a);
  exibe_produto_escalar(v1);
  printf(" . ");
  exibe_produto_escalar(v2); 
  printf(" = ");
  printf("%i", a);

  return 0;
}

int produto_escalar(int array[], int array2[]){
  int i = 0;
  int S = 0;
  
  for(i; i < ARRAY_MAX; i++){
    // printf("\n\nANTES DA SOMA: \n\n");
    // printf("o i vale %i\n", i);
    // printf("o array[%i] vale %i = %i\n", i, array[i]);
    // printf("o array2[%i] vale %i = %i\n", i, array2[i]);
    // printf("O S vale %i\n\n", S);
    S += array[i]*array2[i];
    // printf("\n\nDEPOIS DA SOMA: \n\n");
    // printf("O S vale %i", S);
  }

  return S;
}

int le_array(int array[ARRAY_MAX]){
  int i = 0, entrada;
  printf("Digite o array: ");
  do{
    scanf(" %i", &entrada);
    array[i++] = entrada;
  } while (i< ARRAY_MAX);
}


int exibe_produto_escalar(int array[]){
  printf("[%i, %i, %i]", array[0],array[1],array[2]);
}