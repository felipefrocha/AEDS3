#ifndef FORDFULKERSONALG_H_INCLUDED
#define FORDFULKERSONALG_H_INCLUDED
#include "grafoMatrixAdj.h"
#include "filaVetor.h"
#define bool short
#define TRUE 1
#define FALSE 0

//Retorna menor entre dois numeros (em caso de igualdade retorna y)
int minimo(int x, int y);
/*
 Busca em Largura: visita e enfileira todas as adjacencias de um dado vertice,
 muda a cor dos mesmos para marcar visita utilizando um vetor de indices para cores
 A busca sempre é realizada entre o super nó de origem e o super nó de sorvedouro
 um vetor de indices com o caminho aumentante (pred) é criado para auxiliar a função maxFluxo()
 retorna True sempre que todas as visitas até o vertie de destino foram realizadas (fila vazia)
*/
int bfs (int inicio, int alvo, int * cor, int * pred, int **fluxo, Grafo * g);
/*
  MaxFLuxo() utiliza o metodo de FordFulkerson modificado com BFS (Edmonds Karp) para encontrar o valor máximo de
  fluxo entre dois vertices (super nós de origem e sorvedouro) que agrupam vertices de franquias e clientes respectivamente.
  A cada passo da função uma busca em largura é ralizada para avaliar se existe um caminho aumentante no grafo.
  A construção do caminho aumentante (vetor de indices "pred") permite atualizar os valores da matrix fluxo com os
  valores máximos de caminhamento dentro do grafo para cada caminho aumentante possivel.
  O fluxo máximo para um caminho aumentante cria um valor de fluxo máximo para cada vértice.
  A cada fim de iteração para um caminho aumentante é atualizado o valor de fluxo maximo do grafo como um todo.
  Por fim a iteração while rompe quando não ha mais um caminho aumentante entre os vertices de origem e sorvedouro,
  retornando o valor de fluxo máximo e atualizando a capacidade de cada aresta do grafo para o fluxo máximo para
  cada vertice encontrado.
*/
 int maxFluxo (int origem, int sorvedor, Grafo * g);


#endif // FORDFULKERSONALG_H_INCLUDED
