#include <stdio.h>

main()
{
    int matriz[3][3];
    int dobro[3][3];
    int i, j;
    printf("digite os valores da matriz");
    for(i=0; i<3; i++)
    {
        for(i=0; i<3; i++)
        {
            scanf("%i", &matriz [i][j]);
            dobro[i][j] = matriz[i][j] * 2;
        }
    }
    for(i=0;i<3; i++) // para aparecer no printf
    {
        for(i=0;i<3; i++)
        printf(" o dobro é %i", dobro[i][j]);

    }
}