#include <stdio.h>

int main() {
    int matriz[4][4];
    int diagonal[4];
    int somaDiagonal = 0;

    printf("Digite os elementos da matriz 4x4:\n");
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            scanf("%i", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++)
         {
            printf("%i", matriz[i][j]);  // Exibindo a matriz
            if (i == j) //  os elementos têm a mesma linha e coluna (ou seja, i e j são iguais
            {
                somaDiagonal= somaDiagonal + matriz[i][j]; // Calculando a soma da diagonal principal
                diagonal[i] = matriz[i][j]; // Preenchendo o vetor com os elementos da diagonal principal
            }
        }
        printf("\n");
    }
    printf("Soma dos elementos da diagonal principal: %d\n", somaDiagonal);
    printf("Vetor com os elementos da diagonal principal:\n");
    for (int i = 0; i < 4; i++) 
    {
        printf("%i ", diagonal[i]);
    }
}
