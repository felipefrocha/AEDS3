#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

#include <math.h>

#define MAXCHAR 10000

int main()
{
    printf("Leia do arquivo\n");
    char * linha;
    bool ** matrix_operacoes;
    int resposta;
    bool flag;

    linha = malloc(MAXCHAR*sizeof(char));
    //teste falha alocação
    if(!linha){perror(NULL); exit(EXIT_FAILURE);}
    //leitura de
    fgets(linha, MAXCHAR, stdin);

    scanf("%d",&resposta);

    int i,j,aux;
    int n_operacoes = 0;
    bool *vetor;
    int listaNumeros[100];
    j = 0;
    aux = 0;
    for(i = 0 ; linha[i] != '\n'  ; i++)
    {

        if(linha[i] >= 48 && linha[j] <= 57)
        {
            aux = aux * 10;
            aux = aux +  (linha[i]-48);
            flag = true;
            printf("%d \n",aux);
        }
        else if (flag == true)
        {
            printf("%d \n",aux);
            flag = false;
            aux = 0;
        }
        printf("\t%d\n",flag);
        if(linha[i]=='?') n_operacoes++;

        listaNumeros[j] = aux;
        j++;

    }
    int nOpera = pow(2,n_operacoes);
    matrix_operacoes = malloc((nOpera)*sizeof(bool*));
    vetor = malloc (n_operacoes*sizeof(bool));
    printf("\n%d\n",nOpera);
    for (i = 0; i < nOpera; i++)
    {
        matrix_operacoes[i] = malloc(n_operacoes*(sizeof(bool)));
        if(!matrix_operacoes[i]){perror(NULL);exit(EXIT_FAILURE);}
        aux = i;

        for (j = n_operacoes ; aux > 0 ; j--)
        {
            if(aux == 2)matrix_operacoes[i][j] = aux/2;
            aux = aux /2;
            matrix_operacoes[i][j] = aux%2;
        }
        printf("\n");

    }
    for (i = 0; i < nOpera; i++)
    {
        for (j = 0 ; aux < n_operacoes ; j++)
        {
            printf("\t%d" ,matrix_operacoes[i][j]);
        }
    }


    printf("\n \t %s \t %d",linha, n_operacoes);

    return 0;
}
