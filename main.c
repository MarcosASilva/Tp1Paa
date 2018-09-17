#include "tp1.h"
void imprimeV(int *v,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\n",v[i]);
    }
}


int main()
{
    double tempo;
    int x,*vet,n,i,j;
    __int64 freq, inicio, fim;

    //Inicialização do Vetor
    for(n=10;n<100;n=n*10){
    srand( (unsigned)time(NULL) );

    vet = (int *) malloc(sizeof(int) * n);
    inicializaVetor(vet,n);


    printf("Tamanho da Entrada : %d\n",n);

    x = rand()%(n);
    mergeSort(vet,0,n-1);

    QueryPerformanceFrequency((LARGE_INTEGER *) & freq);
    QueryPerformanceCounter((LARGE_INTEGER *) & inicio);
    j = verificaVetor2(x,vet,n);
    QueryPerformanceCounter((LARGE_INTEGER *) & fim);
    tempo = ((double) fim - (double) inicio) / (double) freq;
    printf("Foi encontrado(1 - sim 0-nao) %d\n",j);
    printf("Tempo funcao 1: %lf\n",tempo);
    tempo = 0;
    QueryPerformanceFrequency((LARGE_INTEGER *) & freq);
    QueryPerformanceCounter((LARGE_INTEGER *) & inicio);
    j = verificaVetor(x,vet,n);
    QueryPerformanceCounter((LARGE_INTEGER *) & fim);
    printf("Foi encontrado(1 - sim 0-nao) %d\n",j);
    tempo = ((double) fim - (double) inicio) / (double) freq;
    printf("Tempo funcao otimizada:%lf\n",tempo);





    free(vet);
    }



}
