/* 
 * Enunciado: 
 * Implemente um programa que permita a entrada de valores de um array cujo 
 * tamanho máximo é definido pela constante MAX. A quantidade de valores 
 * armazenado no vetor será definida pelo usuário (quando digitar -100, a 
 * leitura para). É obrigatório o uso da subrotina ler_vetor, que recebe como 
 * parâmetros um ponteiro que aponta para o início do vetor e um ponteiro para 
 * um valor inteiro que representa o tamanho real do vetor.
 *
 * Exemplos:
 *
 * Digite os valores do vetor: 1 2 3 4 5 6 7 -100
 * [1, 2, 3, 4, 5, 6, 7]
 *
 */

#include <stdio.h>

#define MAX 100
void ler_vetor(int *v, int *tam);
void exibe_vetor(int *v, int tam);

int main (int argc, char *argv[]){
  int vet[MAX];
  int tamanho;
  
  
  ler_vetor(vet, &tamanho);
  exibe_vetor(vet,tamanho);


  return 0;
}

void ler_vetor(int *v, int *tam){
  int entrada;
  printf("Digite os valores do vetor: ");
  for(*tam = 0;*tam <= MAX; ++(*tam)){
    scanf("%i", &entrada);
    if(entrada != -100){
      *(v + (*tam)) = entrada;
    }
    else{
      break;
    }

  }
 
}

void exibe_vetor(int *v, int tam) {
  printf("[");
  for(int i = 0; i < tam; ++i) {
    printf("%i", *(v+i));
    if(i != tam - 1) printf(", ");
  }
  printf("]\n");
}
