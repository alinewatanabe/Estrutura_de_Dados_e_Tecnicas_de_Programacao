#include <stdio.h>

#define MAX_ARR 1024 // Não modifique esse valor!!

int le_vetor(int vetor[MAX_ARR]);
void exibe_vetor(int veto[MAX_ARR], int tamanho_vetor);

int main (int argc, char *argv[]){
int vetor[MAX_ARR] = {};
int tam;

tam = le_vetor(vetor);
exibe_vetor(vetor, tam);
}

int le_vetor(int vetor[MAX_ARR]){
    int numero = 0;
    int i = 0;

    printf("Digite os valores do vetor: ");
    while((numero != -100) && (i < MAX_ARR)){
        scanf("%i", &numero);
        if(numero != -100){
            vetor[i] = numero;
            i++;
        }
    }
    return i;
}


void exibe_vetor(int vetor[MAX_ARR], int tamanho_vetor){
    printf("[");
    for(int i = 0; i < tamanho_vetor; i++){
        printf("%i", vetor[i]);
        if(i < tamanho_vetor - 1) printf(", ");
        
    }
    printf("]\n");
}





