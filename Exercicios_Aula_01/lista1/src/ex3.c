#include <stdio.h>

/* Enunciado:
 *
 * Elabore um programa que leia um numero inteiro e exiba-o na tela
 * como um numero flutuante e, logo em seguida, exiba o mesmo numero
 * mas com apenas duas casas apos a virgula
 *
 * Ex: 
 *  Digite um numero: 5
 *  5.000000 5.00
 *
 */

int main (int argc, char *argv[])
{
  printf("Digite um numero: ");
  // Seu codigo a partir daqui

  float a;
  scanf("%f", &a);
  printf("%f %.2f", a,a);
    
  return 0;
}
