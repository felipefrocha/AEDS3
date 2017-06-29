#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

fila* IniciaFila()
{
    fila* f = (fila*)malloc(sizeof(fila));
    if(!f) {perror(NULL); exit(EXIT_FAILURE);}
    f->primeiro = NULL;
    f->ultimo = f->primeiro;
    f->tamanho = 0;
    return f;
}
void   LiberaFila(fila* f){
    while(!FilaVazia(f))
    {
        Desenfilera(f);
    }
}

void   Enfilera(fila* f, int numDocumento,int frqDocumento,int posDocumento)
{
    celula *c = CriaCelula(numDocumento,frqDocumento,posDocumento);
    if(FilaVazia(f)){f->primeiro = c;f->ultimo=c;}
    f->ultimo->anterior = c;
    c->proximo = f->ultimo;
    f->ultimo = c;
    f->tamanho++;

}
bool   Desenfilera(fila* f)
{
    celula* c = f->primeiro;
    if(!FilaVazia(f)){
        f->primeiro = c->anterior;
        printf("\t");
        LiberaCelula(c);
        f->tamanho--;
        return true;
    }
    return false;
}
bool   FilaVazia(fila* f)
{
    return f->tamanho==0;
}
