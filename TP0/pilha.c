#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "celula.h"


//O(1);
pilha * CriaPilha(void)
{
    pilha * p = malloc(sizeof(pilha));
    if(!p){perror(NULL); exit(EXIT_FAILURE);}
    p->topo = NULL;
    p->tamanho=0;
    return p;

}

void Empilha(pilha*p,int inteiro)
{
    celula * c = CriaCelula();
    //se tamanho for maior que zero então pega celula proximo para celula c
    if(!PilhaVazia(p))p->topo->topo = c;
    //inicializa dados
    c->dados = inteiro;
    //se tamanho 0 então anterior NULL caso contrário pega a celula anterior
    c->anterior = p->topo;
    p->topo = c;
    p->tamanho++;
}
void Desempilha(pilha*p, int *recupera)
{
    celula * c;
    if(!PilhaVazia(p)) { c = p->topo;/* printf("\n\tpilha nao vazia");}*/}
    else return;
    p->topo = c->anterior;
    p->tamanho--;
    if(!c->anterior) {
            LiberaCelula(c);
            return;
    }
    else p->topo->topo = NULL;

    printf( "\ndado sendo liberado: %d  ;\n",c->dados);
    *recupera = c->dados;
    LiberaCelula(c);
}
bool PilhaVazia(pilha* p)
{
    if(!p->topo)
    {
        printf("\n\t PILHA ESTÁ VAZIA0");
        return 1;
    }
    else return 0;
}
void ImprimePilha(pilha *p)
{
    if(PilhaVazia(p))return;
    else
    {
        int i=0;
        celula* c = p->topo;
        do
        {
            printf("\n\tItem %d: %d;", p->tamanho-i,c->dados);
            i++;
            c = c->anterior;
        }while (c);
    }
}
void LiberaPilha(pilha *p)
{
    int i;
    int x;
    int aux = p->tamanho;
    for(i = 0; i < aux ; i++ )
    {
        Desempilha(p,&x);
        //ImprimePilha(p);
    }
    free(p->topo);
    free(p);
}
