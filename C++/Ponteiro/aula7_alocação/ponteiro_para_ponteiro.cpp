#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int qtd); // usa ** quando precisa passar o endereçco do ponteiro, não de um variável
main()
{

    int *p_inteiro = NULL;

    aloca(&p_inteiro, 1);
}

void aloca(int **p, int qtd)
{
 *p =(int *) realloc(*p, qtd * sizeof(int));

}