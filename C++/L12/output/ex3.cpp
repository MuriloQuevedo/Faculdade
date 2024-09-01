#include <stdio.h>
float media (float x, float y);

main()
{
    float num1, num2;
    printf("digite dois numeros");
    scanf("%f %f", &num1, &num2);
    printf("sua media e %.2f", media (num1, num2));
}
float media (float x, float y)
{
    float m;
    m = (x+y)/2;
    return m;
}