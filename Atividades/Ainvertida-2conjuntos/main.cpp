/* Aula 16 - AEDS I - Atividade
 
   Autor: Thiago Martins - 2024.1.08.023
   
   Objetivo: Conhecer e implementar as operações básicas sobre conjuntos de valores.
   
   Etapas:
    1- Criar um projeto novo - FEITO;
    2- Criar 2 vetores de 10 números inteiros, com valores repetidos em cada um - FEITO;
    3- Remover os valores repetidos de cada um deles - FEITOS;
    4- Implementar a operação de união entre eles - FEITO;
    5- Implementar a operação de intersecção entre eles - FEITO;
    6- Melhorar as operações acima para que elas sejam o mais simples e rápido possível - FEITO;
*/

#include <iostream>

using namespace std;

int main(){
    int conjunto1[10] = {5, 4, 2, 5, 3, 2, 4, 8, 2, 9};
    int conjunto2[10] = {7, 1, 12, 10, 9, 2, 8, 1, 2, 7};
    
    int tam1 = 10, tam2 = 10;
    
    cout << "Operações em conjuntos de valores" << endl;

    //Remover valores repetidos (Conjunto 1)
    int i = 0;

    /*O código para fazer isso consiste em comparar conjunto1[i] com conjunto1[j], ou seja, comparar com a posição subsequente até achar um número duplicado,
    assim que o duplicado é encontrado, salvamos a posição dele com a variável k, adicionamos seu "limitante" como tam1 - 1, afim de não empurrar nenhum valor
    pra fora do vetor, após isso, é necessário somente atribuir ao número repetido o próximo número na sequência, zerando o subsequente e deslocando todos os
    valores para a esquerda*/

    for( i = 0; i < tam1; i++){
        for(int j = i + 1; j < tam1;){
            if(conjunto1[i] == conjunto1[j]){
                for(int k = j; k < tam1 - 1; k++){
                    conjunto1[k] = conjunto1[k + 1];
                }
                tam1--;
            }else{
                j++;
            }
        }
    }

    //Exibir vetor sem duplicados (Conjunto 1)
    cout << endl << "Conjunto 1 sem duplicados: ";
    for(i = 0; i < tam1; i++){
        cout << " " << conjunto1[i]; 
    }

    //Vetor sem duplicados (Conjunto 2)
    i = 0;
    for(i = 0; i < tam2; i++){
        for(int j = i + 1; j < tam2;){
            if(conjunto2[i] == conjunto2[j]){
                for( int k = j; k < tam2 - 1; k++){
                    conjunto2[k] = conjunto2[k + 1];
                }
                tam2--;
            }else{
                j++;
            }
        }
    }

    //Exibir Conjunto 2 sem duplicados
    cout << endl << endl << "Conjunto 2 sem duplicados: ";
    for(i = 0; i < tam2; i++){
        cout << " " << conjunto2[i];
    }

    //Implentar a união entre conjuntos
    int conjunto3[20];
    int tam3 = 13;

    for(i = 0; i < tam1; i++){
        conjunto3[i] = conjunto1[i];
    }

    for( int j = 0; i < tam3; j++){
        conjunto3[i] = conjunto2[j];
        i++;
    }

    //Retirar duplicados da união de conjuntos

    for( i = 0; i < tam3; i++){
        for(int j = i + 1; j < tam3;){
            if(conjunto3[i] == conjunto3[j]){
                for(int k = j; k < tam3 - 1; k++){
                    conjunto3[k] = conjunto3[k + 1];
                }
                tam3--;
            }
            j++;
        }
    }

    //Exibir a União entre conjuntos (sem repetidos)
    cout << endl << endl << "União entre conjunto 1 e conjunto 2: ";
    for(i = 0; i < tam3; i++){
        cout << " " << conjunto3[i];
    }

    //Intersecção entre os conjuntos 1 e 2
    int conjunto4[10];
    int tam4 = 0;
    for( i = 0; i < tam1; i++) {
        for (int j = 0; j < tam2; j++) {
            if (conjunto1[i] == conjunto2[j]) {
                conjunto4[tam4++] = conjunto1[i];
            }
        }
    }

    //Exibir a intersecção entre os conjuntos 1 e 2
    cout << endl << endl << "Intersecção entre conjunto 1 e conjunto 2: ";
    for(i = 0; i < tam4; i++){
        cout << " " << conjunto4[i];
    }

    return 0;
}