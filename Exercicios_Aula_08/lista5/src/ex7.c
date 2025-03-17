/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma lista de nomes separados por vírgula
 * digitados por um usuário e, a seguir, armazená-los em um array de strings,
 * que deve ser exibido utilizando o procedimento exibe_nomes fornecido.
 * A quantidade de nomes digitado deve ser sempre 5 (definido por MAX_NOMES).
 *
 * Dica: pesquise pela função strtok
 *
 * Exemplo (**CUIDADO COM O ESPAÇO APÓS A VÍRGULA**):
 *
 *   Nomes: Matheus,Ana Julia,Marco Antonio,Joao,Victoria
 *   ['Matheus', 'Ana Julia', 'Marco Antonio', 'Joao', 'Victoria']
 *
 *   Nomes: Julio,Tiririca,Diego,Alexandre,Nicola
 *   ['Julio', 'Tiririca', 'Diego', 'Alexandre', 'Nicola']
 *
 */

#include <stdio.h>
#include <string.h> 

#define MAX_NOMES 5 // Valor máximo para o tamanho do array. Não modifique.
#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void exibe_nomes(char nomes[MAX_NOMES][MAX]);
void ler_nomes(char string[MAX]);
void divide_string(char nomes[MAX], char mnomes[MAX_NOMES][MAX]);

int main (int argc, char *argv[]){
  char nomes[MAX];
  char *token;
  char mnomes[MAX_NOMES][MAX];

  printf("Nomes: ");
  ler_nomes(nomes);
  divide_string(nomes,mnomes);
  exibe_nomes(mnomes);
  return 0;
}

void exibe_nomes(char nomes[MAX_NOMES][MAX]) {
  printf("[");
  for(int i = 0; i < MAX_NOMES; ++i) {
    printf("'%s'", nomes[i]);
    if( i != MAX_NOMES - 1 ) printf(", ");
  }
  printf("]\n");
}

void ler_nomes(char string[MAX]){
  setbuf(stdin,0);
  fgets(string, MAX, stdin);
  if(string[(strlen(string) - 1)] == '\n'){
    string[(strlen(string) - 1)] = '\0';
  }
}

void divide_string(char nomes[MAX], char mnomes[MAX_NOMES][MAX]){
  char *token;
  int i = 0;

  token = strtok(nomes, ",");
  
  for(i; i < token; i++){
    strcpy(mnomes[i], token);
    token = strtok(NULL, ",");
  }
}


