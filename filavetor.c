#include <stdio.h>
#include <stdlib.h>
#define N 10
// jhonn_mig@hotmail.com
struct fila
{
    int n;
    int ini;
    int vet[N];
}; typedef struct fila Fila;

Fila *fila_cria()
{
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f==NULL)
        exit (1);
    f->n = 0;
    f->ini = 0;
    return f;
}

void fila_insere(Fila *f1, float num)
{
    if (f1->n == N )
        exit(1);
    int fim = (f1->n + f1->ini) % N;
    f1->vet[fim] = num;
    f1->n++;
}

float fila_retira(Fila *f1)
{
    if(f1->n == 0)
        exit(1);
    float num = f1->vet[f1->ini];
    f1->ini = (f1-> ini + 1) % N;
    f1->n --;
    return num;
}

void fila_imprime (Fila *f1)
{
  int i;
  for (i=0; i<f1->n; i++)
  {
      printf(" \n %d", f1->vet[(f1->ini + i)%N ]);
  }
}

Fila combina_filas(Fila*f_res, Fila *f1, Fila *f2)
{
    float num;
    while(f1->n != 0 || f2->n != 0)
    {
        if(f1->n != 0)
        {
            num = fila_retira(f1);
            fila_insere(f_res,num);   
        }
        if(f2->n != 0)
        {
            num = fila_retira(f2);
            fila_insere(f_res,num);
        }
    }
}

void fila_libera(Fila *f)
{
    free(f);
}

int main()
{
    Fila *f1, *f2, *f_res;
    
    f1 = fila_cria();
    f2 = fila_cria();
    f_res = fila_cria();
    
    fila_insere(f1,10);
    fila_insere(f1,20);
    fila_insere(f1, 30);
    fila_insere(f1, 40);
    
    float v = fila_retira(f1);
    printf("\n%f:", v);
    printf("\n");
    fila_imprime(f1);
    printf("\n");
    
    fila_insere(f2,5);
    fila_insere(f2,15);
    fila_insere(f2, 25);
    fila_insere(f2, 35);

    fila_imprime(f2);
    printf("\n");
    
    combina_filas(f_res, f1, f2);
    fila_imprime(f_res);
    printf("\n");

    fila_libera(f1);
    fila_libera(f2);
    fila_libera(f_res);
    
    return 0;
}