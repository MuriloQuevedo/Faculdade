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

    dados *pd = NULL; // Ponteiro para alocar os produtos
    char op;          // Opção do usuário para continuar o cadastro
    int qreg;         // Quantidade de registros no arquivo

    aloca(&pd, 1); // Aloca memória inicial para o primeiro produto

    qreg = verifica(); // Verifica quantos registros já existem no arquivo

    do
    {
        cadastro(pd, qreg + 1); // Cadastra um novo produto
        qreg++;                 // Incrementa o número de registros
        printf("\nDeseja Continuar? <S/N>");
        scanf("%c", &op); // Lê a opção do usuário
        fflush(stdin);    // Limpa o buffer do teclado

    } while (op != 'n' && op != 'N'); // Repete enquanto o usuário quiser continuar

    mostra(pd, qreg); // Exibe os produtos cadastrados

    return 0;
}

// Função para alocar memória dinamicamente
void aloca(dados **p, int tam)
{
    if ((*p = (dados *)realloc(*p, tam * sizeof(dados))) == NULL)
    { // Realloc para aumentar o tamanho do array
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

// Função para cadastrar um novo produto
void cadastro(dados *p, int qreg)
{
    p->reg = qreg; // Define o número do registro

    printf("\nRegistro: %i", p->reg);
    printf("\nProduto: ");
    gets(p->produto); // Lê o nome do produto
    fflush(stdin);

    printf("\nQtde Estoque: ");
    scanf("%i", &(p->qtde)); // Lê a quantidade
    fflush(stdin);

    printf("\nPreço: ");
    scanf("%f", &(p->preco)); // Lê o preço
    fflush(stdin);

    grava(p); // Salva o produto no arquivo
}

// Função para gravar o produto no arquivo binário
void grava(dados *p)
{
    FILE *fptr = NULL;

    if ((fptr = fopen("estoque.bin", "ab")) == NULL)
    { // Abre o arquivo para adicionar no final
        printf("\nErro ao abrir o arquivo");
    }
    else
    {
        fwrite(p, sizeof(dados), 1, fptr); // Grava o produto no arquivo
    }
    fclose(fptr); // Fecha o arquivo
}

// Função para verificar quantos registros existem no arquivo
int verifica()
{
    long int cont = 0;
    FILE *fptr = NULL;

    if ((fptr = fopen("estoque.bin", "rb")) == NULL)
    { // Se o arquivo não existir, retorna 0
        return cont;
    }
    else
    {
        fseek(fptr, 0, SEEK_END);           // Move o ponteiro para o final do arquivo
        cont = ftell(fptr) / sizeof(dados); // Calcula o número de registros
        fclose(fptr);                       // Fecha o arquivo
        return cont;
    }
}

// Função para exibir todos os produtos cadastrados
void mostra(dados *p, int qreg)
{
    int i;
    FILE *fptr = NULL;

    if ((fptr = fopen("estoque.bin", "rb")) == NULL)
    { // Se o arquivo não existir
        printf("\nErro ao abrir o arquivo...");
    }
    else
    {
        for (i = 0; i < qreg; i++)
        {                                             // Itera sobre os registros
            fseek(fptr, i * sizeof(dados), SEEK_SET); // Move o ponteiro para o registro atual
            fread(p, sizeof(dados), 1, fptr);         // Lê o registro do arquivo
            printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreço: %.2f",
                   p->reg, p->produto, p->qtde, p->preco); // Exibe o produto
        }
        fclose(fptr); // Fecha o arquivo
    }
    system("pause"); // Pausa o sistema
    system("cls");   // Limpa a tela
}
