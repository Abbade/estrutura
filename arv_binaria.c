#include <stdio.h>
#include <stdlib.h>

struct arv
{
	char info;
	struct arv* esq;
	struct arv* dir;
}; typedef struct arv Arv;

Arv* arv_criavazia()
{
	return NULL;
}

int arv_vazia(Arv *a)
{
	return a == NULL;
}

Arv* arv_cria(char c, Arv* sae, Arv* sad)
{
	Arv* p = (Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}


void preOrdem(Arv* a)
{
	if (!arv_vazia(a))
	{
		printf("%c ", a->info);
		preOrdem(a->esq);
		preOrdem(a->dir);
	}
}


void ordemSimetrica(Arv* a)
{
	if (!arv_vazia(a))
	{
		ordemSimetrica(a->esq);
		printf("%c ", a->info);
		ordemSimetrica(a->dir);
	}
}


void posOrdem(Arv* a)
{
	if (!arv_vazia(a))
	{
		posOrdem(a->esq);
		posOrdem(a->dir);
		printf("%c ", a->info);
	}
}

int main()
{
	Arv* a = arv_cria('A',
		arv_cria('B',
			arv_cria('E',
				arv_cria('K',
					arv_criavazia(),
					arv_cria('L',
						arv_criavazia(),
						arv_criavazia()
					)
				),
				arv_cria('F',
					arv_criavazia(),
					arv_criavazia()
				)
			),
			arv_cria('C',
				arv_cria('G',
					arv_criavazia(),
					arv_criavazia()
				),
				arv_cria('D',
					arv_cria('H',
						arv_cria('M',
							arv_criavazia(),
							arv_criavazia()
						),
						arv_cria('I',
							arv_criavazia(),
							arv_cria('J',
								arv_criavazia(),
								arv_criavazia()
							)
						)
					),
					arv_criavazia()
				)
			)
		),
		arv_criavazia()
	);

	printf("Pre-Ordem: ");
	preOrdem(a);

	printf("\n");

	printf("Ordem Simetrica: ");
	ordemSimetrica(a);

	printf("\n");

	printf("Pos-Ordem: ");
	posOrdem(a);
	printf("\n");
	system("PAUSE");
	return 0;
}
