#include <stdio.h>
#include <string.h>

main()
{
    char palavra[40];
    char inverso[40];
    int tamanho, i;

    printf("digite sua palavra\n");
    gets(palavra);

     tamanho = strlen(palavra);


    for (i = 0; i < tamanho; i++) 
    {
    inverso[i] = palavra[tamanho - i - 1]; 
    inverso[tamanho] = '\0'; //  Adiciona o caractere nulo ao final da string 'inverso' para garantir que seja uma string válida
    }

    printf("O inverso da sua palavra e: %s\n", inverso);

}