#include <stdio.h>

#define MAX_ARR 1024 // Não modifique esse valor!!

/* 
 * Protótipos das funções - NÃO MODIFIQUE 
 *
 */

// le_vetor deve ler um vetor até receber o valor -100 ou chegar em MAX_ARR.
// O retorno da função deve ser o tamanho do vetor lido.
int le_vetor(int vetor[MAX_ARR]);

// selection_sort deve ordernar um vetor de tamanho MAX_ARR. 
// Recebe como parametros o vetor, seu tamanho e se a ordenação será crescente.
void selection_sort(int vetor[MAX_ARR], int tam_vetor, int crescente);

// bubble_sort deve ordernar um vetor de tamanho MAX_ARR. 
// Recebe como parametros o vetor, seu tamanho e se a ordenação será crescente.
void bubble_sort(int vetor[MAX_ARR], int tam_vetor, int crescente);

// troca_elementos deve receber um vetor e dois índices e trocar os troca 
// os elementos do vetor de lugar.
void troca_elementos(int vetor[MAX_ARR], int i, int j);

// Ganharam essa de brinde. =)
void exibe_vetor(int vetor[MAX_ARR], int tam_vetor);

int main (int argc, char *argv[])
{
  int vetor[MAX_ARR];
  int sel;
  int sentido;
  int tam;

  tam = le_vetor(vetor);
  exibe_vetor(vetor, tam);
  printf("Selecione o método de ordenação (1 - Selection, 2 - Bubble): ");
  scanf("%d", &sel);
  if(sel == 1){
    printf("Ordenação crescente (1) ou descrescente (0): ");
    scanf("%d", &sentido);
    selection_sort(vetor, tam,sentido);
  }
  else if(sel == 2){
    printf("Ordenação crescente (1) ou descrescente (0): ");
    scanf("%d", &sentido);
    bubble_sort(vetor, tam, sentido);
  }
  exibe_vetor(vetor, tam);

  return 0;
}

void troca_elementos(int vetor[MAX_ARR], int i, int j) {

}

void selection_sort(int vetor[MAX_ARR], int tam_vetor, int crescente) {
  int i;
  int j; 
  int menor;
  int maior;
  int aux;

  if(crescente == 1){
    for(i = 0; i < tam_vetor - 1; i++){
      menor = i;
      for(j = i+1; j < tam_vetor; j++){
        if(vetor[j] < vetor[menor]){
          menor = j;
        }
      }
      if(i != menor){
      aux = vetor[i];
      vetor[i] = vetor[menor];
      vetor[menor] = aux;
      }
    }
  }

  else if(crescente == 0){
    for(i = 0; i < tam_vetor - 1; i++){
      maior = i;
      for(j = i+1; j < tam_vetor; j++){
        if(vetor[j] > vetor[maior]){
          maior = j;
        }
      }
      if(i != maior){
      aux = vetor[i];
      vetor[i] = vetor[maior];
      vetor[maior] = aux;
      }
    }
  }
}

void bubble_sort(int vetor[MAX_ARR], int tam_vetor, int crescente){
  int i;
  int contador = 1;
  int aux;

  if(crescente == 1){
    for(contador; contador < tam_vetor; contador++){
      for(i = 0; i < tam_vetor - 1; i++){
        if(vetor[i] > vetor[i + 1]){
          aux = vetor[i];
          vetor[i] = vetor[i + 1];
          vetor[i + 1] = aux;
        }
      }
    }
  }

  else if(crescente == 0){
    for(contador; contador < tam_vetor; contador++){
      for(i = tam_vetor; i > 0; i--){
        if(vetor[i] > vetor[i - 1]){
          aux = vetor[i];
          vetor[i] = vetor[i - 1];
          vetor[i - 1] = aux;
        }
      }
    }
  }
}

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
