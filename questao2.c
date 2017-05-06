#include <stdio.h>
#include <stdlib.h>
// ############## QUESTAO A ################ 
int busca_sequecial(int linha, int **func, int mat)
{
	int i,j;
	for (i = 0 ; i < linha ; i++)
	{
			if (func[i][0] == mat)
				return func[i][1];
	}
	return -1;
}
// ########### QUESTAO B ################ 
void ordena(int **func, int n)
{
	int f = n, i,j,aux;
	int troca = 1;
	while (troca == 1)
	{
		f = f -1 ;
		troca = 0;
		for (i = 0 ; i < f ; i++)
		{
			if ( func[i][0] < func[i+1][0])
			{
				for (j = 0 ; j < 2 ; j++)
				{
					aux = func[i][j];
					func[i][j] = func[i+1][j];
					func[i+1][j] = aux ;
				}
				troca = 1;
			}
		}
	}

}
// ########### QUESTAO C #################
int busca_binaria(int linha,int **func, int mat)
{
	int meio,inicio=0,fim=linha-1;
	while (inicio <= fim)
	{
		meio = (inicio + fim) / 2;
		if(func[meio][0] == mat)
			return func[meio][1];
		else
			if(mat > func[meio][0])
			 	fim = meio - 1;
			else
				inicio = meio + 1;
	}
	return -1;
}
// #####  PROGRAMA ####
int main(void) {
	int resultado,matricula,escolha;
	int linha,i,j;
	int **mat;
	printf("Digite a quantidade de funcionarios: ");
	scanf("%d",&linha);
//--alocacao dinamica da matriz--
	mat = (int**) malloc(linha*sizeof(int*));
	if (mat == NULL)
	{
		printf("Memoria insuficiente!");
		exit(1);
	}
	for (i= 0 ; i < linha ; i++)
	{
		mat[i] = (int*) malloc (2*sizeof(int));
	}
// --lendo a matriz 
	for(i=0 ; i < linha ; i++)
	{
		for(j = 0 ; j < 2; j++)
		{
			if(j % 2 == 0)
			{
				printf("Digite um o numero da matricula: ");
				scanf("%d",&mat[i][j]);
			}
			else
			{
				printf("Digite o numero do departamento: ");
				scanf("%d",&mat[i][j]);
			}
		}
	}
//--chamando a funcao ordena (Bubblesort)
	ordena(mat,linha);
	printf("Digite o numero da matricula: ");
	scanf("%d",&matricula);
	printf("Digite 1 para busca sequencial ou 2 para binaria: ");
	scanf("%d",&escolha);
	
//--escolha de funcao
	if (escolha == 1)
		resultado = busca_sequecial(linha,mat,matricula);
	if(escolha == 2)
		resultado = busca_binaria(linha,mat,matricula);
// --resultado da busca
	if (resultado == -1)
		printf("Voce nao achou a matricula requerida !\n");
	else
		printf("Departamento: %d",resultado);
// --
	return 0;
}
