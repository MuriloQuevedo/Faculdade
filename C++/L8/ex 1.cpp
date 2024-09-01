#include <stdio.h>

main()
{
    int a [5] = {1, 2, 3, 4, 5};
    int b [5] = {1, 2, 3, 4, 5};
    int produto = 0;
    for (int i = 0; i < 5; i++)
    {
        produto = produto + (a[i] * b[i]); // Atualiza o valor de 'produto' adicionando o produto dos elementos correspondentes de 'a' e 'b'
    }
       printf("O valor é %i\n", produto);
}