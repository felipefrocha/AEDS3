#include <stdio.h>
#include <stdlib.h>
#include "grafoMatrixAdj.h"


Grafo * criaGrafo(int vertices,int arestas, int franquias,int clientes)
{
    Grafo * g = (Grafo*)malloc(sizeof(Grafo));
    vertices+=2;
    g->capacidade = (int**)malloc(vertices*sizeof(int*));
    int i;
    for (i = 0 ; i < vertices ; i++)
    {
        g->capacidade[i] = (int*)calloc(vertices,sizeof(int));
    }
    g->franquias = (int*)calloc(vertices,sizeof(int));
    g->clientes = (int*)calloc(vertices,sizeof(int));
    g->vertices = vertices;
    g->arestas = arestas+franquias+clientes;
    g->fraq = franquias;
    g->cl = clientes;
    return g;
}
void destroiGrafo(Grafo * g)
{
    int i;
    for (i = 0 ; i < g->vertices ; i++)free(g->capacidade[i]);
    free(g->capacidade);
    free(g->clientes);
    free(g->franquias);
    free(g);
}
void insereAresta(Grafo * g, int vOrigem, int vDestino, int aPeso)
{
    g->capacidade[vOrigem+1][vDestino+1] = aPeso;
    //printf("inseriu aresta %d %d %d\n",vOrigem, vDestino, aPeso);
}
void insereFranquia(Grafo * g, int vert)
{
    //printf("%d\n",vert);
    g->franquias[vert+1] = vert+1;
}
void insereCliente(Grafo * g, int vert)
{
    //printf("%d\n",vert);
    g->clientes[vert+1] = vert+1;
}
void insereSuperNos(Grafo* g)
{
    int i;
    for(i = 1 ; i < g->vertices-1; i++) g->capacidade[0][g->franquias[i]] = INFINITO;
    for(i = 1 ; i < g->vertices-1; i++) g->capacidade[g->clientes[i]][g->vertices-1] = INFINITO;
}

void printGrafo(Grafo * g)
{
    int i, j;
    for(i = 0 ; i < g->vertices; i++)
    {
        for(j = 0 ; j < g->vertices; j++) printf("\t%d ",g->capacidade[i][j]);
        printf("\n\n");
    }
}

