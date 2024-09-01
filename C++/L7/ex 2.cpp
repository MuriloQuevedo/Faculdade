#include <stdio.h>

main()
{
    int num[10];
    int i;
    for(int i=0; i<10; i++) // vetor começa no 0, por isso é de 0 até 9
    {
        printf("insira dez numeros");
        scanf("%i", &num[i]);  // Quando você escreve num[i], está essencialmente acessando o elemento do vetor num que está na posição i
    }
    
    for (i=9; i>=1; i--)
    {
        printf("%i\n",num[i] ); // for é usado para iterar sobre os elementos do vetor num e imprimir cada um deles na tela.
    }
}