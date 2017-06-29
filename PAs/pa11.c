#include <stdio.h>
#include <stdlib.h>
#define MAX 10001
#define true 1
#define false 0
#define bool short

typedef struct{
  int dano,mana;
}feitico;


int manatotal=100002;
int **dp;

typedef struct{
    int filapossivel[MAX];
    int posicao;
}pilha;

pilha*criaPilha(){
    pilha * f = malloc(sizeof(pilha));
    f->posicao=0;
}

void destroiPilha(pilha * f){
    free(f->filapossivel);
    free(f);
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
//  printf("%d  %d\n",p->posicao, f);
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
//  printf("Dano\tFilaI\tFila\n");
    for ( i = 0; i < p->posicao; ++i){
      soma+= v[p->filapossivel[i]].mana;
      aux+=v[p->filapossivel[i]].dano;
//      printf("%d\t%d\t%d\n",v[p->filapossivel[i]].dano,i,p->filapossivel[i]);
    }
//    printf("Dano total = %d | mana: %d | %d\n",aux,soma,manatotal);
    if(soma<manatotal)manatotal = soma;
    destroiPilha(p);
}
void printSubsetsRec(feitico* arr, int i, int sum,pilha * p)
{
    // If we reached end and sum is non-zero. We print
    // p[] only if arr[0] is equal to sun OR dp[0][sum]
    // is true.
    if (i == 0 && sum != 0 && dp[0][sum])
    {
      empilha(p,i);
      display(p,arr);
      if(!p)destroiPilha(p);
      return;
    }

    // If sum becomes 0
    if (i == 0 && sum == 0)
    {
        display(p,arr);
	if(!p)destroiPilha(p);
        return;
    }

    // If given sum can be achieved after ignoring
    // current element.
    if (dp[i-1][sum])
    {
        // Create a new vector to store path
      pilha* b = criaPilha();
      copPilha(p,b);
      printSubsetsRec(arr, i-1, sum, b);
    }

    // If given sum can be achieved after considering
    // current element.
    if (sum >= arr[i].dano && dp[i-1][sum-arr[i].dano])
    {
      empilha(p,i);
      printSubsetsRec(arr, i-1, sum-arr[i].dano,p);
    }
}
// Prints all subsets of arr[0..n-1] with sum 0.
bool printAllSubsets(feitico* arr, int n, int sum)
{
    int i,j;
    if (n == 0 || sum < 0)
       return false;

    // Sum 0 can always be achieved with 0 elements
    dp = (int**)calloc(n,sizeof(int*));
    for ( i=0; i < n; ++i)
    {
        dp[i] = calloc((sum + 1),sizeof(int));
        dp[i][0] = true;
    }

    // Sum arr[0] can be achieved with single element
    if (arr[0].dano <= sum)
       dp[0][arr[0].dano] = true;

    // Fill rest of the entries in dp[][]
    for ( i = 1; i < n; ++i)
        for ( j = 0; j < sum + 1; ++j)
            dp[i][j] = (arr[i].dano <= j) ? dp[i-1][j] || dp[i-1][j-arr[i].dano] : dp[i - 1][j];
    if (dp[n-1][sum] == false)
    {
        //printf("There are no subsets with sum %dn", sum);
        return false;
    }
//    for ( i = 0; i < n; ++i){
//      for ( j = 0; j < sum + 1; ++j)
////        printf("%d  ",dp[i][j]);
//      printf("\n");
   // }

    // Now recursively traverse dp[][] to find all
    // paths from dp[n-1][sum]
    pilha* p= criaPilha();
    printSubsetsRec(arr, n-1, sum,p);
 //   printf("termina aqui \n");
    if(!p)destroiPilha(p);
    for (i=0; i<n; ++i) free(dp[i]);
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

  return 0;
}

    
