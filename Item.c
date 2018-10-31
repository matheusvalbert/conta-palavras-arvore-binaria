//Item.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Item.h"
#include "ST.h"

int criaItem(char palavra[],int frequencia , arvore **raiz)
{
	(*raiz)->item = (lista *) malloc(sizeof(lista));

	if((*raiz) -> item == NULL)
	{
		printf("ERROR!!\n");
		return (-1);
	}

	strcpy((*raiz)-> item ->palavra, palavra);
	(*raiz)-> item ->frequencia = frequencia;
	(*raiz)-> item -> prox = NULL;
	return 0;

}

void percorre_lista(arvore *raiz, arvore **raiz_ordenada)
{
    lista *aux = (lista *) malloc(sizeof(lista));
    lista *aux2 = (lista *) malloc(sizeof(lista));

    aux = (*raiz_ordenada)->item;
    aux2->prox = NULL;
    strcpy(aux2->palavra, (raiz)->item->palavra);
	aux2->frequencia = (raiz)-> item ->frequencia;

    if (aux == NULL)
        (*raiz_ordenada)->item = aux2;

    else {
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = aux2;
    }
}