#ifndef CELULA_H_INCLUDED
#define CELULA_H_INCLUDED

typedef enum boolean
{
    true = 1,
    false = 0
};
typedef enum boolean bool;

typedef struct{
    struct celula * proximo;
    struct celula * anterior;
    int numDocumento;
    int frqDocumento;
    int posDocumento;

}celula;

celula * CriaCelula(int numDocumento,int frqDocumento, int posDocumento);
void LiberaCelula(celula * c);
void imprimeCelula(celula* c);

#endif // CELULA_H_INCLUDED
