#include <stdio.h>

int main()
{
    int i, num, neg = 0, pos = 0;
    for(i=1; i<=10; i++)
    {
        printf("digite um numero");
        scanf("%i", &num);
        if (num>=0)
        {
            pos++; // se o valor digitado for positivo, soma 1 para o pos
        }
        else if (num<0)
        {
            neg++; // se o valor digitado for negativo, soma 1 para o neg
        }

    }
    printf("Numeros de Positivos: %i\nNumeros de Negativos: %i" , pos, neg);
}
