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
//Cria Fila Vazia
Fila * criaFilaVazia(int tamanho);
//Destroi Fila
void destroiFila(Fila * f);
//Enfilera inteiro x e muda a cor do indice de x para cinza
void enfilera(Fila * f, int x, int * cor);
//desenfilera o primeiro a entrar na fila e muda a cor do indice do item para preto (indicando vizitação de todos os adjacentes
int desenfilera(Fila * f, int * cor);

#endif // FILAVETOR_H_INCLUDED
