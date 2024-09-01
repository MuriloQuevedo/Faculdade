#include <stdio.h>

main()
{
    int i;
    int num{10};
    int soma_impares;
    for(i=0; i<10; i++)
    {
        printf("digite um numero positivo");
        scanf("%i", &num[i]);
        
            if (num[i]<0)
            {
                printf("numero invalido. tente de novo\n");
            }
             else if (num[i]>=0)
            {
                printf("numero valido\n");
            }
            
    }
    for(i=1; i<10; i=i+2)
    {
        soma_impares = soma_impares + num[i];
    }
    printf("a soma dos numeros nas posicoes impares e %i\n", soma_impares);
}