#ifndef GRAFOMATRIXADJ_H_INCLUDED
#define GRAFOMATRIXADJ_H_INCLUDED
#define MAX_VERTICES 1000
#define INFINITO 100000

typedef struct Grafo
{
    int ** capacidade;
    int vertices, arestas, fraq, cl;
    int * franquias;
    int * clientes;
} Grafo;

Grafo * criaGrafo(int vertices,int arestas,int franquias, int clientes);

void destroiGrafo(Grafo * g);

void insereAresta(Grafo * g, int vOrigem, int vDestino, int aPeso);

void insereFranquia(Grafo * g, int vert);

void insereCliente(Grafo * g, int vert);

void insereSuperNos(Grafo* g);

void printGrafo(Grafo * g);


#endif // GRAFOMATRIXADJ_H_INCLUDED
