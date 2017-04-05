#ifndef SOLVE_H_INCLUDED
#define SOLVE_H_INCLUDED
#include "pilha.h"

typedef
{
    bool ** solucoesPossiveis;
    int * listaNumerosEntrada;
    pilha * solucoes;
    int * i;
}solucoes

void sendInteiro(int* i);
bool ** fazMatriz(int nOpera, int n_operacoes);
void imprimeListaSolucoes(pilha * p);

void liberaSolucoes(bool ** b, int* a, pilha *p, int * c);

#endif // SOLVE_H_INCLUDED
