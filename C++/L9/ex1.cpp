#include <stdio.h>

main()
{
    int j, i;
    int matriz[4][3];
    printf("digite os numeros da matriz\n");
   
    for(i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%i", &matriz[i][j]);
        }
    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
           printf("%i\t", matriz[i][j]);
        }
        printf("\n"); //Adiciona uma nova linha após cada linha da matriz, tem que ser dentro do for
}