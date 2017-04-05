
#include <stdio.h>
#include <stdlib.h>
#include "celula.h"
celula * CriaCelula(){
    celula * c = malloc(sizeof(celula));
    if(!c){perror(NULL); exit(EXIT_FAILURE);}
    c->anterior = NULL;
    c->topo = NULL;
    c->dados = 0;
    return c;
}
void LiberaCelula(celula * c){
    c->topo = NULL;
    c->anterior = NULL;
    free(c->topo);
    free(c->anterior);
    free(c);
}
