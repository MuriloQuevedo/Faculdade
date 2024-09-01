#include <stdio.h>

// Função recursiva direta para calcular o fatorial
int fatorial(int x);

int main() {
    int numero;

    // Solicita ao usuário que insira um número
    printf("Digite um número inteiro não-negativo: ");
    scanf("%d", &numero);

    // Verifica se o número é negativo
    if (numero < 0) {
        printf("O fatorial não está definido para números negativos.\n");
    } else {
        // Exibe o resultado
        printf("O fatorial de %d é %d\n", numero, fatorial(numero));
    }
    return 0;
}

int fatorial(int x) 
{
    // Caso base: o fatorial de 0 ou 1 é 1
    if (x <= 1) {
        return 1;
    } else {
        // Chamada recursiva direta
        return x * fatorial(x - 1);
    }
}
