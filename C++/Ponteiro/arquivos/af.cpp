#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct quarto
{
    int num;
    char categoria;
    char status; // L-ivre ou O-cupado
} quarto;
typedef struct hospede
{
    int quarto;
    char nome[80];
    int acompanhante;
    char categoria;
    int dias;
} hospede;
void aloca_quarto(quarto **q, int qq);
void aloca_hospede(hospede **h, int qh);
int verifica_quarto();
int verifica_hospede();
void cadastro_quarto(quarto *q, int qq);
void cadastro_hospede(hospede *h, quarto *q, int qq);
void grava_quarto(quarto *q);
void grava_hospede(hospede *h, char *aux, int pos);
void atualiza_quarto(quarto *q, int n_quarto);
int busca_quarto(quarto *q, int qq, char cat);
int busca_hospede(hospede *h, int n_quarto);
int busca_vago(hospede *h, int qh);
void check_out(hospede *h, quarto *q);
void mostra_quarto(quarto *q);
void mostra_hospede(hospede *h);
main()
{
    quarto *pq = NULL;
    hospede *ph = NULL;
    int op, pos, qquarto;

    aloca_quarto(&pq, 1); // Chama a função 'aloca_quarto' para alocar memória para 1 quarto
    qquarto = verifica_quarto();

    if (qquarto == 0)            // Se não houver nenhum quarto, cadastra um quarto com capacidade para 15 pessoas
        cadastro_quarto(pq, 15); // Função para cadastrar o quarto, passando a estrutura
    else
        aloca_hospede(&ph, 1); // Aloca memória para 1 hóspede

    do
    {
        system("cls");
        printf("\n[1]Check-in\n[2]Check-out\n[3]Mostra Quarto\n[4]Mostra Hospede\n[5]Fim\nOpcao: ");
        scanf("%i", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            cadastro_hospede(ph, pq, 15); // Chama a função para cadastrar um hóspede, passando o ponteiro do hóspede, do quarto e a capacidade 15
            break;
        case 2:
            check_out(ph, pq); // Chama a função de check-out (provavelmente para remover o hóspede)
            break;
        case 3:
            mostra_quarto(pq);
            break;
        case 4:
            mostra_hospede(ph);
            break;
        }
    } while (op != 5);
} // Fim da função main

void aloca_quarto(quarto **q, int qq)
{
    if ((*q = (quarto *)realloc(*q, qq * sizeof(quarto))) == NULL) // erro de alocação
        exit(1);
}

void aloca_hospede(hospede **h, int qh)
{
    if ((*h = (hospede *)realloc(*h, qh * sizeof(hospede))) == NULL)
        exit(1);
}

int verifica_quarto()
{
    FILE *fq = NULL; // Ponteiro para o arquivo (será usado para manipular o arquivo "quartos.bin")
    int qtde = 0;    // Variável que armazena a quantidade de quartos

    // Tenta abrir o arquivo "quartos.bin" no modo de leitura binária ("rb")
    if ((fq = fopen("quartos.bin", "rb")) == NULL) // leitura em modo binário
        return qtde;                               // Se o arquivo não existir ou não puder ser aberto, retorna 0, indicando que não há quartos registrados

    else
    {
        // fseek posiciona o ponteiro do arquivo no final para calcular o tamanho do arquivo
        fseek(fq, 0, 2); // 0: deslocamento, 2: modo "seek_end" (desloca até o final do arquivo)

        // ftell retorna a posição atual do ponteiro do arquivo (número de bytes lidos até o momento)
        qtde = ftell(fq) / sizeof(quarto); // A quantidade de quartos é calculada dividindo o tamanho total do arquivo pelo tamanho de uma estrutura 'quarto'

        fclose(fq);  // Fecha o arquivo após terminar a leitura
        return qtde; // Retorna a quantidade de quartos no arquivo
    } // else
}

int verifica_hospede()
{
    FILE *fh = NULL;
    int qtde = 0;

    // Indica que o arquivo será aberto para leitura apenas, b: Indica que o arquivo será aberto no modo binário.
    if ((fh = fopen("hospedes.bin", "rb")) == NULL)
        return qtde; // Se o arquivo não existir ou não puder ser aberto, retorna 0.

    else
    {
        // fseek posiciona o ponteiro do arquivo no final para calcular o tamanho do arquivo
        fseek(fh, 0, 2); // O deslocamento é 0, então o ponteiro não se move além do final do arquivo.

        // Usa ftell para obter a posição atual do ponteiro, que é o tamanho do arquivo em bytes.
        qtde = ftell(fh) / sizeof(hospede); // Divide pelo tamanho da estrutura `hospede` para calcular a quantidade de registros.

        fclose(fh);
        return qtde; // Retorna a quantidade de hóspedes encontrados no arquivo.
    }

} // verifica_hospede

