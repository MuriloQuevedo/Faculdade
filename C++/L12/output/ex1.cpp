#include <stdio.h>
// Protótipo
float divisao (float x, float y);

main()
{
    float num1, num2, resultado;
    printf("digite dois numeros ");
    scanf("%f %f", &num1, &num2);

    resultado = divisao (num1, num2);
    printf("%.2f\n", resultado);

   // Chama a função divisao diretamente dentro do printf
    printf("%.2f\n", divisao(num1, num2));
}

//definição da função
float divisao (float x, float y)
{
    float d;
    d= x/y;
    return d; // retorna o valor
}