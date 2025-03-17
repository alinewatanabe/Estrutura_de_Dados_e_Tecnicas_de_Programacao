#include <stdio.h>

/* Enunciado:
 *
 * Elabore um programa que receba um valor inteiro de 6 digitos do usuario
 * e, em seguida, exiba uma versao binaria falsa desse numero. Para calcular
 * a versao binaria falsa, verifique cada um dos digitos do numero e, se o 
 * digito for maior ou igual a 5, transforme-o em 1, se for menor, transforme-o
 * em 0.
 *
 *
 * Ex:
 *     Digite um numero: 123456
 *     000011
 *
 *     Digite um numero: 583910
 *     110100
 *
 *     Digite um numero: 830209
 *     100001
 *
 * DICA: Lembre-se das ferramentas de quebra de fluxo que tinhamos em Python.
 * Como usa-las em C? Pesquise!
 *
 */

int main (int argc, char *argv[])
{
  int inv = 0;
  int a;
  int c;

  printf("Digite um numero: ");
  scanf("%i", &a);

  while(a > 0){
    inv = 10*inv + a%10;
    a /= 10;
  }

  while(inv > 0){
    c = inv%10;
    if (c < 5){
      printf("0");
    }
    else{
      printf("1");
    }
    inv = inv/10;
  }
  return 0;
}