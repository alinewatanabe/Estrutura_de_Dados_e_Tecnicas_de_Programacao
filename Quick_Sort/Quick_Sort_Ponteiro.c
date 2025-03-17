#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 10

// Protótipos
int le_vetor(int vetor[MAX_ARR]);
void exibe_vetor(int vetor[MAX_ARR], int tam_vetor);
void quicksort(int *V, int inicio, int fim);
int particiona( int *V, int inicio, int final);


/****** Inicio do Programa Principal ******/
int main (int argc, char *argv[])
{
  int vetor[MAX_ARR]={};
  int tam;
  
  tam = le_vetor(vetor);
  exibe_vetor(vetor,tam);
  quicksort(vetor,-1, tam);
  exibe_vetor(vetor, tam);
  return 0;
}
/******  Fim do Programa Principal  ******/


int le_vetor(int vetor[MAX_ARR]) { 
  int i = 0, entrada;
  printf("Digite os Valores: ");
  do{
    scanf(" %i", &entrada);
    vetor[i++] = entrada;
  } while (i< MAX_ARR);
  return i;
}

void exibe_vetor(int vetor[MAX_ARR], int tam_vetor) {
  printf("[");
  for (int i = 0; i < tam_vetor; i++) {
    printf("%i", vetor[i]);
    if ( i < tam_vetor - 1 ) printf(", ");
  }
  printf("]\n");
}

void quicksort(int V[MAX_ARR], int inicio, int fim){
    int pivo;

    if(fim > inicio){
    pivo = particiona(V, inicio, fim);
    quicksort(V, inicio, pivo - 1);
    quicksort(V, pivo + 1, fim);
    }
}

int particiona( int V[MAX_ARR], int inicio, int final){
    int esq;
    int dir;
    int pivo;
    int aux;

    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while(esq < dir){
        while(V[esq] <= pivo){
            esq++;
        }
        while(V[dir] > pivo){
            dir--;
        }
        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;

    return dir;
}
