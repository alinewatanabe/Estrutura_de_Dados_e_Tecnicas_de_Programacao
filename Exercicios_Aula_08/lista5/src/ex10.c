/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, exibir o maior palíndromo possível dentro da string digitada.
 * Caso não haja nenhum palíndromo possível, o programa deve alertar o usuário.
 * O programa deve desconsiderar diferenças entre letras minúsculas e letras
 * maiúsculas.
 *
 * Exemplos:
 *
 *   Digite uma string: tiririca
 *   iriri
 *
 *   Digite uma string: I have a racecar
 *   racecar
 *
 *   Digite uma string: Cuidado com o Diego
 *   dad
 *
 *   Digite uma string: Alexandre
 *   Não existe nenhum palíndromo possível
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void ler_string(char s[MAX]);
int palindromo_bubble(char palavra[MAX], char palindromo[MAX]);
int verifica_palindromo(char string[MAX]);

int main(int argc, char *argv[])
{
  char s[MAX];
  printf("Digite uma string: ");
  ler_string(s);

  char listapalavras[MAX][MAX];

  char *token;
  int i = 0;
  token = strtok(s, " ");
  while (token != NULL)
  {
    strcpy(listapalavras[i], token);
    token = strtok(NULL, " ");
    i++;
  }

  int tam = 0;

  for (int j = 0; j <= i; j++)
  {
    if (strlen(listapalavras[j]) > strlen(listapalavras[tam]))
    {
      tam = j;
    }
  }

  char palindromo[MAX];
  int verificador = palindromo_bubble(listapalavras[tam], palindromo);

  if (verificador == -1)
  {
    printf("Não existe nenhum palíndromo possível\n");
    return 0;
  }

  printf("%s\n", palindromo);

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

int verifica_palindromo(char string[MAX])
{
  char comeco, fim;
  char comeco_l, fim_l;
  for (int i = 0, j = strlen(string) - 1; i < j; i++, j--)
  {
    comeco = string[i];
    comeco_l = tolower(comeco);
    fim = string[j];
    fim_l = tolower(fim);

    if (comeco_l != fim_l)
      return 0;
  }
  return -1;
}

int palindromo_bubble(char palavra[MAX], char palindromo[MAX])
{
  int verificador;
  int tam = 0;
  for (int pivo = (strlen(palavra) - 1); pivo > 0; pivo--)
  {
    for (int comeco = 0; comeco < pivo; comeco++)
    {
      for (int i = comeco; i <= pivo; i++)
      {
        palindromo[tam++] = palavra[i];
      }

      tam = 0;
      verificador = verifica_palindromo(palindromo);

      if (verificador == 0)
      {
        memset(palindromo, 0, strlen(palindromo));
      }
      if (verificador == -1)
      {
        return 0;
      }
    }
  }
  return -1;
}
