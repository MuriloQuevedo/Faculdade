#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 100 // Tamanho máximo para a senha

// Protótipo das funções
void gerenciarSenha(char *senha);

int main()
{
    char senha[MAX_TAMANHO];

    // Solicitar que o usuário defina uma senha inicial
    printf("Defina sua senha: ");
    gets(senha); // Usando gets para ler a senha inicial

    // Gerenciar a senha (verificar se o usuário deseja alterá-la)
    gerenciarSenha(senha);

    // Exibir a senha final
    printf("Sua senha final é: %s\n", senha);

    return 0;
}

// Função para gerenciar a senha
void gerenciarSenha(char *senha)
{
    char opcao[10];

    printf("Deseja alterar a senha? (sim/nao): ");
    gets(opcao); // Ler a opção do usuário

    if (strcmp(opcao, "sim") == 0)
    {
        printf("Digite a nova senha: ");
        gets(senha); // Alterar a senha diretamente
        printf("Senha alterada com sucesso!\n");
    }
    else
    {
        printf("Senha mantida.\n");
    }
}
