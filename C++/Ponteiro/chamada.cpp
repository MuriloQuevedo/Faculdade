#include <stdio.h>

void troca(int *x, int *y);
int main()
{
    int a, b;

    a = 10;
    b = 20;

    // Chama a função 'troca' passando os endereços das variáveis 'a' e 'b'
    // '&a' e '&b' são os endereços de memória das variáveis 'a' e 'b'
    troca(&a, &b);

    // Após a chamada da função, os valores de 'a' e 'b' foram trocados
    printf("a = %i, b = %i\n", a, b); // Exibe os valores atualizados de 'a' e 'b'
}

// Função que troca os valores de duas variáveis inteiras usando ponteiros
void troca(int *x, int *y)
{
    int temp; // Variável temporária para armazenar o valor de uma das variáveis durante a troca

    temp = *x; // Armazena o valor apontado por 'x' (ou seja, o valor de 'a') na variável 'temp'
    *x = *y;   // Atribui o valor apontado por 'y' (ou seja, o valor de 'b') ao endereço apontado por 'x' (ou seja, 'a')
    *y = temp; // Atribui o valor armazenado em 'temp' (que era o valor de 'a') ao endereço apontado por 'y' (ou seja, 'b')

    // Após esses três passos, os valores de 'a' e 'b' foram trocados
}
