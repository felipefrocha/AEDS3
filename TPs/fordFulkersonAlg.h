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
 A busca sempre � realizada entre o super n� de origem e o super n� de sorvedouro
 um vetor de indices com o caminho aumentante (pred) � criado para auxiliar a fun��o maxFluxo()
 retorna True sempre que todas as visitas at� o vertie de destino foram realizadas (fila vazia)
*/
int bfs (int inicio, int alvo, int * cor, int * pred, int **fluxo, Grafo * g);
/*
  MaxFLuxo() utiliza o metodo de FordFulkerson modificado com BFS (Edmonds Karp) para encontrar o valor m�ximo de
  fluxo entre dois vertices (super n�s de origem e sorvedouro) que agrupam vertices de franquias e clientes respectivamente.
  A cada passo da fun��o uma busca em largura � ralizada para avaliar se existe um caminho aumentante no grafo.
  A constru��o do caminho aumentante (vetor de indices "pred") permite atualizar os valores da matrix fluxo com os
  valores m�ximos de caminhamento dentro do grafo para cada caminho aumentante possivel.
  O fluxo m�ximo para um caminho aumentante cria um valor de fluxo m�ximo para cada v�rtice.
  A cada fim de itera��o para um caminho aumentante � atualizado o valor de fluxo maximo do grafo como um todo.
  Por fim a itera��o while rompe quando n�o ha mais um caminho aumentante entre os vertices de origem e sorvedouro,
  retornando o valor de fluxo m�ximo e atualizando a capacidade de cada aresta do grafo para o fluxo m�ximo para
  cada vertice encontrado.
*/
 int maxFluxo (int origem, int sorvedor, Grafo * g);


#endif // FORDFULKERSONALG_H_INCLUDED
