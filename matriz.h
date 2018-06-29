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
    
    No* aux = sentinela;

    while(aux->direita != sentinela && pos > aux->direita->coluna){
        aux = aux->direita;
    }

    return aux;
}

No* getAddressColuna (No* sentinela, int pos){
    
    No* aux = sentinela;

    while(aux->baixo != sentinela && pos > aux->baixo->linha){
        aux = aux->baixo;
    }

    return aux;
}

void inserir_linha (No* sentinela, No* no) {

    No* aux = getAddressLinha (sentinela, no->coluna);

    no->direita = aux->direita;
    no->esquerda = aux;
    aux->direita->esquerda = no;
    aux->direita = no;
}

void inserir_coluna (No* sentinela, No* no) {
    No* aux = getAddressColuna (sentinela, no->linha);

    no->baixo = aux->baixo;
    no->cima = aux;
    aux->baixo->cima = no;
    aux->baixo = no;
}

Matriz* matriz_criar (int qtdeLinhas, int qtdeColunas) {
    Matriz* matriz = (Matriz*) malloc(sizeof(Matriz));

    matriz->colunas = (No**) malloc(qtdeColunas * sizeof(No*));
    matriz->linhas = (No**) malloc(qtdeLinhas * sizeof(No*));
    matriz->numLinhas = qtdeLinhas;
    matriz->numColunas = qtdeColunas;

    for (int i = 0 ; i < matriz->numColunas ; i++ ) {
        matriz->colunas[i] = no_criar(0,i,0);
    }
    for (int i = 0 ; i < matriz->numLinhas ; i ++) {
        matriz->linhas[i] = no_criar(i,0,0);
    }

    return matriz;
}

int verifyValue ( Matriz* m, int linha, int coluna, int valor){
    No* sentinela = m->linhas[linha];

    No* aux = sentinela->direita;

    while (aux != sentinela ){
        if(coluna == aux->coluna){
            aux->valor = valor;
            return 1;
        }
        aux=aux->direita;
    }
    return 0;
}

void desalocar(Matriz* matriz) {
    for (int i = 0 ; i<matriz->numLinhas ; i++) {
        free(matriz->linhas[i]);
    }

    for (int i = 0 ; i<matriz->numColunas ; i++) {
        free(matriz->colunas[i]);
    }

    free(matriz);
}

int matriz_inserir (Matriz* matriz, int linha, int coluna, int valor) {
    if (linha < 0 || linha > matriz->numLinhas ) return 0;
    if (coluna < 0 || coluna > matriz->numColunas ) return 0;
    if( verifyValue(matriz,linha, coluna, valor) ) return 1;

    No* novo = no_criar(linha, coluna, valor);

    inserir_linha(matriz->linhas[linha], novo);
    inserir_coluna(matriz->colunas[coluna], novo);

    return 1;
}

void matriz_imprimir (Matriz *matriz) {
    No* aux;
    int l,c;

    for (l = 0 ; l < matriz->numLinhas ; l++) {
        aux = matriz->linhas[l]->direita;
        for (c = 0 ; c < matriz->numColunas ; c++) {
            if (aux != matriz->linhas[l] && c == aux->coluna) {
                printf("%5d ", aux->valor);
                aux = aux->direita;
            } else {
                printf("%5d ", 0);
            }
        }
        printf("\n ", 0);
    }
}

int matriz_acessar(Matriz* matriz, int linha, int coluna) {
    if (linha < 0 || linha > matriz->numLinhas ) return 0;
    if (coluna < 0 || coluna > matriz->numColunas ) return 0;

    No* sentinela = matriz->linhas[linha];

    No* aux = getAddressLinha(sentinela, coluna+1);

    return aux->valor;

}

void imprimir_linha (Matriz* m, int linha) {
    No* sentinela = m->linhas[linha];
    No* aux = sentinela->direita;

    while (aux != sentinela ){
        printf("%d ", aux->valor);
        aux = aux->direita;
    }
    printf("\n");
}
