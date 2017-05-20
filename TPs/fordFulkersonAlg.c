#include <stdio.h>
#include <stdlib.h>
#include "fordFulkersonAlg.h"



int minimo(int x, int y) {
    return x<y ? x : y;  // returns minimum of x and y
}
int bfs (int inicio, int alvo, int * cor, int * pred, int **fluxo, Grafo * g) {

    int u,v;
    int n = g->vertices;

    printf("chamou BFS\n");

    for (u=0; u<n; u++) cor[u] = BRANCO;

    Fila * f = criaFilaVazia(MAX_VERTICES+2);
    enfilera(f, inicio, cor);
    pred[inicio] = -1;
    while (f->inicio!=f->fim)
    {
        u = desenfilera(f,cor);
            // Search all adjacent white nodes v. If the capacidade
            // from u to v in the residual network is positive,
            // enqueue v.
        for (v=0; v<n; v++)
        {
            if (cor[v]==BRANCO && g->capacidade[u][v]-fluxo[u][v]>0)
            {
                enfilera(f, v, cor);
                pred[v] = u;
            }
        }
    }
    destroiFila(f);
    // If the color of the target node is black now,
    // it means that we reached it.
    return cor[alvo]==PRETO;
}

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
    printf("chamouMaxFLuxo\n");


    // While there exists an augmenting path,
    // increment the flow along this path.
    while (bfs(origem, sorvedor, cor, pred, fluxo, g))
    {
            // Determine the amount by which we can increment the flow.
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

    for (i = 0; i < n; i++)
    {
        free(fluxo[i]);
    }
    free(fluxo);
    free(cor);
    free(pred);

    // No augmenting path anymore. We are done.
    return (maxFluxo-INFINITO);
}
