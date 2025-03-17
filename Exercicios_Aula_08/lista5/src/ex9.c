/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, ler um intervalo separado por vírgula que deve ser utilizado para
 * gerar uma substring que começa no começo do intervalo digitado e termina no
 * índice final (intervalo fechado).
 *
 * Exemplos:
 *
 * Digite uma string: Oi, eu sou o Goku!
 * Intervalo: 0, 9
 * Oi, eu sou
 *
 * Digite uma string: 0123456789
 * Intervalo: 3,7
 * 34567
 *
 * Digite uma string: Estruturas de Dados
 * Intervalo: 3, 12
 * ruturas de
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void ler_string(char s[MAX]);

int main(int argc, char *argv[])
{
  char s[MAX];
  printf("Digite uma string: ");
  ler_string(s);
  int intervalos[2];
  printf("Intervalo: ");
  scanf("%i, %i", &intervalos[0], &intervalos[1]);
  for (int i = intervalos[0]; i <= intervalos[1]; i++)
    printf("%c", s[i]);
  printf("\n");

  return 0;
}

void ler_string(char s[MAX])
{
  setbuf(stdin, 0); // cuidado
  fgets(s, MAX, stdin);
  int s_tam = strlen(s);
  if (s[s_tam - 1] == '\n')
  {
    s[s_tam - 1] = '\0';
  }
}