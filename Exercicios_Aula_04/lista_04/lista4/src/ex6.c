/* Enunciado:
 * Desenvolva um programa capaz de ler os valores inteiros de uma matriz 3x3 
 * e, a seguir, exiba a sua forma transposta
 *
 * Exemplos: 
 *
 *
 *    Digite a linha 0: 1 2 3
 *    Digite a linha 1: 4 5 6
 *    Digite a linha 2: 7 8 9
 *    [[1, 4, 7],
 *    [2, 5, 8],
 *    [3, 6, 9]]
 *    
 *    Digite a linha 0: 1 0 0
 *    Digite a linha 1: 0 1 0
 *    Digite a linha 2: 0 0 1
 *    [[1, 0, 0],
 *    [0, 1, 0],
 *    [0, 0, 1]]
 *    
 */

#include <stdio.h>

#define ARRAY_MAX 3 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void le_array(int array[ARRAY_MAX]);
void le_matriz(int mat[ARRAY_MAX][ARRAY_MAX]);
void exibe_matriz(int mat[ARRAY_MAX][ARRAY_MAX]);
void exibe_matriz_transposta(int mat[ARRAY_MAX][ARRAY_MAX]);

int main (int argc, char *argv[])
{

  int mat[ARRAY_MAX][ARRAY_MAX];
  le_matriz(mat);
  exibe_matriz_transposta(mat);

  return 0;
}

void le_array(int array[ARRAY_MAX])
{
  int i = 0;
  printf("Digite os Valores: ");
 
  do 
  {
    scanf(" %i", &array[i]);
    i++;
  } while (i< ARRAY_MAX);

}

void le_matriz(int mat[ARRAY_MAX][ARRAY_MAX])
{
  int lin = 0,col,array[ARRAY_MAX];


  for (lin = 0; lin < ARRAY_MAX; lin++)
  {
    le_array(array);
    for (col = 0; col < ARRAY_MAX; col++)
    {
      mat[lin][col] = array[col];
    } 
  }
}

void exibe_matriz(int mat[ARRAY_MAX][ARRAY_MAX])
{
  
  
  printf("[");
  for (int lin = 0; lin < ARRAY_MAX; lin++)
    {
      printf("[");
      for (int col = 0; col < ARRAY_MAX; col++)
      {
        printf("%i",mat[lin][col]);
        if(col != ARRAY_MAX -1) printf(", ");
      } 
      printf("]");
      if(lin != ARRAY_MAX -1) printf(",\n");
    }
   printf("]");
  
}

void exibe_matriz_transposta(int mat[ARRAY_MAX][ARRAY_MAX])
{
  
  printf("[");
  for (int col = 0; col < ARRAY_MAX; col++)
    {
      printf("[");
      for (int lin = 0; lin < ARRAY_MAX; lin++)
      {
        printf("%i",mat[lin][col]);
        if(lin != ARRAY_MAX -1) printf(", ");
      } 
      printf("]");
      if(col != ARRAY_MAX -1) printf(",\n");
    }
   printf("]");
  
}