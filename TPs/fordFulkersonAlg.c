#include <stdio.h>
#include <stdlib.h>
#include "fordFulkersonAlg.h"

int minimo(int x, int y)
{
    return x<y ? x : y;  // returns minimum of x and y
}

int bfs (int inicio, int alvo, int * cor, int * pred, int **fluxo, Grafo * g) {

    int u,v;
    int n = g->vertices;

    for (u=0; u<n; u++) cor[u] = BRANCO;

    Fila * f = criaFilaVazia(n);

    enfilera(f, inicio, cor);

    pred[inicio] = -1;

    while (f->inicio!=f->fim)
    {
        u = desenfilera(f,cor);

        for (v = 0; v < n; v++)
        {
            if (cor[v]==BRANCO && g->capacidade[u][v]-fluxo[u][v]>0)
            {
                enfilera(f, v, cor);
                pred[v] = u;
            }
        }
    }
    destroiFila(f);
    return cor[alvo]==PRETO;
}
//Teste
int maxFluxo (int origem, int sorvedor, Grafo * g) {
    int i,j,u;

    int n = g->vertices;

    int maxFluxo = 0;

    int ** fluxo = (int**)malloc(n*sizeof(int*));
    int * cor = (int*)calloc(n,sizeof(int));
    int * pred = (int*)calloc(n,sizeof(int));

    for (i = 0; i < n; i++)
    {
        fluxo[i] = calloc(n,sizeof(int));
    }
    while (bfs(origem, sorvedor, cor, pred, fluxo, g))
    {
        int adiciona = INFINITO;
        for (u=n-1; pred[u]>=0; u=pred[u])
        {
            adiciona = minimo(adiciona,g->capacidade[pred[u]][u]-fluxo[pred[u]][u]);
        }
        for (u=n-1; pred[u]>=0; u=pred[u])
        {
            fluxo[pred[u]][u] += adiciona;
            fluxo[u][pred[u]] -= adiciona;
        }
        maxFluxo += adiciona;
    }

//    for(i = 0 ; i < n ; i++)
//    {
//        for (j = i ; j < n ; j++)
//        {
//            g->capacidade[i][j] = fluxo[i][j];
//            //printf("\t%d",g->capacidade[i][j]);
//        }
//    }

    for (i = 0; i < n; i++)
    {
        free(fluxo[i]);
    }
    free(fluxo);
    free(cor);
    free(pred);

    return (maxFluxo-INFINITO);
}
