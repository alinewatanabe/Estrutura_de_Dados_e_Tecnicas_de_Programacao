/* Enunciado:
 *  Desenvolva um programa capaz de ler os valores de uma matriz m x n. 
 *  A leitura deve ser feita em uma linha para cada linha da matriz (ver ex1).
 *  A condição de parada para a leitura das linhas é uma linha vazia
 *  (apenas com -100). O programa deve assumir que a quantidade de colunas
 *  da primeira linha define a dimensão da matriz, ou seja, qualquer linha 
 *  subsequente que não tenha a mesma quantidade de linhas da linha inicial
 *  deve causar um erro e o encerramento do programa. Após a leitura da matriz,
 *  ela deve ser exibida seguindo o padrão mostrado nos exemplos a seguir.
 *
 *  Exemplos:
 *
 *   Linha 0: 1 1 1 -100
 *   Linha 1: 2 2 2 -100
 *   Linha 2: 3 3 3 -100
 *   Linha 3: -100
 *   [[1, 1, 1],
 *   [2, 2, 2],
 *   [3, 3, 3]]
 *
 *   Linha 0: 1 1 1 1 1 -100
 *   Linha 1: 1 2 3 -100
 *   Número de colunas incompatível. Saindo...
 *
 *   Linha 0: 1 2 3 4 5 6 7 8 -100
 *   Linha 1: 8 7 6 5 4 3 2 1 -100
 *   Linha 2: -100
 *   [[1, 2, 3, 4, 5, 6, 7, 8],
 *   [8, 7, 6, 5, 4, 3, 2, 1]]
 *
 */

#include <stdio.h>

#define ARRAY_MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
int le_array(int array[ARRAY_MAX]);
void le_matriz(int mat[ARRAY_MAX][ARRAY_MAX], int array[ARRAY_MAX],int array2[2]);
void exibe_matriz(int mat[ARRAY_MAX][ARRAY_MAX],int array[2]);

// Função Principal
int main (int argc, char *argv[])
{
  int a[ARRAY_MAX] = {};
  int b[2] = {};
  int mat[ARRAY_MAX][ARRAY_MAX];
  int tam = 0;
  int coluna = 0;

  le_matriz(mat,a,b);
  exibe_matriz(mat,b);

  return 0;
}


// Função que lê o array e devolve o tamanho dele
int le_array(int array[ARRAY_MAX])
{
  int i = 0; 
  int entrada;
  int c = 0;


  do 
  {
    printf("Digite os Valores: ");
    scanf(" %i", &entrada);
    if(entrada == -100) break;
    array[i++] = entrada;
  } while (i< ARRAY_MAX);
  return i;
}

//função que lê a matriz e retorna o numero de colunas dela
void le_matriz(int mat[ARRAY_MAX][ARRAY_MAX], int array[ARRAY_MAX],int array2[2])
{
  int lin = 0;
  int col2;
  int tam1;
  int tam2;

  tam1 = le_array(array);
    
  if (tam1 == 0)
    return 0;
    for (int col = 0; col <= tam1; col++)
    {
      mat[0][col] = array[col];
    }

  for (lin = 1; lin <= tam1; lin++)
  {
    tam2 = le_array(array);
    if (tam1 * tam2 == 0) break;
    if (tam2 != tam1) 
      {
      printf("Número de colunas incompatível. Saindo...");
      tam1 = 0;
      break;
      }   
    for (col2 = 0; col2 <= tam1; col2++)
    {
      mat[lin][col2] = array[col2];
    } 
  }
  array2[0] = tam1;
  array2[1] = (lin);
}

//Função que faz a exibição da matriz
void exibe_matriz(int mat[ARRAY_MAX][ARRAY_MAX],int array[2])
{
  int tam;
  int coluna;

  tam = array[0];
  coluna = array[1];
  if (tam != 0)
  {
  
  printf("[");
  for (int lin = 0; lin < coluna; lin++)
    {
      printf("[");
      for (int col = 0; col < tam; col++)
      {
        printf("%i",mat[lin][col]);
        if(col != tam -1) printf(", ");
      } 
      printf("]");
      if(lin != coluna -1) printf(",\n");
    }
   printf("]");
  }
}