#include "lista.h"
struct pilha 
{
    Lista* prim; 
}; typedef struct pilha Pilha;

Pilha* pilha_cria()
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL; 
    return p;
}
void pilha_push(Pilha *p, float num)
{
    Lista *n = (Lista*) malloc(sizeof(Pilha));
    n->info = num;
    n->prox = p->prim;
    p->prim = n
}