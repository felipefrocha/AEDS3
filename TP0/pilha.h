#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "celula.h"

typedef struct{
    celula * topo;
    int tamanho;
    //celula* fundo;
}pilha;

pilha * CriaPilha(void);
void Empilha(pilha*p,int inteiro);
void Desempilha(pilha*p, int* recupera);
void ImprimePilha(pilha *p);
bool PilhaVazia(pilha* p);
void LiberaPilha(pilha *p);
#endif // PILHA_H_INCLUDED
