#include <stdio.h>
#include <stdlib.h>
#include "filaVetor.h"


Fila * criaFilaVazia(int tamanho)
{
    Fila * f = (Fila*)malloc(sizeof(Fila));
    f->fila = (int*)calloc(tamanho,sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    return f;
}
void destroiFila(Fila * f)
{
    free(f->fila);
    free(f);
}
void enfilera(Fila * f, int x, int * cor)
{
    f->fila[f->fim] = x;
    f->fim++;
    cor[x] = CINZA;
}
int desenfilera(Fila * f, int * cor)
{
    int i ,x = 0;
    x = f->fila[f->inicio];
    for(i = 0; i < f->fim-1 ; i++) f->fila[i] = f->fila[i+1];
    f->fim--;
    cor[x] = PRETO;
    return x;
}
