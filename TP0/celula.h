#ifndef CELULA_H_INCLUDED
#define CELULA_H_INCLUDED

typedef enum boolean
{
    true = 1,
    false = 0
};
typedef enum boolean bool;

typedef struct {
    struct celula * topo;
    struct celula * anterior;
    int dados;

}celula;

celula * CriaCelula();
void LiberaCelula(celula * c);

#endif // CELULA_H_INCLUDED
