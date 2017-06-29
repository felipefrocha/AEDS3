#include <stdio.h>

#define MAX 1000000

typedef struct{
	int posicao,lucro;
	int indice;
}radar;

int lucro[MAX] = 0;

int pesquisa(const int distancia, radar* v, int pesq,const int ultimo)
{
 	int indice = pesq;
 	if(pesq == ultimo) return 0;
 	if (v[indice].posicao <= distancia)
    	lucro[pesq]+=pesquisa(distancia,v,indice+1,ultimo);
    return v[indice].lucro;
}

int main(){
	int numTestes,numRadares,distMin;
	radar* radares;

	scanf("%d",&numTestes);
	for(i = 0; i < numTestes; i++)
	{
		scanf("%d %d",&numRadares,&distMin);
		radares = (radar*)malloc(numRadares*sizeof(radar));
		
		for(j = 0; j < numRadares; j++)
			scanf("%d",&radares[j].posicao;

		for(j = 0; j < numRadares; j++)
			scanf("%d",&radares[j].lucro;
		}
		lucro+=pesquisa(distMin,radares,0,numRadares);
	}
}