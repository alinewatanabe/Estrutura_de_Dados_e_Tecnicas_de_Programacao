/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler duas palavras digitadas pelo usuário e,
 * a seguir, deve informá-lo se as palavras formam um anagrama. O programa deve
 * desconsiderar a diferença entre letras maíusculas e letras minúsculas.
 *
 * Exemplos:
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robed
 * bored é anagrama de robed
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robbed
 * bored não é anagrama de robbed
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: oii
 * ooi não é anagrama de oii
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: ioo
 * ooi é anagrama de ioo
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void ler_string(char string[MAX]);
void minusculo(char string[MAX]);
void ordenar_string(char string[MAX]);


/********* PROGRAMA PRINCIPAL *********/
int main (int argc, char *argv[]){
char str[MAX] = {};
char str1[MAX] = {};
char str_copia[MAX] = {};
char str1_copia[MAX] = {};

printf("Digite uma palavra: ");
ler_string(str);
strcpy(str_copia,str);
minusculo(str);
ordenar_string(str);

printf("Digite uma palavra: ");
ler_string(str1);
strcpy(str1_copia,str);
minusculo(str1);
ordenar_string(str1);

if(strcmp(str, str1) == 0){
  printf("%s é anagrama de %s", str_copia, str1_copia);
}

else{
  printf("%s não é anagrama de %s", str_copia, str1_copia);
}


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