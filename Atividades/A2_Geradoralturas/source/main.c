/* 
 * File:   Atividade 2 - AEDS I
 * 
 * Projeto que gera 1000 alturas aleatoriamente entre 1.5m e 2.3m, informando 
 * a maior altura, a menor, a média entre todas elas, assim como a porcentagem de pessoas
 * com mais de 2m.
 * 
 * Author: Thiago Martins da Silva - 2024.1.08.023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double gerar_altura(){
    return ((rand() / (double) RAND_MAX) * 0.8) + 1.5;
}

int main(){
    srand(time(NULL));
    
    double altura, maioralt = 0, menoralt = 2.3;
    double soma_alturas = 0, pessoas_mais2m = 0;
    int total_pessoas = 1000;

    printf("\nGerador de Alturas\n");

    for(int i = 0; i < total_pessoas; i++){
        altura = gerar_altura(); 

        soma_alturas += altura; 
        
        if(altura >= 2.0){
            pessoas_mais2m++;
        }

        if(altura > maioralt){
            maioralt = altura;
        }

        if(altura < menoralt){
            menoralt = altura;
        }
    }

    double media = soma_alturas / total_pessoas;
    double percentual_mais2m = (pessoas_mais2m / total_pessoas) * 100;

    printf("\nResultados:\n");
    printf("\nMaior Altura: %.2fm", maioralt);
    printf("\nMenor Altura: %.2fm", menoralt);
    printf("\nMédia das Alturas: %.2f", media);
    printf("\nPorcentagem com mais de 2m: %.f%% \n", percentual_mais2m);

    return 0;
}