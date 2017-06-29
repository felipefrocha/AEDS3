
#include <stdio.h>
#include <stdlib.h>
#include "celula.h"
celula * CriaCelula(int numDocumento,int frqDocumento, int posDocumento){
    celula * c = malloc(sizeof(celula));
    if(!c){perror(NULL); exit(EXIT_FAILURE);}
    c->anterior = NULL;
    c->proximo = NULL;
    c->numDocumento = numDocumento;
    c->frqDocumento = frqDocumento;
    c->posDocumento = posDocumento;
    return c;
}
void LiberaCelula(celula * c){
    c->proximo = NULL;
    c->anterior = NULL;
    imprimeCelula(c);
    //free(c->proximo);
    //free(c->anterior);
    free(c);
}
void imprimeCelula(celula * c)
{
    printf("%d, %d, %d\n",c->numDocumento,c->frqDocumento,c->posDocumento);
}
