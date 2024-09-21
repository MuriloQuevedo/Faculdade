#include <stdio.h>

main()
{
    int x = 10;
    double y = 20.50;
    char z = 'a';

    int *pX = &x;
    double *pY = &y;
    char *pZ = &z;

    printf("Endereco x =%i - Valor de x = %i\n", pX, *pX);
    printf("Endereco y =%i - Valor de y = %f\n", pY, *pY);
    printf("Endereco z =%i - Valor de z = %c\n", pZ, *pZ);

    double soma = *pX + *pY;
    printf("Valor de x = %f\n", soma);
}
