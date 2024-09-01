#include <stdio.h>

 main() 
 {
    int numerosPares[50]; // Como 100/2 = 50 números pares

    // Preenchimento do vetor com números pares entre 1 e 100
    for (int i = 1; i < 50; i++)
     {
        numerosPares[i] = i * 2;
     }

    // Exibição dos números para o usuário
    for (int i = 0; i < 50; i++) {
        printf("%i ", numerosPares[i]);
    }
    printf("\n"); // opcional
}
