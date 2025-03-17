#include <stdio.h>

/* Enunciado - Faça um programa que leia um numero inteiro positivo par e,
 * a seguir, exiba todos os numeros pares de 0 ate o numero digitado em ordem
 * crescente, separados apenas por um espaco.
 *
 * Exemplos:
 *
 * Numero: 5
 * Digite um numero par!
 *
 * Numero: -5
 * Digite um numero positivo!
 *
 * Numero: 6
 * 0 2 4 6
 *
 * Numero: 14
 * 0 2 4 6 8 10 12 14
 */

int main (int argc, char *argv[])
{
  int a;
  int i = 0;

  printf("Numero: ");
  scanf("%i", &a);
  
  if(a < 0){
    printf("Digite um numero positivo!");
  }

  else if (a%2 != 0){
    printf("Digite um numero par!");
  }

  else{
    while(i <= a){
      printf("%d ", i);
      i += 2;
    }
    }

  return 0;
}