struct lista
{
    float info;
    struct lista *prox;
}; typedef struct lista Lista;

Lista *lista_cria()
{
    return NULL;
}

Lista *lista_insere(Lista *l, float num)
{
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = l;
    return novo;
}

void lista_imprime(Lista *l)
{
    Lista *aux;
    for (aux = l; aux != NULL; aux = aux->prox)
        printf("Info: %.2f\n",aux->info);
    
}

int lista_vazia(Lista *l)
{
    return (l == NULL); // retorna 1 se estiver vazia !!!
}

Lista * lista_busca(Lista* l, float num)
{
    Lista *aux;
    for(aux = l; aux !=NULL; aux = aux->prox)
    {
        if(aux->info == num)
            return aux;
    }
    return NULL;
}

Lista * lista_retira(Lista *l, float num)
{
    Lista *anterior = NULL;
    Lista *aux = l;
    while(aux != NULL && aux->info != num) // procura o elemento que quer retirar e armazena o anterior
    {
        anterior = aux;
        aux = aux->prox;
    }
    if(aux == NULL)
        return l; // nao achou o numero que quer retirar
    if (anterior == NULL)
        l = aux->prox; // retira o primeiro elemento
    else
        anterior->prox = aux->prox; // retira o elemento do meio
    free(aux);
    return l;
}

void lista_libera(Lista *l)
{
    Lista *p = l;
    while(p !=NULL)
    {
        Lista *aux = p->prox;
        free(p);
        p = aux;
    }
}