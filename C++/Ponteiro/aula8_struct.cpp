#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura aluno com três campos: nome, idade e nota.
typedef struct aluno
{
    char nome[20];  // Cadeia de caracteres para armazenar o nome do aluno.
    int idade;      // Inteiro para armazenar a idade do aluno.
    float nota;     // Valor float para armazenar a nota do aluno.
} aluno;

// Função para realizar o cadastro de um aluno e retornar os dados preenchidos.
aluno cadastro();

int main()
{
    // Vetor para armazenar até 10 alunos.
    aluno alu[10];
    char op; // Variável para armazenar a escolha do usuário (continuar ou não).
    int cont = 0; // Contador para controlar o número de cadastros realizados.

    do
    {
        // Verifica se ainda há espaço para mais cadastros.
        if (cont < 10)
        {
            alu[cont] = cadastro(); // Chama a função de cadastro e armazena os dados no vetor.
            cont++; // Incrementa o contador após um novo cadastro.
        }
        else
        {
            printf("\nCadastro Lotado\n"); // Mensagem exibida caso o limite de cadastros seja atingido.
        }

        printf("\nDeseja Continuar <S/N>: ");
        scanf(" %c", &op); // Captura a escolha do usuário sobre continuar o cadastro.
        fflush(stdin); // Limpa o buffer do teclado para evitar problemas na leitura de caracteres.

    } while (op == 's' || op == 'S'); // Continua o loop enquanto o usuário digitar 's' ou 'S'.

    system("cls"); // Limpa a tela (dependente do sistema operacional).

    // Exibe os dados de todos os alunos cadastrados.
    int i;
    for (i = 0; i < cont; i++)
    {
        printf("\nAluno %i\nNome: %s\nIdade: %i\nNota: %.2f\n", i + 1, alu[i].nome, alu[i].idade, alu[i].nota);
    }

    return 0;
}

// Função para realizar o cadastro de um aluno.
aluno cadastro()
{
    aluno x; // Declara uma variável do tipo aluno para armazenar as informações.
    
    printf("\nNome : ");
    gets(x.nome); // Usa gets para capturar o nome. Tenha cuidado com o uso de gets, pois pode causar estouro de buffer.
    
    printf("\nIdade : ");
    scanf("%i", &(x.idade)); // Lê a idade do aluno.
    fflush(stdin); // Limpa o buffer para evitar problemas com a leitura de strings.
    
    printf("\nNota: ");
    scanf("%f", &(x.nota)); // Lê a nota do aluno.
    fflush(stdin); // Limpa o buffer novamente.

    printf("\n\n\n");
    
    return x; // Retorna a estrutura preenchida.
}
