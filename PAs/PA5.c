#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
    int ** matrixAdj;
    int tamanho;
}grafo;

grafo * iniciaGrafo(int vertices)
{
    grafo * n = (grafo*)malloc(sizeof(grafo));
    n->matrixAdj = (int**)malloc(vertices*sizeof(int*));
    int i,j;
    for (i = 0 ; i < vertices ; i ++)
    {
        n->matrixAdj[i] = (int*)malloc(vertices*sizeof(int));
        for (j = 0; j < vertices; j++) n->matrixAdj[i][j] = 0;
    }
    n->tamanho = vertices;
    return n;
}
void criaAresta (grafo * g, int vert1, int vert2, int peso)
{
    g->matrixAdj[vert1][vert2] = peso;
    g->matrixAdj[vert2][vert1] = peso;
}

void Kruskal(grafo *g, int inicio, int * agm)
{
    int i, j, dest, primeiro, NV = g->tamanho;

}
int main()
{
    int R, C,  V, W, P;

    scanf("%d %d",&R,&C);
    grafo * g = iniciaGrafo(R);
    int i;
    for (i = 0 ; i < C; i ++)
    {
        scanf("%d %d %d",&V,&W,&P);
        criaAresta(g,V,W,P);
    }
    int * p = (int*)malloc(R*sizeof(int));
    Kruskal(g, 0, p)
    return 0;
}

//******************************************************
#include <stdio.h>
#include <stdlib.h>
#define bool short
#define false 0
#define true 1

typedef struct grafo
{
    int nVertices;
    int ** arestas;
    int ** pesos;
    int * grau;
}grafo;

grafo * criaGrafo(int nVertices, int grauMax)
{
    grafo * g = (grafo*)malloc(sizeof(grafo));
    if(!g) {perror(NULL);exit(EXIT_FAILURE);}
    g->nVertices = nVertices;
    g->grau = (int*)calloc(nVertices,sizeof(int));
    g->arestas = (int**)malloc(nVertices*sizeof(int*));
    int i;
    for (i = 0 ; i < nVertices; i++)
        g->arestas[i] = (int*)malloc(grauMax*sizeof(int));
    g->pesos = (int**)malloc(nVertices*sizeof(int*));
    for (i = 0 ; i < nVertices; i++)
        g->pesos[i] = (int*)malloc(grauMax*sizeof(int));
    return g;
}
void liberaGrafo(grafo* g)
{
    int i;
     for (i = 0 ; i < g->nVertices; i++)
        free(g->arestas[i]);
    free(g->arestas);
     for (i = 0 ; i < g->nVertices; i++)
        free(g->pesos[i]);
    free(g->pesos);
    free(g->grau);
    free(g);
}
int insereAresta(grafo * g, int vert1, int vert2, int peso, bool flag)
{
    if (!g) return 0;
    if(vert1 < 0 || vert1 >= g->nVertices) return 0;
    if(vert2 < 0 || vert2 >= g->nVertices) return 0;
    g->arestas[vert1][g->grau[vert1]] = vert2;
    g->pesos[vert1][g->grau[vert1]] = peso;
    g->grau[vert1]++;
    if(!flag) insereAresta(g,vert2,vert1,peso,true);
    return 1;
}


void Kruskal(grafo *g, int inicio, int * agm)
{
    int i, j, dest, primeiro, NV = g->nVertices;
    int menorPeso;
    int * arv = (int*)malloc(NV*sizeof(int));
    for (i  = 0 ; i < NV ; i++)
    {
        arv[i] = i;
        agm[i] = -1;
    }
    while(1)
    {
        primeiro  = 1;
        for (i = 0 ; i < NV ; i++)
        {
            for( j = 0 ; j < g->grau[i]; j++)
            {
                if(arv[i]!=arv[g->arestas[i][j]])
                {
                    if(primeiro)
                    {
                        menorPeso = g->pesos[i][j];
                        inicio = i;
                        dest = g->arestas[i][j];
                        primeiro = 0;
                    }
                    else
                    {
                        if(menorPeso>g->pesos[i][j])
                        {
                            menorPeso = g->pesos[i][j];
                            inicio = i;
                            dest = g->arestas[i][j];
                        }
                    }
                }
            }
        }
        if(primeiro == 1)break;
        if(agm[inicio==-1])agm[inicio]=dest;
        else agm[dest] = inicio;
        for ( i = 0 ; i < NV ; i++)
        {
            if(arv[i] == arv[dest])arv[i]=arv[inicio];
        }
    }
    free(arv);
}
int main()
{
    int R, C,  V, W, P;

    scanf("%d %d",&R,&C);
    grafo * g = iniciaGrafo(R);
    int i;
    for (i = 0 ; i < C; i ++)
    {
        scanf("%d %d %d",&V,&W,&P);
        if(!insereAresta(g,V,W,P,false)) printf("Falha ao inserir aresta\n");
    }
    int * p = (int*)malloc(R*sizeof(int));
    Kruskal(g, 0, p);
    for (i = 0 ; i < C; i ++)printf()
    return 0;
}
