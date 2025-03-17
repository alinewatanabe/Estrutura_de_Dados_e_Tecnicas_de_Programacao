/* 
 * Enunciado: 
 * Implemente um programa que leia o nome, a idade e o endereço de uma pessoa 
 * e armazene esses dados em uma estrutura. Em seguida, imprima na tela os 
 * dados da estrutura lida. Para armazenar os dados, escolha os tipos de dados 
 * mais adequados para cada informação. Utilize, obrigatoriamente, uma função 
 * para realizar a leitura da estrutura e outra função para realizar sua 
 * exibição. Outras funções auxiliares podem ser utilizadas.
 *
 * Exemplos:
 *
 *  Nome: Rodrigo Nicola
 *  Endereço: Praça Mauá, 1
 *  Idade: 31
 *  Pessoa{'Rodrigo Nicola',31,'Praça Mauá, 1'}
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
  char nome[MAX];
  int idade;
  char endereco[MAX];
} Pessoa;

void ler_string(char s[MAX]);
Pessoa ler_pessoa();
void exibe_pessoa(Pessoa p);

int main (int argc, char *argv[]){
  struct Pessoa;
  Pessoa p = ler_pessoa();
  exibe_pessoa(p);
  return 0;
}

void ler_string(char s[MAX]){
  scanf("\n");
  fgets(s,MAX,stdin);
  int s_tam = strlen(s);
  if(s[s_tam-1] == '\n'){
    s[s_tam - 1] = '\0';
  }
}

Pessoa ler_pessoa(){
  Pessoa p;
  printf("Endereço: ");
  ler_string(p.endereco);
  printf("Idade: ");
  scanf("%i", &p.idade);
  return p;
}

void exibe_pessoa(Pessoa p){
  printf("Pessoa{'%s',%i,'%s'}", p.nome,p.idade,p.endereco);
}
