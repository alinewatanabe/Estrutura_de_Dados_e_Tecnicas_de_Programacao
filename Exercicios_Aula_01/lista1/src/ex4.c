#include <stdio.h>

/* Enunciado:
 *
 * Elabore um programa que leia dois numero inteiros
 * e os imprima na ordem inversa que eles foram inseridos
 *
 * Ex:
 *      Digite um numero: 5
 *      Digite um numero: 7
 *      7 5
 *
 */

int main (int argc, char *argv[])
{
  printf("Digite um numero: ");
  // Leitura do numero
  int a;
  scanf("%i", &a);

  printf("Digite um numero: ");
  // Resto do seu codigo
  int b;
  scanf("%i", &b);
  printf("%i %i", b,a);  

  return 0;
}
