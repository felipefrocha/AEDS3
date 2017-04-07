#include <stdio.h>
#include <stdlib.h>
#define MAXLINHA 50
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
            printf("%d, %c - %d, %c\n",j,linhaEd[j],i,linhaEd[i]);
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
