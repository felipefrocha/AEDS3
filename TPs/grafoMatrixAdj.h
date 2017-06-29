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
//Cria Grafo Vazio de tamanho de Vertices e com franquias posicoes para franquias e clientes posicoes para posicoes (isso é util para criação dos supernós de origem e sorvedouro
Grafo * criaGrafo(int vertices,int arestas,int franquias, int clientes);
//Destroi grafo
void destroiGrafo(Grafo * g);
//insere arestas de relações ponderadas entre os vertices de origem e destino
void insereAresta(Grafo * g, int vOrigem, int vDestino, int aPeso);
//insere indice de vertice para franquias
void insereFranquia(Grafo * g, int vert);
//insere indice de vertice para clientes
void insereCliente(Grafo * g, int vert);
//insere supernos de origem e sorvedouro com aresta "infinita"
void insereSuperNos(Grafo* g);
//utilizado para conferir a construção e modificação do grafo
void printGrafo(Grafo * g);


#endif // GRAFOMATRIXADJ_H_INCLUDED
