
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
    //insere todas as arestas da leitura O(E)
    for (i = 0 ; i < E; i++)
    {
        scanf("%d %d %d", &verticeV, &verticeU, &pesoArestaIni);
        insereAresta(G, verticeV, verticeU, pesoArestaIni);
    }
    //leitura de todos os indices das franquias e clientes O(F+C)
    int x;
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
    //insere os super nós que agrupam franquias como origem e clientes como sorvedouros.
    insereSuperNos(G);
    //Busca o maior fluxo possível no grafo O(
    printf("%d\n",maxFluxo(0,G->vertices-1,G));
    //imprime uma possibilidade de fluxo máximo em cada aresta entre dois vertices do grafo.
//    for(i = 1 ; i < G->vertices-1 ; i++)
//    {
//        for (j = i ; j < G->vertices-1 ; j++)
//        {
//            if(G->capacidade[i][j]>0) printf("%d %d %d\n",i-1, j-1, G->capacidade[i][j]);
//        }
//    }

    destroiGrafo(G);

    return 0;
}
