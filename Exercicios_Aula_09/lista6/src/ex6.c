/*
 * Enunciado:
 * Crie um programa capaz de ler dois pontos que compõe uma estrutura de um
 * Retângulo. Os dois pontos correspondem aos vértices inferior esquerdo e
 * superior direito. Após a leitura do Retângulo, deve ser lido um terceiro
 * ponto. O programa, então, exibirá se o ponto digitado pertence ao retângulo.
 *
 * Exemplos:
 *
 *   Digite um ponto (x, y): 0, 0
 *   Digite um ponto (x, y): 4, 4
 *   Digite um ponto (x, y): 2, 1
 *   O ponto digitado faz parte do Retângulo
 *
 *   Digite um ponto (x, y): 0, 0
 *   Digite um ponto (x, y): 3, 4
 *   Digite um ponto (x, y): 5, 7
 *   O ponto digitado não pertence ao Retângulo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
  int x;
  int y;
} Ponto;

typedef struct{
  Ponto supdir;
  Ponto supesq;
  Ponto infdir;
  Ponto infesq;
} Ret;

int main(int argc, char *argv[]){
  Ret a;
  Ponto questao;

  printf("Digite um ponto (x, y): ");
  scanf("%i, %i", &a.infesq.x, &a.infesq.y);

  printf("Digite um ponto (x, y): ");
  scanf("%i, %i", &a.supdir.x, &a.supdir.y);

  printf("Digite um ponto (x, y): ");
  scanf("%i, %i", &questao.x, &questao.y);

  if (questao.x > a.infesq.x && questao.x < a.supdir.x && questao.y > a.infesq.y && questao.y < a.supdir.x){
    printf("Ponto digitado faz parte do Retângulo\n");
  }
  else
    printf("O ponto digitado não pertence ao Retângulo\n");
  return 0;
}
