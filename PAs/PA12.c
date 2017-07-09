#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

typedef struct{
	int posicao,lucro;
	int indice;
}radar;

int lucro[MAX];

int min( int a, int b){return(a<b)?b:a;}

int pesquisa(const int distancia, radar* v, int pesq,const int ultimo)
{
 	int indice = pesq;
 	int auxLucro = 0;
 	if(pesq == ultimo && v[indice)] return;
 	if (v[indice].posicao <= v[indice-1]distancia){
    
}

int main(){
	int numTestes,numRadares,distMin;
	radar* radares;
	int i, j;
	int lucro1=10000;

	scanf("%d",&numTestes);
	for(i = 0; i < numTestes; i++)
	{
		scanf("%d %d",&numRadares,&distMin);
		radares = (radar*)malloc(numRadares*sizeof(radar));
		
		for(j = 0; j < numRadares; j++)
			scanf("%d",&radares[j].posicao);

		for(j = 0; j < numRadares; j++)
			scanf("%d",&radares[j].lucro);

		for(j = 0; j < numRadares; j++){
			lucro[j] = pesquisa(distMin,radares,j,numRadares);
			if(j>0) lucro1 = min(lucro[j],lucro[j-1]);
			printf("final %d - %d\n",lucro1, lucro[j]);
		}
			

	}
}