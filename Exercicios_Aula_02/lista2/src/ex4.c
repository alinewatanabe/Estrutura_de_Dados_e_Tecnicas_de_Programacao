#include <stdio.h>

/* Enunciado - Faça um programa que leia duas notas de um aluno em uma
 * única linha, separando cada valor com uma vírgula. Verifique se as notas
 * são válidas e, caso sejam exiba a média do aluno na tela. Para que a nota 
 * seja válida, ela deve estar entre 0.0 e 10.0. Caso alguma das notas não seja
 * válida, o programa deve informar o usuário e encerrar sua operação.
 *
 * Exemplos:
 *
 * Notas: 5.0, 10.0
 * 7.5
 *
 * Notas: 5, 5.0
 * 5.0
 *
 * Notas: -1.0, 5.0
 * Nota invalida. Deve ser entre 0.0 e 10.0
 */

int main (int argc, char *argv[])
{
  float media;
  float nota1;
  float nota2;

  printf("Notas: ");
  scanf("%f, %f", &nota1, &nota2);

  if ((nota1 < 0) || (nota2 < 0) || (nota1 > 10) || (nota2 > 10)){
    printf("Nota invalida. Deve ser entre 0.0 e 10.0");
  }

  else{
    media = (nota1 + nota2)/2;
    printf("%.1f", media);
  }

  return 0;
}

