<h1 align='center'>AEDS I - Algoritmos e Estruturas de Dados I </h1>

<p align='center'> 
  <img loading='lazy' src="https://img.shields.io/badge/Language-gray?style=flat-square&logo=c&logoColor=white&labelColor=blue"/>
  <img loading='lazy' src="https://img.shields.io/badge/Status-Finalizado-green"/>
  <img loading='lazy' src="https://img.shields.io/badge/License-MIT-blue?style=flat-square"/>
</p>

<p align="center">
  Repositório com as atividades e projetos desenvolvidos na disciplina de Algoritmos e Estruturas de Dados I, cursada no 1º semestre de 2024, 
  como parte do <strong>Bacharelado em Ciências da Computação</strong> pela <em>Universidade Federal de Alfenas - MG.</em>
</p>

---

## Descrição

Este repositório contém os códigos desenvolvidos ao longo da disciplina de **Algoritmos e Estruturas de Dados I (AEDS I)**.  
Todos os projetos foram implementados utilizando a linguagem **C** e incluem **makefiles** para facilitar a compilação e a organização dos arquivos. 

### Recursos do Repositório:
- **Makefiles:**  
  - `make all`: Compila o projeto de forma simples e eficiente.  
  - `make clean`: Limpa os arquivos gerados durante a compilação, restaurando o estado inicial do projeto.
- **Organização Estruturada:** Códigos separados por pastas para facilitar a navegação e manutenção.
  - `source`: Contém os arquivos de código.
  - `objects`: Contém os arquivos objetos gerados a partir da compilação do código.
  - `instances`: Contém todos os arquivos instância que são utilizados no projeto.
---

## Atividades

### [`I - Formando Triângulos`](./Atividades/A1_Formartriangulos)

- **Descrição:**  
  O código permite que o usuário insira três valores correspondentes aos lados de um triângulo e determina se é possível formá-lo. Caso seja possível, o programa classifica o triângulo em equilátero, isósceles ou escaleno,  e verifica também se ele é retângulo. Se não for possível formar um triângulo, o programa avisa o usuário.

### [`II - Gerador de Alturas`](./Atividades/A2_Geradoralturas)

- **Descrição:**
  Projeto que gera 1000 alturas aleatoriamente entre 1.5m e 2.3m, informando 
  a maior altura, a menor, a média entre todas elas, assim como a porcentagem de pessoas
  com mais de 2m.

### [`III - Cena Gráfica`](./Atividades/A3_Cenagrafica)

- **Descrição:**
   Este projeto tem como objetivo o cálculo da área e do volume de diversas formas geométricas,
  cujas dimensões são lidas de um arquivo de entrada, o `cenagrafica.txt`. O programa calcula 
  medidas para as seguintes formas geométricas:
  - Bidimensionais: Quadrado, Círculo, Retângulo e Triângulo.
  - Tridimensionais: Paralelepípedo, Cone, Cubo, Esfera e Cilindro.
