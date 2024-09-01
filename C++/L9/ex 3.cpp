#include <stdio.h>

int main() 
{
    int matriz[5][3];
    int maior = 0, coluna_maior, linha_maior;

    printf("Digite os números da matriz 5x3:\n");
    // Preenchendo a matriz e encontrando o maior elemento
    for(int i = 0; i < 5; i++) 
    {
        for(int j = 0; j < 3; j++) 
        {
            scanf("%i", &matriz[i][j]);

            // Verifica se o elemento atual é maior do que o maior encontrado até agora
            if (matriz[i][j] > maior)
             {
                maior = matriz[i][j];
                 linha_maior = i;
                 coluna_maior = j;
            }
        }
    }
    printf("O maior elemento da matriz é %i na posiçao %i %i.\n", maior, coluna_maior, linha_maior);
}
