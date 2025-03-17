/* 
 * Enunciado: 
 *  Elabore um programa capaz de fazer a leitura de uma lista de pokemons 
 *  de um arquivo csv (separador ',') e aramazene esses dados em uma estrutura
 *  do tipo fila. Após a construção da fila de pokemons, seu programa deve 
 *  permitir ao usuário que informe o nome de um pokemon a ser buscado na fila
 *  para exibir todas as suas informações na tela ou, caso a busca não tenha
 *  encontrado nada, informar isso ao usuário.
 *
 *  É OBRIGATÓRIO implementar as subrotinas descritas nos protótipos do código.
 *
 * Exemplos:
 *
 *   Digite o pokemon a ser buscado: Zapdos
 *   Zapdos (90 HP, 90 AT, 85 DEF, 100 SP)
 *
 *   Digite o pokemon a ser buscado: Pikachu
 *   Pikachu (35 HP, 55 AT, 40 DEF, 90 SP)
 *
 *   Digite o pokemon a ser buscado: Pichu
 *   O pokemon não foi encontrado...
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
  char nome[MAX];
  int HP, AT, DEF, SP;
} Pokemon;

typedef struct SFila {
  Pokemon pk;
  struct SFila* prox;
} TFila;

/* 
 * Subrotinas de implementação OBRIGATÓRIA 
 * Essas subrotinas devem ser implementadas de acordo com a sua descrição.
 * Não modifique os protótipos.
 * 
 */ 

// A função cria_fila deve criar uma estrutura do tipo fila.
// Seu retorno é um ponteiro que aponta para o começo da fila.
TFila* cria_fila();

// A função destrói fila deve liberar a memória de todos os elementos da fila.
// Seu retorno deve ser NULL se o procedimento foi bem sucedido.
TFila* destroi_fila(TFila* pokedex);

// A função remove_da_frente deve remover o elemento posicionado na frente da
// fila. Esse elemento deve ser armazenado no endereço pk. O retorno dessa
// função deve ser 0 se a remoção foi bem sucedida ou -1 se houve algum erro.
int remove_da_frente(TFila* pokedex, Pokemon* pk);

// O procedimento insere_no_fim deve inserir um novo elemento no final da fila.
void insere_no_fim(TFila* pokedex, Pokemon pk);

// A função preenche_pokedex deve realizar a leitura de um arquivo e armazenar
// as informações lidas em uma estrutura do tipo Fila. Seu retorno deve ser
// -1 se houve algum erro ou a quantidade de itens lidos, em caso de sucesso.
int preenche_pokedex(TFila* pokedex, char nome_arq[MAX]);

// A função busca_pokemon deve um pokemon a partir de seu nome em uma estrutura
// do tipo Fila, armazenando o resultado no endereço pk. Seu retorno é 0 em
// caso de busca bem sucedida e -1 caso o pokemon não tenha sido encontrado.
int busca_pokemon(TFila* pokedex, char nome_pk[MAX], Pokemon* pk);

// A função ler_pokemon realiza a leitura de uma estrutura Pokemon a partir de
// uma linha. Seu retorno é a estrutura lida.
Pokemon ler_pokemon(char linha[MAX]);


/* 
 * Funções para uso livre 
 * Não modifique nada. Essas funções já estão prontas para uso.
 *
 */
void exibe_pokemon(Pokemon pk); // exibe um pokemon
void exibe_pokedex(TFila* pokedex); // exibe a fila de pokemons
void ler_string(char* s); // le uma string de forma "segura"
void ler_linha(char linha[], FILE *arq);

int main (int argc, char *argv[]){
  char nome_arq[MAX] = "pokedex.csv";
  char nome_pk[MAX];
  Pokemon pk;
  TFila *p ;
  
  p = criar_fila();
  preenche_pokedex(p, nome_arq);

  printf("Digite o pokemon a ser buscado: ");
  scanf("%s", &nome_pk);

  busca_pokemon(p,nome_pk,pk.nome);

  if(busca_pokemon(p,nome_pk,&pk) == 0){
    exibe_pokemon(pk);
  }

  else{
    printf("O pokemon não foi encontrado...");
  }

  return EXIT_SUCCESS;
}

TFila* cria_fila(){
  TFila *p;
  p = (TFila*) malloc(sizeof(TFila));

  p->prox = NULL;
  return p;  
}

TFila* destroi_fila(TFila* pokedex){
  TFila *aux;
  aux = pokedex;

  while(aux->prox != NULL){
    aux = aux->prox;
    free(pokedex);
    pokedex = aux;
  }

  free(pokedex);
  return NULL;
  
}

void insere_no_fim(TFila *p, Pokemon pk){
  TFila *novo;
  novo = (TFila*) malloc(sizeof(TFila));
  if(novo == NULL){
    printf("Não foi possivel alocar memoria!");
    exit(EXIT_FAILURE);
  }

  novo->pk = pk;
  
  TFila *aux;
  aux = p;

  while(aux->prox != NULL){
    aux = aux->prox;
  }

  novo->prox = NULL;
  aux->prox = novo;
}

int remove_da_frente(TFila* pokedex, Pokemon* pk){
  if(pokedex->prox == NULL){
  return -1;
  }
  
  else{
  TFila* aux = pokedex->prox;
  *pk = aux->pk;
  pokedex->prox = aux->prox;
  free(aux);
  return 0;
 }
}

int busca_pokemon(TFila* pokedex, char nome_pk[MAX], Pokemon* pk){
  while(pokedex->prox != NULL){
      int remove = remove_da_frente(pokedex,pk);
      if(remove == 0 && strcmp(pk->nome,nome_pk) == 0){
        return 0;
      }
    }
    return -1;
}

Pokemon ler_pokemon(char linha[MAX]){

  Pokemon pk;

  char *string;
  string = strtok(linha,",");
  strcpy(pk.nome,string);
  string = strtok(0,",");
  pk.HP = atof(string);
  string = strtok(0,",");
  pk.AT = atof(string);
  string = strtok(0,",");
  pk.DEF = atof(string);
  string = strtok(0,",");
  pk.SP = atof(string);

  return pk;
}

int preenche_pokedex(TFila* pokedex, char nome_arq[MAX]){
  Pokemon pk;
  FILE *arquivo;
  char string[MAX];

  arquivo = fopen("pokedex.csv", "r");

  if(arquivo == NULL){
    printf("Erro ao abrir o arquivo. \n");
    exit(EXIT_FAILURE);
  } 

  ler_linha(string, arquivo);
  do{
    ler_linha(string, arquivo);
    insere_no_fim(pokedex,pk);
  }while(feof(arquivo) != 0);
  fclose(arquivo);
}

void exibe_pokemon(Pokemon pk) {
  printf("%s (%i HP, %i AT, %i DEF, %i SP)\n",
         pk.nome, pk.HP, pk.AT, pk.DEF, pk.SP);
}

void exibe_pokedex(TFila* pokedex) {
  TFila* aux = pokedex->prox;
  printf("%10s", "Frente -> ");
  exibe_pokemon(aux->pk);
  aux = aux->prox;
  while(aux != NULL) {
    printf("%10s", "");
    exibe_pokemon(aux->pk);
    aux = aux->prox;
  }
}

void ler_string(char* s) {
  scanf("\n");
  fgets(s, MAX, stdin);
  size_t tam = strlen(s);
  if( s[tam-1] == '\n' ) s[tam-1] = '\0';
}


void ler_linha(char linha[], FILE *arq){
  fgets(linha, MAX, arq);
  if(linha[strlen(linha)-1] == '\n')
  linha[strlen(linha)-1] = '\0';
}
