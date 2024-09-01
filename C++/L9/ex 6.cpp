#include <stdio.h>

main()
{
    int matriz[3][4];
    float media = 0;
    int i, j, linha;
    printf("digite os numeros da matrix 3x4");
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            scanf("%i", &matriz[i][j]);
        };
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%i", matriz[i][j]);
        }
        printf("\n");
    }
    printf("escolha entre a linha 0, 1 e 2");
    scanf("%i", &linha);
    for(j = 0; j < 4; j++) 
    {
    media= media + matriz[linha][j]; // Somando todos os elementos da linha escolhida
    }
    media= media/4; // Dividindo pela quantidade de colunas
    printf("sua media e %f", media);
}