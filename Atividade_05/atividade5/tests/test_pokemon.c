#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"

int main (int argc, char *argv[]) {
  char linha[MAX] = "Teste,0,0,0,0";
  exibe_pokemon(ler_pokemon(linha));

  return EXIT_SUCCESS;
}
