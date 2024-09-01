#include <stdio.h>

int main()
{
    int num, soma = 0, num_dig;
    float media;
    
    printf("Digite o numero de numeros que voce deseja digitar: ");
    scanf("%i", &num);

    for(int i = 1; i <= num; i++)
    {
        printf("Digite um numero: ");
        scanf("%i", &num_dig);
        soma = soma + num_dig; // soma inicia no 0, e assim vai somando
    }
    media = soma / num;
    printf("Sua media e %f", media);

    return 0;
}
