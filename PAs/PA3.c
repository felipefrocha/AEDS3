#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define MAXLINHA 150
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')


struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

bool insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    int i,j;
    i = j = 0;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if(pCrawl->isLeaf)i++;
        if (!pCrawl->children[index]) {pCrawl->children[index] = getNode();j++;}
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isLeaf = true;
    if(i || !j)return false;
    return true;
}

int main(){
    long nTestes;
    long i;
    bool k = false;
    while(1)
    {
        scanf("%ld", &nTestes);
        if(!nTestes) return 0;
        struct TrieNode *root = getNode();
        k = false;


        for(i = 0; i < nTestes ; i++)
        {
            char linha[MAXLINHA] = {};
            scanf("%s",linha);
            if(!insert(root, linha)) k = true;
        }
        free(root);
        if(k) printf("Conjunto Ruim\n");
        else printf("Conjunto Bom\n");
    }
    return 0;
}
