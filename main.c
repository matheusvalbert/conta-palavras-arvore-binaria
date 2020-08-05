#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"
#include "Item.h"
#include "STb.h"


int main(int argc, char *argv[ ])
{
	arvore *raiz = NULL;
	arvore *raiz_ordenada = NULL;
	arvoreB *raizB = NULL;

	char palavra[50];
	char operacao;
	char nome_arquivo[20];
	char palavraEncontrar[50];
	int i;
	int exibir = 0;
	int flag = 0, flag1 = 0, flag2 = 0;
	int h, flagBalanceada = 0;

	for (i = 0; i < argc; i++)
	{
		if(argv[i][0] == '-' && argv[i][1] == 'n')
		{
			exibir = atoi(&argv[i][2]);
		}

		if(argv[i][0] == '-' && argv[i][1] == 'w')
		{
			operacao = 'w';
			strcpy(nome_arquivo, argv[i]);
			flag = 1;
		}

		if(argv[i][0] == '-' && argv[i][1] == 'r')
		{
			operacao = 'r';
			strcpy(nome_arquivo, argv[i]);
		}

		if(argv[i][0] == '-' && argv[i][1] == 's') 
		{
			strcpy(palavraEncontrar,argv[i]);
			flag2 = 1;
		}

		if(argv[i][0] == '-' && argv[i][1] == 'b') 
		{
			flagBalanceada = 1;
		}
	}

	//printf("%s\n", palavraEncontrar);
	//printf("%c\n", operacao);
	//printf("%s\n", nome_arquivo);

	if(operacao == 'r' && flag != 1 && flagBalanceada != 1)
		leituraDoArquivo(nome_arquivo, &raiz);

	if(operacao != 'r' && flagBalanceada != 1) {
		while((scanf("%s", palavra)) != EOF)
		{
			Inserir(palavra, &raiz);
		}
		flag1 = 1;
	}
	
	if(flagBalanceada == 1)
	{
		h = 0;
		while((scanf("%s", palavra)) != EOF)
		{
			inserirB(palavra, &h, &raizB);
		}
		printf("\n");
		imprimirB(raizB);
	}
	if(flagBalanceada != 1)
		ordenaPorValor(raiz , &raiz_ordenada);

	if(exibir > 0 && flagBalanceada != 1)
		Imprimir(raiz_ordenada, &exibir);

	if(flag2 == 1 && flagBalanceada != 1)
		Word(raiz, palavraEncontrar);

	if(operacao == 'w' && flag1 == 1 && flagBalanceada != 1)
		escritaDoArquivo(nome_arquivo, raiz);
		
	return 0;
}
