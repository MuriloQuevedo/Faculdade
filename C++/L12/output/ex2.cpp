#include <stdio.h>
// Protótipo
float multi (float x, float y);

main()
{
    float num1, num2, resultado;
    printf("digite dois numeros ");
    scanf("%f %f", &num1, &num2);

    resultado = multi (num1, num2);
    printf("%.2f\n", resultado);

   // Chama a função divisao diretamente dentro do printf
    printf("%.2f\n", multi(num1, num2));
}

//definição da função
float multi (float x, float y)
{
    float m;
    m = x*y;
    return m; // retorna o valor
}