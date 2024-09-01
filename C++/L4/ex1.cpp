#include <stdio.h>

main()
{
    int num, dobro;
    for (int i = 0; i<=10; i++)
    {
        printf("digite um numero");
        scanf("%i", &num);
        dobro = num*2;
        printf("o dobro de %i e %i", num, dobro);
    }

}