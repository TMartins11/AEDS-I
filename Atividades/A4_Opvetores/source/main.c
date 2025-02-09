/* 
 * Atividade 4 - AEDS I - Operações com Vetores
 * Autor: Thiago Martins - 2024.1.08.023
 * 
 * Este programa permite realizar diversas operações com um vetor de 1000 elementos, como:
 * 1- Exibir o vetor
 * 2- Buscar pela primeira ocorrência de um valor dentro do vetor
 * 3- Informar a quantidade de ocorrências de um número no vetor
 * 4- Inverter o vetor
 * 5- Excluir um valor do vetor
 * 6- Eliminar todos os valores repetidos do vetor
 * 7- Buscar a ocorrência de valores dentro de um intervalo no vetor
 * 8- Sair
 * 
 * Para cada operação, insira o número correspondente ao menu.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search_number(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void remove_duplicates(int arr[], int *size) {
    for (int i = 0; i < *size; i++) {
        for (int j = i + 1; j < *size; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < *size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                (*size)--; 
                j--; 
            }
        }
    }
}

void display_array(int arr[], int size) {
    printf("\nVetor Completo:\n");
    for (int i = 0; i < size; i++) {
        printf("vet[%d] = %d\n", i, arr[i]);
    }
}

int main() {
    srand(time(NULL));
    int SIZE = 1000;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = (rand() % 101) + 100;
    }

    int op = 0, target = 0, tmp = 0, count = 0, start = 0, finish = 0;

    do {
        printf("\n====================== MENU ========================================\n");
        printf("1 - Exibir o vetor\n");
        printf("2 - Buscar pela primeira ocorrência de um valor no vetor\n");
        printf("3 - Informar a quantidade de ocorrências de um número no vetor\n");
        printf("4 - Inverter o vetor\n");
        printf("5 - Excluir um valor do vetor\n");
        printf("6 - Eliminar todos os valores repetidos do vetor\n");
        printf("7 - Buscar a ocorrência de valores dentro de um intervalo no vetor\n");
        printf("8 - Sair\n");
        printf("====================================================================\n");
        printf("Insira a opção desejada: ");
        while (scanf("%d", &op) != 1 || op > 8 || op < 0) {
            printf("\nOpção inválida! Insira novamente: ");
            while (getchar() != '\n');
        }

        switch (op) {
            case 1:
                display_array(arr, SIZE);
                break;

            case 2:
                printf("\nInsira o número que você deseja buscar no vetor: ");
                while (scanf("%d", &target) != 1) {
                    printf("\nOpção inválida! Insira novamente: ");
                    while (getchar() != '\n');
                }

                int index = search_number(arr, SIZE, target);
                if (index != -1) {
                    printf("\nO número desejado foi encontrado na posição %d do vetor!\n", index);
                } else {
                    printf("\nO número desejado não está presente no vetor.");
                }
                break;

            case 3:
                printf("\nInsira o número o qual deseja buscar as ocorrências no vetor: ");
                while (scanf("%d", &target) != 1) {
                    printf("\nOpção inválida! Insira novamente: ");
                    while (getchar() != '\n');
                }

                count = 0;
                for (int i = 0; i < SIZE; i++) {
                    if (arr[i] == target) {
                        count++;
                    }
                }

                if (count >= 1) {
                    printf("\nO número desejado foi encontrado %d vez(es) no vetor!", count);
                } else {
                    printf("\nO número desejado não está presente no vetor.");
                }
                break;

            case 4:
                printf("\nInvertendo vetor...\n");
                int j = 0;
                for (int i = 0; i < SIZE / 2; i++) {
                    j = SIZE - i - 1;
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
                printf("\nVetor Invertido!\n");
                display_array(arr, SIZE);
                break;

            case 5:
                printf("\nInsira o número que você deseja excluir do vetor: ");
                while (scanf("%d", &target) != 1) {
                    printf("\nOpção inválida! Insira novamente: ");
                    while (getchar() != '\n');
                }

                int del_number = search_number(arr, SIZE, target);
                if (del_number != -1) {
                    for (int i = del_number; i < SIZE - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    SIZE--;
                    printf("\nNúmero excluído com sucesso!");
                } else {
                    printf("\nO número desejado não está presente no vetor.");
                }
                break;

            case 6:
                printf("\nRemovendo duplicados...\n");
                remove_duplicates(arr, &SIZE);
                printf("\nDuplicados removidos!\n");
                display_array(arr, SIZE);
                break;

            case 7:
                printf("\nInsira o número que você deseja buscar no vetor: ");
                while (scanf("%d", &target) != 1) {
                    printf("\nOpção inválida! Insira novamente: ");
                    while (getchar() != '\n');
                }

                printf("\nAgora insira o início do intervalo do vetor em que deseja buscar: ");
                while (scanf("%d", &start) != 1 || start < 0 || start >= SIZE) {
                    printf("\nÍndice de início inválido! Insira novamente: ");
                    while (getchar() != '\n');
                }

                printf("\nInsira o final desse intervalo: ");
                while (scanf("%d", &finish) != 1 || finish < 0 || finish >= SIZE) {
                    printf("\nÍndice de final inválido! Insira novamente: ");
                    while (getchar() != '\n');
                }

                count = 0;
                for (int i = start; i <= finish; i++) {
                    if (arr[i] == target) {
                        count++;
                    }
                }

                if (count >= 1) {
                    printf("\nO número desejado foi encontrado %d vez(es) durante esse intervalo!", count);
                } else {
                    printf("\nO número desejado não está presente no intervalo selecionado.");
                }
                break;

            case 8:
                printf("\nSaindo do programa...\n");
                break;
        }
    } while (op != 8);

    return 0;
}