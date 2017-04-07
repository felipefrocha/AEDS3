#include <stdio.h>
#include <stdlib.h>
#define MAXLINHA 50
int main()
{
    printf("Digite a Linha");

    char *linha = malloc (MAXLINHA*sizeof(char));
    char *linhaEd = malloc(MAXLINHA*sizeof(char));
    if(!linhaEd){perror(NULL);exit(EXIT_FAILURE);}
    if(!linha){perror(NULL);exit(EXIT_FAILURE);}
    int i = 0;
    int j = 0;
    int aux = 0;
    int tamanhoSequencia = 0;
    char * padrao = malloc((MAXLINHA/2+1)*sizeof(char));
    char * padraoInv = malloc((MAXLINHA/2+1)*sizeof(char));
    if(!padrao){perror(NULL);exit(EXIT_FAILURE);}
    if(!padraoInv){perror(NULL);exit(EXIT_FAILURE);}

    fgets(linha, MAXLINHA, stdin);

    for (i = 0 ; linha[i] != '\n' ; i++)
    {
        if((linha[i] == 97) || (linha[i] == 101) || (linha[i] == 105) || (linha[i] == 111) || (linha[i] == 117))
        {
            linhaEd[j] = linha[i];
            j++;
        }
    }
    tamanhoSequencia = j;
    //Casos pequenos e inexistentes
    if(j==1) {printf("S\n"); return 0;}
    else if(!j) {printf("N\n"); return 0;}
    //Casos maiores que duas letras vogais na sequência

    //Casos de numeros impares pega-se até a metade mais um e compara-se com a metade superior menos um

    if (tamanhoSequencia%2){
        tamanhoSequencia = tamanhoSequencia/2+1;

        for(i = 0 ; i <= tamanhoSequencia ; i++)
        {
            printf("\n 1 inv : %d %c, %d %c",j-i, linhaEd[j-i],i,linhaEd[i]);
            if(linhaEd[j-1-i] == linhaEd[i])continue;
            else {aux = 1; break;}
        }
    }
    //Casos pares divide se o vetor em comparação de frente pra tras e de tras pra frente
    else
    {
        tamanhoSequencia = tamanhoSequencia/2;
        for(i = 0 ; i <= tamanhoSequencia ; i++)
        {
            printf("\n 2 inv : %d %c, %d %c",j-i, linhaEd[j-i],i,linhaEd[i]);
            if(linhaEd[j-1-i] == linhaEd[i])continue;
            else {aux = 1; break;}
        }
    }
    printf("\n %d",aux);
    if (aux)
    {
        printf("N\n");
        system("PAUSE");
        return 0;
    }
    else
    {
        printf("S\n");
        system("PAUSE");
        return 0;
    }

    for (i = 0 ; linha=='\n'; i++) printf(" %c",linha[i]);
    for (i = 0 ; i < tamanhoSequencia; i++) printf(" %c",linhaEd[i]);
    free(linha);
    free(linhaEd);
    return 0;
}