void cadastro_quarto(quarto *q, int qq)
{
    int i;
    for (i = 0; i < qq; i++) // Loop que percorre os quartos a serem cadastrados
    {
        q->num = i + 1;         // Define o número do quarto como (índice + 1)
        q->status = 'L';        // Define o status como 'L' (Livre)
        if (i < 5)              // Define a categoria com base no índice
            q->categoria = 'S'; // Se for um dos primeiros 5 quartos, a categoria é 'S' (Simples)
        else
            q->categoria = 'F'; // Para os demais quartos, a categoria é 'F' (Familiar)
        grava_quarto(q);        // Grava os dados do quarto no arquivo
    } // for
} // cadastra_quarto

void cadastro_hospede(hospede *h, quarto *q, int qq)
{
    int qhosp, pos;

    // Obtém a quantidade de hóspedes já cadastrados
    qhosp = verifica_hospede();

    // Busca a posição de um registro de hóspede que esteja "vago"
    pos = busca_vago(h, qhosp);

    printf("\nNome: ");
    gets(h->nome);
    fflush(stdin);


    // Solicita a quantidade de acompanhantes, com validação do limite
    do
    {
        printf("\nQtde de acompanhantes - max.3: ");
        scanf("%i", &h->acompanhante);
        fflush(stdin);
    } while (h->acompanhante < 0 || h->acompanhante > 3);

    // Determina a categoria do quarto com base no número de acompanhantes
    if (h->acompanhante == 0)
        h->categoria = 'S';
    else
        h->categoria = 'F';
    printf("\nDias: ");
    scanf("%i", &h->dias);
    fflush(stdin);

    // Busca um quarto disponível na categoria desejada
    h->quarto = busca_quarto(q, qq, h->categoria);

    if (h->quarto == -1) // Se pos == -1, significa que não há registros vagos no arquivo.
    {
        // Caso não haja quartos disponíveis na categoria
        printf("\nNao ha quartos com a categoria desejada\n\n");
    }
    else
    {
        printf("\nCadastro com sucesso - quarto = %i\n\n", h->quarto);

        // Verifica se há uma posição vaga para reescrever o hóspede
        if (pos == -1)
            grava_hospede(h, "ab", 1); // ab é usado para adicionar novos registros sem modificar os existentes.
        else
            grava_hospede(h, "rb+", pos); // Sobrescreve um registro de hóspede vago
    }

    printf("\n\n\n");
    system("pause");
}

void grava_quarto(quarto *q)
{
    FILE *fq = NULL;

    // Abre o arquivo 'quartos.bin' para adicionar dados binários ao final, sem sobrescrever os dados existentes. Se o arquivo não existir, ele será criado.
    if ((fq = fopen("quartos.bin", "ab")) == NULL)
    {
        // Caso o arquivo não possa ser aberto (erro), exibe uma mensagem
        printf("\nErro\n\n");
    }
    else
    {
        // Grava 1 elemento do tamanho da estrutura 'quarto' (sizeof(quarto)) no arquivo apontado por 'fq', utilizando os dados da memória apontada por 'q'.
        fwrite(q, sizeof(quarto), 1, fq);
    }
    fclose(fq);
} // grava_quarto

void grava_hospede(hospede *h, char *aux, int pos)
{
    FILE *fh = NULL;

    // Tenta abrir o arquivo 'hospedes.bin' no modo indicado por 'aux'
    if ((fh = fopen("hospedes.bin", aux)) == NULL)
        printf("\nArquivo inexistente\n"); // Caso não consiga abrir, exibe erro
    else
    {
        // Se 'aux' for "rb+", move o ponteiro do arquivo para a posição indicada por 'pos. rb+ altera arquivo, rb não'
        if (strcmp(aux, "rb+") == 0)
            fseek(fh, pos * sizeof(hospede), 0); // A multiplicação ajusta a posição para o registro correto (posição de byte no arquivo), 0 indica que é o começo

        // Grava o registro do hóspede no arquivo
        fwrite(h, sizeof(hospede), 1, fh);
    }
    // fora do ELSE por conta do ab ou rb+
    fclose(fh); // Fecha o arquivo. Isso é feito fora do else para garantir que o arquivo seja fechado, independentemente do modo de abertura
} // grava_hospede

