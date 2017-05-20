#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define MAXLINHA 150
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define MALLOC_ERROR {perror(NULL);exit(EXIT_FAILURE);}

bool procuraSaida(char **, const int , const int);
bool procuraLinhaLeste(char**,const int, const int,int,int);
bool procuraColunaSul(char**,const int, const int,int,int);
bool procuraLinhaOeste(char**,const int, const int,int,int);
bool procuraColunaNorte(char**,const int, const int,int,int);
int max,cont;
int main()
{
    char ** matrix;
    int colunas, linhas;
    int i, j , k;
    i = k = j = cont = 0;
    scanf("%d",&colunas);
    scanf("%d",&linhas);

    matrix = (char**)malloc(colunas*sizeof(char*));
    if(!matrix)MALLOC_ERROR;

    for (i = 0; i < linhas ; i++)
    {
        matrix[i] = (char*)malloc(linhas*sizeof(char));
        if(!matrix)MALLOC_ERROR;
        scanf("%s",matrix[i]);
    }
    max = linhas*colunas;

    if(procuraSaida(matrix, colunas, linhas))printf("*\n");
    else printf("!\n");

    for (i = 0; i < linhas ; i++) free(matrix[i]);
    free(matrix);
    return 0;
}

bool procuraSaida(char ** matrix, const int colunas, const int linhas)
{
    int i, j;
    i = j = 0;
    return procuraLinhaLeste(matrix, colunas , linhas, i ,j);
}
bool procuraLinhaLeste(char** matrix, const int colunas, const int linhas, int i, int j)
{
    while (j < colunas && cont <= max)
    {
        switch (matrix[i][j])
        {
            case '>':
                return procuraLinhaLeste(matrix,colunas,linhas, i,++j);
                break;
            case '<':
                return procuraLinhaOeste(matrix,colunas,linhas, i,--j);
                break;
            case 'v':
                return procuraColunaSul(matrix,colunas,linhas,++i,j);
                break;
            case '^':
                return procuraColunaNorte(matrix,colunas,linhas,--i,j);
                break;
            case '*':
                return true;
            default:
                break;
        }
        j++;
        cont++;
    }

    return false;
}
bool procuraLinhaOeste(char** matrix, const int colunas, const int linhas, int i, int j)
{

    while (j >= 0 && cont <= max)
    {
        switch (matrix[i][j])
        {
            case '>':
                return procuraLinhaLeste(matrix,colunas,linhas, i,++j);
                break;
            case '<':
                return procuraLinhaOeste(matrix,colunas,linhas, i,--j);
                break;
            case 'v':
                return procuraColunaSul(matrix,colunas,linhas,++i,j);
                break;
            case '^':
                return procuraColunaNorte(matrix,colunas,linhas,--i,j);
                break;
            case '*':
                return true;
            default:
                break;
        }
        j--;
        cont++;
    }
    return false;
}
bool procuraColunaSul(char** matrix, const int colunas, const int linhas, int i, int j)
{
    while (i < linhas && cont <= max)
    {
        switch (matrix[i][j])
        {
            case '>':
                return procuraLinhaLeste(matrix,colunas,linhas, i,++j);
                break;
            case '<':
                return procuraLinhaOeste(matrix,colunas,linhas, i,--j);
                break;
            case 'v':
                return procuraColunaSul(matrix,colunas,linhas,++i,j);
                break;
            case '^':
                return procuraColunaNorte(matrix,colunas,linhas,--i,j);
                break;
            case '*':
                return true;
            default:
                break;
        }
        i++;
        cont++;
    }
    return false;
}
bool procuraColunaNorte(char** matrix, const int colunas, const int linhas, int i, int j)
{
    while (i >= 0 && cont <= max)
    {
        switch (matrix[i][j])
        {
            case '>':
                return procuraLinhaLeste(matrix,colunas,linhas, i,++j);
                break;
            case '<':
                return procuraLinhaOeste(matrix,colunas,linhas, i,--j);
                break;
            case 'v':
                return procuraColunaSul(matrix,colunas,linhas,++i,j);
                break;
            case '^':
                return procuraColunaNorte(matrix,colunas,linhas,--i,j);
                break;
            case '*':
                return true;
            default:
                break;
        }
        i--;
        cont++;
    }
    return false;
}
