#include <stdio.h>

main()
{

    int x = 10;    // Variável normal
    int *ptr = &x; // Ponteiro que armazena o endereço de x

    printf("Valor de x: %i\n", x);                   // Imprime o valor de x
    printf("Endereco de x: %p\n", &x);               // Imprime o endereço de x, precisa do & para achar
    printf("Endereco armazenado em ptr: %p\n", ptr); // Imprime o endereço armazenado no ponteiro, sem *
    printf("Valor apontado por ptr: %i\n", *ptr);    // Imprime o valor de x através do ponteiro, com *

    
}
