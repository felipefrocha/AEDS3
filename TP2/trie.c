#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "trie.h"

TrieNo* selecionaNo(void)
{
    TrieNo* pNo = NULL;

    pNo = (TrieNo* )malloc(sizeof(TrieNo));

    if (pNo)
    {
        int posAlfabeto;

        pNo->eFolha = false;
        pNo->detalhes = NULL;


        for (posAlfabeto = 0; posAlfabeto < ALFABETO; posAlfabeto++)
            pNo->filhos[posAlfabeto] = NULL;
    }
    return pNo;
}

int charToIndex(char c){return (int)(c-'a');}

bool insereNo( TrieNo *raiz, const char *chave, int numAtualDocumento, int posAtualDocumento)
{
    int nivel;//nivel de profundidade da arvore
    int tamanho = strlen(chave);//profundidade máxima
    int posAlfabeto; //posição do alfabeto nas folhas
    int i,j;
    nivel = posAlfabeto = 0;

    //printf("\n\t%s %d\n",chave,tamanho);
    TrieNo* pBusca = raiz;

    for (nivel = 0; nivel < tamanho; nivel++)
    {
        posAlfabeto = charToIndex(chave[nivel]);
        if(pBusca->eFolha)
        {
            i++;
            if(pBusca->detalhes->ultimo->numDocumento!=numAtualDocumento)
            {
                pBusca->detalhes->ultimo->frqDocumento++;
                pBusca->detalhes->ultimo->posDocumento = posAtualDocumento;
            }
            else Enfilera(pBusca->detalhes,numAtualDocumento,1,posAtualDocumento);

        }

        if (!pBusca->filhos[posAlfabeto]) {pBusca->filhos[posAlfabeto] = selecionaNo();j++;}
        pBusca = pBusca->filhos[posAlfabeto];
    }
    pBusca->eFolha = true;
    if(!pBusca->detalhes) {
        pBusca->detalhes=IniciaFila();
        Enfilera(pBusca->detalhes,numAtualDocumento,1,posAtualDocumento);
    }
    else Enfilera(pBusca->detalhes,numAtualDocumento,pBusca->detalhes->ultimo->frqDocumento+1,posAtualDocumento);
    if(i || !j)return false;
    return true;
}

bool destroiTrie(TrieNo * raiz)
{
    //if(!raiz) return;
    int i,j;
    j=0;
    for(i = 0 ; i < ALFABETO; i++){

        if(raiz->filhos[i])
        {
            printf("%c",(int)'a'+i);
            if(destroiTrie(raiz->filhos[i])) printf("%c",(int)'a'+i);
        }
        else if(raiz->eFolha){
            if(!Desenfilera(raiz->detalhes)){
                LiberaFila(raiz->detalhes);
                raiz->eFolha = false;
                free(raiz);
                return true;
            }
        }
    }
    return false;
}
