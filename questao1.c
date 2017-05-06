#include <stdio.h>
#include <stdlib.h>
void pares(int n)
{
	int aux,i;
	int f = n, troca = 1;
	int *vet;
	// alocando vetor dinamicamente
	vet = (int*) malloc(n*sizeof(int));
	if (vet == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);
	}
	// lendo vetor
	for (i= 0 ; i < n ; i++)
	{
		printf("Digite um numero inteiro: ");
		scanf("%d",&vet[i]);
	}
	// ordernando em ordem decrescente (metodo da bolha)
	while(troca == 1)
	{
		f = f - 1;
		troca = 0;
		for (i = 0; i < f ; i++)
		{
			if (vet[i] < vet[i+1])
			{
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				troca = 1;
			}
		}
	}
	// lendo numeros pares 
	for (i = 0 ; i < n ; i++)
	{
		if (vet[i] % 2 == 0) // só printa numero par
		{
			printf("%d\n",vet[i]);
		}
	}
	
}
int main(void) {
	int n;
	printf("Digite o tamanho do vetor: ");
	scanf("%d",&n);
	pares(n);
	return 0;
}
