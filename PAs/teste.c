#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 10001

int bmhs (char* texto, int n, char *P, int m)
{
    int i, j , k , d[MAXCHAR];
    int count = 0;
    for (j = 0 ; j <= MAXCHAR; j++)d[j] = m+1;
    for (j = 1 ; j <= m; j++) d[P[j-1]]=m-j+1;
    i=m;
    while (i<=m)
    {
        k = i;
        j = m;
        while ((texto[k-1] == P[j-1]) && (j>0)){k--;j--;}
        if(j==0) count++;
        i+=d[texto[i]];
    }
    return count;
}
char** montaMatrixSub(char* texto , char ** subs, int N)
{
    int i,j;

    for(i = 0 ; i < (strlen(texto)-N+1);i++)
    {
        subs[i] = (char*)malloc(N*sizeof(char));
        if (!subs[i]){perror(NULL);exit(EXIT_FAILURE);}
        for(j = 0; j < N ;j++) {subs[i][j] = texto[j+i];}
        subs[i][j] = '\n';
        printf("\n%s",subs[i]);
    }
    printf("saiu\n");
    return subs;
}


int main() {
	int T, N, i, j;
	char * texto = (char*)malloc(MAXCHAR*sizeof(char));
	char **subs = (char**)malloc(MAXCHAR*sizeof(char*));
	scanf("%d",&T);
	for(i = 0; i < T; i++)
	{
	    scanf("%d %s",&N, texto);

	    int aux, index, maximo;
	    aux = index = maximo = 0;
	    subs = montaMatrixSub(texto, subs, N);
	    for(j = 0; j < strlen(texto); j++)
	    {
	        aux = bmhs(texto, strlen(texto),subs[j], N);
	        if (aux>=maximo) {maximo = aux; index = j;}
	    }
	    printf("Faisca %s",subs[j]);
	}
	for(j = 0; j < strlen(texto); j++) free(subs[j]);
	free(subs);
	free(texto);
	return 0;
}
