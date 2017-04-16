#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINHA 20
typedef struct {
    char *linha;
    char **linhaOp;
    int *tamanhoLinhas;
    int nOperacoes;
    }TipoTeste;
int main()
{
    TipoTeste *Testes;
    int i = 0;
    int j = 0;
    int aux = 0;
    int nTestes = 0;
    scanf("%d",&nTestes);
    /*Numero de estruturas de teste*/
    Testes = malloc(nTestes*sizeof(TipoTeste));
    /*Entrada de Dados */
    for(i = 0; i < nTestes ; i++)
    {
        printf("\n ntestes %d",nTestes);
        /*Le String do n Teste*/
        Testes[i].linha = malloc (MAXLINHA*sizeof(char));
        if(!Testes[i].linha){perror(NULL);exit(EXIT_FAILURE);}
        fgets(Testes[i].linha, MAXLINHA, stdin);
        printf("\n%s\n",Testes[i].linha);
        /*Numero de Operacoes para esse Teste*/
        scanf("%d",&(Testes[i].nOperacoes));

        printf("\n noperacoes %d\n",Testes[i].nOperacoes);
        Testes[i].linhaOp = malloc(Testes[i].nOperacoes*(sizeof(char*)));
        if(!Testes[i].linhaOp){perror(NULL);exit(EXIT_FAILURE);}

        for(j = 0 ; j < Testes[i].nOperacoes ; j++)
        {
            //Le cada entrada de operacoes
            Testes[i].linhaOp[j] = malloc(3*(sizeof(char)));
            if(!Testes[i].linhaOp[j]){perror(NULL);exit(EXIT_FAILURE);}
            fgets(Testes[i].linhaOp[j], 3, stdin);
        }

        for(i = 0; i < nTestes ; i++){
            for(j = 0 ; j < Testes[i].nOperacoes ; j++) free(Testes[i].linhaOp[j]);
            free(Testes[i].linha);
        }
        free(Testes);



    }



    return 0;
}






int main()
{
    char *linha = malloc (MAXLINHA*sizeof(char));
    char *linhaEd = malloc(MAXLINHA*sizeof(char));
    if(!linhaEd){perror(NULL);exit(EXIT_FAILURE);}
    if(!linha){perror(NULL);exit(EXIT_FAILURE);}
    int i = 0;
    int j = 0;
    int aux = 0;
    int tamanhoSequencia = 0;

    fgets(linha, MAXLINHA, stdin);

    for (i = 0 ; linha[i]!='\n' && i < MAXLINHA; i++)
    {
        if((linha[i] == 97) || (linha[i] == 101) || (linha[i] == 105) || (linha[i] == 111) || (linha[i] == 117))
        {
            linhaEd[j] = linha[i];
            j++;
        }
    }
    tamanhoSequencia = j;
    //Casos pequenos e inexistentes
    if(j==1)
    {
        printf("S\n");
        free(linha);
        free(linhaEd);
        return 0;
    }
    else if(!j)
    {
        printf("N\n");
        free(linha);
        free(linhaEd);
        return 0;
    }
    //Casos maiores que duas letras vogais na sequência

    //Casos de numeros impares pega-se até a metade mais um e compara-se com a metade superior menos um

    for(i = 0 ,j = j-1 ; i < tamanhoSequencia ; i++, j--)
    {
           // printf("%d, %c - %d, %c\n",j,linhaEd[j],i,linhaEd[i]);
            if(linhaEd[j] == linhaEd[i])continue;

            else {aux = 1; break;}
    }
    //flag de auxílio a passa ou não passa
    if (aux)
    {
        printf("N\n");
        free(linha);
        free(linhaEd);
        return 0;
    }
    else
    {
        printf("S\n");
        free(linha);
        free(linhaEd);
        return 0;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINHA 10000

int main(){

    char * linha = (char*)malloc(MAXLINHA*sizeof(char));
    if(!linha){perror(NULL);exit(EXIT_FAILURE);}
    char * linhaOp = (char*)malloc(MAXLINHA*sizeof(char));
    if(!linha){perror(NULL);exit(EXIT_FAILURE);}
    int * pConsoates = (int*)malloc(MAXLINHA*sizeof(int));
    if(!pConsoates){perror(NULL);exit(EXIT_FAILURE);}
    int * pVogais = (int*)malloc(MAXLINHA*sizeof(int));
    if(!pVogais){perror(NULL);exit(EXIT_FAILURE);}

    int tamanhoLinha, nTestes, nOperacoes;
    int operacao, nPos,tMovimentoConsoante,tMovimentoVogais;
    int i , j, k;
    scanf("%d", &nTestes);
    for (i = 0; i < nTestes; i++)
    {
        int nVogais = 0;
        int nConsoantes = 0;

        strcpy(linha,"");
        strcpy(linhaOp,"");

        scanf("%s",linha);
        tamanhoLinha = strlen(linha);
        printf ( "Caso #%d:\n", i+1  );
        for( j = 0 ; j < tamanhoLinha ; j++)
        {
            if((linha[j] == 97) || (linha[j] == 101) || (linha[j] == 105) || (linha[j] == 111) || (linha[j] == 117)) pVogais[nVogais++] = j;
            else pConsoates[nConsoantes++] = j;
        }
        tMovimentoConsoante = tMovimentoVogais = 0;
        scanf("%d",&nOperacoes);
        for(j = nOperacoes; j ; j--)
        {
            scanf("%d",&operacao);
            switch (operacao)
            {
                case 0:
                    scanf("%d",&nPos);
                    tMovimentoVogais+=nPos;
                    break;
                case 1:
                    scanf("%d",&nPos);
                    tMovimentoConsoante+=nPos;
                    break;
                case 2:
                    if(tMovimentoConsoante)
                    {
                        strcpy(linhaOp,linha);
                        for(k = 0 ; k < nConsoantes ; k++) linha[pConsoates[(k+tMovimentoConsoante)%nConsoantes]] = linhaOp[pConsoates[k]];
                    }
                    if(tMovimentoVogais)
                    {strcpy(linhaOp,linha);
                        for(k = 0 ; k < nVogais ; k++) linha[pVogais[(k+tMovimentoVogais)%nVogais]] = linhaOp[pVogais[k]];

                    }
                    tMovimentoConsoante = tMovimentoVogais = 0;
                    printf("%s",linha);
                    puts("");
                    break;
                default :
                    break;
            }
        }
    }
free(linha);
free(linhaOp);
free(pConsoates);
free(pVogais);
}

