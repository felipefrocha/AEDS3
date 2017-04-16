#ifndef CELULA_H_INCLUDED
#define CELULA_H_INCLUDED
#define bool short
#define false 0
#define true 1

typedef struct {
    struct celula * topo;
    struct celula * anterior;
    int dados;

}celula;

celula * CriaCelula();
void LiberaCelula(celula * c);

#endif // CELULA_H_INCLUDED
