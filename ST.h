#include <stdio.h> //stdio é necessario, pois usa o tipo FILE (linha 20);

typedef struct tLista lista;
typedef struct tArvore arvore;

struct tArvore
{
	lista *item;
	arvore *dir, *esq;
};

int Inserir(char palavra[], arvore **raiz);
void ordenaPorValor(arvore *raiz , arvore **raiz_ordenada);
int inserePorValor(arvore *raiz,arvore **raiz_ordenada);
void Imprimir(arvore *raiz, int *exibir);
void ImprimirLista(lista *item, int *exibir);
void exibicao(arvore *raiz, int *exibir);
void leituraDoArquivo(char nome_arquivo[], arvore **raiz);
void escritaDoArquivo(char nome_arquivo[], arvore *raiz);
void escreverNoArquivo(char nome_arquivo[], arvore *raiz);
void escreverNoArquivoRecursivo (FILE *arq, arvore *raiz);
void leNoArquivo(char nome_arquivo[], arvore **raiz);
int inserirAposLeitura(int frequencia, char palavra[ ], arvore **raiz);
void Word(arvore *raiz, char palavra []);
int procura(arvore *raiz, char palavra[], int *posicao);