/*
    Nome: [SEU NOME AQUI]
    RA: [SEU RA AQUI]
    Descrição: Programa que utiliza interpolação polinomial de Lagrange para calcular valores não tabelados de uma função,
    utilizando ponteiros, chamada por referência e funções modulares.
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipação das funções
void receberDados(float **x, float **fx, int *n);
float calcularLagrange(float *x, float *fx, int n, float valorX);
void liberarMemoria(float *x, float *fx);

int main() {
    float *x = NULL, *fx = NULL;
    int n;
    float valorX, resultado;
    char opcao;

    receberDados(&x, &fx, &n);

    do {
        printf("\nDigite o valor de x que deseja interpolar: ");
        scanf("%f", &valorX);

        resultado = calcularLagrange(x, fx, n, valorX);
        printf("f(%.2f) = %.6f\n", valorX, resultado);

        printf("Deseja interpolar outro valor? (s/n): ");
        scanf(" %c", &opcao);
    } while (opcao == 's' || opcao == 'S');

    liberarMemoria(x, fx);

    return 0;
}

// Função para receber os dados dos pontos e armazenar dinamicamente
void receberDados(float **x, float **fx, int *n) {
    int i;

    printf("Informe a quantidade de pontos: ");
    scanf("%d", n);

    *x = (float *)malloc(*n * sizeof(float));
    *fx = (float *)malloc(*n * sizeof(float));

    if (*x == NULL || *fx == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    printf("\nInforme os pares (x, f(x)):\n");
    for (i = 0; i < *n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", *x + i);
        printf("f(x[%d]): ", i);
        scanf("%f", *fx + i);
    }
}

// Função que calcula a interpolação de Lagrange
float calcularLagrange(float *x, float *fx, int n, float valorX) {
    float resultado = 0.0f;

    for (int i = 0; i < n; i++) {
        float Li = 1.0f;

        for (int j = 0; j < n; j++) {
            if (j != i) {
                Li *= (valorX - *(x + j)) / (*(x + i) - *(x + j));
            }
        }

        resultado += Li * (*(fx + i));
        printf("L%d(%.2f) = %.6f\n", i, valorX, Li);
    }

    return resultado;
}

// Liberação da memória alocada
void liberarMemoria(float *x, float *fx) {
    free(x);
    free(fx);
}
