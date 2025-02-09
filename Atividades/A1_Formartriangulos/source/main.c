/*
  File: Atividade 1 - AEDS I

  Programa que informa ao usuário o triângulo formado pelas dimensões inseridas
  por ele (se for possível com as medidas inseridas).
  
  Author: Thiago Martins da Silva - 2024.1.08.023
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ehRetangulo(float a, float b, float c) {
    return (pow(a, 2) == pow(b, 2) + pow(c, 2)) ||
           (pow(b, 2) == pow(a, 2) + pow(c, 2)) ||
           (pow(c, 2) == pow(a, 2) + pow(b, 2));
}

int main() {
    float lado1, lado2, lado3;

    printf("Vamos Formar Triângulos!!!\n");

    printf("\nInsira o comprimento do 1º lado: ");
    while (scanf("%f", &lado1) != 1 || lado1 <= 0) {
        printf("Valor inválido! Insira um número positivo: ");
        while (getchar() != '\n'); 
    }

    printf("Insira o comprimento do 2º lado: ");
    while (scanf("%f", &lado2) != 1 || lado2 <= 0) {
        printf("Valor inválido! Insira um número positivo: ");
        while (getchar() != '\n'); 
    }

    printf("Insira o comprimento do 3º lado: ");
    while (scanf("%f", &lado3) != 1 || lado3 <= 0) {
        printf("Valor inválido! Insira um número positivo: ");
        while (getchar() != '\n'); 
    }

    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        printf("\nTriângulo formado: ");

        if (lado1 == lado2 && lado2 == lado3) {
            printf("Equilátero");
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            printf("Isósceles");
        } else {
            printf("Escaleno");
        }

        if (ehRetangulo(lado1, lado2, lado3)) {
            printf(" e Retângulo");
        }

        printf(".\n");
    } else {
        printf("\nNão foi possível formar um triângulo com as dimensões inseridas.\n");
    }

    return 0;
}