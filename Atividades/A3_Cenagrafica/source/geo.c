#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "geo.h"

// Função para calcular a área do quadrado
void Quadrado(double lado1, double *area, double *area_cena){
    *area = pow(lado1, 2);
    *area_cena += *area;
    printf("\nQuadrado - Área: %.2lfm²", *area); 
}

// Função para calcular a área do círculo
void Circulo(double raio, double *area, double *area_cena){
    *area = PI * (pow(raio, 2));
    *area_cena += *area;
    printf("\nCírculo - Área: %.2lfm²", *area); 
}

// Função para calcular a área do retângulo
void Retangulo(double base, double altura, double *area, double *area_cena){
    *area = (base * altura);
    *area_cena += *area;
    printf("\nRetângulo - Área: %.2lfm²", *area);
}

// Função para calcular a área do triângulo
void Triangulo(double base, double altura, double *area, double *area_cena){
    *area = (base * altura) / 2;
    *area_cena += *area;
    printf("\nTriângulo - Área: %.2lfm²\n", *area);
}

// Função para calcular a área e o volume do paralelepípedo
void Paralelepipedo(double lado1, double lado2, double lado3, double *area, double *volume, double *area_cena, double *volume_cena){
    *area = 2 * ((lado1 * lado2) + (lado2 * lado3) + (lado1 * lado3));
    *volume = lado1 * lado2 * lado3;
    *area_cena += *area;
    *volume_cena += *volume;
    printf("\nParalelepípedo - Área: %.2lfm², Volume: %.2lfm³", *area, *volume);
}

// Função para calcular a área e o volume do cone
void Cone(double raio, double altura, double *area, double *volume, double *area_cena, double *volume_cena){
    double geratriz = sqrt( pow(raio, 2) + pow(altura, 2));
    *area = PI * raio * (raio + geratriz);
    *volume = (PI * pow(raio, 2) * altura) / 3;
    *area_cena += *area;
    *volume_cena += *volume;
    printf("\nCone - Área: %.2lfm², Volume: %.2lfm³", *area, *volume);
}

// Função para calcular a área e o volume do cubo
void Cubo(double lado1, double *area, double *volume, double *area_cena, double *volume_cena){
    *area = 6 * (pow(lado1, 2));
    *volume = (pow(lado1, 3));
    *area_cena += *area;
    *volume_cena += *volume;
    printf("\nCubo - Área: %.2lfm², Volume: %.2lfm³", *area, *volume);
}

// Função para calcular a área e o volume da esfera
void Esfera(double raio, double *area, double *volume, double *area_cena, double *volume_cena){
    *area = 4.0 * PI * (pow(raio, 2.0));
    *volume = 4.0 / 3.0 * PI * (pow(raio, 3));
    *area_cena += *area;
    *volume_cena += *volume;
    printf("\nEsfera - Área: %.2lfm², Volume: %.2lfm³", *area, *volume);
}

// Função para calcular a área e o volume do cilindro
void Cilindro(double raio, double altura, double *area, double *volume, double *area_cena, double *volume_cena){
    *area = 2 * PI * raio * (raio + altura);
    *volume = PI * pow(raio, 2) * altura;
    *area_cena += *area;
    *volume_cena += *volume;
    printf("\nCilindro - Área: %.2lfm², Volume: %.2lfm³\n", *area, *volume);
}