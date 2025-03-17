/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, informe-o se o valor digitado se trata de um palíndromo ou não.
 * O programa deve descosiderar diferença entre maíusculas e minúsculas.
 *
 * Exemplos:
 *
 *  Digite uma string: racecar
 *  É palíndromo
 *
 *  Digite uma string: oi
 *  Não é palíndromo
 *
 *  Digite uma string: RaceCar
 *  É palíndromo
 *
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void le_string(char string[MAX]);
void inverte_string(char string[MAX]);
void verificacao(char string[MAX], char string2[MAX]);
void letra_minuscula(char string[MAX], char string2[MAX]);

int main (int argc, char *argv[]){
  char str[MAX];
  char str2[MAX];
  char str_m[MAX];

  le_string(str);
  letra_minuscula(str,str_m);
  strcpy(str2,str_m);
  inverte_string(str2);
  verificacao(str_m,str2);

  return 0;
}

void le_string(char string[MAX]){
  char string_tolower;
  printf("Digite uma string: ");
  setbuf(stdin, 0);
  fgets(string,MAX, stdin);

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

void inverte_string( char string[MAX]){
  int i = strlen(string);
  int tam = strlen(string);
  int aux = strlen(string);
  int fim = strlen(string) - 1;

  for(i = 0; i < tam/2;i++){
    aux = string[i];
    string[i] = string[fim];
    string[fim] = aux;
    fim--;
  }
}

void verificacao(char string[MAX], char string2[MAX]){
  int comp;
  
  comp = strcmp(string,string2);
  
  if(comp == 0){
    printf("É palíndromo");
  }

  else if((comp =! 0)){
    printf("Não é palíndromo");
  }
}