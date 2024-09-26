#include <stdio.h>
#include <stdlib.h>

main()
{
    // Inicializa o ponteiro 'p' como NULL. Isso é importante quando se usa 'realloc' pela primeira vez,
    // pois 'realloc' pode alocar memória de forma segura mesmo se o ponteiro inicial for NULL.
    int *p = NULL;

    // A função 'realloc' tenta redimensionar o bloco de memória apontado por 'p'.
    // No primeiro uso, como 'p' é NULL, 'realloc' age como 'malloc', alocando 1 espaço de memória para um inteiro.
    // Sintaxe: realloc(ponteiro, novo_tamanho_em_bytes)
    // Aqui, '1 * sizeof(int)' significa que estamos alocando espaço suficiente para armazenar um único inteiro.
    p = (int *)realloc(p, 1 * sizeof(int));





    
}
