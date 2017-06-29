#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"


int main()
{
	char caracter;
	int leituraInt;
	char* palavra = (char*)calloc(20,sizeof(char));
	char* caminhoEntrada = (char*)malloc(100*sizeof(char));
	char* caminhoSaida = (char*)malloc(100*sizeof(char));
	char* openArq = (char*)malloc(100*sizeof(char));

	TrieNo* raiz = selecionaNo();
	if(!raiz){perror(NULL); exit(EXIT_FAILURE);}
	int i,j,index;
	int tamMemoria, numDocs=0;
	scanf("%d %d %s %s",&numDocs,&tamMemoria,caminhoEntrada,caminhoSaida);


	FILE * ArqLeitura;
  	int atualDocumento = 1;
  	long posAtualDocumento = 0;

    //printf("%d",charToIndex('a'));
    while(numDocs){
        strcpy(openArq,caminhoEntrada);
        strcat(openArq,teste);

  		posAtualDocumento = 0;

  		ArqLeitura = fopen(openArq,"r");
        if(!ArqLeitura){perror(NULL); exit(EXIT_FAILURE);}

  		i = 0;

  		while((leituraInt = fgetc(ArqLeitura))!= EOF){
			caracter = (char)leituraInt;
			printf("%c - %d ",caracter,i);
			index = charToIndex(caracter);
			printf("%d\t", index);
			if('a' <= caracter && caracter<='z')
            {
                palavra[i++] = caracter;
            }
			else if(caracter ==' '|| caracter=='\n')
            {
                palavra[i]='\0';
                insereNo(raiz, palavra, atualDocumento, posAtualDocumento);
                strcpy(palavra,"");
                caracter !='\n' ? (posAtualDocumento+=i+1) : (posAtualDocumento+=(i));
                i = 0;j++;
			}
		}
		fclose(ArqLeitura);
		atualDocumento++;
		numDocs--;
  	}
    free(palavra);
    free(caminhoEntrada );
    free(caminhoSaida);
    free(openArq);
	destroiTrie(raiz);
	return 0;
}
