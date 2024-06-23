#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    /*Nessa Primeira parte do código, determinamos todas as variáveis que iremos precisar para determinar as áreas e os volumes
      das figuras descritas no arquivo "cenagrafica.txt*/

    string objeto;
    double lado, lado1, lado2, lado3, raio, altura, geratriz, base, area, volume, area_cena = 0, volume_cena = 0;
    const float PI = 3.14159265359;

    /*Já nessa sequência, usamos ifstream para abrir o arquivo mencionado e criamos uma condicional para emitir erro caso o arquivo
     não exista*/

    ifstream arquivo("cenagrafica.txt");

    if (!arquivo.is_open()) {
        cout << endl << "Erro, arquivo não existe";
        return 1;
    }
    
    /*Usamos agora um bloco com as condicionais while, if e else if:
     *
     * While é usado com função de executar todas essas condicionais enquanto o valor da variável objeto for dado
     * pelo arquivo "cenagrafica.txt", ou seja, até todos os comandos serem executados.
     *
     * If e else if são usados para calcular e exibir a área das figuras conforme o prescrito no arquivo, cada um personalizado
     * conforme as fórmulas correspondentes.
     */

    while (arquivo >> objeto) {

        if (objeto == "Quadrado" || objeto == "quadrado") {
            arquivo >> lado;
            area = pow(lado, 2);
            cout << endl << objeto << endl;
            cout << endl << "Área: " << area << endl;
            area_cena = area_cena + area;
        } else if (objeto == "Círculo" || objeto == "círculo") {
            arquivo >> raio;
            area = PI * pow(raio, 2);
            cout << endl << objeto << endl;
            cout << endl << "Área: " << area << endl;
            area_cena = area_cena + area;
        } else if (objeto == "Retângulo" || objeto == "retângulo") {
            arquivo >> base >> altura;
            area = base * altura;
            cout << endl << objeto << endl;
            cout << endl << "Área: " << area << endl;
            area_cena = area_cena + area;
        } else if (objeto == "Triângulo" || objeto == "triângulo") {
            arquivo >> base >> altura;
            area = base * altura / 2;
            cout << endl << objeto << endl;
            cout << endl << "Área: " << area << endl;
            area_cena = area_cena + area;
        } else if (objeto == "Paralelepípedo" || objeto == "paralelepípedo") {
            arquivo >> lado1 >> lado2 >> lado3;
            area = 2 * (lado1 * lado2) + 2 * (lado1 * lado3) + 2 * (lado2 * lado3);
            volume = lado1 * lado2 * lado3;
            cout << endl << objeto << endl;
            cout << endl << "Área: " << area << endl;
            cout << endl << "Volume: " << volume << endl;
            area_cena = area_cena + area;
            volume_cena = volume_cena + volume;
        } else if (objeto == "Cone" || objeto == "cone") {
            arquivo >> raio >> altura;
            geratriz = sqrt( pow(raio,2) + pow(altura,2));
            area = PI * raio * (raio + geratriz);
            volume = (PI * pow(raio, 2) * altura) / 3;
            cout << endl << objeto << endl;
            cout << endl << "Área: " << area << endl;
            cout << endl << "Volume: " << volume << endl;
            area_cena = area_cena + area;
            volume_cena = volume_cena + volume;
        } else if (objeto == "Cubo" || objeto == "cubo") {
            arquivo >> lado;
            area = 6 * pow(lado, 2);
            volume = pow(lado, 3);
            cout << endl << objeto << endl;
            cout << endl << "Área total: " << area << endl;
            cout << endl << "Volume: " << volume << endl;
            area_cena = area_cena + area;
            volume_cena = volume_cena + volume;
        } else if (objeto == "Esfera" || objeto == "esfera") {
            arquivo >> raio;
            area = 4.0 * PI * pow(raio, 2.0);
            volume = 4.0 / 3.0 * PI * pow(raio, 3);
            cout << endl << objeto << endl;
            cout << endl << "Área total: " << area << endl;
            cout << endl << "Volume: " << volume << endl;
            area_cena = area_cena + area;
            volume_cena = volume_cena + volume;
        } else if (objeto == "Cilindro" || objeto == "cilindro") {
            arquivo >> raio >> altura;
            area = 2 * PI * raio * (raio + altura);
            volume = PI * pow(raio, 2) * altura;
            cout << endl << objeto << endl;
            cout << endl << "Área total: " << area << endl;
            cout << endl << "Volume: " << volume << endl;
            area_cena = area_cena + area;
            volume_cena = volume_cena + volume;
        }
    }

    // E para finalizar, as linhas de código seguintes imprimem na tela o valor da área e volume totais da cena.
    cout << endl << "A área total da cena é: " << area_cena << endl;
    cout << endl << "O volume total da cena é: " << volume_cena;
    
    arquivo.close();

    return 0;
}