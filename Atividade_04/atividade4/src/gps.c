/* 
 * Enunciado: 
 * Ver PDF!!!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING 100
#define MAX_ARRAY 4000
#define RAIO 6372795.477598

typedef struct {
  double lat, lon, alt;
  int tempo;
} Gps;

/* Funções de implementação obrigatória */
void troca_char(char *linha, char antigo, char novo);
void ler_ponto(char *linha, Gps *ponto);
void ler_linha(char *linha,FILE *arc);
double calcula_distancia(Gps pa, Gps pb);
double calcula_velocidade(Gps pa, Gps pb);
int ler_arquivo(char *nome_arq, Gps *pontos);
int escreve_dados(char *nome_arq, Gps *pontos, int tam);

/* Fuções para ajudar com testes */
void exibe_ponto(Gps ponto);
void exibe_pontos(Gps *pontos, int tam);

int main (int argc, char *argv[])
{
  char entrada[MAX_STRING] = "entrada.csv";
  char saida[MAX_STRING] = "saida.csv";
  FILE *arq;
  Gps *pontos;
  char *linha;
  
  ler_arquivo(&arq,&pontos);

  return 0;
}

void troca_char(char *linha, char antigo, char novo) {
  for(int i = 0; i<strlen(linha);i++){
    if(linha[i] == antigo){
      linha[i] = novo;
    }
  }
}

void ler_linha(char *linha, FILE *arc) {
  fgets(linha,MAX_STRING,arc);
  if(linha[strlen(linha) -1] == '\n'){
    linha[strlen(linha) - 1] = '\0';
  }    
}

void ler_ponto(char *linha, Gps *ponto) {

  troca_char(linha,',','.');
  troca_char(linha,';',',');

  ponto = strtok(NULL,",");  
}

double calcula_velocidade(Gps pa, Gps pb) {

  float vel;

  vel = 3,6*(calcula_distancia(pa,pb)/(pa.tempo - pb.tempo));

  return vel;
}

double calcula_distancia(Gps pa, Gps pb) {
  float dh;
  float dv;
  float Dist;

  dh = RAIO*acos(sin(pa.lat*(M_PI/180))* sin(pb.lat*(M_PI/180)) 
  + cos(pa.lat*(M_PI/180))*cos(pb.lat*(M_PI/180))*cos(pa.lon*(M_PI/180) - pb.lon*(M_PI/180)));

  dv = pb.alt - pa.alt;

  Dist = sqrt((pow(dh,2) + pow(dv,2)));

  return Dist;
}

int ler_arquivo(char *nome_arq, Gps *pontos) {

  nome_arq = fopen("entrada.csv", "r");

  if(nome_arq == NULL){
    printf("Erro ao abrir o arquivo.\n");
  }

  ler_linha(pontos, nome_arq);
  printf("%s\n", pontos);

  fclose(nome_arq);
  return 0;
}

int escreve_dados(char *nome_arq, Gps *pontos, int tam) {
}

void exibe_pontos(Gps *pontos, int tam) {
  for( int i = 0; i < tam; ++i )
    exibe_ponto(pontos[i]);
}

void exibe_ponto(Gps ponto) {
  printf("Coord: %f %s %f %s | Alt: %.1f m | Tempo: %i s\n",
      fabs(ponto.lat), ponto.lat<0?"Sul":"Norte",
      fabs(ponto.lon), ponto.lon<0?"Oeste":"Leste",
      ponto.alt, ponto.tempo);
}
