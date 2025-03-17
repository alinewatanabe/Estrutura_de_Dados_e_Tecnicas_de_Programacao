#include <stdio.h>

/* Enunciado:
 *
 * Elabore um programa que leia um valor monetario (int) a ser pago e retorne
 * a solucao otimizada para quantas notas de 50, 10 e 2 sao necessarias para
 * compor aquele valor monetario, alem do troco necessario.
 *
 * Formato da saida:
 *  N50: **qtd_50** N10: **qtd_10** N2: **qtd_2** T: **troco**
 *
 *
 * Ex:
 *      Total: 60
 *      N50: 1 N10: 1 N2: 0 T: 0
 *
 *      Total: 85
 *      N50: 1 N10: 3 N2: 2 T: 1
 *
 *      Total: 171
 *      N50: 3 N10: 2 N2: 0 T: 1
 *
 */

int main (int argc, char *argv[])
{
  int Total;
  int N50;
  int N10;
  int N2;
  int T;

  printf("Total: ");
  scanf("%i", &Total);

  N50 = Total/50;
  N10 = (Total%50)/10;
  N2 = ((Total%50)%10)/2;
  T = ((Total%50)%10)%2;

  printf("N50: %i N10: %i N2: %i T: %i", N50,N10,N2,T); 

  return 0;
}