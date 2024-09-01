#include <stdio.h>
#include <string.h>

main()
{
    char palavra[11];
    int tamanho;

    printf("digite uma palavra com no maximo 10 caracteres, e no minimo 3\n");
    gets(palavra);
    tamanho = strlen(palavra); // strlen retorna o comprimento de uma string, ou seja, o número de caracteres antes do caractere nulo 

    if(tamanho <3 || tamanho >10 )
    {
        printf("palavra invalida, possui %i caracteres\n", tamanho);
        printf("por favor, tente novamente\n");
        printf("digite uma palavra com no maximo 10 caracteres, e no minimo 3\n");
        gets(palavra);
        tamanho = strlen(palavra); 
        if(tamanho >=3 && tamanho <=10 )
        printf("palavra valida\n");
    }
    else 
    printf("palavra valida\n");
}