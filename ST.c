#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ST.h"
#include "Item.h"

int Inserir(char palavra[], arvore **raiz)
{
	if(*raiz == NULL)
	{
		(*raiz) = (arvore *) malloc(sizeof(arvore));
		if((*raiz) == NULL) return (-1);
		
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;

		criaItem(palavra,1, raiz);

		return (1);

	}
	if(strcmp((*raiz)->item ->palavra, palavra) == 0) 
	{
		(*raiz)->item->frequencia += 1;
		return (0);
	}

	if(strcmp((*raiz)->item->palavra, palavra) > 0) 
		return (Inserir(palavra, &(*raiz)->esq));

	return (Inserir(palavra, &(*raiz)->dir));


}

void ordenaPorValor(arvore *raiz , arvore **raiz_ordenada)
{
	if(raiz)
	{
		ordenaPorValor(raiz->esq, raiz_ordenada);
		inserePorValor(raiz, raiz_ordenada);
		ordenaPorValor(raiz->dir, raiz_ordenada);
	}
}

int inserePorValor(arvore *raiz,arvore **raiz_ordenada)
{
	if(*raiz_ordenada == NULL)
	{
		(*raiz_ordenada) = (arvore *) malloc(sizeof(arvore));
		
		(*raiz_ordenada)->esq = NULL;
		(*raiz_ordenada)->dir = NULL;

		criaItem(raiz -> item -> palavra ,raiz -> item -> frequencia, raiz_ordenada);

	}

	//strcmp retorna 0 se for igual
	if((raiz -> item -> frequencia) == ((*raiz_ordenada) -> item -> frequencia)) 
	{

		percorre_lista(raiz, raiz_ordenada);
		return 0;
	}

	if((raiz->item->frequencia) > ((*raiz_ordenada) -> item -> frequencia)) 
		return (inserePorValor(raiz, &(*raiz_ordenada)->esq));

	return (inserePorValor(raiz, &(*raiz_ordenada)->dir));

}

void Imprimir(arvore *raiz, int *exibir)
{
	if(raiz)
	{
		Imprimir(raiz->esq, exibir);
		exibicao(raiz, exibir);
		if(raiz->item->prox != NULL)
			ImprimirLista(raiz->item->prox->prox, exibir);
		Imprimir(raiz->dir, exibir);
	}
}

void ImprimirLista(lista *item, int *exibir) {

	lista *aux = item;

    for (aux = item; item != NULL; item = item->prox) {
		if(*exibir > 0) {
			printf("%i %s\n", item->frequencia, item->palavra);
			*exibir -= 1;
		}
    }
}

void exibicao(arvore *raiz, int *exibir) {

	if(*exibir > 0) {
		printf("%i %s\n", raiz->item->frequencia, raiz->item->palavra);
		*exibir -= 1;
	}
}

void leituraDoArquivo(char nome_arquivo[], arvore **raiz)
{
	int tamanho = strlen(nome_arquivo);
	int i;

	//printf("%d\n", tamanho);

	for(i = 0; i < tamanho; i++)
	{
		if(i != 0 || i != 1)
			nome_arquivo[i-2] = nome_arquivo[i];
	}
	nome_arquivo[i-2] = '\0';

	strcat(nome_arquivo,".txt");

	//printf("%c\n", operacao);
	//printf("%s\n", nome_arquivo);

	leNoArquivo(nome_arquivo, raiz);
}

void escritaDoArquivo(char nome_arquivo[], arvore *raiz)
{
	int tamanho = strlen(nome_arquivo);
	int i;

	//printf("%d\n", tamanho);

	for(i = 0; i < tamanho; i++)
	{
		if(i != 0 || i != 1)
			nome_arquivo[i-2] = nome_arquivo[i];
	}
	nome_arquivo[i-2] = '\0';

	strcat(nome_arquivo,".txt");

	//printf("%c\n", operacao);
	//printf("%s\n", nome_arquivo);

	escreverNoArquivo(nome_arquivo, raiz);
}

void escreverNoArquivo(char nome_arquivo[], arvore *raiz) {

	int i;

	FILE *arq;
	arq = fopen(nome_arquivo,"w");

	escreverNoArquivoRecursivo(arq, raiz);

	fclose(arq);
}

void escreverNoArquivoRecursivo (FILE *arq, arvore *raiz) {

	if(raiz)
	{
		fprintf(arq, "%i %s\n", raiz->item->frequencia, raiz->item->palavra);
		escreverNoArquivoRecursivo(arq, raiz->esq);
		escreverNoArquivoRecursivo(arq, raiz->dir);
	}
}

void leNoArquivo(char nome_arquivo[], arvore **raiz) {

	int frequencia;
	char palavra[50];

	FILE *arq;
	arq = fopen(nome_arquivo,"r");

	while((fscanf(arq, "%i %s", &frequencia, palavra)) != EOF) {

		inserirAposLeitura(frequencia, palavra, raiz);
	}

	fclose(arq);
}

int inserirAposLeitura(int frequencia, char palavra[ ], arvore **raiz) {

	if(*raiz == NULL)
	{
		(*raiz) = (arvore *) malloc(sizeof(arvore));
		if((*raiz) == NULL) return (-1);
		
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;

		criaItem(palavra,frequencia, raiz);
		//printf("%i %s\n", (*raiz)->item->frequencia, (*raiz)->item->palavra);

		return (1);

	}
	if(strcmp((*raiz)->item ->palavra, palavra) == 0) 
	{
		return (0);
	}

	if(strcmp((*raiz)->item->palavra, palavra) > 0) 
		return (inserirAposLeitura(frequencia, palavra, &(*raiz)->esq));

	return (inserirAposLeitura(frequencia, palavra, &(*raiz)->dir));
}

void Word(arvore *raiz, char palavra [ ]) {

	clock_t comeco = clock();

	int posicao = 0, i, repeticao = 0;
	int tamanho = strlen(palavra);

	//printf("%s\n", palavra);

	for(i = 0; i < tamanho; i++)
	{
		if(i != 0 || i != 1)
			palavra[i-2] = palavra[i];
	}
	palavra[i-2] = '\0';

	repeticao = procura(raiz, palavra, &posicao);
	if(repeticao == 0)
		printf("palavra nao encontrada\n");
	else {
	printf("Palavra: %s\nRepeticao: %i\nPosicao: %i\n", palavra, repeticao, posicao);
	}

	clock_t fim = clock();

	double tempo = (double)(fim - comeco) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de Execucao: %f µs\n", tempo);
}

int procura(arvore *raiz, char palavra[], int *posicao)
{
    if (raiz)
    {
        if(strcmp(raiz->item->palavra,palavra) == 0) {
			*posicao += 1;
	    	return (raiz->item->frequencia);
		}
        else
        {
            if(strcmp(raiz->item->palavra,palavra) < 0) {
				*posicao += 1;
                return procura(raiz->dir, palavra, posicao);
			}
            else {
				*posicao += 1;
                return procura(raiz->esq, palavra, posicao);
			}
        }
		return 0;
    }
	return 0;
}