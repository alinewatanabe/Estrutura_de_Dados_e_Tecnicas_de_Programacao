/* Enunciado:
 *   Desenvolva um programa capaz de ler os valores inteiros de uma matriz 3x3 
 *   e, a seguir, calcule e exiba sua determinante. O cálculo da determinante 
 *   deve ser feito pela função determinante, que recebe por referência uma 
 *   matriz 3x3 e retorna o valor inteiro referente à determinante.
 *
 *   Exemplos: 
 *     Digite a linha 0: 2 3 4
 *     Digite a linha 1: 1 3 4
 *     Digite a linha 2: 5 6 7
 *     -3
 *
 *     Digite a linha 0: 1 0 0
 *     Digite a linha 1: 0 1 0
 *     Digite a linha 2: 0 0 1
 *     1
 *
 */

#include <stdio.h>

#define ARRAY_MAX 3 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
int determinante(int matriz[ARRAY_MAX][ARRAY_MAX]);
void le_array(int array[ARRAY_MAX]);
void le_matriz(int mat[ARRAY_MAX][ARRAY_MAX]);
void exibe_matriz(int mat[ARRAY_MAX][ARRAY_MAX]);


int main (int argc, char *argv[])
{
  int mat[ARRAY_MAX][ARRAY_MAX];


  le_matriz(mat);
  //exibe_matriz(mat);
  printf("%i",determinante(mat));
  return 0;
}

int determinante(int matriz[ARRAY_MAX][ARRAY_MAX]) {
  int det;
  
  det = (matriz[0][0]*matriz[1][1]*matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0]) + (matriz[0][2]*matriz[1][0]*matriz[2][1]) - (matriz[2][0]*matriz[1][1]*matriz[0][2]) - (matriz[2][1]*matriz[1][2]*matriz[0][0]) - (matriz[2][2]*matriz[1][0]*matriz[0][1]);

  return det;
}

void le_array(int array[ARRAY_MAX])
{
  int i = 0;
  printf("Digite os Valores: ");
 
  do 
  {
    scanf(" %i", &array[i]);
    i++;
  } while (i < ARRAY_MAX);

}

void le_matriz(int mat[ARRAY_MAX][ARRAY_MAX])
{
  int lin = 0;
  int col;
  int array[ARRAY_MAX];


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

