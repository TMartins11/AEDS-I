/* 
 * File:   Atividade 2 - AEDS I
 * 
 * Projeto que gera 1000 alturas aleatoriamente entre 1.5m e 2.3m, informando 
 * a maior altura, a menor, a média entre elas, assim como a porcentagem de pessoas
 * com mais de 2m.
 * 
 * Author: Thiago Martins da Silva - 2024.1.08.023
 *
 * Created on 27 de março de 2024, 12:22
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  
 /*Nessa primeira parte do código, declaramos as variáveis que utilizaremos no processo
  *e utilizamos o comando srand(time(NULL)) para garantir valores realmente aleatórios em cada execução*/
    
  int alturas;
  double media, maioraltura = 0, menoraltura = 230, mais2m = 0, i = 0;

  srand(time(NULL));

  cout << endl << "Gerador de Alturas!!!" << endl;
  
 /*Já na 2º Parte do programa, utilizamos a função for para gerar exatamente 1000 números, fazendo uso de
  *uma cadeia de if dentro da primeira função para conseguir armazenar o maior e menor valor gerados. assim como
  *fazer o cálculo da média entre todas as 1000 alturas*/
  
  for (i = 0; i < 1000; i++)
  {

    /*Utilizamos essa próxima linha de código a fim de que a variável alturas receba um valor aleatório entre 230 e 150,
     *valores estes que iremos dividir no final do código, para que correspondam a um intervalo de alturas entre 1.5m
     *e 2.3m*/
    
    alturas = rand() % (230 + 1 - 150) + 150;
    
    if (alturas >= 200)
    {
      mais2m++;
      if (alturas / 100.0 > maioraltura)
      {
        maioraltura = alturas;
      }
    }
    else if (alturas / 100.0 < menoraltura)
    {
      menoraltura = alturas;
    }
    media += alturas;
  }

/*E para finalizar, dividimos as variáveis media e mais2m para que o intervalo dos números gerados
 *seja sempre entre 1.5m e 2.3m de altura, como desejado. Também realizamos 4 linhas de código afim de emitir
 *as informações desejadas na tela, finalizando assim o programa e cumprindo todas os objetivos propostos*/
  
  media /= 100000;
  mais2m = (mais2m / 1000) * 100;

  cout << endl << "A maior altura gerada foi: " << maioraltura / 100.0 << endl;
  cout << endl << "A menor altura gerada foi: " << menoraltura / 100.0 << endl;
  cout << endl << "A média entre as alturas geradas foi: " << media << endl;
  cout << endl << "A porcentagem de pessoas maiores de 2m é: %" << mais2m << endl;

  return 0;
}
