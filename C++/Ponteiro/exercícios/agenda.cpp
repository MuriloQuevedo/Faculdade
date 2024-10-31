#include <stdio.h>
#include <stdlib.h>

typedef struct agenda
{
    int reg;
    char nome[20];
    float nota;
} agenda;

void aloca(agenda **p, int tam);
void cadastro(agenda *p);
void mostra(agenda *p, int tam);

main()
{
    agenda *ag = NULL;
    int op, cont = 0;
    do
    {
        system("cls");
        printf("Menu:\n[1]Cadastro\n[2]Mostrar\n[3]Sair\n");
        scanf("%i", &op);
        fflush(stdin);
        switch (op)
        {
        case 1:
            aloca (&ag, cont + 1); // Redimensiona o array para incluir mais um registro.
            cadastro(ag + cont);
            cont ++;
            break;
        
       case 2:
            mostra(ag, cont);
            break;
        }
    } while (op<3);
    return 0;
}

void aloca(agenda **p, int tam)
{
    if((*p=(agenda *)realloc(*p, tam * sizeof(agenda))) == NULL) 
    {
    printf("erro"); 
    exit(1);
    }
}

void cadastro (agenda *p)
{

    static int n = 1;
    p->reg = n;
    n++;

    printf("\nNome:");
    gets(p->nome);
    fflush(stdin);

    printf("Digite sua nota: ");
    scanf("%f", &p->nota);
    fflush(stdin);

    if (p->nota < 0 || p->nota > 10)
    {
        printf("Nota invalida!\n");
        exit(1);
    }
    system("PAUSE");
}

void mostra(agenda *p, int tam)
{
    int i;
    for (i=0 ; i<tam; i++, p++)
    {
        printf("\nRegistro %i", p->reg);
        printf("\nNome %s", p->nome);
        printf("\nNota %.2f", p->nota);
    }
    system("PAUSE");

}       
