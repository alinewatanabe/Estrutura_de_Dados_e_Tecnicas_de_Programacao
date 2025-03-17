/* 
 * Enunciado: 
 *    Crie uma lista ligada de alunos, em que cada aluno deve consistir de um
 *    struct contendo o seu RA, 4 notas e a média do aluno. O programa
 *    principal deve pedir para que o usuário digite o RA e as 4 notas de 
 *    3 alunos, para a seguir exibir a lista ligada completa (use exibe_lista).
*
 * Exemplos:
 * 
 *    Aluno: Rodrigo 2 3 4 5
 *    Aluno: Alexandre 10 10 8 9
 *    Aluno: Diego 7 8 10 10 
 *    (Rodrigo | 3.50) -> (Alexandre | 9.25) -> (Diego | 8.75)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
  char nome[MAX];
  float notas[4];
  float media;
} Aluno;

typedef struct SLista {
  Aluno aluno;
  struct SLista *prox
} TLista;;

/* Funções recomendadas (não precisa implementar nenhuma delas se não quiser)
 */
Aluno ler_aluno();
void exibe_aluno(Aluno a);
float calcula_media(float* notas);

TLista* cria_lista();
TLista* destroi_lista(TLista* alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

/* Funções para uso livre */
void exibe_lista(TLista* alunos); // exibe uma lista de alunos
void ler_string(char* s); // le uma string de forma "segura"


/******** PROGRAMA PRINCIPAL ********/
int main (int argc, char *argv[]){
  int i = 0;
  struct Aluno;
  TLista *alunos;
  
  alunos = cria_lista();
  do{
    insere_no_fim(alunos,ler_aluno()); 
    i++;
  }while(i < 3);

  exibe_lista(alunos);
  destroi_lista(alunos);

  return EXIT_SUCCESS;
}
/******** ******** ********* ********/

Aluno ler_aluno(){
  Aluno a;

  printf("Aluno: ");
  scanf("%s %f %f %f %f", &a.nome, &a.notas[0], &a.notas[1], &a.notas[2], &a.notas[3]); 

  a.media = calcula_media(a.notas);

  return a;
}

float calcula_media(float* notas){
  float media;
  media = (notas[0] + notas[1] + notas[2] + notas[3])/4;
  return media;
}

TLista* cria_lista(void){
  TLista *lista;
  lista = (TLista*) malloc(sizeof(TLista));
  if(lista == NULL){
    printf("Não é possivel criar lista");
    exit(EXIT_FAILURE);
  }
  
  lista->prox = NULL;
  
  return lista;
}

TLista* destroi_lista(TLista* alunos){
  TLista *aux;
  aux = alunos;

  while(aux->prox != NULL){
    aux = aux->prox;
    free(alunos);
    alunos = aux;
  }

  free(alunos);
  return NULL;
  
}

void insere_no_fim(TLista *alunos, Aluno aluno) {
  TLista *novo;
  novo = (TLista*) malloc(sizeof(TLista));
  if(novo == NULL){
    printf("Não foi possivel alocar memoria!");
    exit(EXIT_FAILURE);
  }

  novo->aluno = aluno;
  
  TLista *aux;
  aux = alunos;

  while(aux->prox != NULL){
    aux = aux->prox;
  }

  novo->prox = NULL;
  aux->prox = novo;
}

void exibe_aluno(Aluno a) {
  printf("(%s | %.2f)", a.nome, a.media);
}

void exibe_lista(TLista* alunos) {
  TLista *aux = alunos->prox;
  while(aux != NULL) {
    exibe_aluno(aux->aluno);
    if( aux->prox != NULL ) printf(" -> ");
    aux = aux->prox;
  }
  printf("\n");
}

void ler_string(char* s) {
  scanf("\n");
  fgets(s, MAX, stdin);
  size_t tam = strlen(s);
  if( s[tam-1] == '\n' ) s[tam-1] = '\0';
}
