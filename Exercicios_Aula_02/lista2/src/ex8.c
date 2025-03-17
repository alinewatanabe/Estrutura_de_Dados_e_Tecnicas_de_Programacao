#include <stdio.h>

/* Enunciado - Faça um programa que calcula a associação em paralelo 
 * de dois resistores R1 e R2 fornecidos pelo usuário via teclado. 
 * O programa deverá solicitar valores e calcula a resistência equivalente até 
 * que o usuário entre com um valor para alguma das resistências igual a 0
 *
 * Exemplos:
 *
 * Digite um valor para R1: 470
 * Digite um valor para R2: 2200
 * 
 *
 * Digite um valor para R1: 0
 * Digite um valor para R2: 100
 * Finalizando o programa!
 */

int main (int argc, char *argv[])
{
  int R1 = 1;
  int R2 = 2;
  int Req;

  while((R1 != 0) && (R2 != 0)){
    printf("Digite um valor para R1: ");
    scanf("%i", &R1);

    printf("Digite um valor para R2: ");
    scanf("%i", &R2);
    
    Req = (R1*R2)/(R1 + R2);
  }

  printf("Finalizando programa!");

  return 0;
}
