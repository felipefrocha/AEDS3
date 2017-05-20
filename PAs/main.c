#include <stdio.h>
#include <stdlib.h>
#define bool short
#define false 0
#define true 1

struct Edge
{
    int src, dest, weight;
};
struct Graph
{
    int V, E;
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

    return graph;
}
struct subset
{
    int parent;
    int rank;
};
int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
            subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
void isort(struct Graph * g)
{
    int i;
    struct Edge e;
    for (i = 0; i < g->E-1; ++i)
    {
        if(g->edge[i].weight > g->edge[i+1].weight){
            e = g->edge[i];
            g->edge[i] = g->edge[i+1];
            g->edge[i+1] = e;
        }
    }

}
int algKruskal(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    int v;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    isort(graph);

    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) );

    for (v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1)
    {
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }

    }
    int aux=0;
    for (i = 0; i < e; ++i)
    {
        aux +=result[i].weight;
    }
    free(subsets);
    return aux;
}

int main()
{
    int R, C,  V, W, P;

    scanf("%d %d",&R,&C);
    struct Graph* graph = createGraph(R, C);
    int i;
    for (i = 0 ; i < C; i ++)
    {
        scanf("%d %d %d",&V,&W,&P);
        graph->edge[i].src = V-1;
        graph->edge[i].dest = W-1;
        graph->edge[i].weight = P;
    }

    printf("%d\n",algKruskal(graph));
    free(graph->edge);
    free(graph);
    return 0;
}
