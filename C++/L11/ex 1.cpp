#include <stdio.h>
#include <string.h>

main()
{
    char senha[7];
    char senha_repetida[7];
    
    printf("digite uma senha de 6 catacteres\n");
    gets(senha);
    printf("confirme sua senha, digite novamente\n");
    gets(senha_repetida);

    if (strcmp(senha, senha_repetida) == 0) // Ele retorna 0 se as duas strings forem idênticas
        printf("Senha valida\n");
    
    
    if (strncmp(senha, senha_repetida, 3) == 0) // O número "3" usado na função strncmp indica que apenas os primeiros três caracteres das strings devem ser comparados.
        printf("Erro de digitaçao: Os tres primeiros caracteres sao iguais.\n"); 
    else
        printf("Senha invalida\n");
}
  