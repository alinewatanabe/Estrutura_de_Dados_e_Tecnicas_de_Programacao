/*
 * Enunciado:
 * Crie um programa capaz de ler 4 estruturas Retângulo
 * (leitura de 2 em 2 pontos) que devem ser armazenados em um array.
 * A seguir, o programa deve exibir o array de retângulos, ordenando-os por
 * área. Utilize o algoritmo de ordenação que preferir.
 *
 * Exemplos:
 *
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,2,2
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,1,1
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,3,3
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,1.5,1.5
 *   [Ret{Ponto{0.00, 0.00},Ponto{1.00, 1.00}},
 *   Ret{Ponto{0.00, 0.00},Ponto{1.50, 1.50}},
 *   Ret{Ponto{0.00, 0.00},Ponto{2.00, 2.00}},
 *   Ret{Ponto{0.00, 0.00},Ponto{3.00, 3.00}}]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 4

typedef struct{
  float x, y;
} Ponto;

typedef struct{
  float base;
  float altura;
  float area;

  Ponto p1, p2;
} Ret;

float calcula_dist(float A, float B);
void troca_vetor(Ret vetor[4], int i, int j);
void exibe_vetor(Ret vetor[4]);
void organiza_vetor(Ret vetor[4]);

int main(int argc, char *argv[]){
  // criação do array de tipo Ret
  Ret array[4];

  // Recebe pontos dos retangulos
  for (int contador = 0; contador < 4; contador++){
    printf("Digite os valores do retângulo (x1, y1, x2, y2): ");
    scanf("%f,%f,%f,%f", &array[contador].p1.x, &array[contador].p1.y, &array[contador].p2.x, &array[contador].p2.y);

    // calcula altura de cada retangulo
    array[contador].altura = calcula_dist(array[contador].p2.y, array[contador].p1.y);

    // calcula base de cada retangulo
    array[contador].base = calcula_dist(array[contador].p2.x, array[contador].p1.x);

    // calcula area de cada retangulo
    array[contador].area = array[contador].base * array[contador].altura;
  }

  organiza_vetor(array);
  exibe_vetor(array);

  return 0;
}

float calcula_dist(float A, float B){
  return A - B;
}

void organiza_vetor(Ret vetor[4]){
  int i, pivo;

  for (pivo = 0; pivo < 3; pivo++){
    for (i = pivo; i < 4; i++){
      if (vetor[i].area < vetor[pivo].area){
        troca_vetor(vetor, i, pivo);
      }
    }
  }
}

void troca_vetor(Ret vetor[4], int i, int j){
  Ret aux;

  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

void exibe_vetor(Ret vetor[4]){
  printf("[");
  for (int i = 0; i < 4; i++){
    printf("Ret{Ponto{%.2f, %.2f},Ponto{%.2f, %.2f}}", vetor[i].p1.x, vetor[i].p1.y, vetor[i].p2.x, vetor[i].p2.y);
    if (i < 3)
      printf(",\n");
  }
  printf("]");
}