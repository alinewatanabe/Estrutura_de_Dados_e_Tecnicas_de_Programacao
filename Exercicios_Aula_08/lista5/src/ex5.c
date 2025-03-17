/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma palavra digitada pelo usuário e,
 * a seguir, deve exibir uma string contendo os caracteres da palavra digitada
 * em ordem alfabética. Utilize o algoritmo de ordenação que preferir.
 * O programa deve desconsiderar a diferença entre letras maíusculas e 
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma palavra: ola
 *   alo
 *
 *   Digite uma palavra: alo
 *   alo
 *
 *   Digite uma palavra: RaceCar
 *   aaccerr
 *
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void ler_string(char string[MAX]);
void ordenar_string(char string[MAX]);
void minusculo(char string[MAX]);
void troca_char(char string[MAX],int i, int j);

/********* PROGRAMA PRINCIPAL *********/
int main (int argc, char *argv[]){
  char str[MAX];
  char str1[MAX];

  printf("Digite uma palavra: ");
  ler_string(str);
  minusculo(str);
  ordenar_string(str);
  printf(str);

  return 0;
}
/********* ******** ********* *********/

void ler_string(char string[MAX]){
  setbuf(stdin,0);
  fgets(string, MAX, stdin);
  if(string[(strlen(string) - 1)] == '\n'){
    string[(strlen(string) - 1)] = '\0';
  }
}

void minusculo(char string[MAX]){
  int i = 0;
  for(i; i < strlen(string); i++){
    string[i] = tolower(string[i]);
  }
}

void ordenar_string(char string[MAX]){
  char temp;
	int i, j;
	int n = strlen(string);

	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (string[i] > string[j]) {
        temp = string[i];
				string[i] = string[j];
        string[j] = temp;
      }
    }
  }
}
