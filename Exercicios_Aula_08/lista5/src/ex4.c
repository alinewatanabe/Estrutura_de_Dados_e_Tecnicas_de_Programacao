/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, implemente a estratégia de criptografia ZENIT - POLAR.
 * A estratégia em questão consiste em substituir os caracteres da string 
 * da seguinte maneira:
 *
 *            Z <-> P 
 *            E <-> O
 *            N <-> L
 *            I <-> A
 *            T <-> R
 *
 * O programa deve desconsiderar a diferença entre letras maíusculas e
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma string: polar
 *   zenit
 *
 *   Digite uma string: zenit
 *   polar
 *
 *   Digite uma string: ZeNit
 *   polar
 *   
 *   Digite uma string: seu ou, e ratataci!
 *   sou eu, o tiririca!
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void le_string(char string[MAX]);
void letra_minuscula(char string[MAX], char string2[MAX]);
void criptografia(char string[MAX]);


int main (int argc, char *argv[]){
  char str[MAX];
  char str_m[MAX];

  le_string(str);
  letra_minuscula(str, str_m);
  criptografia(str_m);
  printf(str_m);

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

void criptografia(char string[MAX]){
  int i = 0;
  for(i; i < strlen(string); i++){
    if(string[i] == 'p'){
      string[i] = 'z';
    }

    else if(string[i] == 'z'){
      string[i] = 'p';
    }

    else if(string[i] == 'e'){
      string[i] = 'o';
    }

    else if(string[i] == 'o'){
      string[i] = 'e';
    }

    else if(string[i] == 'n'){
      string[i] = 'l';
    }

    else if(string[i] == 'l'){
      string[i] = 'n';
    }

    else if(string[i] == 'i'){
      string[i] = 'a';
    }

    else if(string[i] == 'a'){
      string[i] = 'i';
    }

    else if(string[i] == 't'){
      string[i] = 'r';
    }

    else if(string[i] == 'r'){
      string[i] = 't';
    }

  }
}
  
