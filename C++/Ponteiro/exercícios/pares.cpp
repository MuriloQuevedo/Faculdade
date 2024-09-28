#include <stdio.h>
#include <stdlib.h>


// Função para alocar memória para um vetor de inteiros
void aloca(int **p, int tam);

// Função para receber um número e armazenar no vetor
void recebe(int *p);

// Função para exibir os números armazenados em um vetor
void mostra(int *p, int tam);

// Função que calcula as subtrações consecutivas e armazena as pares
int pares(int *p, int tam, int qtdpares, int **pares);

int main()
{

    int *num = NULL;  // Ponteiro para armazenar os números digitados
    int cont = 0;     // Contador de quantos números foram digitados
    int qtdpares = 0; // Contador de quantas subtrações pares foram encontradas
    int *numpares = NULL;  // Ponteiro para armazenar as subtrações pares
    char opc;  // Variável para armazenar a opção do usuário (continuar ou não)

    // Laço para continuar inserindo números até que o usuário digite 'n' ou 'N'
    do
    {
        aloca(&num, cont + 1);     // Realoca memória para o vetor de números
        recebe(num + cont);        // Lê o próximo número e armazena no vetor
        cont++;                    // Incrementa o contador de números

        printf("\nDeseja Continuar <S/N>: ");
        scanf(" %c", &opc);        // Lê a resposta do usuário
        fflush(stdin);             // Limpa o buffer do teclado para evitar problemas na próxima leitura

    } while (opc == 's' || opc == 'S');  // Continua enquanto o usuário digitar 's' ou 'S'

    system("cls");  // Limpa a tela (no Windows)

    // Calcula as subtrações entre números consecutivos e armazena as que são pares
    qtdpares = pares(num, cont, qtdpares, &numpares);

    // Exibe todos os números digitados
    printf("\nNumeros Digitados\n");
    mostra(num, cont);

    printf("\n===============================================\n");

    // Exibe as subtrações que resultaram em números pares
    printf("\nSubtrações Pares:\n");
    mostra(numpares, qtdpares);

    return 0;  // Finaliza o programa
}

// Função para alocar (ou realocar) memória para um vetor
void aloca(int **p, int tam)
{
    // Realoca memória para o vetor, aumentando o tamanho conforme necessário
    if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
    {
        printf("Erro ao Alocar Memória...");  // Se der erro, exibe a mensagem
        exit(1);  // Sai do programa caso haja falha na alocação de memória
    }
}

// Função para ler um número inteiro e armazená-lo no vetor
void recebe(int *p)
{
    printf("\nDigite um Número: ");
    scanf("%i", p);  // Lê o número inteiro inserido pelo usuário e armazena no endereço indicado por 'p'
}

// Função para exibir os números armazenados em um vetor
void mostra(int *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("\n%i\n", *(p + i));  // Exibe o número armazenado no vetor
    }
}

// Função que calcula as subtrações entre números consecutivos e armazena as pares
int pares(int *p, int tam, int qtdpares, int **pares)
{
    int i, j, sub;  // Variáveis para percorrer o vetor e armazenar a subtração

    // Laço para percorrer o vetor e calcular as subtrações
    for (i = 0, j = i + 1; j < tam; i++, j++)  // 'i' e 'j' representam dois números consecutivos
    {
        sub = *(p + j) - *(p + i);  // Calcula a subtração entre números consecutivos

        if (sub % 2 == 0)  // Verifica se a subtração é par
        {
            aloca(pares, qtdpares + 1);  // Realoca memória para armazenar a subtração par
            *(*pares + qtdpares) = sub;  // Armazena a subtração no vetor de pares
            qtdpares++;  // Incrementa o contador de subtrações pares
        }
    }

    return qtdpares;  // Retorna a quantidade de subtrações pares encontradas
}
