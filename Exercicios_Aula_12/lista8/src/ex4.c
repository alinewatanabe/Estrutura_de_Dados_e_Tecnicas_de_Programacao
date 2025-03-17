/*
 * Enunciado:
 *    Repita o exercício 2, mas agora o seu programa deve implementar um
 *    algoritmo de ordenação para ordenar e exibir a lista de alunos em ordem
 *    crescente de média.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
  char nome[MAX];
  float notas[4];
  float media;
} Aluno;

typedef struct SLista{
  Aluno aluno;
  struct SLista *prox;
} TLista;

/* Funções recomendadas (não precisa implementar nenhuma delas se não quiser)
 */
Aluno ler_aluno(char linha[MAX]);
void exibe_aluno(Aluno a);

int ler_alunos(TLista *alunos);

TLista *cria_lista();
TLista *destroi_lista(TLista *alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

void ordena_lista(TLista *alunos);
void troca_alunos(Aluno *a, Aluno *b);

/* Funções para uso livre */
void exibe_lista(TLista *alunos); // exibe uma lista de alunos
void ler_string(char *s);         // le uma string de forma "segura"
int remove_da_frente(TLista *alunos, Aluno *x);

int main(int argc, char *argv[]){
  FILE *arq;
  arq = fopen("notas.csv", "r");

  if (arq == NULL)
    printf("Erro ao abrir o arquivo");

  Aluno aluno;
  Aluno b;
  TLista *lista;
  int i = 0;
  lista = cria_lista();

  char entrada[MAX];
  do{
    memset(entrada, 0, strlen(entrada));
    lerlinha(entrada, arq);
    insere_no_fim(lista, ler_aluno(entrada));
    i++;
  } while (!feof(arq));

  ordena_lista(lista);

  exibe_lista(lista);

  lista = destroi_lista(lista);

  fclose(arq);

  return EXIT_SUCCESS;
}

void troca_alunos(Aluno *a, Aluno *b){
  Aluno aux;
  strcpy(aux.nome, a->nome);
  aux.media = a->media;
  aux.notas[0] = a->notas[0];
  aux.notas[1] = a->notas[1];
  aux.notas[2] = a->notas[2];
  aux.notas[3] = a->notas[3];
  strcpy(a->nome, b->nome);
  a->media = b->media;
  a->notas[0] = b->notas[0];
  aux.notas[1] = b->notas[1];
  aux.notas[2] = b->notas[2];
  aux.notas[3] = b->notas[3];
  strcpy(b->nome, aux.nome);
  b->media = aux.media;
  b->notas[0] = aux.notas[0];
  b->notas[1] = aux.notas[1];
  b->notas[2] = aux.notas[2];
  b->notas[3] = aux.notas[3];
}

void ordena_lista(TLista *alunos){
  TLista *aux;
  aux = alunos;
  TLista *proximo;
  Aluno a;
  while (aux != NULL)
  {
    proximo = aux->prox;
    while (proximo != NULL)
    {
      if (aux->aluno.media > proximo->aluno.media)
      {
        a = aux->aluno;
        aux->aluno = proximo->aluno;
        proximo->aluno = a;
      }
      proximo = proximo->prox;
    }
    aux = aux->prox;
  }
  return alunos;
}

int ler_alunos(TLista *alunos){
}

void insere_no_fim(TLista *alunos, Aluno aluno){
  TLista *novo;
  novo = (TLista *)malloc(sizeof(TLista));
  if (novo == NULL){
    printf("Não foi possível alocar memória!");
    exit(EXIT_FAILURE);
  }
  novo->aluno = aluno;

  TLista *aux;
  aux = alunos;
  while (aux->prox != NULL)
    aux = aux->prox;

  novo->prox = NULL;
  aux->prox = novo;
}

TLista *cria_lista(){
  TLista *p;
  p = (TLista *)malloc(sizeof(TLista));
  if (p == NULL){
    printf("Não pode criar a lista");
    exit(EXIT_FAILURE);
  }
  p->prox = NULL;
  return p;
}

TLista *destroi_lista(TLista *alunos){
  TLista *aux;
  aux = alunos;
  while (aux->prox != NULL){
    aux = aux->prox;
    free(alunos);
    alunos = aux;
  }
  free(alunos);
  return NULL;
}

Aluno ler_aluno(char entrada[MAX]){
  Aluno a;
  char *token;

  token = strtok(entrada, ",");
  strcpy(a.nome, token);

  token = strtok(NULL, ",");
  a.notas[0] = atof(token);

  token = strtok(NULL, ",");
  a.notas[1] = atof(token);

  token = strtok(NULL, ",");
  a.notas[2] = atof(token);

  token = strtok(NULL, ",");
  a.notas[3] = atof(token);

  a.media = ((a.notas[0] + a.notas[1] + a.notas[2] + a.notas[3]) / 4);

  return a;
}

void exibe_aluno(Aluno a){
  printf("(%s | %.2f)", a.nome, a.media);
}

void exibe_lista(TLista *alunos){
  TLista *aux = alunos->prox;
  while (aux != NULL){
    exibe_aluno(aux->aluno);
    if (aux->prox != NULL)
      printf(" -> ");
    aux = aux->prox;
  }
  printf("\n");
}

void ler_string(char *s){
  scanf("\n");
  fgets(s, MAX, stdin);
  size_t tam = strlen(s);
  if (s[tam - 1] == '\n')
    s[tam - 1] = '\0';
}

void lerlinha(char linha[MAX], FILE *arq){
  fgets(linha, MAX, arq);
  if (linha[strlen(linha) - 1] == '\n')
    linha[strlen(linha) - 1] = '\0';
}

int remove_da_frente(TLista *pokedex, Aluno *a){
  TLista *removedor;
  removedor = pokedex->prox;

  if (removedor != NULL){
    pokedex->prox = removedor->prox;
    *a = removedor->aluno;
    return 0;
  }
  return -1;
}
