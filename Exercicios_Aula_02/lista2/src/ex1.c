#include <stdio.h>

/* Enunciado - Faça um programa que receba dois números e mostre qual deles
 * é o maior. Caso os números sejam iguais, o programa deve informar o usuário.
 * Os números devem ser sempre exibidos com apenas duas casas após a vírgula.
 * Exemplos:
 *
 * Digite um numero: 5
 * Digite um numero: 7.5
 * 7.50 > 5.00
 *
 * Digite um numero: 5
 * Digite um numero: 5
 * Numeros iguais!
 */

int main (int argc, char *argv[])
{
  float a;
  float b;

  printf("Digite um numero: ");
  scanf("%f", &a);

  printf("Digite um numero: ");
  scanf("%f", &b);

  if(a > b){
    printf("%.2f > %.2f", a,b);
  }
  else if (a < b){
    printf("%.2f > %.2f", b,a);
  }
  else if(a == b){
    printf("Numeros iguais!");
  }

  return 0;
}