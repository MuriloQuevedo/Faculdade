#include <stdio.h>
#include <stdlib.h>

main()
{
    // O casting (int *) converte o ponteiro genérico (void *) retornado por malloc para um ponteiro do tipo int. É obrigatório em C++
    int *p = (int *)malloc(sizeof(int));           // Aloca memória suficiente para armazenar um valor do tipo int
    int *p_dois = (int *)malloc(10 * sizeof(int)); // mesma coisa, mas para um vetor

    // Verificação se o malloc funcionou corretamente. Se malloc falhar, ele retorna NULL.
    // NULL é um ponteiro especial que indica que o ponteiro não aponta para uma área de memória válida.
    if (p == NULL)
    {
        printf("Malloc nao funcionou");
    }

    *p = 1000;        // Atribui o valor 1000 à posição de memória apontada pelo ponteiro 'p', ou seja, o inteiro alocado dinamicamente.
    printf("%i", *p); // Exibe o valor armazenado na posição de memória apontada por 'p', que é 1000.

    // A função free libera a memória alocada dinamicamente por malloc, evitando vazamentos de memória.
    free(p);
