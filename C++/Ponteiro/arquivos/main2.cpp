#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para armazenar dados do produto
typedef struct dados
{
    int reg;          // Número do registro
    char produto[20]; // Nome do produto
    int qtde;         // Quantidade no estoque
    float preco;      // Preço do produto
} dados;

// Protótipos das funções
void aloca(dados **p, int tam);
void cadastro(dados *p, int qreg);
void grava(dados *p);
int verifica();
void mostra(dados *p, int qreg);

int main()
{
    setlocale(LC_ALL, "portuguese");

    dados *pd = NULL; // Ponteiro para armazenar os produtos dinamicamente
    char op;          // Opção para continuar ou não o cadastro
    int qreg;         // Quantidade de registros no arquivo

    aloca(&pd, 1); // Inicializa a alocação de memória para o primeiro produto

    qreg = verifica(); // Verifica quantos registros já existem no arquivo

    do
    {
        cadastro(pd, qreg + 1); // Adiciona um novo registro
        qreg++;                 // Incrementa o contador de registros
        printf("\nDeseja Continuar? <S/N>");
        scanf(" %c", &op); // Lê a escolha do usuário
        fflush(stdin);     // Limpa o buffer do teclado
    } while (op != 'n' && op != 'N'); // Continua enquanto a resposta for diferente de 'N' ou 'n'

    mostra(pd, qreg); // Exibe todos os produtos cadastrados

    return 0;
}

// Função para alocar memória para a estrutura dinamicamente
void aloca(dados **p, int tam)
{
    *p = (dados *)realloc(*p, tam * sizeof(dados)); // Realoca a memória para armazenar os produtos
    if (*p == NULL)
    { // Verifica se a alocação foi bem-sucedida
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

// Função para cadastrar um novo produto
void cadastro(dados *p, int qreg)
{
    p->reg = qreg; // Atribui o número do registro

    printf("\nRegistro: %i", p->reg);
    printf("\nProduto: ");
    gets(p->produto); // Lê o nome do produto
    fflush(stdin);

    printf("\nQtde Estoque: ");
    scanf("%i", &(p->qtde)); // Lê a quantidade no estoque
    fflush(stdin);

    printf("\nPreço: ");
    scanf("%f", &(p->preco)); // Lê o preço do produto
    fflush(stdin);

    grava(p); // Salva o produto no arquivo binário
}

// Função para gravar um produto no arquivo
void grava(dados *p)
{
    FILE *fptr = fopen("estoque.bin", "ab"); // Abre o arquivo no modo "adicionar binário"
    if (fptr == NULL)
    { // Verifica se houve erro ao abrir o arquivo
        printf("\nErro ao abrir o arquivo");
    }
    else
    {
        fwrite(p, sizeof(dados), 1, fptr); // Escreve os dados do produto no arquivo
    }
    fclose(fptr); // Fecha o arquivo
}

// Função para verificar quantos registros existem no arquivo
int verifica()
{
    long int cont = 0;
    FILE *fptr = fopen("estoque.bin", "rb"); // Abre o arquivo no modo "leitura binária"
    if (fptr == NULL)
    { // Retorna 0 se o arquivo ainda não existir
        return cont;
    }
    else
    {
        fseek(fptr, 0, SEEK_END);           // Move o ponteiro até o final do arquivo
        cont = ftell(fptr) / sizeof(dados); // Calcula o número de registros
        fclose(fptr);                       // Fecha o arquivo
        return cont;
    }
}

// Função para exibir todos os produtos cadastrados
void mostra(dados *p, int qreg)
{
    FILE *fptr = fopen("estoque.bin", "rb"); // Abre o arquivo no modo "leitura binária"
    if (fptr == NULL)
    { // Verifica se o arquivo foi aberto corretamente
        printf("\nErro ao abrir o arquivo...");
    }
    else
    {
        for (int i = 0; i < qreg; i++)
        {                                             // Itera sobre os registros
            fseek(fptr, i * sizeof(dados), SEEK_SET); // Move o ponteiro para o registro atual
            fread(p, sizeof(dados), 1, fptr);         // Lê os dados do registro
            printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreço: %.2f",
                   p->reg, p->produto, p->qtde, p->preco); // Exibe os dados na tela
        }
        fclose(fptr); // Fecha o arquivo
    }
    system("pause"); // Pausa a execução
    system("cls");   // Limpa a tela
}
