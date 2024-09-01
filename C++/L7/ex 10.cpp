#include <stdio.h>

main()
{
    int vetor1[10];
    int vetor2[10];
    
	for (int i = 0; i < 10; i++)
	{
        printf("Digite 10 numeros:\n"); 
        scanf("%i", &vetor1[i]);
    }
    for (int i = 0; i < 10; i++)
	{
        vetor2[i] = vetor1[9 - i]; // Quando i é 0, queremos copiar o último elemento de vetor1 para a primeira posição de vetor2. Nesse caso, 9 - 0 resulta em 9, então o último elemento de vetor1 é copiado para vetor2[9].
    }
	for (int i = 0; i < 10; i++)
	{
        if (vetor1[i] == vetor2[i]) 
		{
            printf("Posicao %i: %i\n", i, vetor1[i]);
        }
    }
}