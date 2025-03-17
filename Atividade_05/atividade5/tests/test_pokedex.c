#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"

int main (int argc, char *argv[]) {
  TFila* pokedex = cria_fila();
  char nome_arq[MAX] = "./tests/teste.csv";
  preenche_pokedex(pokedex, nome_arq);
  exibe_pokedex(pokedex);
  destroi_fila(pokedex);

  return EXIT_SUCCESS;
}
