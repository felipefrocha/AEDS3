

#include <stdio.h>
#define MAXN 100001
#define ERR 0.000005
int min(const void* a, const void* b)
{
    return((*(int*)a)>(*(int*)b)?-1:1);
}
double buscaBinaria (const int x, const int *v ,int N, double e, double d)
{
     int i;
     double H;
     H = (e + d)/2.0;
     double area=0;
     //printf("\n %.2f\n", H);
     for(i = 0; (i < N) && (v[i]>=H) ;i++){
        //printf(" %.2f %.2f | ",area,(double)v[i]-H);
        area+=((double)v[i]-H);
     }

     //printf("\n area %.2f - area ob %.4f\t altura %.4f\tmenor %.2f\tmenor%.2f ",(double)x,area, H,e,d);
     if ((d-e)< ERR)
        return H;
     else if( area > (double)x){
        return buscaBinaria(x,v,N,H,d);
     }
     else{
        return buscaBinaria(x, v,N, e,H);
     }
}


int nada(){
	int N,A;
	double H;
	int v[MAXN];
	int v2[MAXN];
    int soma,i,j,n,t;
    int menor,maior;
    while(1){
        maior=0;
        menor=9999999;
        scanf("%d %d",&N,&A);
        if(N==A&&A==0)return 0;
        i=soma=0;
        do{
            scanf("%d",&v[i]);
            soma+=v[i];
            if(maior<v[i]) maior = v[i];
            if(menor>v[i]) menor = v[i];
            i++;
        }while(i<N);
        //printf("%d < %d\n",menor, maior);

        if(soma==A) printf(":D\n");
        else if(soma<A) printf("-:-\n");
        else{
            soma =0;
            qsort(v,N,sizeof(int),min);
            H = buscaBinaria(A, v,N,0.0,(double)maior);
            printf("%.4f\n",H);

        }
    }
    return 0;
}

