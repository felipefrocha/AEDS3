#include <stdio.h>
#include <stdlib.h>
#include "solve.h"
#include "pilha.h"
bool solve(bool* linhaPossivel, int * linhaOp, int tamanho,int resultado)
{
    pilha * p = CriaPilha();
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    while(i < tamanho)
    {
        if (linhaOp[i]>0) Empilha(p, linhaOp[i]);
        else
        {
            Desempilha(p,&a);
            Desempilha(p,&b);
            //printf("\n\tA: %d B: %d",a,b);
            if(linhaPossivel[j]) Empilha(p,a*b);
            if(!linhaPossivel[j]) Empilha(p,a+b);
            j++;
        }
        i++;
    }
    Desempilha(p,&i);
    LiberaPilha(p);
    return (resultado==i);
}
