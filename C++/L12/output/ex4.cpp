#include <stdio.h>
int dias (int x);
int meses(int y);


main()
{
    int idade;
    printf("digite sua idade em anos ");
    scanf("%i", &idade);
    printf("Sua idade em dias é de %d\n", dias(idade));
    printf("Sua idade em meses é de %d\n", meses(idade));
}

int dias (int x)
{
    int d;
    d = x * 365;
    return d;
}

int meses(int y)
{
    return y * 12;
}