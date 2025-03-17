/*
 * Enunciado:
 *    Repita o exercício anterior, mas agora o programa principal deve pedir
 *    ao usuário que digite um nome para ser buscado na lista de alunos.
 *    O programa deve implementar um algoritmo de busca na lista ligada para
 *    encontrar e exibir o aluno com o nome informado. Caso o aluno não seja
 *    encontrado, o usuário deve ser alertado.
 *
 * Exemplos:
 *
 *    Digite o aluno a ser buscado: Rodrigo
 *    Aluno encontrado: (Rodrigo | 2.50)
 *
 *    Digite o aluno a ser buscado: Alexandre
 *    Aluno encontrado: (Alexandre | 9.25)
 *
 *    Digite o aluno a ser buscado: Oi
 *    O aluno não foi encontrado...
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
void lerlinha(char linha[MAX], FILE *arq);

int ler_alunos(TLista *alunos);

TLista *cria_lista();
TLista *destroi_lista(TLista *alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

int busca_aluno(TLista *alunos, char aluno[MAX], Aluno *a);

/* Funções para uso livre */
void exibe_lista(TLista *alunos); // exibe uma lista de alunos
void ler_string(char *s);         // le uma string de forma "segura"

int main(int argc, char *argv[]){
  Aluno aluno;
  TLista *lista;
  int i = 0;
  lista = cria_lista();

  FILE *arq;
  arq = fopen("notas.csv", "r");

  if (arq == NULL)
    printf("Erro ao abrir o arquivo");

  char entrada[MAX];
  do{
    memset(entrada, 0, strlen(entrada));
    lerlinha(entrada, arq);
    insere_no_fim(lista, ler_aluno(entrada));
    i++;
  } while (!feof(arq));

  char nomebusca[MAX];
  printf("Digite o nome a ser buscado: ");
  ler_string(nomebusca);
  if (busca_aluno(lista, nomebusca, &aluno) == 0){
    exibe_aluno(aluno);
  }
  else
    printf("O nome não foi encontrado...\n");

  fclose(arq);

  lista = destroi_lista(lista);

  return EXIT_SUCCESS;
}

int busca_aluno(TLista *alunos, char aluno[MAX], Aluno *a){
  TLista *aux;
  aux = alunos;

  while (aux->prox != NULL){
    aux = aux->prox;
    int comp = strcmp((*aux).aluno.nome, aluno);
    if (comp == 0){
      *a = aux->aluno;
      return 0;
    }
  }
  return -1;
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