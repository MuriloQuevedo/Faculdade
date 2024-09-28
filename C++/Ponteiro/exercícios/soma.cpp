#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void mostra(int *p, int tam);
void separar_pares_e_impares(int *p_lista, int tam, int *pares, int *tam_pares, int *impar, int *tam_impar);

int main()
{
    int *p_lista = NULL; // Ponteiro para armazenar os números digitados
    int *pares = NULL;   // Ponteiro para armazenar os números pares
    int *impar = NULL;   // Ponteiro para armazenar os números ímpares
    int tam = 0;         // Tamanho da lista de números
    int tam_pares = 0;   // Tamanho da lista de números pares
    int tam_impar = 0;   // Tamanho da lista de números ímpares
    char op = 'S';       // Variável para continuar inserindo números

    do
    {
        aloca(&p_lista, tam + 1);
        printf("Usuario digite um numero %i: ", tam + 1);
        scanf("%i", p_lista + tam); // Correção aqui
        tam++;

        printf("Deseja continuar? (S/N): ");
        scanf("%c", &op); // Correção aqui para leitura correta de op

    } while (op == 's' || op == 'S');

    separar_pares_e_impares(p_lista, tam, &pares, &tam_pares, &impar, &tam_impar);

    // Mostra os resultados
    printf("Somas pares:\n");
    mostra(pares, tam_pares);

    printf("Somas impares:\n");
    mostra(impar, tam_impar);

    return 0;
}

void aloca(int **p, int tam)
{
    if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
    {
        printf("Erro na alocacao\n");
        exit(1);
    }
}

void soma_pares_impares(int *p_lista, int tam, int **pares, int *tam_pares, int **impar, int *tam_impar)
{
    *tam_pares = 0;
    *tam_impar = 0;

    // Percorre a lista somando o primeiro com o último, o segundo com o penúltimo, e assim por diante
    for (int i = 0; i < tam / 2; i++)
    {
        int soma = p_lista[i] + p_lista[tam - i - 1]; // Soma o elemento atual com o correspondente do final
        if (soma % 2 == 0)
        { // Verifica se a soma é par
            aloca(pares, *tam_pares + 1);
            (*pares)[*tam_pares] = soma;
            (*tam_pares)++;
        }
        else
        { // A soma é ímpar
            aloca(impar, *tam_impar + 1);
            (*impar)[*tam_impar] = soma;
            (*tam_impar)++;
        }
    }

    // Se a quantidade de números for ímpar, verifica o número do meio
    if (tam % 2 != 0)
    {
        int meio = p_lista[tam / 2];
        if (meio % 2 == 0)
        { // Número do meio é par
            aloca(pares, *tam_pares + 1);
            (*pares)[*tam_pares] = meio;
            (*tam_pares)++;
        }
        else
        { // Número do meio é ímpar
            aloca(impar, *tam_impar + 1);
            (*impar)[*tam_impar] = meio;
            (*tam_impar)++;
        }
    }
}

void mostra(int *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}