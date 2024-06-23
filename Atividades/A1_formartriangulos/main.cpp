/* 
  File: Atividade 1 - AEDS I
  
  Programa que informa ao usuário o triângulo formado pelas dimensões inseridas
  por ele (se for possível com as medidas inseridas)
    
  Author: Thiago Martins da Silva - 2024.1.08.023
 
  Created on 12 de março de 2024, 23:08
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    /* Nessa primeira parte do código, definimos as variáveis que usaremos
       para armazenar os valores dos 3 lados do triângulo*/
    
    float lado1,lado2,lado3;
    
    /*Nessa sequência, definimos comandos que instruam o usuário a inserir as medidas
     do triângulo, utilizamos o comando cin para registrar os dados dentro das variáveis
     criadas anteriormente, já o while é usado para impedir a entrada de valores negativos 
     ou nulos*/
    
    cout << "Vamos formar triângulos!" << endl;
        
    cout << endl << "Insira o comprimento do 1º lado: ";
    cin >> lado1;
    while(lado1 <= 0){
        cout << endl << "Valor inválido!" << endl << "Insira um número positivo: ";
        cin>> lado1;
    }
    
    cout << "\nInsira o comprimento do 2º lado: ";
    cin >> lado2;
     while(lado2 <= 0){
        cout << endl << "Valor inválido!" << endl << "Insira um número positivo: ";
        cin>> lado2;
    }
    
    cout << "\nInsira o comprimento do 3º lado: ";
    cin >> lado3;
     while(lado3 <= 0){
        cout << endl << "Valor inválido!" << endl << "Insira um número positivo: ";
        cin>> lado3;
    }
    
    /*Agora, criamos uma condicional para verificar se é possível formar um triângulo com
     as dimensões inseridas pelo usuário*/
    
    if(lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1){
        
    /*Já essas próximas condicionais têm o objetivo de definir o tipo de triângulo que será
     formado com base nos dados fornecidos pelo usuário, classificando-o como Equilátero, Isósceles
     ou Escaleno*/
        
        if(lado1 == lado2 && lado1 == lado3){
            cout << endl << "Você formou um triângulo Equilátero" << endl;
        }else if(lado1 == lado2 || lado1 == lado3 || lado2 == lado3){
            cout << endl << "Você formou um triângulo Isósceles";
        }else{
            cout << endl << "Você formou um triângulo Escaleno";
        }
    
    /*Essa condicional existe para informar se o triângulo formado anteriormente também é retângulo,
     usamos a função pow para elevar a suposta hipotenusa ao quadrado e checar se o teorema de pitágoras
     se aplica a figura formada, o que, se confirmado, indica um triângulo retângulo*/
        
    if(pow(lado1, 2) == pow(lado2, 2) + pow(lado3, 2)||
       pow(lado2, 2) == pow(lado1, 2) + pow(lado3, 2)||
       pow(lado3, 2) == pow(lado1, 2) + pow(lado2, 2)){
        
        cout << " e Retângulo";
    }
    
    /*E para finalizar, essa última condicional existe para informar ao usuário quando não é possível
     formar o polígono com as dimenões escollhidas, ou seja, quando a condição fundamental estabelecida 
     no primeiro bloco de condicionais é falsa*/
    
    }else{
        cout << endl << "É impossível formar um triângulo com as dimensões apresentadas";
    }
    
    return 0;
}