#include <stdio.h>

main()
{
    int num[12];
    int i;
    for (i=0; i<12; i++)
    {
        printf("insira os numeros");
        scanf("%i", &num[i]);
    }
    for (i=0; i<12; i++)
    {
        if(num[i]<=0)
        printf("os valores sao %i\n", num[i]);
    }
}