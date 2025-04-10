#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Prototipos
void alocarCoeficientes(float **vetor, int tamanho);
void alocarIntervalo(float **vetor, int tamanho);

void definirFuncao();
void definirIntervalo();

int temMesmoSinal(float valor1, float valor2);

float calcularFuncao(float x);
float estimarIteracoes(float esquerda, float direita, float erro);
float metodoBissecao(float *esquerda, float *direita, float erro, int maxIteracoes);

void imprimirCabecalho();
void imprimirLinha(int passo, float esquerda, float direita, float meio, float fEsquerda, float fDireita, float fMeio, char sinal1, char sinal2);

// Variaveis globais
float *coeficientes = NULL;
float *intervalo = NULL;
float erro; // margem de erro

int grau;

int main(void)
{	
	definirFuncao();
	definirIntervalo();
	
	if (temMesmoSinal(calcularFuncao(*(intervalo)), calcularFuncao(*(intervalo + 1))))
	{
		printf("Nao e possivel determinar raiz, pois f(esquerda) e f(direita) tem mesmo sinal.\n");
	} 
	else
	{
		printf("Existe raiz no intervalo, pois f(esquerda) e f(direita) tem sinais opostos.\n");
		
		printf("\n\n");
		system("pause");
		printf("\n\n");
		
		float passos = estimarIteracoes((*intervalo), (*(intervalo+1)), erro);
		
		imprimirCabecalho();
		
		float raiz = metodoBissecao(intervalo, intervalo + 1, erro, (int)passos);
		
		printf("\nA raiz estimada da funcao e: %f\n", raiz);
	}
	
	printf("\n\n");
	system("pause");
	printf("\n\n");
	
	return 0;
}

void alocarCoeficientes(float **vetor, int tamanho) 
{
	if ((*vetor = (float*)realloc(*vetor, tamanho * sizeof(float))) == NULL)
		exit(1);
}

void alocarIntervalo(float **vetor, int tamanho)
{
	if ((*vetor = (float*)realloc(*vetor, tamanho * sizeof(float))) == NULL)
		exit(1);
}

float calcularFuncao(float x)
{
	float resultado = 0;
	for (int i = 0; i <= grau; i++)
	{
		resultado += *(coeficientes + i) * pow(x, grau - i);
	}
	return resultado;
}

void imprimirCabecalho()
{
	printf("Passo | Esquerda | Direita  |  Meio   | f(Esq)  | f(Dir)  | f(Meio) | fE*fM | fM*fD |\n");
	printf("------+----------+----------+---------+--------+---------+---------+-------+-------+\n");
}

void imprimirLinha(int passo, float esquerda, float direita, float meio, float fEsquerda, float fDireita, float fMeio, char sinal1, char sinal2)
{
	printf("%4d | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f |   %c   |   %c   |\n",
		passo, esquerda, direita, meio, fEsquerda, fDireita, fMeio, sinal1, sinal2);
}

void definirFuncao()
{
	do
	{
		printf("Informe o grau da funcao (2 a 6): ");
		scanf("%d", &grau);
	} while (grau < 2 || grau > 6);
	
	alocarCoeficientes(&coeficientes, grau + 1);
	
	for (int i = grau; i >= 0; i--) 
	{
		int indice = grau - i;
		printf("Informe o coeficiente de x^%d (letra %c): ", i, 65 + indice);
		scanf("%f", (coeficientes + indice));
	}
	
	printf("Funcao definida: ");
	for (int i = grau; i >= 0; i--)
	{
		int indice = grau - i;
		if (i == 0)
			printf("%.2f = 0", *(coeficientes + indice));
		else
			printf("%.2fx^%d + ", *(coeficientes + indice), i);
	}
	
	printf("\n\n");
	system("pause");
	printf("\n\n");
}

void definirIntervalo()
{
	printf("Informe os valores do intervalo [esquerda, direita] e o erro:\n");
	alocarIntervalo(&intervalo, 2);
	
	printf("Valor de esquerda: ");
	scanf("%f", intervalo);
	printf("Valor de direita: ");
	scanf("%f", intervalo + 1);
	printf("Valor do erro: ");
	scanf("%f", &erro);
	
	printf("\n\n");
}

int temMesmoSinal(float valor1, float valor2)
{
	if (valor1 * valor2 <= 0)
		return 0;
	return 1;
}

float estimarIteracoes(float esquerda, float direita, float erro)
{
	return ceil((log10(direita - esquerda) - log10(erro)) / log10(2));
}

float metodoBissecao(float *esquerda, float *direita, float erro, int maxIteracoes)
{
	float meio, fEsquerda, fDireita, fMeio;
	char sinal1, sinal2;
	int passo = 1;
	
	while (maxIteracoes >= passo || *direita - *esquerda >= erro || fabs(calcularFuncao(meio)) >= erro)
	{
		meio = (*esquerda + *direita) / 2;
		
		fEsquerda = calcularFuncao(*esquerda);
		fDireita = calcularFuncao(*direita);
		fMeio = calcularFuncao(meio);
		
		sinal1 = (fEsquerda * fMeio < 0) ? '-' : '+';
		sinal2 = (fMeio * fDireita < 0) ? '-' : '+';
		
		imprimirLinha(passo, *esquerda, *direita, meio, fEsquerda, fDireita, fMeio, sinal1, sinal2);
		
		if (sinal1 == '-')
			*direita = meio;
		else if (sinal2 == '-')
			*esquerda = meio;
		
		passo++;
	}
	
	return meio;
}