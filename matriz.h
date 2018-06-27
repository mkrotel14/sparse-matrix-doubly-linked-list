#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int linha;
	int coluna;
	int valor;
	struct No* direita;
    struct No* esquerda;
    struct No* cima;
	struct No* baixo;	
}No;

typedef struct{
	No** linhas;	//ponteiro para o vetor cujas células são ponteiros de nós
	No** colunas;	//ponteiro para o vetor cujas células são ponteiros de nós
	int numLinhas;	//Quantidade de linhas da matriz
	int numColunas;	//Quantidade de colunas da matriz
}Matriz;

// Cria uma matriz vazia e devolve seu endereço de memória.
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas);

// Insere o <valor> na matriz <m> na linha <linha> e coluna <coluna>. Caso a posição já exista, substitua o valor da célula.
int matriz_inserir(Matriz* matriz, int linha, int coluna, int valor);

// Devolve o valor correspondente a linha e coluna solicitada. Faça a validação dos índices. Caso a posição solicitada esteja fora do intervalo, devolva zero.
int matriz_acessar(Matriz* matriz, int linha, int coluna);

// Imprime os valores da matriz na tela. Cada linha deve ser impressa em uma linha diferente e os elementos separados por espaço ou tabulação. Os elementos não representados na matriz (valor zero), também devem ser impressos.
void matriz_imprimir(Matriz* matriz);

// Libera toda memória alocada dinamicamente para a matriz.
void desalocar(Matriz* matriz);

void ler(char* arquivo, Matriz* matriz);

No* no_criar(int linha, int coluna, int valor) {
    No* no = (No*) malloc(sizeof(No));
    no->linha = linha;
    no->coluna = coluna;
    no->valor = valor;
    no->direita = no;
    no->esquerda = no;
    no->cima = no;
    no->baixo = no;

    return no;
}

No* getAddressLinha (No* sentinela, int pos){

}

int inserir_linha (No* sentinela, No* no) {

    No* aux = getAddressLinha(sentinela, no->coluna-1);

    no->direita = aux->direita;
    no->esquerda = aux;
    aux->direita = no;
    aux->direita->esquerda = no;
}

int inserir_coluna () {

}

Matriz* matriz_criar (int qtdeLinhas, int qtdeColunas) {
    Matriz* matriz = (Matriz*) malloc(sizeof(Matriz));

    matriz->colunas = (No**) malloc(qtdeColunas * sizeof(No*));
    matriz->linhas = (No**) malloc(qtdeLinhas * sizeof(No*));
    matriz->numLinhas = qtdeLinhas;
    matriz->numColunas = qtdeColunas;

    for (int i = 0 ; i < matriz->numColunas ; i++ ) {
        matriz->colunas[i] = no_criar(0,0,0);
    }
    for (int i = 0 ; i < matriz->numLinhas ; i ++) {
        matriz->linhas[i] = no_criar(i,0,-10);
    }

    return matriz;
}

int matriz_inserir (Matriz* matriz, int linha, int coluna, int valor) {
    No* novo = no_criar(linha, coluna, valor);

    if (novo->linha < 0 && novo->linha > matriz->numLinhas ) return 0;

    int inserir_linha(Matriz* matriz, No* no, int linha, int coluna, int valor);
    int inserir_coluna(Matriz* matriz, No* no, int linha, int coluna, int valor); 
}

void matriz_imprimir (Matriz *matriz) {
    No* aux;
    int l,c;

    for (l = 0 ; l < matriz->numLinhas ; l++) {
        aux = matriz->linhas[l]->direita;
        for (c = 0 ; c < matriz->numColunas ; c++) {
            if (aux != matriz->linhas[l] && c == aux->coluna) {
                printf("%d", aux->valor);
                aux = aux->direita;
            } else {
                printf("%d", 0);
            }
        }
        printf("\n ", 0);
    }
}