#include <stdio.h>
#include <stdlib.h>
#include "TP1.h"




void TP1Solve()
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
        for (i = 0 ; i < F; i++)
    for (i = 0 ; i < E; i++)






    return 0;
}