void atualiza_quarto(quarto *q, int n_quarto)
{
    FILE *fq = NULL;
    int qq, i;

    // Obtém a quantidade total de quartos no arquivo
    qq = verifica_quarto();

    if ((fq = fopen("quartos.bin", "rb+")) == NULL)
        printf("\nErro ao abrir o arquivo\n\n");
    else
    {
        // Percorre cada registro no arquivo
        for (i = 0; i < qq; i++)
        {
            // Posiciona o ponteiro do arquivo no registro atual
            fseek(fq, i * sizeof(quarto), 0);
                                   
            // Lê o registro atual para a estrutura 'q'
            fread(q, sizeof(quarto), 1, fq);

            // Verifica se o número do quarto corresponde ao que precisa ser atualizado
            if (q->num == n_quarto)
            {
                // Atualiza o status do quarto para 'L' (livre)
                q->status = 'L';

                // Volta o ponteiro para o início do registro atual
                fseek(fq, i * sizeof(quarto), 0);

                // Sobrescreve o registro atualizado no arquivo
                fwrite(q, sizeof(quarto), 1, fq);

                // O valor de i é alterado para ser igual a qq, o que faz com que a condição do laço (i < qq) não seja mais verdadeira. Isso interrompe o laço imediatamente.
                i = qq;
            }
        }
    }
    // Fecha o arquivo (é sempre chamado, mesmo que o arquivo não seja encontrado)
    fclose(fq);
} // atualiza_quarto

int busca_quarto(quarto *q, int qq, char cat)
{
    int pos = -1;    // Inicializa a variável 'pos' com -1, indicando que nenhum quarto foi encontrado
    int i;           // Variável de controle para o loop
    FILE *fq = NULL; // Ponteiro para o arquivo "quartos.bin"

    // Tenta abrir o arquivo "quartos.bin" no modo leitura/escrita binário ("rb+")
    if ((fq = fopen("quartos.bin", "rb+")) == NULL)
        printf("\nErro\n\n"); // Caso o arquivo não seja encontrado ou não possa ser aberto, exibe uma mensagem de erro

    else
    {
        // Loop para percorrer todos os registros de quartos (qq é a quantidade de quartos)
        for (i = 0; i < qq; i++)
        {
            // Posiciona o ponteiro do arquivo na posição do quarto atual
            // Cada estrutura ocupa sizeof(quarto) bytes, então a posição é `i * sizeof(quarto)`
            fseek(fq, i * sizeof(quarto), 0);

            // Lê um registro de quarto da posição atual do arquivo e armazena na estrutura apontada por 'q'
            fread(q, sizeof(quarto), 1, fq);

            // Verifica se o quarto lido atende aos critérios:
            // - Mesma categoria (q->categoria == cat)
            // - Está livre (q->status == 'L')
            if (q->categoria == cat && q->status == 'L')
            {
                // Atualiza o status do quarto para ocupado ('O')
                q->status = 'O';

                // Volta o ponteiro do arquivo para a posição onde o registro foi lido
                fseek(fq, i * sizeof(quarto), 0);

                // Escreve a estrutura atualizada no arquivo (status alterado para 'O')
                fwrite(q, sizeof(quarto), 1, fq);

                // Armazena o número do quarto encontrado
                pos = q->num;

                // Força a saída do loop, pois o quarto desejado já foi encontrado
                i = qq;
            }
        }
    }
    fclose(fq); // Fecha o arquivo
    return pos; // Retorna o número do quarto encontrado, ou -1 se nenhum foi encontrado
}

int busca_hospede(hospede *h, int n_quarto)
{
    int pos = -1, i, qh; // `pos` inicia com -1 para indicar que o hóspede não foi encontrado.
    FILE *fh = NULL;
    qh = verifica_hospede(); // Obtém a quantidade de hóspedes cadastrados.

    if ((fh = fopen("hospedes.bin", "rb+")) == NULL) // Abre o arquivo para leitura e escrita.
        printf("\nErro\n\n");
    else
    {
        for (i = 0; i < qh; i++) // Percorre todos os hóspedes.
        {
            fseek(fh, i * sizeof(hospede), 0); // Posiciona o ponteiro no registro do hóspede atual.
            fread(h, sizeof(hospede), 1, fh);  // Lê o hóspede atual do arquivo.

            if (h->quarto == n_quarto) // Verifica se o hóspede está no quarto especificado.
            {
                h->quarto = -1;                    // Marca o quarto como "livre" no registro do hóspede.
                fseek(fh, i * sizeof(hospede), 0); // Retorna ao registro para sobrescrevê-lo.
                fwrite(h, sizeof(hospede), 1, fh); // Atualiza o registro no arquivo.
                pos = i;                           // Armazena a posição do hóspede.
                i = qh;                            // Força a saída do loop.
            }
        }
    }
    fclose(fh); // Fecha o arquivo.
    return pos; // Retorna a posição do hóspede ou -1 se não foi encontrado.
}

