#include <stdio.h>

main()
{
    int j, i, soma;
    int matriz[3][4];
    printf("digite os numeros da matriz\n");
   
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            scanf("%i", &matriz[i][j]);
        }
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
           soma= soma + matriz[i][j];
        }
    }
    printf("%i", soma );
}