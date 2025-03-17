#include <stdio.h>

#define TAM_L 3 // NÃO MODIFIQUE
#define TAM_C 6 // NÃO MODIFIQUE

/* 
 * Protótipos das funções - NÃO MODIFIQUE 
 *
 */

// le_matriz deve ler uma matriz de tamanho [TAM_L, TAM_C] linha por linha.
void le_matriz(int matriz[TAM_L][TAM_C]);

// busca_linear deve implementar o algoritmo de busca linear para vetores
// do tamanho [TAM_C]. Recebe como parâmetros o vetor e a chave a ser buscada.
// Retorna -1 se não encontrar nada e o índice da chave se ela for encontrada.
int busca_linear(int vetor[TAM_C], int chave);

// busca_binaria deve implementar o algoritmo de busca binária para vetores
// do tamanho [TAM_C]. Recebe como parâmetros o vetor e a chave a ser buscada.
// Retorna -1 se não encontrar nada e o índice da chave se ela for encontrada.
int busca_binaria(int vetor[TAM_C], int chave);

// verifica_ordenacao deve verificar se um vetor de tamanho [TAM_C] 
// está ordenado em ordem crescente. Se estiver, a função retorna 1.
// Se não estiver, a função retorna 0. Recebe como parâmetro o vetor.
int verifica_ordenacao(int vetor[TAM_C]);

// Outro brinde =)
void exibe_matriz(int matriz[TAM_L][TAM_C]);




int main (int argc, char *argv[]){
  int l[TAM_C];

  le_linha(l);
  
  return 0;
}

int le_linha(int vetor[]){
  int i = 0;
  int entrada;
  int n = 0;

  while(n <= 3){
    switch (n)
    {
    case 0:
      printf("Digite a linha %i: ", n);

    do{
      scanf("%i", &entrada);
      vetor[i] = entrada;
      i++;
    } while(i < TAM_C);
      break;
    
    case 1:
    printf("Digite a linha %i: ", n);

    do{
      scanf("%i", &entrada);
      vetor[i] = entrada;
      i++;
    } while(i < TAM_C);
      break;

    case 2:
    printf("Digite a linha %i: ", n);
    
    do{
      scanf("%i", &entrada);
      vetor[i] = entrada;
      i++;
    } while(i < TAM_C);
      break;

    default:
      break;
    }
    
    n++;
  }
  return 0;
}
  


int busca_binaria(int vetor[TAM_C], int chave){

}

int verifica_ordenacao(int vetor[TAM_C]) {

  return -1;
}

int busca_linear(int vetor[TAM_C], int chave) {
  int i;
  int j;
  int achar = 0;
  for(i = 0; i < TAM_C; i++){
    if(vetor[i] == chave){
      achar = 1;
      break;
    }
  }

  if(achar == 1){
    printf("Chave %d encontrada em [%d,%d]", chave, i,j);
  }

  else{
    printf("Chave %d não foi encontrada", chave);
  }
  return 0;
}

void le_matriz(int matriz[TAM_L][TAM_C]) {
  int mat[TAM_L][TAM_C];
  int i, j;

  for(i=0; i<TAM_L; j++){
    for(j=0;j<TAM_C;j++){
      printf("mat[%i][%i]: ",i,j);
      scanf("%i",&mat[i][j]);
  }
  }
}

void exibe_matriz(int matriz[TAM_L][TAM_C]) {
  printf("[");
  for (int i = 0; i < TAM_L; ++i) { 
    printf("[");
    for (int j = 0; j < TAM_C; ++j) {
      printf("%i", matriz[i][j]);
      if( j < TAM_C - 1) printf(", ");
    }
    printf("]");
    if( i < TAM_L - 1 ) printf(",\n");
  }
  printf("]\n");
}
