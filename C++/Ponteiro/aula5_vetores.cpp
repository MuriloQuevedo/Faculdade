#include <stdio.h>

#define MAX_TAMANHO 1000 // Define o tamanho máximo do vetor

// Protótipos das funções
void preencherVetor(int *vetor, int *tamanho);
void exibirVetor(int *vetor, int tamanho);

int main()
{
    int tamanho;            // Tamanho do vetor
    int vetor[MAX_TAMANHO]; // Declaração do vetor com tamanho fixo

    printf("Digite o tamanho do vetor (max %d): ", MAX_TAMANHO);
    scanf("%d", &tamanho); // Lê o tamanho do vetor

    // Verifica se o tamanho está dentro do limite
    if (tamanho < 1 || tamanho > MAX_TAMANHO)
    {
        printf("Tamanho inválido. Deve ser entre 1 e %d.\n", MAX_TAMANHO);
        return 1;
    }

    preencherVetor(vetor, &tamanho); // Passa o endereço de tamanho, vetor é um ponteiro e não precisa de &, feito para mudar os valores, caso queira

    exibirVetor(vetor, tamanho); // Exibe o vetor

    return 0;
}

void preencherVetor(int *vetor, int *tamanho) // Acessa o valor que está na memória onde o ponteiro aponta, usado para alterar o valor *
{
    // Permite que o usuário altere o tamanho do vetor
    printf("Deseja alterar o tamanho do vetor? (1 para sim, 0 para nao): ");
    int alterar;
    scanf("%d", &alterar);

    if (alterar == 1)
    {
        printf("Digite o novo tamanho do vetor (max %d): ", MAX_TAMANHO);
        scanf("%d", tamanho); // Lê o novo tamanho do vetor

        // Verifica se o novo tamanho está dentro do limite
        if (*tamanho < 1 || *tamanho > MAX_TAMANHO)
        {
            printf("Tamanho inválido. Deve ser entre 1 e %d.\n", MAX_TAMANHO);
        }
    }

    // Preenche o vetor
    int i;
    for (i = 0; i < *tamanho; i++)
    {
        printf("Valor %d: ", i); // Solicita o valor começando do índice 0
        scanf("%d", &vetor[i]);  // Lê o valor do usuário e armazena no vetor
    }
}

void exibirVetor(int *vetor, int tamanho) // tamanho é uma variável inteira que contém um valor específico, n altera.
{
    printf("Os valores digitados foram: ");
    int i;
    for (i = 0; i < tamanho; ++i)
    {
        printf("%d ", vetor[i]); // Imprime cada elemento do vetor
    }
    printf("\n");
}
