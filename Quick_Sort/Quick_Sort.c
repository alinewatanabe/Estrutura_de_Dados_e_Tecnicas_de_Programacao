#include <stdio.h>
#define MAX_ARR 10

// Protótipos
int le_vetor(int vetor[MAX_ARR]);
void exibe_vetor(int vetor[MAX_ARR], int tam_vetor);
void quick_sort(int vetor[MAX_ARR], int esq, int dir);
int dividir(int vetor[MAX_ARR], int esq, int dir);

/****** Inicio do Programa Principal ******/
int main (int argc, char *argv[]){
  int vetor[MAX_ARR]={};
  int tam;
  
  tam = le_vetor(vetor);
  exibe_vetor(vetor, tam);
  quick_sort(vetor,0,MAX_ARR);
  exibe_vetor(vetor, tam);
}
/******  Fim do Programa Principal  ******/


int le_vetor(int vetor[MAX_ARR]) { 
  int i = 0;
  int entrada;

  printf("Digite os valores do vetor: ");

  while((entrada != -100) && (i<MAX_ARR)){
    scanf("%i",&entrada);
    if(entrada != -100){
      vetor[i] = entrada;
      i++;
    }
  }
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

void quick_sort(int vetor[MAX_ARR], int esq, int dir){
    int pos;
    if(esq < dir){
        pos = dividir(vetor, esq, dir);
        quick_sort(vetor,esq, pos - 1);
        quick_sort(vetor, pos + 1, dir);
    }
}

int dividir(int *vetor, int esq, int dir){
    int aux;
    int cont = esq;
    for(int i = esq + 1; i <= dir; i++){
        if(vetor[i] < vetor[esq]){
            cont++;
            aux = vetor[i];
            vetor[i] = vetor[cont];
            vetor[esq] = aux;
        }
    }

    aux = vetor[esq];
    vetor[esq] = vetor[cont];
    vetor[cont] = aux;

}