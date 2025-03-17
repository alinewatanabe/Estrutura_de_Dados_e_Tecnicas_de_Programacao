#include <stdio.h>

#define MAX_ARR 1024 // Não modifique esse valor!!

/* 
 * Protótipos das funções - NÃO MODIFIQUE 
 *
 */

// le_vetor deve ler um vetor até receber o valor -100 ou chegar em MAX_ARR.
// O retorno da função deve ser o tamanho do vetor lido.
int le_vetor(int vetor[MAX_ARR]);

// busca_linear deve receber um vetor, seu tamanho e uma chave a ser buscada.
// A função deve implementar o algoritmo de busca linear.
// Seu retorno deve ser o índice onde a chave for encontrada ou,
// caso não tenha encontrado nada, -1.
int busca_linear(int vetor[MAX_ARR], int tam_vetor, int chave);

// Ganharam essa de brinde. =)
void exibe_vetor(int vetor[MAX_ARR], int tam_vetor);



int main (int argc, char *argv[])
{
  int v[MAX_ARR];
  int chave;
  int tam,i;

  tam = le_vetor(v);
  printf("Chave a ser buscada: ");
  scanf("%i", &chave);
    
  exibe_vetor(v,tam);

  busca_linear(v,tam, chave);

  return 0;
}


int busca_linear(int vetor[MAX_ARR], int tam_vetor, int chave){
  int i;
  int achar = 0;
  for(i = 0; i < tam_vetor; i++){
    if(vetor[i] == chave){
      achar = 1;
      break;
    }
  }

  if(achar == 1){
    printf("Chave %d encontrada na posição %d", chave, i);
  }

  else{
    printf("Chave %d não foi encontrada", chave);
  }
  return 0;
}

int le_vetor(int vetor[MAX_ARR]){
  int i = 0;
  int entrada;

  printf("Digite o vetor: ");

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
