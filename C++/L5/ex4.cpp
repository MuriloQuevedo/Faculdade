#include <stdio.h>

main()
{
    int i, num, maior_num, menor_num;
    for(i=1; i<=10; i++)
    {
        printf("digite dez numeros");
        scanf("%i", &num);
        if(num>maior_num) // verifica se o número digitado (num) é maior que o atual valor armazenado na variável maior_num, Se for verdadeiro, o número digitado (num) é atribuído à variável maior_num
		{
			maior_num = num; // maior_num é atualizado para o valor de num
		}		
	
		else if (num<menor_num) // Similarmente, este bloco verifica se o número digitado (num) é menor que o atual valor armazenado na variável menor_num
		{
			menor_num = num;	//se num for menor que menor_num, então menor_num é atualizado para o valor de num
		}	
    }
    printf("maior numero : %i\n menor numer: %i", maior_num, menor_num);
}