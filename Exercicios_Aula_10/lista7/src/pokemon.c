#include <stdio.h>
#include <stdlib.h>
#include "pokedex.h"

void Atacar(Pokemon *p1, Pokemon *p2);
int Batalha(Pokemon *p1, Pokemon *p2);
void ExibirTimes(Pokemon *p1, Pokemon *p2);

int main(){

    int pokemon_atual1 = 0;
    int pokemon_atual2 = 0;

    Pokemon p1[6];
    Pokemon p2[6];

    GerarTimes(p1, p2);
    ExibirTimes(p1, p2);

    while(((p1[5]).HP != 0) && ((p2[5]).HP != 0)){
        int ganhou;
        ganhou = Batalha(&p1[pokemon_atual1], &p2[pokemon_atual2]);
        if( ganhou == 1){
            pokemon_atual2 += 1;
        }

        else if(ganhou == 2){
            pokemon_atual1 += 1;
        }
        ExibirTimes(p1,p2);
    }

    if(p1[5].HP == 0){
        printf("/nVencedor: time 2\n\n");
    }

    if(p2[5].HP == 0){
        printf("/nVencedor: time 1\n\n");
    }
   
    return 0;
}

void Atacar(Pokemon *p1, Pokemon *p2){
    int dano;

    dano = p1->AT - p2->DF;
    if(p2->DF < p1->AT){
        p2->HP -= dano;
    }

    else{
        p2->HP -= 1;
    }

    if(p2->HP < 0){
        p2->HP = 0;
    }

}

int Batalha(Pokemon *p1, Pokemon *p2){

    if(p1->SP >= p2->SP){
        while((p1->HP != 0) && (p2->HP != 0)){
            Atacar(p1,p2);
            if(p2->HP != 0){
                Atacar(p2, p1);
            }
        }
    }

    if(p2->SP > p1->SP){
        while((p1->HP != 0) && (p2->HP != 0)){
            Atacar(p2,p1);
            if(p1->HP != 0){
                Atacar(p1,p2);
            }
        }        
    }

    if(p1->HP == 0){
        return 2; // time 2 venceu
    }

    if(p2->HP == 0){
        return 1; // time 1 venceu
    }

}

void ExibirTimes(Pokemon* p1, Pokemon* p2){
    //system("CLS"); // usar "CLS" no Windows
    printf("Jogador 1\n\n");
    printf("        Nome        \tHP\tAT\tDF\tSP\t\n");

    for(int i = 0; i < 6; i++){
        printf("%s\t%i\t%i\t%i\t%i\t\n", p1[i].Nome,p1[i].HP,p1[i].AT,p1[i].DF,p1[i].SP);
    }

    printf("\n\nJogador 2\n\n");
    for(int i = 0; i < 6; i++){
        printf("%s\t%i\t%i\t%i\t%i\t\n", p2[i].Nome,p2[i].HP,p2[i].AT,p2[i].DF,p2[i].SP);
    }
    getchar();
}
