#include <stdio.h>

#define MAX_ARR 1024 // Não modifique esse valor!!

int le_vetor(int vetor[MAX_ARR]);
void troca_elementos(int vetor[MAX_ARR], int i, int j);
int particiona(int vetor[MAX_ARR], int comeco, int fim);
void quicksort(int vetor[MAX_ARR], int tam_vetor, int comeco, int fim);
void exibe_vetor(int vetor[MAX_ARR], int tam_vetor);
int fatorial(int n);

int main (int argc, char *argv[]){

  //int vetor[MAX_ARR];
  int vetor[] = {5, 25, 12, 2, 8, 9, 7, 13, 2, 11};
  int tamanho = 10;

  tamanho = le_vetor(vetor);
  quicksort(vetor,tamanho,0,tamanho-1);
  
  exibe_vetor(vetor,tamanho);
  
  return 0;
}

void quicksort(int vetor[MAX_ARR], int tam_vetor, int comeco, int fim) {
  int p;
  printf(">> Quicksort(começo = %i, fim = %i). Vetor = ",comeco,fim);
  exibe_vetor(vetor,tam_vetor);
  if(comeco < fim){
    p = particiona(vetor,comeco,fim);
    quicksort(vetor,tam_vetor,comeco,p-1);
    quicksort(vetor,tam_vetor,p+1,fim);
  }
  printf("** Quicksort(começo = %i, fim = %i). Vetor = ",comeco,fim);
  //exibe_vetor(vetor,tam_vetor);
}

int particiona(int vetor[MAX_ARR], int comeco, int fim) {
  int pivo, i,j = comeco;
  pivo = (comeco + fim)/2;
  troca_elementos(vetor,pivo,fim);
  for(i=comeco;i<fim;i++){
    if(vetor[i] < vetor[fim]){
      troca_elementos(vetor,i,j);
      j++;
    }
  }
  troca_elementos(vetor,fim,j);
  return j;
}

void troca_elementos(int vetor[MAX_ARR], int i, int j) {
  int aux;
  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

void exibe_vetor(int vetor[MAX_ARR], int tam_vetor) {
  printf("[");
  for (int i = 0; i < tam_vetor; i++) {
    printf("%i", vetor[i]);
    if ( i < tam_vetor - 1 ) printf(", ");
  }
  printf("]\n");
}

int le_vetor(int vetor[MAX_ARR]) {
  int valor = 0, i = 0;
  printf("Digite um vetor: ");
  while( (valor != -100) && (i<MAX_ARR) ){
    scanf("%i",&valor);
    if(valor != -100){
      vetor[i] = valor;
      i++;
    }
  }
  return i;
}

int fatorial(int n){
  int fat = 0;
  if(n==0){
    return 1;
  }
  else{
    printf("Entrando no fatorial(%i-1)\n",n);
    fat = fatorial(n-1);
    printf("fat = %i\n",fat);
    return n*fat;
  }
}