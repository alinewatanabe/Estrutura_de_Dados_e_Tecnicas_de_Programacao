/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, solicite ao usuário que digite um caractere a ser buscado na
 * string digitada. O programa deve informar ao usuário se o caractere foi
 * encontrado ou não. O programa deve desconsiderar a difereça entre maíusculas
 * e minúsculas. Utilize o algoritmo de busca que achar melhor.
 *
 * Exemplos:
 *
 *   Digite uma string: teste!
 *   Digite a chave: !
 *   Caractere ! encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: M
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: m
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: b
 *   Caractere b não foi encontrado.
 *
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void le_string(char string[MAX]);
int busca_linear(char string[MAX], char chave);
void letra_minuscula(char string[MAX], char string2[MAX]);

int main (int argc, char *argv[]){
  char str[MAX];
  char chave;
  char str_m[MAX];
  char chave_m;
  int b;

  le_string(str);
  letra_minuscula(str, str_m);
  printf("Digite a chave: ");
  scanf("%c", &chave);
  chave_m = tolower(chave);
  b = busca_linear(str_m, chave_m);
  if(b == -1){
    printf("Caracter %c não foi encontrado.", chave_m);
  }
  else{
    printf("Caracter %c foi encontrado na posição %i.", chave_m, b);
  }
  
  return 0;
}

void le_string(char string[MAX]){
  printf("Digite uma string: ");
  setbuf(stdin, 0);
  fgets(string,MAX,stdin);

  if(string[strlen(string) - 1] == '\n'){
    string[strlen(string) - 1] = '\0';
  }
}

void letra_minuscula(char string[MAX], char string2[MAX]){
  int i = 0;
  while(string[i] != '\0'){
    string2[i] = tolower(string[i]);
    i++;
  }
  string2[i] = '\0';
}

int busca_linear(char string[MAX], char chave){
  int i = 0;
  for(i; i < strlen(string); i++){
    if(string[i] == chave){
      return i;
    }
  }
  return -1;
}