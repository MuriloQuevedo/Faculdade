#include <stdio.h>
#include <string.h>

main()
{
    int num, i;
    printf("digite um numero menor ou igual a 20\n");
    scanf("%i", &num);

    char letra[num];
    printf("digite uma letra\n");
    scanf("%s", letra);

    for(i=1; i<num; i++)
    printf("%s\n", letra);
}