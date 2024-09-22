#include <stdio.h>

// Protótipos das funções, *a e *b recuperam os valores das variáveis num1 e num2
void soma(int *a, int *b, int *resultado);
void subtracao(int *a, int *b, int *resultado);
void multiplicacao(int *a, int *b, int *resultado);
void divisao(int *a, int *b, int *resultado);

int main()
{
    int num1, num2;    // Variáveis para armazenar os números digitados pelo usuário
    int res;           // Variável para armazenar o resultado
    int *ptr1 = &num1; // Ponteiro apontando para num1,  O ponteiro, por si só, não é suficiente; ele precisa apontar para uma variável que armazene um valor
    int *ptr2 = &num2; // Se você tentar usar apenas um ponteiro sem ter uma variável correspondente, não funcionará, pois não haverá valor armazenado para acessar. O ponteiro deve sempre apontar para uma variável válida


    // No scanf, passamos o ponteiro diretamente (ptr1) porque ele já contém o endereço da variável.
    // Não usamos *ptr1, pois isso passaria o valor armazenado, e scanf precisa de um endereço para armazenar o dado
    printf("Digite o primeiro numero: ");
    scanf("%i", ptr1); // Lê o valor diretamente no endereço de num1

    printf("Digite o segundo numero: ");
    scanf("%i", ptr2);

    // Chamada das funções e impressão dos resultados em um único printf
    soma(ptr1, ptr2, &res);
    printf("Numeros digitados: %i e %i\n", *ptr1, *ptr2);
    printf("Resultados:\n");
    printf("Soma: %i + %i = %i\n", *ptr1, *ptr2, res);

    subtracao(ptr1, ptr2, &res);
    printf("Subtracao: %i - %i = %i\n", *ptr1, *ptr2, res);

    multiplicacao(ptr1, ptr2, &res);
    printf("Multiplicacao: %i * %i = %i\n", *ptr1, *ptr2, res);

    divisao(ptr1, ptr2, &res);
    printf("Divisao: %i / %i = %i\n", *ptr1, *ptr2, res);

    return 0;
}

// Implementação da função soma
void soma(int *a, int *b, int *resultado)
{
    *resultado = *a + *b;
}

// Implementação da função subtração
void subtracao(int *a, int *b, int *resultado)
{
    *resultado = *a - *b;
}

// Implementação da função multiplicacao
void multiplicacao(int *a, int *b, int *resultado)
{
    *resultado = *a * *b;
}

// Implementação da função divisão
void divisao(int *a, int *b, int *resultado)
{
    if (*b != 0)
    {
        *resultado = *a / *b;
    }
    else
    {
        printf("Erro: Divisão por zero!\n");
    }
}
