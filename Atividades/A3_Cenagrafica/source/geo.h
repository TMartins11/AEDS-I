#ifndef GEO_H // Se geo.h é indefinida.

#define GEO_H // Defina geo.h

#define PI 3.14159265359 

// Funções para calcular a área das figuras bidimensionais.
void Quadrado(double lado1, double *area, double *area_cena);
void Circulo(double raio, double *area, double *area_cena);
void Retangulo(double base, double altura, double *area, double *area_cena);
void Triangulo(double base, double altura, double *area, double *area_cena);

// Funções para calcular a área e o volume das figuras tridimensionais.
void Paralelepipedo(double lado1, double lado2, double lado3, double *area, double *volume, double *area_cena, double *volume_cena);
void Cone(double raio, double altura, double *area, double *volume, double *area_cena, double *volume_cena);
void Cubo(double lado1, double *area, double *volume, double *area_cena, double *volume_cena);
void Esfera(double raio, double *area, double *volume, double *area_cena, double *volume_cena);
void Cilindro(double raio, double altura, double *area, double *volume, double *area_cena, double *volume_cena);

#endif // Fim da definição.