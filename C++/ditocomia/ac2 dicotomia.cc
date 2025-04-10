#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Dicas:
// pow(base, expoente) -> potencia
// ceil(valor) -> arredondar para cima
// fabs(valor) -> valor absoluto

float calcularK(float a, float b, float erro);
float calcularFuncao(float x);
void imprimirCabecalho();
void imprimirLinha(int i, float a, float b, float m, float fa, float fb, float fm, char sinal1, char sinal2);
float pontoMedio(float a, float b);

float *coeficientes = NULL;
int grau;

int main()
{
	int i, tam = 7;
	coeficientes = (float *)malloc(tam * sizeof(float));

	printf("Informe o grau da funcao (2 a 6): ");
	scanf("%d", &grau);

	for (i = grau; i >= 0; i--, coeficientes++)
	{
		printf("Informe o coeficiente de x^%d: ", i);
		scanf("%f", coeficientes);
	}

	printf("Funcao recebida: ");
	for (i = grau; i >= 0; i--)
	{
		if (i == 0)
			printf("%.2f = 0", *(coeficientes - i - 1));
		else
			printf("%.2fx^%d + ", *(coeficientes - i - 1), i);
	}

	printf("\n\n");

	float a, b, erro;
	printf("Digite o valor de A: ");
	scanf("%f", &a);

	printf("Digite o valor de B: ");
	scanf("%f", &b);

	printf("Digite o valor do erro: ");
	scanf("%f", &erro);

	float fa = calcularFuncao(a);
	float fb = calcularFuncao(b);

	printf("f(A) = %f\n", fa);
	printf("f(B) = %f\n", fb);

	imprimirCabecalho();

	if ((fa * fb) < 0)
	{
		int iter = 1;
		float varA = a, varB = b;
		int k = calcularK(a, b, erro);
		float m = pontoMedio(varA, varB);
		float fm = calcularFuncao(m);

		char sinal1 = (fa * fm < 0) ? '-' : '+';
		char sinal2 = (fm * fb < 0) ? '-' : '+';

		imprimirLinha(iter, varA, varB, m, fa, fb, fm, sinal1, sinal2);

		while (iter < k)
		{
			iter++;
			if ((fa * fm) < 0)
			{
				varB = m;
				fb = fm;
			}
			else
			{
				varA = m;
				fa = fm;
			}

			m = pontoMedio(varA, varB);
			fm = calcularFuncao(m);

			sinal1 = (fa * fm < 0) ? '-' : '+';
			sinal2 = (fm * fb < 0) ? '-' : '+';

			imprimirLinha(iter, varA, varB, m, fa, fb, fm, sinal1, sinal2);
		}
	}
	else
	{
		printf("O metodo nao pode ser aplicado neste intervalo.\n");
	}

	free(coeficientes);
	return 0;
}

float calcularK(float a, float b, float erro)
{
	return ceil((log10(b - a) - log10(erro)) / log10(2));
}

float calcularFuncao(float x)
{
	float resultado = 0;
	for (int i = 0; i <= grau; i++)
	{
		resultado += *(coeficientes - i - 1) * pow(x, i);
	}
	return resultado;
}

void imprimirCabecalho()
{
	printf("I |\ta\t|\tb\t|\tm\t|\tf(a)\t|\tf(b)\t|\tf(m)\t|fa*fm\t|fm*fb\t|\n");
	printf("--+-------------+---------------+---------------+---------------+---------------+---------------+-------+-------+\n");
}

void imprimirLinha(int i, float a, float b, float m, float fa, float fb, float fm, char sinal1, char sinal2)
{
	printf("%d |%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%c\t|%c\t|\n", i, a, b, m, fa, fb, fm, sinal1, sinal2);
}

float pontoMedio(float a, float b)
{
	return (a + b) / 2;
}
