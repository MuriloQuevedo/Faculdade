#include <stdio.h>
#include <stdlib.h>

typedef struct quartoHospede
{
    int num;            // Número do quarto
    char categoria;     // Categoria do quarto
    char status;        // L-ivre ou O-cupado
    char nome[80];      // Nome do hóspede
    int acompanhante;   // Número de acompanhantes
    int dias;           // Dias de estadia
} QuartoHospede;

void aloca_quarto(QuartoHospede **qh, int qq);
void cadastro_quarto(QuartoHospede *qh, int qq);
void check_in(QuartoHospede *qh, int qq);
void check_out(QuartoHospede *qh, int qq);
void mostra_quarto(QuartoHospede *qh, int qq);

int main()
{
    QuartoHospede *qh = NULL;
    int op;
    aloca_quarto(&qh, 15);
    cadastro_quarto(qh, 15);

    do
    {
        system("cls");
        printf("\n[1]Check-in\n[2]Check-out\n[3]Mostra Quarto\n[4]Fim\nOpcao: ");
        scanf("%i", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            check_in(qh, 15);
            break;
        case 2:
            check_out(qh, 15);
            break;
        case 3:
            mostra_quarto(qh, 15);
            break;
        }
    } while (op != 4);
    free(qh);
    return 0;
}

void aloca_quarto(QuartoHospede **qh, int qq)
{
    if ((*qh = (QuartoHospede *)realloc(*qh, qq * sizeof(QuartoHospede))) == NULL)
        exit(1);
}

void cadastro_quarto(QuartoHospede *qh, int qq)
{
    for (int i = 0; i < qq; i++)
    {
        (qh + i)->num = i + 1;
        (qh + i)->status = 'L';
        (qh + i)->categoria = (i < 5) ? 'S' : 'F';
    }
}

void check_in(QuartoHospede *qh, int qq)
{
    int found = 0;
    for (int i = 0; i < qq; i++)
    {
        if ((qh + i)->status == 'L')
        {
            printf("\nNome: ");
            gets((qh + i)->nome);
            fflush(stdin);

            do
            {
                printf("\nQtde de acompanhantes - max.3: ");
                scanf("%i", &(qh + i)->acompanhante);
                fflush(stdin);
            } while ((qh + i)->acompanhante < 0 || (qh + i)->acompanhante > 3);

            printf("\nDias: ");
            scanf("%i", &(qh + i)->dias);
            fflush(stdin);

            (qh + i)->status = 'O'; // Marca o quarto como ocupado
            printf("\nCadastro com sucesso - quarto = %i\n\n", (qh + i)->num);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nNao ha quartos disponiveis\n");
    system("pause");
}

void check_out(QuartoHospede *qh, int qq)
{
    int n_quarto, found = 0;
    float valor;

    printf("\nQuarto a ser finalizado: ");
    scanf("%i", &n_quarto);
    fflush(stdin);

    for (int i = 0; i < qq; i++)
    {
        if ((qh + i)->num == n_quarto && (qh + i)->status == 'O')
        {
            valor = (qh + i)->dias * (((qh + i)->acompanhante + 1) * 65);
            printf("\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\nValor a ser pago: %.2f\n\n",
                   (qh + i)->nome, (qh + i)->acompanhante, (qh + i)->categoria, (qh + i)->dias, valor);

            (qh + i)->status = 'L'; // Libera o quarto
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nQuarto invalido ou nao ocupado\n");
    system("pause");
}

void mostra_quarto(QuartoHospede *qh, int qq)
{
    for (int i = 0; i < qq; i++)
    {
        printf("\nQuarto: %i\nCategoria: %c\nStatus: %c\n", (qh + i)->num, (qh + i)->categoria, (qh + i)->status);
        if ((qh + i)->status == 'O')
            printf("Nome: %s\nAcompanhantes: %i\nDias: %i\n", (qh + i)->nome, (qh + i)->acompanhante, (qh + i)->dias);
    }
    system("pause");
}
