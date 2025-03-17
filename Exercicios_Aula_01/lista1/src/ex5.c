#include <stdio.h>

/* Enunciado:
 *
 * Elabore um programa que leia um numero de 5 digitos e, em seguida, exiba
 * o numero digitado com os digitos invertidos.
 *
 * Ex:
 *      Digite um numero: 54321
 *      12345
 *
 *      Digite um numero: 38271
 *      17283
 *
 */

int main (int argc, char *argv[])
{
  int inv = 0;
  int a;

  printf("Digite um numero: ");
  scanf("%i", &a);

  while(a > 0){
    inv = 10*inv + a%10;
    a /= 10; 
  }

  printf("%i", inv);

}
