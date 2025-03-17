#include <stdio.h>

#define ARR_SIZE 10

/*** Prototipos ***/
int le_vetor(int vetor[ARR_SIZE]);
void exibe_vetor(int vetor[ARR_SIZE], int tam_vetor);
int bubble_sort(int vetor[ARR_SIZE], int tam_vetor,int chave);
int busca_binaria(int vetor[ARR_SIZE], int chave);

int main (int argc, char *argv[])
{ int chave;
  int v[ARR_SIZE] = {},tam,posi;

  tam = le_vetor(v);
  exibe_vetor(v,tam);
  
  printf("Valor a ser buscado: ");
  scanf("%i",&chave);

  posi = bubble_sort(v,tam,chave);
  printf("%i",posi);
  exibe_vetor(v,tam);

  if(posi == -1)
  {
    printf("Valor %i não foi encontrado!",chave);
    return 0;
  }
  printf("Valor %i encontrado no índice %i",chave,(posi));

  return 0;
}

void exibe_vetor(int vetor[ARR_SIZE], int tam_vetor) {
  printf("[");
  for (int i = 0; i < (tam_vetor); i++) {
    printf("%i", vetor[i]);
    if ( i < tam_vetor - 1 ) printf(", ");
  }
  printf("]\n");
}

int le_vetor(int vetor[ARR_SIZE]) {
  int i = 0, entrada;
  printf("Digite os Valores: ");
  do 
  {
    scanf(" %i", &entrada);
    vetor[i++] = entrada;
  } while (i < ARR_SIZE);
  return i;
}

int bubble_sort(int vetor[ARR_SIZE], int tam_vetor,int chave) 
{
  int aux;
  int posi = -1;

  for (int i = tam_vetor - 1; i >= 1; i--)
  {
    for (int j = 0; j < (i - 1); j++)
    {
      if (vetor[j] == chave) posi = j;
      if(vetor[j] > vetor[j + 1])
      {
        aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = aux;
      }
    } 
  }
  return posi;
}

int busca_binaria(int vetor[ARR_SIZE], int chave) {
  int pos_ini,pos_fim,pos_meio;

  pos_ini = 0;
  pos_fim = ARR_SIZE;
  pos_meio = pos_fim / 2;

  do
  {
    if (vetor[pos_meio] < chave)
    {
      pos_ini = pos_meio + 1;
      pos_meio = (pos_fim + pos_ini )/ 2;
      if (vetor[pos_meio] == chave) return pos_meio;
    }
    if (vetor[pos_meio] > chave)
    {
      pos_fim = pos_meio;
      pos_meio = (pos_fim + pos_ini )/ 2;
      if (vetor[pos_meio] == chave) return pos_meio;
    }
  } while (pos_fim != pos_ini );
  

  return -1;
}