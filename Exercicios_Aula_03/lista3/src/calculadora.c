#include <stdio.h>
#include <math.h>

int menu();
float soma(float a, float b);
float subtracao(float a, float b);
float multiplicacao(float a, float b);
float divisao(float a, float b);
float raiz_n(float x, float n);
float potencia_n(float exp, float pot);
float seno(float ang_graus);
float cosseno(float ang_graus);

int main (int argc, char *argv[]){

// Variaveis Locais
int num;
float ang_graus;
float x;
float n;
float a;
float b;
float resposta;

  printf("** Calculadora V1.0 **\n\n\n");
  printf("Para utilizar a calculadora, digite uma das opções abaixo.\n");
  printf("\t1 - Soma\n");
  printf("\t2 - Subtração\n");
  printf("\t3 - Multiplicação\n");
  printf("\t4 - Divisão\n");
  printf("\t5 - Raiz enésima\n");
  printf("\t6 - X elevado a N\n");
  printf("\t7 - Seno (graus)\n");
  printf("\t8 - Cosseno (graus)\n");
  printf("\t-1 - Sair\n");

  printf("Digite uma opção: ");
  scanf("%i", &num);
  
  // Menu
  switch (num){
  case -1:
    printf("Saindo...");
    break;

  case 1:
    printf("Soma\n");
    printf("Digite os valores (a + b): ");
    scanf("%f+%f", &a, &b);

    resposta = soma(a,b);
    printf("%.2f + %.2f = %.2f", a,b,resposta);
    break;
  
  case 2:
    printf("Subtração\n");
    printf("Digite os valores (a - b): ");
    scanf("%f-%f", &a, &b);

    resposta = subtracao(a,b);
    printf("%.2f - %.2f = %.2f", a,b,resposta);
    break;

  case 3:
    printf("Multiplicação\n");
    printf("Digite os valores (a * b): ");
    scanf("%f*%f", &a, &b);

    resposta = multiplicacao(a,b);
    printf("%.2f * %.2f = %.2f", a,b,resposta);
    break;
  
  case 4:
    printf("Divisão\n");
    printf("Digite os valores (a / b): ");
    scanf("%f/%f", &a, &b);

    resposta = divisao(a,b);
    printf("%.2f / %.2f = %.2f", a,b,resposta);
    break;

    case 5:
    printf("Raiz Enésima\n");
    printf("Digite os valores (x r n): ");
    scanf("%fr%f", &x, &n);

    resposta = raiz_n(x,n);
    printf("%.2f r %.2f = %.2f", x,n,resposta);
    break;

    case 6:
    printf("X elevado a N\n");
    printf("Digite os valores (exp ^ pot): ");
    scanf("%f^%f", &x, &n);

    resposta = potencia_n(x,n);
    printf("%.2f ^ %.2f = %.2f", x,n,resposta);
    break;

    case 7:
    printf("Seno\n");
    printf("Digite o valor: ");
    scanf("%f", &ang_graus);

    resposta = seno(ang_graus);
    printf("seno(%.2f) = %.2f", ang_graus,resposta);
    break;
  
    case 8:
    printf("Cosseno\n");
    printf("Digite o valor: ");
    scanf("%f", &ang_graus);

    resposta = cosseno(ang_graus);
    printf("cosseno(%.2f) = %.2f", ang_graus,resposta);
    break;

  default:
    printf("Digite uma opção válida!");
    break;

  }


  return 0;
}


float soma(float a, float b){
  return a + b;
}

float subtracao(float a, float b){
  return a - b;
}

float multiplicacao(float a, float b){
  return a*b;
}

float divisao(float a, float b){
  if ((a || b) != 0){
    return a/b;
  } 
  else{
    return INFINITY;
  }
}

float raiz_n(float x, float n){
  return pow(x, 1/n);
}

float potencia_n(float x, float n){
  return pow(x,n);
}

float seno(float ang_graus){
  return sin((ang_graus*M_PI)/(180));
}

float cosseno(float ang_graus){
  return cos((ang_graus*M_PI)/(180));
}

