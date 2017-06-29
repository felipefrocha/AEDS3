#include <stdio.h>
#include <stdlib.h>
#define MAX 10001
#define true 1
#define false 0
#define bool short

typedef struct{
  int dano,mana;
}feitico;

int pilhas=0;
int manatotal=100002;
int **dp;

typedef struct{
    int filapossivel[MAX];
    int posicao;
}pilha;

pilha * criaPilha(){
    pilha * f = (pilha*)malloc(sizeof(pilha));
    if(!f){perror("nao foi possivel");exit(EXIT_FAILURE);}
    f->posicao=0;
    pilhas++;
    printf("criouPilha\t%p\n", f);
    return f;
}

void destroiPilha(pilha * f){
	printf("DestruiuPilha\t%p\n", f);
    free(f);
	pilhas--;

}

void copPilha(pilha * f, pilha *f1){
    int i;
    for(i = 0;i<f->posicao;i++)
        f1->filapossivel[i] = f->filapossivel[i];
    f1->posicao = f->posicao;
}

void empilha(pilha * p,int f)
{
  p->filapossivel[p->posicao] = f;
  p->posicao++;

}

int compFeit(const feitico * a, const feitico * b)
{
  return (a->mana < b->mana)? -1 : 1;
}

void display(pilha *p,const feitico * v)
{
  int aux,soma = 0;
  aux = 0;
  int i = 0;

    for ( i = 0; i < p->posicao; ++i){
      soma+= v[p->filapossivel[i]].mana;
      aux+=v[p->filapossivel[i]].dano;

    }

    if(soma<manatotal)
	manatotal = soma;

    destroiPilha(p);
    return;
}
void printSubsetsRec(feitico* arr, int i, int sum,pilha * p)
{
    
    if (i == 0 && sum != 0 && dp[0][sum])
    {
      empilha(p,i);
      display(p,arr);
      return;
    }

    if (i == 0 && sum == 0)
    {
        display(p,arr);
	if(p)destroiPilha(p);
        return;
    }

    
    if (dp[i-1][sum])
    {
      pilha* b = criaPilha();
      copPilha(p,b);
      printSubsetsRec(arr, i-1, sum, b);
    }

    if (sum >= arr[i].dano && dp[i-1][sum-arr[i].dano])
    {
      empilha(p,i);
      printSubsetsRec(arr, i-1, sum-arr[i].dano,p);
    }
}

bool printAllSubsets(feitico* arr, int n, int sum)
{
    int i,j;
    if (n == 0 || sum < 0)
       return false;

    dp = (int**)malloc(n*sizeof(int*));
    for ( i=0; i < n; ++i)
    {
        dp[i] = calloc((sum + 1),sizeof(int));
        dp[i][0] = true;
    }

    if (arr[0].dano <= sum)
       dp[0][arr[0].dano] = true;

    for ( i = 1; i < n; ++i)
        for ( j = 0; j < sum + 1; ++j)
            dp[i][j] = (arr[i].dano <= j) ? dp[i-1][j] || dp[i-1][j-arr[i].dano] : dp[i - 1][j];
    if (dp[n-1][sum] == false)
	return false;

    pilha* p= criaPilha();

    printSubsetsRec(arr, n-1, sum,p);

    destroiPilha(p);

    for (i=0; i<n; ++i){
	free(dp[i]);
    }
    free(dp);
    return true;
}
int main(void)
{
  int i,qtdFeit,vida,aux,aux2;
  double totMana;

  scanf("%d %d",&qtdFeit,&vida);

  feitico feiticos[MAX];
  aux = 0;
  for(i = 0 ; i < qtdFeit ; i++){
    scanf("%d %d",&feiticos[i].dano,&feiticos[i].mana);
    aux+=feiticos[i].dano;
}
//  qsort(feiticos,qtdFeit,sizeof(feitico),compFeit);
  if(aux < vida)
    printf("-1\n");
  for(i = 0;i < 5 && !(printAllSubsets(feiticos,qtdFeit,vida+i));i++);
    printf("%d\n",manatotal);
	printf("numero de pilhas = %d\n",pilhas);

  return 0;
}

    
