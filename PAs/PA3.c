#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINHA 100
#define bool int
#define true 1
#define false 0

bool avaliaPrefixo(char*,int, char*,int);
int main(){
    long nTestes;
    long i , j;
    bool k;
    while(1)
    {
        scanf("%d", &nTestes);
        if(!nTestes) return 0;

        k = false;

        char ** linha = (char**)malloc(nTestes*sizeof(char*));
        if(!linha){perror(NULL);exit(EXIT_FAILURE);}

        for(i = 0; i < nTestes ; i++)
        {
            linha[i] = (char*)malloc(MAXLINHA*sizeof(char));
            if(!linha){perror(NULL);exit(EXIT_FAILURE);}
            scanf("%s",linha[i]);
        }
        for(i = 0; i < nTestes ; i++)
        {
            for(j = 0 ; j < nTestes ; j++)
            {
                if(i == j)continue;
                //printf("\ntamanho linha i : %d\ntamanho linha j :%d\n",strlen(linha[i]),strlen(linha[j]));
                if( strlen(linha[i]) > strlen(linha[j]) ) continue;
                if(avaliaPrefixo(linha[j],strlen(linha[j]),linha[i],strlen(linha[i]))){k = true;break;}
                else continue;
            }
        }
        if(k) printf("Conjunto Ruim\n");
        else printf("Conjunto Bom\n");
        for(i = 0 ; i < nTestes ; i++) free(linha[i]);
        free(linha);
    }

    return 0;
}
bool avaliaPrefixo(char* linha, int tamanhoLinha, char* prefixo,int tamanhoPrefixo)
{
    long j, k;
    j = tamanhoPrefixo;
    //printf("prefixo %s, linha %s",prefixo, linha);
    while(linha[j-1]==prefixo[j-1] && j > 0)
    {
        k--;
        j--;
    }
    //printf("\t%d\n",j);
    if(j==0) return true;
    return false;
}
