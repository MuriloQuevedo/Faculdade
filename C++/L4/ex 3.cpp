#include <stdio.h>

 main() 
 {
    int num, i;
    for (i = 0; i < 11; i++) {
        printf("Digite um numero:\n");
        scanf("%i", &num);
        if (num > 0) 
        {
            printf("Seu numero e positivo.\n");
        } else if (num == 0) 
        {
            printf("Seu numero e nulo.\n");
        } else if (num<0)
        {
            printf("Seu valor e negativo.\n");
        }
    }
}
