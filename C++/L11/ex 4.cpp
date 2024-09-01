#include <stdio.h>
#include <string.h>

main()
{
    char sobrenome[20];
    char nome[10];
    int tamanho;

    printf("digite o sobrenome\n");
    gets(sobrenome);
    printf("digite seu nome\n");
    gets(nome);

    strcat(nome, sobrenome);
    printf("Nome completo: %s\n", nome); // usa %s para exibir mais de um caractere

    tamanho = strlen(nome); // strlen retorna o comprimento de uma string, ou seja, o número de caracteres antes do caractere nulo 
    printf("a quantidade de caracteres e %i\n", tamanho);
}