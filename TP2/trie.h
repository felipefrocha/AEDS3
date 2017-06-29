#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
#define ALFABETO 23
#include "fila.h"
#include "trie.h"
#define PARA printf("\n");system("PAUSE")

typedef struct
{
    struct TrieNo* filhos[ALFABETO];
    bool eFolha;
    fila * detalhes
}TrieNo;

TrieNo *selecionaNo(void);
int charToIndex(char c);
bool insereNo( TrieNo *raiz, const char *chave, int atualDocumento, int posAtualDocumento);
bool destroiTrie(TrieNo * raiz);


#endif
