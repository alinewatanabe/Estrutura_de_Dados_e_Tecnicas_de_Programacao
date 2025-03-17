/*
 * Enunciado:
 * Repita o exercício anterior, mas agora ordene o array por idade.
 *
 * Exemplos:
 *
 *   Nome: Diego
 *   Endereço: Rua da Miséria, 666
 *   Idade: 30
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Tawfik
 *   Endereço: Praça da Mesquita, 17
 *   Idade: 18
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Alexandre
 *   Endereço: Praça Mauá, 1
 *   Idade: 34
 *   Deseja adicionar outra pessoa? (s/n): n
 *   [Pessoa{'Tawfik',18,'Praça da Mesquita, 17'},Pessoa{'Diego',30,'Rua da Miséria, 666'},Pessoa{'Alexandre',34,'Praça Mauá, 1'}]
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_PESSOAS 100

typedef struct cadastro{
  char nome[MAX];
  int idade;
  char endereco[MAX];
} Pessoa;

// Protótipos
void ler_string(char s[MAX]);
Pessoa ler_pessoa();
void exibicao(struct cadastro lista[MAX_PESSOAS], int numero);

int main(int argc, char *argv[]){
  struct Pessoa;
  int i = 0;
  int j = 0;
  int numero = 0;
  char nomebusca[MAX];
  struct cadastro pessoacadastro[MAX_PESSOAS];
  char verificador = 's';
  while (verificador != 'n'){
    pessoacadastro[i] = ler_pessoa();
    printf("Deseja adicionar outra pessoa(s/n): ");
    setbuf(stdin, 0);
    scanf("%c", &verificador);
    i++;
    numero++;
  }
  ordenar(pessoacadastro, numero);
  exibicao(pessoacadastro, numero);
  return 0;
}

Pessoa ler_pessoa(){
  Pessoa p;
  printf("Nome: ");
  ler_string(p.nome);
  printf("Endereço: ");
  ler_string(p.endereco);
  printf("Idade: ");
  scanf("%i", &p.idade);
  return p;
}

void exibe_pessoa(Pessoa p){
  printf("Pessoa{'%s',%i,'%s'}", p.nome, p.idade, p.endereco);
}

void ler_string(char s[MAX]){
  scanf("\n");
  fgets(s, MAX, stdin);
  int s_tam = strlen(s);
  if (s[s_tam - 1] == '\n'){
    s[s_tam - 1] = '\0';
  }
}

void exibicao(struct cadastro lista[MAX_PESSOAS], int numero){
  int i = 0;
  printf("[");
  for (i; i < numero; i++){
    printf("Pessoa{'%s',%i,'%s'}", lista[i].nome, lista[i].idade, lista[i].endereco);
    if (i != numero - 1){
      printf(",");
    }
  }
  printf("]");
}

void ordenar(Pessoa lista[MAX_PESSOAS], int tam){
  for (int i = 1; i < tam; i++){
    for (int j = 1; j < tam; j++){
      if (lista[j - 1].idade > lista[j].idade){
        Pessoa aux[1];
        aux[0] = lista[j - 1];
        lista[j - 1] = lista[j];
        lista[j] = aux[0];
      }
    }
  }
}
