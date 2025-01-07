/*
  File: Atividade 1 - AEDS I

  Programa que informa ao usuário o triângulo formado pelas dimensões inseridas
  por ele (se for possível com as medidas inseridas)
  
  Author: Thiago Martins da Silva - 2024.1.08.023

  Created on 12 de março de 2024, 23:08
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função auxiliar para verificar se o triângulo é retângulo
int ehRetangulo(float a, float b, float c) {
    return (pow(a, 2) == pow(b, 2) + pow(c, 2)) ||
           (pow(b, 2) == pow(a, 2) + pow(c, 2)) ||
           (pow(c, 2) == pow(a, 2) + pow(b, 2));
}

// Função principal
int main() {
    float lado1, lado2, lado3;

    printf("Vamos Formar Triângulos!!!\n");

    // Solicita o comprimento do 1º lado
    printf("\nInsira o comprimento do 1º lado: ");
    while (scanf("%f", &lado1) != 1 || lado1 <= 0) {
        printf("Valor inválido! Insira um número positivo: ");
        while (getchar() != '\n'); // Limpa o buffer, evitar caracteres indesejados.
    }

    // Solicita o comprimento do 2º lado
    printf("Insira o comprimento do 2º lado: ");
    while (scanf("%f", &lado2) != 1 || lado2 <= 0) {
        printf("Valor inválido! Insira um número positivo: ");
        while (getchar() != '\n'); // Limpa o buffer
    }

    // Solicita o comprimento do 3º lado
    printf("Insira o comprimento do 3º lado: ");
    while (scanf("%f", &lado3) != 1 || lado3 <= 0) {
        printf("Valor inválido! Insira um número positivo: ");
        while (getchar() != '\n'); // Limpa o buffer
    }

    // Verifica se as medidas formam um triângulo válido
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        printf("\nTriângulo formado: ");

        // Verifica o tipo do triângulo quanto aos lados
        if (lado1 == lado2 && lado2 == lado3) {
            printf("Equilátero");
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            printf("Isósceles");
        } else {
            printf("Escaleno");
        }

        // Verifica se o triângulo é retângulo
        if (ehRetangulo(lado1, lado2, lado3)) {
            printf(" e Retângulo");
        }

        printf(".\n");
    } else {
        printf("\nNão foi possível formar um triângulo com as dimensões inseridas.\n");
    }

    return 0;
}