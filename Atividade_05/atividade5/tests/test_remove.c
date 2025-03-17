#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"

int main (int argc, char *argv[]) {
  TFila* pokedex = cria_fila();
  Pokemon pk = {.nome="Teste", .AT=0, .HP=0, .DEF=0, .SP=0};
  insere_no_fim(pokedex, pk);
  insere_no_fim(pokedex, pk);
  Pokemon pk2;
  remove_da_frente(pokedex, &pk2);
  exibe_pokemon(pk2);
  exibe_pokedex(pokedex);
  destroi_fila(pokedex);

  return EXIT_SUCCESS;
}
