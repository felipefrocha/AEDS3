#include <stdio.h>
#include <stdlib.h>
#include "fordFulkersonAlg.h"
int main()
{
    int V, E, F, C;
    int i, j;
    int verticeV, verticeU;
    int pesoArestaIni;

    scanf("%d %d %d %d",&V, &E, &F, &C);
    Grafo * G = criaGrafo(V, E, F, C);
    //insere todas as arestas da leitura
    for (i = 0 ; i < E; i++)
    {
        scanf("%d %d %d", &verticeV, &verticeU, &pesoArestaIni);
        insereAresta(G, verticeV, verticeU, pesoArestaIni);
    }
    printf("%d, %d, %d, %d\n", G->vertices, G->arestas , G->fraq, G->cl);
    int x;
    //scanf("%d",&x);
    for (i = 0 ; i < F; i++)
    {
        scanf("%d",&x);
        insereFranquia(G,x);
    }
    for (i = 0 ; i < C; i++)
    {
        scanf("%d",&x);
        insereCliente(G,x);
    }

   //printGrafo(G);
    insereSuperNos(G);
    printf("%d\n",maxFluxo(0,G->vertices-1,G));
    //printGrafo(G);

    destroiGrafo(G);

    return 0;
}
