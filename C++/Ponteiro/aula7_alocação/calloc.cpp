#include <stdio.h>
#include <stdlib.h>

main()
{
    int *p = (int *)calloc(5, sizeof(int)); // Aloca um array de 5 inteiros, inicializando todos os valores com 0

    *(p + 1) = 10; // Atribui o valor 10 na segunda posição do array (ou seja, p[1])

    printf("%i\n", *p);       // Imprime o valor da primeira posição do array, que será 0 (pois calloc inicializa os valores com 0)
    printf("%i\n", *(p + 1)); // Imprime o valor da segunda posição do array, que será 10
    printf("%i\n", p[1]);     // Alternativa para imprimir o valor da segunda posição do array, também será 10

    int *ponteiro = (int *)calloc(5, sizeof(int)); // Aloca outro array de 5 inteiros, inicializando todos os valores com 0
    int i;
    for (i = 0; i < 5; i++) // Itera pelas 5 posições do array alocado
    {
        // Para cada posição i, imprime o índice, o endereço do ponteiro e o valor armazenado naquela posição.
        printf("endereco do ponteiro %i = %p / O valor do ponteiro e %i\n", i, (ponteiro + i), *(ponteiro + i));
    }
}
