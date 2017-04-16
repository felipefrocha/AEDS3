#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "pilha.h"

#define MAXCHAR 101
#define CHARNUM_TO_INT(c) ((int)c-(int)'0')
bool solve(bool* linhaPossivel, int * linhaOp, int tamanho,int resultado)
{
    pilha * p = CriaPilha();
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    while(i < tamanho)
    {
        if (linhaOp[i]>0) Empilha(p, linhaOp[i]);
        else
        {
            Desempilha(p,&a);
            Desempilha(p,&b);
            //printf("\n\tA: %d B: %d",a,b);
            if(linhaPossivel[j]) Empilha(p,a*b);
            if(!linhaPossivel[j]) Empilha(p,a+b);
            j++;
        }
        i++;
    }
    Desempilha(p,&i);
    LiberaPilha(p);
    return (resultado==i);
}

int main()
{
    char * linha;
    bool ** matrix_operacoes;
    int resposta;
    bool flag;
    int listaNumeros[101];

    linha = malloc(MAXCHAR*sizeof(char));
    //teste falha alocação
    if(!linha){perror(NULL); exit(EXIT_FAILURE);}
    //leitura de
    fgets(linha, MAXCHAR, stdin);
    scanf("%d",&resposta);
    int i,j,aux,n_operacoes;
    j = aux = n_operacoes = 0;

    for(i = 0 ; i < strlen(linha)-1 ; i++)
    {
        int a = CHARNUM_TO_INT(linha[i]);
        if(a>=0 && a < 10)
        {
            aux = aux * 10;
            aux += (CHARNUM_TO_INT(linha[i]));
            flag = true;
        }
        else if (flag == true && linha[i]==' ')
        {
            listaNumeros[j] = aux;
            j++;
            flag = false;
            //printf("\t%d",aux);
            aux = 0;
        }
        if (linha[i]=='?')
        {
            n_operacoes++;
            flag = false;
            listaNumeros[j]=-1;
            j++;
            aux = 0;
        }
    }
    int tamanho = j;
    int nOpera = pow(2,n_operacoes);

    matrix_operacoes = (bool**)malloc((nOpera)*sizeof(bool*));

    for (i = 0; i < nOpera; i++)
    {
        matrix_operacoes[i] = malloc(n_operacoes*(sizeof(bool)));
        if(!matrix_operacoes[i]){perror(NULL);exit(EXIT_FAILURE);}
        aux = i;

        for (j = n_operacoes-1 ; j >= 0 ; j--)
        {
            if(aux == 2)matrix_operacoes[i][j] = aux/2;
            matrix_operacoes[i][j] = aux%2;
            aux = aux /2;
        }
    }

    for(i = 0;i < nOpera;i++)
    {
        if(solve(matrix_operacoes[i],listaNumeros,tamanho,resposta))
        {
            for(j = 0;j<n_operacoes;j++)
            {
                if(matrix_operacoes[i][j])printf("*");
                else printf("+");
            }
            printf("\n");
        }

    }

    for(i = 0; i < n_operacoes; i++) free(matrix_operacoes[i]);
    free(matrix_operacoes);
    printf("\n \t %s",linha);

    return 0;
}
