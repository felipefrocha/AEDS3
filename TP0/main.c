#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "solve.h"
#define MAXCHAR 101
#define CHARNUM_TO_INT(c) ((int)c-(int)'0')

int main()
{
    char * linha;
    bool ** matrix_operacoes;
    int resposta;
    bool flag;
    int listaNumeros[MAXCHAR];

    linha = malloc(MAXCHAR*sizeof(char));
    //teste falha alocação
    if(!linha){perror(NULL); exit(EXIT_FAILURE);}

    //leitura de linha de caracteres tamanho fixo MAXCHAR
    fgets(linha, MAXCHAR, stdin);
    //define resposta
    scanf("%d",&resposta);
    int i,j,aux,n_operacoes;
    j = aux = n_operacoes = 0;
    //trata entrada de n caracteres em vetor de numeros subistituindo ? por -1
    for(i = 0 ; i < strlen(linha)-1 ; i++)
    {
        //macro para caracteres - entrada convertida pra inteiro diminuida do caracter 0 convertido para inteiro
        int a = CHARNUM_TO_INT(linha[i]);
        if(a>=0 && a < 10)
        {
            //cria numeracao de entrada
            aux = aux * 10;
            aux += (CHARNUM_TO_INT(linha[i]));
            flag = true;
        }
        //consolida numero e insere no vetor na ordem de entrada
        else if (flag == true && linha[i]==' ')
        {
            listaNumeros[j] = aux;
            j++;
            flag = false;
            //printf("\t%d",aux);
            aux = 0;
        }
        //insere no vetor na ordem de entrada o numero -1 (indica operação)
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
    //n*2^n, sendo n o numero de operacoes realizados
    //numero de possibilidades = quantidade de operadores possiveis (2 - "+" "*") elevado ao numero de operadores na linha)
    int nOpera = pow(2,n_operacoes);
    //cria tabela verdade de possibilidades de combinacoes de operacao
    matrix_operacoes = (bool**)malloc((nOpera)*sizeof(bool*));
    //monta tabela de operações 0 + 1 * - garante a ordem lexografica
    for (i = 0; i < nOpera; i++)
    {
        matrix_operacoes[i] = malloc(n_operacoes*(sizeof(bool)));
        if(!matrix_operacoes[i]){perror(NULL);exit(EXIT_FAILURE);}
        aux = i;

        //converte inteiro para binário
        for (j = n_operacoes-1 ; j >= 0 ; j--)
        {
            if(aux == 2)matrix_operacoes[i][j] = aux/2;
            matrix_operacoes[i][j] = aux%2;
            aux = aux /2;
        }
    }
    //para cada linha da matrix tenta soluções
    for(i = 0;i < nOpera;i++)
    {
        //chama solve m*n*2^n - para cada linha (2^n) realiza um conjunto de operacoes (n) para todos os numero inseridos (m) e avalia se o resultado final é igual ao resultado esperado
        if(solve(matrix_operacoes[i],listaNumeros,tamanho,resposta))
        {
            //caso seja vedadeiro imprime na linha de operações que leva ao resultado esperado
            for(j = 0;j<n_operacoes;j++)
            {
                if(matrix_operacoes[i][j])printf("*");
                else printf("+");
            }
            printf("\n");
        }
    }
    //libera a matrix de operaçoes possiveis
    for(i = 0; i < n_operacoes; i++) free(matrix_operacoes[i]);
    free(matrix_operacoes);
    return 0;
}
