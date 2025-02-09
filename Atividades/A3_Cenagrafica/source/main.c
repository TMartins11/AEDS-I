/* 
 * Este projeto tem como objetivo o cálculo da área e do volume de diversas formas geométricas,
 * cujas dimensões são lidas de um arquivo de entrada, o `cenagrafica.txt`. O programa calcula 
 * medidas para as seguintes formas geométricas:
 * 
 * - Bidimensionais: Quadrado, Círculo, Retângulo e Triângulo.
 * - Tridimensionais: Paralelepípedo, Cone, Cubo, Esfera e Cilindro.
 * 
 * O cálculo da área e volume de cada figura é realizado por funções específicas implementadas em 
 * uma biblioteca personalizada, "geo.h", que abstrai a lógica dos cálculos e proporciona um código 
 * mais modular e organizado.
 * 
 * Estrutura do Projeto:
 * 
 * O projeto é desenvolvido inteiramente em C, utilizando um Makefile para gerenciar a compilação 
 * e facilitar o processo de build. A biblioteca **geo.h** contém as funções que realizam os cálculos 
 * geométricos e que são chamadas no programa principal. O código é compilado utilizando o comando 
 * `make all`, gerando o executável `cenagrafica`.
 *
 * Autor: Thiago Martins - 2024.1.08.023
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "geo.h"

int main() {
    FILE *arq = fopen("./instancia/cenagrafica.txt", "r");
    if (!arq) {
        printf("\nErro! O arquivo não foi aberto corretamente.");
        return 1; 
    }

    char objeto[30];
    double lado1, lado2, lado3, raio, altura, base, area, volume, area_cena = 0, volume_cena = 0;

    printf("\nCena Gráfica - Calculando Área e Volume!\n");

    while (fscanf(arq, "%s", objeto) == 1) {
        if (strcmp(objeto, "Quadrado") == 0) {
            if (fscanf(arq, "%lf", &lado1) == 1) {
                Quadrado(lado1, &area, &area_cena);
            }
        } else if (strcmp(objeto, "Círculo") == 0) {
            if (fscanf(arq, "%lf", &raio) == 1) {
                Circulo(raio, &area, &area_cena);
            }
        } else if (strcmp(objeto, "Retângulo") == 0) {
            if (fscanf(arq, "%lf %lf", &base, &altura) == 2) {
                Retangulo(base, altura, &area, &area_cena);
            }
        } else if (strcmp(objeto, "Triângulo") == 0) {
            if (fscanf(arq, "%lf %lf", &base, &altura) == 2) {
                Triangulo(base, altura, &area, &area_cena);
            }
        } else if (strcmp(objeto, "Paralelepípedo") == 0) {
            if (fscanf(arq, "%lf %lf %lf", &lado1, &lado2, &lado3) == 3) {
                Paralelepipedo(lado1, lado2, lado3, &area, &volume, &area_cena, &volume_cena);
            }
        } else if (strcmp(objeto, "Cone") == 0) {
            if (fscanf(arq, "%lf %lf", &raio, &altura) == 2) {
                Cone(raio, altura, &area, &volume, &area_cena, &volume_cena);
            }
        } else if (strcmp(objeto, "Cubo") == 0) {
            if (fscanf(arq, "%lf", &lado1) == 1) {
                Cubo(lado1, &area, &volume, &area_cena, &volume_cena);
            }
        } else if (strcmp(objeto, "Esfera") == 0) {
            if (fscanf(arq, "%lf", &raio) == 1) {
                Esfera(raio, &area, &volume, &area_cena, &volume_cena);
            }
        } else if (strcmp(objeto, "Cilindro") == 0) {
            if (fscanf(arq, "%lf %lf", &raio, &altura) == 2) {
                Cilindro(raio, altura, &area, &volume, &area_cena, &volume_cena);
            }
        }
    }

    printf("\nResultados Finais\n");
    printf("\nÁrea Total: %.2lfm²", area_cena);
    printf("\nVolume Total: %.2lfm³\n", volume_cena);

    fclose(arq);

    return 0;
}