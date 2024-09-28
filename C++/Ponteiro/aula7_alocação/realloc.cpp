#include <stdio.h>
#include <stdlib.h>

main()
{
    // Inicialmente, o ponteiro 'p' é definido como NULL.
    // Isso é importante porque, ao chamar 'realloc' pela primeira vez com um ponteiro NULL,
    // o comportamento é o mesmo de 'malloc' — ou seja, ele aloca um novo bloco de memória.
    int *p = NULL;

    // realloc tenta redimensionar a memória alocada para o ponteiro 'p'.
    // Estrutura: realloc(ponteiro, novo_tamanho_em_bytes)
    // 1. 'ponteiro': É o ponteiro original que aponta para o bloco de memória previamente alocado.
    //    Se for NULL, 'realloc' irá simplesmente alocar memória como 'malloc'.
    // 2. 'novo_tamanho_em_bytes': O novo tamanho que você deseja para o bloco de memória (em bytes).
    //    Isso pode ser maior ou menor do que o tamanho originalmente alocado.

    // Aqui, o 'realloc' está sendo usado para alocar memória suficiente para armazenar um único inteiro.
    p = (int *)realloc(p, 1 * sizeof(int)); // 1 * sizeof(int) garante alocação de memória para um único inteiro.

    // Após chamar 'realloc', sempre é bom verificar se a operação foi bem-sucedida.
    // Se o 'realloc' não conseguir alocar memória, ele retornará NULL, e a memória previamente alocada por 'p'
    // ainda permanece intacta (não será liberada automaticamente).
    if (p == NULL)
    {
        // Se a alocação falhar, imprime uma mensagem de erro e encerra o programa.
        printf("Falha na alocação de memória.\n");
    }
