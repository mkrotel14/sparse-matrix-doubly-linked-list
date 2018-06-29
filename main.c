#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main() {
    Matriz* matriz = matriz_criar(10,10);
    matriz_inserir(matriz, 2, 7, 70);
    imprimir_linha(matriz, 2);
    matriz_inserir(matriz, 2, 8, 80);
    imprimir_linha(matriz, 2);
    matriz_inserir(matriz, 2, 9, 90);
    imprimir_linha(matriz, 2);
    matriz_inserir(matriz, 2, 0, 1);
    imprimir_linha(matriz, 2);
    matriz_inserir(matriz, 2, 1, 10);
    imprimir_linha(matriz, 2);
    matriz_inserir(matriz, 2, 2, 20);
    imprimir_linha(matriz, 2);
    matriz_inserir(matriz, 2, 3, 30);
    imprimir_linha(matriz, 2);
    matriz_inserir(matriz, 2, 3, 300);
    imprimir_linha(matriz, 2);
    matriz_inserir(matriz, 9, 0, 15);
    imprimir_linha(matriz, 2);
    matriz_inserir(matriz, 9, 9, 20);
    imprimir_linha(matriz, 2);
    matriz_imprimir(matriz);

    // Matriz* m = matriz_criar(2,3);

    // matriz_inserir(m,0,2,20);
    // matriz_imprimir(m);
    // matriz_inserir(m,0,2,40);
    // matriz_imprimir(m);
    // int valor = matriz_acessar(m, 3, 1);
    // printf("%d", valor);
    
    
    // int valor = matriz_acessar(matriz, 9, 9);
    // printf("%5d", valor);
}