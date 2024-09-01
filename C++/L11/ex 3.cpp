#include <stdio.h>
#include <string.h>

main()
{
    char palavra[11];
    printf("digite uma palavra com ate 10 caracteres\n");
    gets(palavra);

    printf("As seis primeiras letras da palavra digitada:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%c\n", palavra[i]); // usa %c pois só exibe um caractere;
    }
}