int busca_vago(hospede *h, int qh)
{
    FILE *fh = NULL;
    int i;
    if ((fh = fopen("hospedes.bin", "rb")) == NULL) // Abre o arquivo para leitura.
        return -1;                                  // Retorna -1 caso o arquivo não exista.

    else
    {
        for (i = 0; i < qh; i++) // Percorre os registros de hóspedes.
        {
            fseek(fh, i * sizeof(hospede), 0); // Posiciona o ponteiro no registro atual.
            fread(h, sizeof(hospede), 1, fh);  // Lê o registro do hóspede.

            if (h->quarto == -1) // Verifica se o registro está "vago".
            {
                fclose(fh); // Fecha o arquivo antes de retornar.
                return i;   // Retorna a posição vaga.
            }
        }
        fclose(fh); // Fecha o arquivo se nenhum registro vago for encontrado.
    }
    return -1; // Retorna -1 se nenhum registro vago for encontrado.
}

void check_out(hospede *h, quarto *q)
{
    int n_quarto, achou;
    float valor;

    printf("\nQuarto a ser finalizado: ");
    scanf("%i", &n_quarto);
    fflush(stdin);

    achou = busca_hospede(h, n_quarto); // Procura o hóspede no quarto especificado.

    if (achou == -1) // Se não encontrou o hóspede.
        printf("\nQuarto invalido\n\n");
    else
    {
        // Calcula o valor da estadia com base na categoria e nos acompanhantes.
        if (h->categoria == 'S')
            valor = h->dias * 85; // Sem acompanhantes: valor fixo por dia.
        else
            valor = h->dias * ((h->acompanhante) + 1) * 65; // Com acompanhantes.

        // Exibe os dados do hóspede e o valor total.
        printf("\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\nValor a ser pago: %.2f\n\n",
               h->nome, h->acompanhante, h->categoria, h->dias, valor);

        atualiza_quarto(q, n_quarto); // Libera o quarto.
    }

    system("pause");
}

void mostra_quarto(quarto *q)
{
    int i, qq;
    FILE *fq = NULL;

    qq = verifica_quarto(); // Quantidade de quartos no arquivo.

    if ((fq = fopen("quartos.bin", "rb")) == NULL) // Abre o arquivo.
        printf("\nArquivo Inexistente\n\n");
    else
    {
        for (i = 0; i < qq; i++) // Percorre todos os quartos.
        {
            fseek(fq, i * sizeof(quarto), 0); // Posiciona o ponteiro no registro atual.
            fread(q, sizeof(quarto), 1, fq);  // Lê o registro do quarto.
            printf("\nQuarto: %i\nCategoria: %c\nStatus: %c\n\n", q->num, q->categoria, q->status);
        }
        fclose(fq);
    }
    system("pause");
}

]void mostra_hospede(hospede *h)
{
    int i, qh;
    FILE *fh = NULL;

    qh = verifica_hospede(); // Obtém a quantidade total de hóspedes no arquivo.

    if ((fh = fopen("hospedes.bin", "rb")) == NULL) // Abre o arquivo binário para leitura.
    {
        printf("\nErro\n\n"); // Informa erro caso o arquivo não exista ou não possa ser aberto.
    }
    else
    {
        for (i = 0; i < qh; i++) // Itera sobre cada hóspede no arquivo.
        { 
            fseek(fh, i * sizeof(hospede), 0); // Posiciona o ponteiro no registro do hóspede atual.
            fread(h, sizeof(hospede), 1, fh);  // Lê os dados do hóspede atual para a estrutura `h`.

            // Exibe os dados do hóspede atual.
            printf("\nQuarto: %i\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\n\n",
                   h->quarto,       // Número do quarto do hóspede.
                   h->nome,         // Nome do hóspede.
                   h->acompanhante, // Número de acompanhantes.
                   h->categoria,    // Categoria do quarto ('S', por exemplo).
                   h->dias);        // Quantidade de dias hospedado.
        }
        fclose(fh); // Fecha o arquivo após a leitura.
    }
    system("pause"); // Pausa o programa para o usuário visualizar os dados.
}
