/* 
 * Enunciado: 
 * Implemente um programa que leia o nome, a idade e o endereço de diversas
 * pessoas, armazene esses dados em um array de estruturas (Pessoa). O programa
 * deve permitir a leitura de diferentes pessoas até que o usuário decida 
 * encerrar a inserção (caractere 'n'). Em seguida, o programa deve pedir para
 * o usuário digitar um nome a ser buscado no array de Pessoas. Caso o nome
 * seja encontrado, o endereço da Pessoa buscada deve ser exibido. Caso o nome
 * não seja encontrado, o usuário deve ser informado de que a busca não foi 
 * bem sucedida. Utilize o algoritmo de busca que preferir.
 *
 * Exemplos:
 *   Nome: Rodrigo
 *   Endereço: Aqui
 *   Idade: 31
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Alexandre
 *   Endereço: Ali
 *   Idade: 34
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Alexandre
 *   Endereço de Alexandre: Ali
 *
 *   Nome: Camila
 *   Endereço: Rua da Felicidade, 340
 *   Idade: 20
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Diego
 *   Endereço: Rua da Miséria, 666
 *   Idade: 30
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Diego
 *   Endereço de Diego: Rua da Miséria, 666
 *
 *   Nome: Ahmad 
 *   Endereço: Avenida Brasil, 5670
 *   Idade: 19
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Alexandre
 *   'Alexandre' não foi encontrado
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

void ler_string(char s[MAX]);
Pessoa ler_pessoa();

int main (int argc, char *argv[]){
  struct Pessoa;
  int i = 0;
  int j = 0;
  char nomebusca[MAX];
  char verificador = 's';
  struct cadastro pessoacadastro[MAX_PESSOAS];
  
  while(verificador != 'n'){
    pessoacadastro[i] = ler_pessoa();
    printf("Deseja adicionar outra pessoa(s/n): ");
    setbuf(stdin,0);
    scanf("%c", &verificador);
    i++;
  }

  printf("Digite um nome para ser buscado: ");
  ler_string(nomebusca);

  for(j; j<MAX_PESSOAS; j++){
    if(strcmp(nomebusca, pessoacadastro[j].nome) == 0){
      printf("O endereço de %s: %s", nomebusca, pessoacadastro[j].endereco);
      return 0;
    }
  } printf("'%s' não foi encontrado", nomebusca);
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
  int s_tam;
  scanf("\n");
  fgets(s, MAX, stdin);
  s_tam = strlen(s);

  if(s[s_tam - 1] == '\n'){
    s[s_tam - 1] = '\0';
  }
}