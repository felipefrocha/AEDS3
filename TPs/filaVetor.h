#ifndef FILAVETOR_H_INCLUDED
#define FILAVETOR_H_INCLUDED
#define BRANCO 0
#define CINZA 1
#define PRETO 2
typedef struct Fila{
    int * fila;
    int inicio;
    int fim;
}Fila;

Fila * criaFilaVazia(int tamanho);
void destroiFila(Fila * f);
void enfilera(Fila * f, int x, int * cor);
int desenfilera(Fila * f, int * cor);

#endif // FILAVETOR_H_INCLUDED
