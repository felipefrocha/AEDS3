#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "celula.h"

typedef struct fila
{
    celula * primeiro;
    celula * ultimo;
    int tamanho;
}fila;

fila*  IniciaFila();
void   LiberaFila(fila* f);
void   Enfilera(fila* f, int numDocumento,int frqDocumento,int posDocumento);
bool   Desenfilera(fila* f);
bool   FilaVazia(fila* f);
#endif // FILA_H_INCLUDED
