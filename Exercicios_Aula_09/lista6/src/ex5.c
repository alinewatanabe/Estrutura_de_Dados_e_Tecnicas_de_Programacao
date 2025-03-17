/*
 * Enunciado:
 * Crie um programa capaz de ler os valores(float) de x e y de uma
 * estrutura Ponto. A seguir, o programa deve calcular e exibir a distância
 * entre esses dois pontos.
 *
 * Exemplos:
 *
 *   Digite um ponto (x, y): 0, 1
 *   Digite um ponto (x, y): 0, 0
 *   Distancia: 1.00
 *
 *   Digite um ponto (x, y): 5, 7
 *   Digite um ponto (x, y): 10, 3
 *   Distancia: 6.40
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{
  int x;
  int y;
} Ponto;

// Prototipos

Ponto ler_ponto();
float calcula_ponto(Ponto p1, Ponto p2);

int main(int argc, char *argv[]){
  float distancia = 0;
  struct Ponto;

  Ponto p1;
  printf("Digite um ponto (x, y): ");
  scanf("%i, %i", &p1.x, &p1.y);

  Ponto p2;
  printf("Digite um ponto (x, y): ");
  scanf("%i, %i", &p2.x, &p2.y);

  distancia = calcula_ponto(p1, p2);
  printf("Distancia: %.2f\n", distancia);
  return 0;
}

float calcula_ponto(Ponto p1, Ponto p2){
  float x_distancia = p1.x - p2.x;
  float y_distancia = p1.y - p2.y;
  float distancia = sqrt(pow(y_distancia, 2) + pow(x_distancia, 2));
  return distancia;
}
