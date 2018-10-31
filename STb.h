typedef struct tArvoreBalanceada arvoreB;
typedef enum ABalance Balance;

enum ABalance {E,C,D};

struct tArvoreBalanceada
{
	char palavra[50];
	int frequencia;
	Balance bal;
	arvoreB *dir, *esq;
};

void inserirB(char palavra[], int *h, arvoreB **raiz);
void imprimirB(arvoreB *raiz);