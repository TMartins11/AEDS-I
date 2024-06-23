/* Atividade 4 - AEDS I - Operações com Vetores
 * 
 * Autor: Thiago Martins - 2024.1.08.023
 *
 * Projeto que lida com operações dentro de um vetor de 1000 posições, fornecendo um menu que possibilita ao usuário:
 * 
 * 1- Buscar pela primeira ocorrência de um valor dentro do vetor
 * 2- Informar a quantidade de ocorrências de um número no vetor
 * 3- Buscar a ocorrência de valores dentro de um intervalo no vetor
 * 4- Inverter o vetor
 * 5- Excluir um valor do vetor
 * 6- Eliminar os valores repetidos do vetor
 * 7- Sair
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int TAM = 1000;
    int vet[TAM], novo_tam = TAM, escolha_usr, i = 0, j = 0, aux = 0; 
    
    srand(time(NULL));
    
    cout << "Projeto Operações com Vetores" << endl;
    
    // Vetor Original
    for(i = 0; i < TAM; i++){
        vet[i] = 100 + rand() % 101;
    }
    
    cout << endl << "Vetor Original: ";
    
    // Exibir Vetor Original
    for(i = 0; i < TAM; i++){
        cout << " " << vet[i];
    }
    
    cout << endl << endl << "Opções disponíveis:" << endl;
    cout << endl << "1- Buscar pela primeira ocorrência de um valor dentro do vetor";
    cout << endl << "2- Informar a quantidade de ocorrências de um número no vetor";
    cout << endl << "3- Buscar a ocorrência de valores dentro de um intervalo no vetor";
    cout << endl << "4- Inverter o vetor";
    cout << endl << "5- Excluir um valor do vetor";
    cout << endl << "6- Eliminar os valores repetidos do vetor";
    cout << endl << "7- Sair" << endl;
    cout << endl << "Obs.: Os números gerados no vetor vão de 100 a 200" << endl;
    
    do {
        cout << endl << "Escolha a opção desejada: ";
        cin >> escolha_usr;
        while(escolha_usr < 0 || escolha_usr > 7){
            cout << endl << "Opção inválida!!! Insira novamente: ";
            cin >> escolha_usr;
        }

        switch(escolha_usr){
            case 1: {
                // Mostrar primeira ocorrência de um valor
                int num_escolhido;
                int posicao_num = 0;
                
                cout << endl << "Digite o valor que deseja encontrar no vetor: ";
                cin >> num_escolhido;
    
                for(i = 0; i < TAM; i++){
                    if(num_escolhido == vet[i]){
                        posicao_num = i + 1;
                        break;
                    }
                }   
                
                if(posicao_num != 0){
                    cout << endl << "O número " << num_escolhido << " foi encontrado pela primeira vez na " << posicao_num << "º posição" << endl;
                } else {
                    cout << endl << "O número escolhido não foi encontrado no vetor";
                }
                break;
            }
            case 2: {
                // Mostrar a quantidade de vezes que um número aparece no vetor
                int num_escolhido2;
                int qtd_num = 0;
                
                cout << endl << "Insira o número o qual deseja checar as ocorrências no vetor: ";
                cin >> num_escolhido2;
    
                for(i = 0; i < TAM; i++){
                    if(num_escolhido2 == vet[i]){
                        qtd_num++;
                    }
                }
    
                if(qtd_num > 0){
                    cout << endl << "O número " << num_escolhido2 << " apareceu " << qtd_num << " vezes no vetor" << endl;
                } else {
                    cout << endl << "O número escolhido não foi encontrado no vetor" << endl;
                }
                break;
            }
            case 3: {
                // Calcular a quantidade de ocorrências de valores de um intervalo inserido pelo usuário
                int i_intervalo, f_intervalo;
                int qtd_intervalo = 0;
                
                cout << endl << "Informe o início do intervalo desejado: ";
                cin >> i_intervalo;
                cout << endl << "Informe o final do intervalo desejado: ";
                cin >> f_intervalo;
    
                for(i = 0; i < TAM; i++){
                    if(vet[i] >= i_intervalo && vet[i] <= f_intervalo){
                        qtd_intervalo++;
                    }
                }
    
                if(qtd_intervalo != 0){
                    cout << endl << "Os valores presentes no intervalo inserido aparecem " << qtd_intervalo << " vezes no vetor" << endl;
                } else {
                    cout << endl << "Nenhum valor do intervalo inserido está presente no vetor" << endl;
                }
                break;
            }
            case 4: {
                // Inverter o Vetor
                for(i = 0; i < TAM / 2; i++){
                    j = TAM - i - 1;
                    aux = vet[i];
                    vet[i] = vet[j];
                    vet[j] = aux;
                }
                
                cout << endl << "Vetor Invertido: ";
                
                // Exibir Vetor Invertido
                for(i = 0; i < TAM; i++){
                    cout << " " << vet[i];
                }
                
                cout << endl;
                
                break;
            }
            case 5: {
                 //Excluir um valor selecionado pelo usuário
                 int excluir_vetor;
                 cout << endl << "Insira o valor que deseja excluir do vetor: ";
                 cin >> excluir_vetor;

                for(i = 0; i < novo_tam; i++){
                    if(excluir_vetor == vet[i]){
                        for(j = i; j < novo_tam - 1; j++){
                            vet[j] = vet[j + 1];
                        }
                        novo_tam--;
                        i--;
                    }
                }

                //Exibir vetor após exclusão do número selecionado
                cout << "Vetor após exclusão: ";
                for(i = 0; i < novo_tam; i++){
                    cout << " " << vet[i];
                }

                cout << endl;

                break;
            }
            case 6: {
                //Excluir os valores repetidos do vetor
                for(i = 0; i < novo_tam; i++){
                    for(j = i + 1; j < novo_tam;){
                        if(vet[i] == vet[j]){
                            for(int k = j; k < novo_tam - 1; k++){
                                vet[k] = vet[k + 1];
                            }
                            novo_tam--;
                        }else{
                            j++;
                        }
                    }
                }

                //Exibir vetor sem os valores repetidos
                cout << endl << "Vetor sem repetidos: ";
                for(i = 0; i < novo_tam; i++){
                    cout << " " << vet[i];
                }

                cout << endl;

                break;
            }
        }
    } while(escolha_usr != 7);

    cout << endl << "Saindo do projeto, obrigado pelo acesso!!!" << endl;
    
    return 0;
}