/*
    Exercicios lista 3 estruturas
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
Lista * separa (Lista *l, float num)
{
    Lista *aux = l;
    Lista *nova;
    while(aux != NULL)
    {
        if(aux->info == num)
        {
            nova = aux->prox;
            aux->prox = NULL;
        }
        aux = aux->prox;
    }
    l = aux;
    return nova;
}

int main ()
{
    int i;
    Lista *l;
    Lista *nova;
    l = lista_cria();
    for (i = 1; i <= 10 ; i++)
    {
        l = lista_insere(l,i);        
    }
    nova = separa(l,5);
    printf("PRIMEIRA LISTA: \n");
    lista_imprime(l);
    printf("Segunda lista: \n");
    lista_imprime(nova);

    return 0;
}