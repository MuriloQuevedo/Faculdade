#include <stdio.h>
#include <stdlib.h>

// Função que aloca memória para o vetor de números
void aloca(int **p_lista, int tam);

// Função que exibe os elementos de um vetor
void mostrar(int *p_lista, int tam);

// Função que calcula a diferença entre pares consecutivos de números ímpares
void impar(int *p_lista, int tam, int **p_impar, int *tam_impar);

int main()
{
    int *p_lista = NULL; // Ponteiro para armazenar a lista de números digitados
    int *p_impar = NULL; // Ponteiro para armazenar as diferenças ímpares

    int tam = 0;       // Tamanho da lista
    int tam_impar = 0; // Tamanho da lista de números ímpares

    char op = 'S'; // Variável para armazenar a resposta do usuário (continuar ou não)

    // Loop para inserir números na lista até o usuário parar
    while (op == 'S' || op == 's')
    {
        aloca(&p_lista, tam + 1); // Aloca mais espaço para um novo número
        printf("Digite o %i numero: ", tam + 1);
        scanf("%i", p_lista + tam); // Lê o próximo número e armazena na lista

        tam++; // Incrementa o tamanho da lista

        // Pergunta se o usuário deseja continuar inserindo números
        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &op);
    }

    // Função que encontra as diferenças ímpares entre os números
    impar(p_lista, tam, &p_impar, &tam_impar);

    // Mostra a lista original de números
    printf("\nLista: \n");
    mostrar(p_lista, tam);

    // Mostra a lista de diferenças ímpares
    printf("\nLista soma impar: \n");
    mostrar(p_impar, tam_impar);
}

// Função para alocar memória ou realocar para o vetor de números
void aloca(int **p_lista, int tam)
{
    // Tenta realocar a memória, se falhar, imprime erro e encerra o programa
    if ((*p_lista = (int *)realloc(*p_lista, tam * sizeof(int))) == NULL)
    {
        printf("Erro de Alocacao");
        exit(1);
    }
}

// Função para exibir os números armazenados no vetor
void mostrar(int *p_lista, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%i ", *(p_lista + i)); // Exibe cada número da lista
    }
}

// Função que calcula as diferenças entre pares consecutivos e armazena as ímpares
void impar(int *p_lista, int tam, int **p_impar, int *tam_impar)
{
    int sub = 0; // Variável para armazenar a diferença entre os números
    // Percorre toda a lista, exceto o último elemento
    for (int i = 0; i < tam - 1; i++) 
    {
        // Calcula a diferença entre o número atual e o próximo
        sub = *(p_lista + i + 1) - *(p_lista + i);

        // Verifica se a diferença é ímpar
        if (sub % 2 != 0)
        {
            aloca(p_impar, (*tam_impar) + 1); // Realoca memória para o vetor de ímpares
            *(*p_impar + *tam_impar) = sub;   // Armazena a diferença ímpar
            (*tam_impar)++;                   // Incrementa o contador de ímpares
        }
    }
}
