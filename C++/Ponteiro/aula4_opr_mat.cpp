#include <stdio.h>

// Protótipos das funções
void soma(int *a, int *b, int *resultado);          // Ponteiros para a soma
void subtracao(int *a, int *b, int *resultado);     // Ponteiros para a subtração
void multiplicacao(int *a, int *b, int *resultado); // Ponteiros para a multiplicação
void divisao(int *a, int *b, int *resultado);       // Ponteiros para a divisão

int main() {
    int num1 = 15, num2 = 5; // Declaração de duas variáveis inteiras
    int res;                // Variável para armazenar o resultado

    // Chamada da função soma
    soma(&num1, &num2, &res); // Passa os endereços de num1 e num2, e o endereço de res
    printf("Soma: %d + %d = %d\n", num1, num2, res);

    // Chamada da função subtração
    subtracao(&num1, &num2, &res); // Passa os endereços
    printf("Subtração: %d - %d = %d\n", num1, num2, res);

    // Chamada da função multiplicação
    multiplicacao(&num1, &num2, &res); // Passa os endereços
    printf("Multiplicação: %d * %d = %d\n", num1, num2, res);

    // Chamada da função divisão
    divisao(&num1, &num2, &res); // Passa os endereços
    printf("Divisão: %d / %d = %d\n", num1, num2, res);

    return 0;
}

// Implementação da função soma
void soma(int *a, int *b, int *resultado) {
    // Desreferencia 'a' e 'b' para acessar seus valores e armazena a soma em 'resultado'
    *resultado = *a + *b;  
}

// Implementação da função subtração
void subtracao(int *a, int *b, int *resultado) {
    // Desreferencia 'a' e 'b' para acessar seus valores e armazena a diferença em 'resultado'
    *resultado = *a - *b;  
}

// Implementação da função multiplicação
void multiplicacao(int *a, int *b, int *resultado) {
    // Desreferencia 'a' e 'b' para acessar seus valores e armazena o produto em 'resultado'
    *resultado = *a * *b;  
}

// Implementação da função divisão
void divisao(int *a, int *b, int *resultado) {
    // Verifica se 'b' não é zero antes de realizar a divisão
    if (*b != 0) {
        *resultado = *a / *b; // Desreferencia 'a' e 'b' para realizar a divisão
    } else {
        printf("Erro: Divisão por zero!\n"); // Mensagem de erro se 'b' for zero
    }
}
