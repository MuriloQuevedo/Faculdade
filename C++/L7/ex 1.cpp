#include <stdio.h>

	main()
{
	int num[10];
	for(int i = 1; i<=10 ; i++)
	{
		printf("Insira o numero:");
		scanf("%i", &num[i]); // Quando você escreve num[i], está essencialmente acessando o elemento do vetor num que está na posição i
	}
	
	for(int i = 0; i<10; i++) // for é usado para iterar sobre os elementos do vetor num e imprimir cada um deles na tela.
	{
		printf("%i\n" , num[i]);
	}
}
