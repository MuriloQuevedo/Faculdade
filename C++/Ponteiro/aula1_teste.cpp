#include <stdio.h>

main()
{
    int x = 10; // Variável 'x' recebe o valor 10
    int *ptr;   // Declaração de um ponteiro para 'int'

    ptr = &x; // O ponteiro 'ptr' recebe o endereço de 'x'

    int y = 20; // Variável 'y' recebe o valor 20
    *ptr = y;   // O valor armazenado (tem que usar *, se não, não pega o valor) no endereço que 'ptr' aponta (ou seja, 'x') é substituído pelo valor de 'y'

    printf("Com ponteiros:\n");
     printf("Valor de y: %i\n", y);
    printf("Valor de x: %i\n", x);                // Imprime o valor de 'x' após ser modificado
    printf("Valor apontado por ptr: %i\n", *ptr); // Imprime o valor apontado por 'ptr' (o valor de 'x')

    // Parte sem ponteiros
    int a = 10; // Variável 'a' recebe o valor 10
    int b = a;  // Variável 'b' recebe o valor de 'a' (10)

    a = 20; // O valor de 'a' é alterado para 20, mas isso não afeta 'b'

    printf("\nSem ponteiros:\n");
    printf("Valor de a: %i\n", a); // Imprime o novo valor de 'a' (20)
    printf("Valor de b: %i\n", b); // Imprime o valor original de 'b' (10), que não foi alterado
}
