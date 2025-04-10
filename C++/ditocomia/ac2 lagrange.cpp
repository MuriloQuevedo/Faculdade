/*
    249309 Murilo Prestes de Quevedo
    249178	Yan Mielke Aletaif

*/
#include <stdio.h>
#include <stdlib.h>

// Função para receber os dados de entrada
void lerPontos(int quantidade, float *pontosX, float *pontosFX)
{
    for (int i = 0; i < quantidade; i++)
    {
        printf("Digite o valor de x[%d]: ", i);
        scanf("%f", &pontosX[i]);

        printf("Digite o valor de f(x[%d]): ", i);
        scanf("%f", &pontosFX[i]);
    }
}

// Função para calcular Lk(x)
float calcularLk(int k, int totalPontos, float x, float *pontosX)
{
    float resultado = 1.0f;
    for (int i = 0; i < totalPontos; i++)
    {
        if (i != k)
        {
            resultado *= (x - pontosX[i]) / (pontosX[k] - pontosX[i]);
        }
    }
    return resultado;
}

// Função para calcular P(x) usando interpolação de Lagrange
float interpolarLagrange(int totalPontos, float x, float *pontosX, float *pontosFX)
{
    float resultado = 0.0f;

    for (int k = 0; k < totalPontos; k++)
    {
        float Lk = calcularLk(k, totalPontos, x, pontosX);
        printf("L%d(%.2f) = %.4f\n", k, x, Lk);
        resultado += pontosFX[k] * Lk;
    }

    return resultado;
}

int main()
{
    int grauPolinomio, quantidadePontos;
    float *pontosX = NULL, *pontosFX = NULL;
    float valorParaInterpolar, resultado;
    char continuar;

    // Solicita o grau do polinômio
    printf("Informe o grau do polinômio desejado: ");
    scanf("%d", &grauPolinomio);

    quantidadePontos = grauPolinomio + 1;

    // Alocação dinâmica dos vetores
    pontosX = (float *)malloc(quantidadePontos * sizeof(float));
    pontosFX = (float *)malloc(quantidadePontos * sizeof(float));

    if (pontosX == NULL || pontosFX == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Leitura dos pontos
    printf("\n--- Cadastro dos Pontos ---\n");
    lerPontos(quantidadePontos, pontosX, pontosFX);

    // Loop de cálculo
    do
    {
        printf("\nDigite o valor de x para interpolar f(x): ");
        scanf("%f", &valorParaInterpolar);

        resultado = interpolarLagrange(quantidadePontos, valorParaInterpolar, pontosX, pontosFX);
        printf("Resultado: f(%.2f) = %.4f\n", valorParaInterpolar, resultado);

        printf("\nDeseja interpolar outro valor? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    // Liberação da memória
    free(pontosX);
    free(pontosFX);

    printf("\nPrograma encerrado. Obrigado por utilizar!\n");
    system("pause");
    return 0;
}
