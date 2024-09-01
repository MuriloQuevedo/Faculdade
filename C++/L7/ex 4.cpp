#include <stdio.h>

main()
{
    int num[15];
    int i;
    for(i=0; i<15; i++)
    {
        printf("insira os numeros");
        scanf("%i", &num[i]);
    }
    for(i=0; i<15; i++)
    {
        printf("o dobro de cada um e %i\n", num[i]*2);
    }
}