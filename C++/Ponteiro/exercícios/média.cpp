#include <stdio.h>
#include <stdlib.h>

// Função que aloca memória para o vetor
void aloca(float **p,int tam);

// Função para leitura de um número e armazenar no vetor
void leitura(float *p);

// Função para calcular a média e armazenar os números menores que a média
void media(float *p,int tam,float **pm,int *qm);

// Função que exibe os valores de um vetor
void mostra(float *p,int tam);

int main()
{
    float *ptr = NULL, *pmenor = NULL;  // Ponteiros para os números digitados e para os menores que a média
    char op;  // Variável para armazenar a resposta do usuário (continuar ou não)
    int cont = 0, qmenor = 0;  // Contadores: cont é a quantidade de números, qmenor a quantidade de números menores que a média

    // Laço para continuar inserindo números até que o usuário digite 'n' ou 'N'
    do {
        aloca(&ptr, cont + 1); // Realoca espaço para o próximo número
        leitura(ptr + cont);   // Lê o próximo número e armazena no vetor
        cont++;                // Incrementa o contador de números
        printf("\nDeseja continuar <S/N>: ");
        scanf("%c", &op);      // Lê a resposta do usuário
        fflush(stdin);         // Limpa o buffer do teclado para evitar problemas com a leitura do próximo caractere
    } while(op != 'n' && op != 'N');  // Continua enquanto o usuário não digitar 'n' ou 'N'

    // Mostra todos os números digitados
    printf("\nNumeros digitados:\n");
    mostra(ptr, cont);

    // Calcula a média e armazena os números menores que a média em outro vetor
    media(ptr, cont, &pmenor, &qmenor);

    // Mostra os números que são menores que a média
    printf("\nMenores que a media\n");
    mostra(pmenor, qmenor);

    printf("\n\n");
    system("pause"); // Pausa o programa antes de fechar
    return 0;
}

// Função que aloca (ou realoca) memória para um vetor
void aloca(float **p, int tam)
{
    // Realoca memória para o vetor, aumentando o tamanho conforme necessário
    if ((*p = (float*) realloc(*p, tam * sizeof(float))) == NULL)
        exit(1);  // Se a realocação falhar, o programa termina
}

// Função para ler um número e armazená-lo no vetor
void leitura(float *p)
{
    printf("\nNumero: ");
    scanf("%f", p);  // Lê um número float e armazena no endereço apontado por 'p'
    fflush(stdin);   // Limpa o buffer do teclado para evitar problemas com a próxima leitura
}

// Função que calcula a média e armazena os números menores que a média
void media(float *p, int tam, float **pm, int *qm)
{
    int i;
    float m = 0;

    // Calcula a soma de todos os números
    for(i = 0; i < tam; i++)
        m += *(p + i);

    // Calcula a média dividindo a soma pelo número de elementos
    m /= tam;
    printf("\nMedia = %.2f\n\n", m);

    // Verifica quais números são menores que a média
    for(i = 0; i < tam; i++)
        if (*(p + i) < m)  // Se o número for menor que a média
        {
            aloca(pm, (*qm) + 1);  // Realoca memória para armazenar o número no vetor de menores que a média
            *(*pm + *qm) = *(p + i);  // Armazena o número no vetor de menores que a média
            (*qm)++;  // Incrementa o contador de números menores que a média
        }
}

// Função que exibe os números armazenados em um vetor
void mostra(float *p, int tam)
{
    int i;
    for(i = 0; i < tam; i++)
        printf("\n%.2f", *(p + i));  // Exibe o número armazenado no vetor
}
