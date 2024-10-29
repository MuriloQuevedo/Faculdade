#include <stdio.h>  // Inclui a biblioteca padrão de entrada e saída
#include <stdlib.h> // Inclui a biblioteca padrão para alocação de memória

// Estrutura para armazenar os dados da agenda
typedef struct agenda
{
    int reg;       // Número de registro
    char nome[20]; // Nome (com no máximo 20 caracteres)
    float nota;    // Nota (um número real)
} agenda;

// Função para alocar memória dinamicamente para a agenda
void aloca(agenda **p, int tam);

// Função para cadastrar um novo registro na agenda
void cadastro(agenda *p);

// Função para mostrar todos os registros cadastrados
void mostra(agenda *p, int tam);

int main()
{
    agenda *ag = NULL; // Ponteiro para a agenda, inicialmente vazio
    int op, cont = 0;  // 'op' é a opção do menu, 'cont' é o número de registros

    // Loop do menu principal
    do
    {
        system("cls"); // Limpa a tela (
        printf("Menu\n[1]Cadastro\n[2]Mostra\n[3]Sair\nDigite a sua opcao: ");
        scanf("%i", &op); // Lê a opção do usuário
        fflush(stdin);    // Limpa o buffer do teclado

        switch (op)
        {
        case 1:
            // Aloca mais memória para a agenda para um novo registro
            aloca(&ag, cont + 1); // cont + 1 é usado para indicar que você quer espaço para um novo registro
            // Cadastra os dados para o novo registro
            cadastro(ag + cont); // ag é o endereço de memoria, e o cont adiciona um numero de registro a ele
            cont++;              // Incrementa o contador de registros
            break;

        case 2:
            // Mostra todos os registros cadastrados
            mostra(ag, cont);
            break;
        }
    } while (op < 3); // O loop continua enquanto a opção for menor que 3 (sair)

    return 0; // Indica que o programa terminou com sucesso
}

// Função para alocar ou realocar memória para a agenda
void aloca(agenda **p, int tam)
{
    // Tenta realocar a memória para o número de registros especificado (tam)
    if ((*p = (agenda *)realloc(*p, tam * sizeof(agenda))) == NULL)
    {
        printf("erro");
        exit(1); // Sai do programa se a alocação falhar
    }
}

// Função para cadastrar um novo registro na agenda
void cadastro(agenda *p)
{

    p->reg = cont + 1; // Definindo o registro como cont + 1, pois o reg começa em 0

    printf("\nNome: ");
    gets(p->nome); // Lê o nome do usuário (não recomendado, pois inseguro)
    fflush(stdin); // Limpa o buffer do teclado

    // Loop para garantir que a nota seja um valor entre 0 e 10
    do
    {
        printf("\nNota: ");
        scanf("%f", &p->nota); // Lê a nota do usuário
        fflush(stdin);         // Limpa o buffer do teclado
    } while (p->nota < 0 || p->nota > 10); // Repete se a nota for inválida

    system("PAUSE"); // Pausa o programa para o usuário ver a mensagem
}

// Função para mostrar todos os registros cadastrados
void mostra(agenda *p, int tam)
{
    int i;
    // Loop para exibir cada registro cadastrado
    for (i = 0; i < tam; i++, p++)
    {
        printf("\nRegistro: %i", p->reg);  // Mostra o número do registro
        printf("\nNome: %s", p->nome);     // Mostra o nome
        printf("\nNota: %.2f\n", p->nota); // Mostra a nota com duas casas decimais
    }

    system("PAUSE"); // Pausa o programa para o usuário ver os registros
}
