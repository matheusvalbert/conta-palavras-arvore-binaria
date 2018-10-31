//item.h
typedef struct tLista lista;
typedef struct tArvore arvore;

struct tLista {

	char palavra[50];
	int frequencia;
	struct tLista *prox;
};


int criaItem(char palavra[] ,int frequencia, arvore **raiz);
void percorre_lista(arvore *raiz, arvore **raiz_ordenada);
