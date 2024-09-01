#include <stdio.h>

main()
{
    int num[10];
    int numero, repeticoes, i;
    for(i=0; i<10; i++)
    {
        printf("digite dez numeros");
        scanf("%i", &num[i]);
    }
    printf("usuario, digite um numero");
    scanf("%i", &numero);
    for(i=0; i<10; i++)
    {
        if(num[i]==numero)
        repeticoes++;      // é um operador de incremento. Ele aumenta o valor da variavel em uma unidade
    }
    if(repeticoes>0)
    printf("o numero %i esta armazenado no vetor %i vezes\n", numero, repeticoes);
    else
    printf("o numero nao esta armazenado no vetor, temte novamente\n");
}