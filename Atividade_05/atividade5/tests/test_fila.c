#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"

int main (int argc, char *argv[]) {
  TFila* pokedex = cria_fila();
  Pokemon pk = {.nome="Teste", .AT=0, .HP=0, .DEF=0, .SP=0};
  insere_no_fim(pokedex, pk);
  exibe_pokedex(pokedex);
  destroi_fila(pokedex);
}
