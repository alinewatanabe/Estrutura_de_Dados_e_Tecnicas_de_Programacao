/* Crie um programa que leia as notas de uma turma de 8 alunos e depois imprima as notas que 
são maiores que a média da turma*/

#include <stdio.h>
#define N 8

int main(int argc, char *argv[]){

int i = 0;
float notas[N];
float somaNotas = 0;
float media;

for(i;i<8;i++){
    printf("Digite a nota do aluno %i: ", i);
    scanf("%f", &notas[i]);
    somaNotas += notas[i];
}

media = somaNotas/N;

printf("Média da turma: %.2f\n", media);
printf("Os alunos que tiraram as notas acima da média foram:\n");

for(i;i<8;i++){
    if(notas[i] > media){
        printf("O aluno %i que tirou %.2f", i,notas[i] );
    }
    else{
        return 0;
    }
}

}