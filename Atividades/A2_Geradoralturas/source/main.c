/* 
 * File:   Atividade 2 - AEDS I
 * 
 * Projeto que gera 1000 alturas aleatoriamente entre 1.5m e 2.3m, informando 
 * a maior altura, a menor, a média entre todas elas, assim como a porcentagem de pessoas
 * com mais de 2m.
 * 
 * Author: Thiago Martins da Silva - 2024.1.08.023
 *
 * Created on 27 de março de 2024, 12:22
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar uma altura aleatória entre 1.5m e 2.3m
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

        soma_alturas += altura; // Somar altura para cálculo da média
        
        // Contar pessoas com mais de 2.0m
        if(altura >= 2.0){
            pessoas_mais2m++;
        }

        // Atualizar maior e menor altura
        if(altura > maioralt){
            maioralt = altura;
        }

        if(altura < menoralt){
            menoralt = altura;
        }
    }

    // Calculando a média e porcentagem com mais de 2.0m
    double media = soma_alturas / total_pessoas;
    double percentual_mais2m = (pessoas_mais2m / total_pessoas) * 100;

    // Exibindo os resultados
    printf("\nResultados:\n");
    printf("\nMaior Altura: %.2fm", maioralt);
    printf("\nMenor Altura: %.2fm", menoralt);
    printf("\nMédia das Alturas: %.2f", media);
    printf("\nPorcentagem com mais de 2m: %.f%% \n", percentual_mais2m);

    return 0;
}