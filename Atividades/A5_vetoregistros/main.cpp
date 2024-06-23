/* 
 * File:   Registros (Struct) - Variável Composta Heterogênea
 * 
 * Projeto para armazenar informações em registors de dados.
 * 
 * Author: Thiago Martins - 2024.1.08.023
 * 
 * (typdef) => declaração de tipo (Não aloca memória até declarada no main)
 * 
 * As operações podem ser realizadas pelo usuário quantas vezes forem necessárias e devem ser:
 *  
 * - Busca pelo nome do amigo;
 * - Excluir um amigo;
 * - Inserir um amigo.
 * 
 *
 * Created on 29 de abril de 2024, 16:09
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int TAM = 1000;

typedef struct{
    bool valido = true;
    string nome;
    string celular;
    string cidade;
    string email;
} Pessoa; // Padrão que a struct seja nomeada com inicial Maiúscula

int main(){
    Pessoa agenda[TAM];
    int qtd = 0, contatos = 0, opcao = 0, i = 0, excluir = 0;
    
    // Abrir arquivo que fornecerá os dados iniciais da agenda
    ifstream arquivo_leitura("bancodedados.txt");
    if(!arquivo_leitura.is_open()){
        cout << endl << "Erro, arquivo não existe.";
        return 1;
    }
    
    arquivo_leitura >> agenda[qtd].nome;
     
    // Gerar Lista inicial de contatos
    while(agenda[qtd].nome != "FIM"){
        arquivo_leitura >> agenda[qtd].celular;
        arquivo_leitura >> agenda[qtd].cidade;
        arquivo_leitura >> agenda[qtd].email;
        contatos++;
        qtd++;
        arquivo_leitura >> agenda[qtd].nome;
    }
    
    // Fechando o arquivo inicial
    arquivo_leitura.close();
    
    //Abrindo o arquivo novamente para armazenar nele as mudanças na agenda
    ofstream arquivo_escrita("bancodedados.txt");
    if(!arquivo_escrita.is_open()){
        cout << endl << "Erro, arquivo não existe." << endl;
        return 1;
    }
    
    // Menu que fornece ao usuário as opções do programa, juntamente com uma repetição que impede a inserção de opções inválidas
    cout << "Agenda de Contatos" << endl;
    cout << endl << "Opções disponíveis:" << endl << "1 - Exibir Agenda" << endl << "2 - Adicionar Contato" << endl << "3 - Excluir Contato";
    cout << endl << "4 - Buscar Contato" << endl << "5 - Sair" << endl;
    cout << endl << "Escolha a opção desejada: ";
    cin >> opcao;
    while(opcao > 5 || opcao <= 0){
        cout << endl << "Opção inválida! Insira novamente: ";
        cin >> opcao;
    }
    
    // Loop com switch case para que o usuário possa acessar todas as opções do programa e sair conforme sua vontade
    while(opcao != 5){
        switch(opcao){
            // Exibir estado atual da agenda
            case 1:
                cout << endl << "Agenda" << endl;
                for( i = 0; i < contatos;i++){
                    if(agenda[i].valido == true){
                        cout << endl << i + 1 << "- Nome:" << agenda[i].nome;
                        cout << endl << "Telefone:" << agenda[i].celular;
                        cout << endl << "Cidade onde mora:" << agenda[i].cidade;
                        cout << endl << "Email:" << agenda[i].email;
                        cout << endl;
                    }
                }
                cout << endl << "Fim da Agenda" << endl;
                
                cout << endl << "Opções disponíveis:" << endl << "1 - Exibir Agenda" << endl << "2 - Adicionar Contato" << endl << "3 - Excluir Contato";
                cout << endl << "4 - Buscar Contato" << endl << "5 - Sair" << endl;
                cout << endl << "Escolha a opção desejada: ";
                cin >> opcao;
                while(opcao > 5 || opcao <= 0){
                    cout << endl << "Opção inválida! Insira novamente: ";
                    cin >> opcao;
                }
                break;     
            // Adicionar Contato
            case 2:
                cout << endl << "Adicionar Contato" << endl;
                cout << endl << "Insira o nome do contato: ";
                cin >> agenda[qtd].nome;
                cout << endl << "Telefone: ";
                cin >> agenda[qtd].celular;
                cout << endl << "Cidade onde mora: ";
                cin >> agenda[qtd].cidade;
                cout << endl << "Email: ";
                cin >> agenda[qtd].email;
                contatos++;
                qtd++;
                cout << endl << "Contato adicionado com sucesso!" << endl;
                
                cout << endl << "Opções disponíveis:" << endl << "1 - Exibir Agenda" << endl << "2 - Adicionar Contato" << endl << "3 - Excluir Contato";
                cout << endl << "4 - Buscar Contato" << endl << "5 - Sair" << endl;
                cout << endl << "Escolha a opção desejada: ";
                cin >> opcao;
                while(opcao > 5 || opcao <= 0){
                    cout << endl << "Opção inválida! Insira novamente: ";
                    cin >> opcao;
                }
                break;  
            // Excluir Contato
            case 3:
                cout << endl << "Excluir contato" << endl;
                cout << endl << "Insira a posição do contato que deseja excluir (Ex: Contato 1, Contato 2...): ";
                cin >> excluir;
                excluir -= 1;
                
                if(excluir >= 0 && excluir <= contatos){
                   agenda[excluir].valido = false; 
                   for(i = excluir; i < contatos - 1; i++){
                       agenda[i] = agenda[i + 1];
                   }
                   contatos--;
                }else{
                    cout << endl << "Contato Inexistente!Insira Novamente: ";
                    cin >> excluir;
                    excluir -= 1;
                }
                
                cout << endl << "Contato Excluído!" << endl;
                
                cout << endl << "Opções disponíveis:" << endl << "1 - Exibir Agenda" << endl << "2 - Adicionar Contato" << endl << "3 - Excluir Contato";
                cout << endl << "4 - Buscar Contato" << endl << "5 - Sair" << endl;
                cout << endl << "Escolha a opção desejada: ";
                cin >> opcao;
                while(opcao > 5 || opcao <= 0){
                    cout << endl << "Opção inválida! Insira novamente: ";
                    cin >> opcao;
                }
                break;
            //Busca por contato
            case 4:
                int contato_encontrado = 0;
                string nome_contato;
                cout << endl << "Buscar Contato" << endl;
                cout << endl << "Insira o nome do contato que você deseja encontrar: ";
                cin >> nome_contato;
                
                for(i = 0; i < contatos; i++){
                    if(agenda[i].nome == nome_contato){
                        cout << endl << "O contato buscado foi:" << endl;
                        cout << endl << i + 1 << "- Nome:" << agenda[i].nome;
                        cout << endl << "Telefone:" << agenda[i].celular;
                        cout << endl << "Cidade:" << agenda[i].cidade;
                        cout << endl << "Email:" << agenda[i].email << endl;
                        contato_encontrado = 1;
                    }
                }
                if(contato_encontrado == 0){
                    cout << "Contato não existente! Insira novamente: ";
                    cin >> nome_contato;
                }
                
                cout << endl << "Opções disponíveis:" << endl << "1 - Exibir Agenda" << endl << "2 - Adicionar Contato" << endl << "3 - Excluir Contato";
                cout << endl << "4 - Buscar Contato" << endl << "5 - Sair" << endl;
                cout << endl << "Escolha a opção desejada: ";
                cin >> opcao;
                while(opcao > 5 || opcao <= 0){
                    cout << endl << "Opção inválida! Insira novamente: ";
                    cin >> opcao;
                }
        }
    }
    
    // Adicionando o novo estado da agenda no arquivo "bancodedados.txt"
    for (i = 0; i < contatos; i++) {
        if (agenda[i].valido) {
            arquivo_escrita << agenda[i].nome << " ";
            arquivo_escrita << agenda[i].celular << " ";
            arquivo_escrita << agenda[i].cidade << " ";
            arquivo_escrita << agenda[i].email << " " << endl;
        }
    }
    
    arquivo_escrita << "FIM" << endl;
    
    // Fechando o arquivo após a inserção da agenda atualizada
    arquivo_escrita.close();
    
    cout << endl << "Fechando agenda...";
         
    return 0;
}