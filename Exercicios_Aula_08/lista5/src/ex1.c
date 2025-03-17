/* 
 * Enunciado: 
 *  Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 *  a seguir, exiba essa string invertida.
 *
 *  Exemplo:
 *    Digite uma string: ola
 *    alo
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void le_string(char string[MAX]);
void inverte_string(char string[MAX]);

int main (int argc, char *argv[]){
  char str[MAX];
  
  le_string(str);
  inverte_string(str);
  printf("%s\n",str);
  
  return 0;
}

void le_string(char string[MAX]){
  printf("Digite uma string: ");
  setbuf(stdin, 0);
  fgets(string,MAX, stdin);

  if(string[strlen(string) - 1] == '\n'){
    string[strlen(string) - 1] = '\0';
  }
}

void inverte_string(char string[MAX]){
  int i = strlen(string);
  int tam = strlen(string);
  int aux = strlen(string);
  int fim = strlen(string) - 1;

  for(i = 0; i < tam/2; i++){
    aux = string[i];
    string[i] = string[fim];
    string[fim] = aux;
    fim--;
  }

}