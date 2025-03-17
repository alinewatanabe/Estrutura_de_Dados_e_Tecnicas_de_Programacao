#include <stdio.h>

/* Enunciado:
 *
 * Elabore um programa que leia os valores de duas resistencias eletricas (int)
 * e, em seguida, exiba o resultado da sua resistencia equivalente em serie
 * e em paralelo. O formato da saida deve ser:
 *
 * S: **Req_Serie** P: **Req_Paralelo**
 *
 *
 * Ex:
 *      R1: 3
 *      R2: 3
 *      S: 6 P: 1.50
 *
 *      R1: 5
 *      R2: 12
 *      S: 17 P: 3.86
 *
 * OBS: Utilize duas casas decimais para representar valores flutuantes.
 */

int main (int argc, char *argv[])
{
  int R1;
  int R2;
  int S;
  float M;
  float P;

  printf("R1: ");
  scanf("%i", &R1);
  
  printf("R2: ");
  scanf("%i", &R2);

  S = R1 + R2;
  M = R1*R2;
  P = M/S;

  printf("S: %i P: %.2f", S,P);

  return 0;
}
