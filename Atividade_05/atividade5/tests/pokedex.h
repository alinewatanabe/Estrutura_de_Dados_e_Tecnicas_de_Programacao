#define MAX 100

typedef struct {
  char nome[MAX];
  int HP, AT, DEF, SP;
} Pokemon;

typedef struct SFila {
  Pokemon pk;
  struct SFila* prox;
} TFila;

TFila* cria_fila();
TFila* destroi_fila(TFila* pokedex);
int remove_da_frente(TFila* pokedex, Pokemon* pk);
void insere_no_fim(TFila* pokedex, Pokemon pk);
int preenche_pokedex(TFila* pokedex, char nome_arq[MAX]);
int busca_pokemon(TFila* pokedex, char nome_pk[MAX], Pokemon* pk);
Pokemon ler_pokemon(char linha[MAX]);
void exibe_pokemon(Pokemon pk);
void exibe_pokedex(TFila* pokedex);
void ler_string(char* s);
