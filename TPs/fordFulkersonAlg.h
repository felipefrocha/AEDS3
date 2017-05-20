#ifndef FORDFULKERSONALG_H_INCLUDED
#define FORDFULKERSONALG_H_INCLUDED
#include "grafoMatrixAdj.h"
#include "filaVetor.h"
#define bool short
#define TRUE 1
#define FALSE 0

int minimo(int x, int y);
int bfs (int inicio, int alvo, int * cor, int * pred, int **fluxo, Grafo * g);
int maxFluxo (int origem, int sorvedor, Grafo * g);


#endif // FORDFULKERSONALG_H_INCLUDED
