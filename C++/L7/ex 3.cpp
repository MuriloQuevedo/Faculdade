#include <stdio.h>

main()
{
    int num[8];
    int posicao, i;
    for (i=0; i<8; i++)
    {
        printf("insira os numeros\n");
        scanf("%i", &num[i]);
    }
    printf("Digite a posicao do numero que deseja: ");
	scanf("%i" , &posicao);
    printf("O Numero da posicao %i equivale a %i", posicao , num[posicao]);	
}