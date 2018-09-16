#include "tp1.h"



int main()
{
    double tempo;
    int x,*vet,n,i,j;
    __int64 freq, inicio, fim;

    //Inicialização do Vetor
    for(n=10;n<100000;n=n*10){
    srand( (unsigned)time(NULL) );

    vet = (int *) malloc(sizeof(int) * n);
    inicializaVetor(vet,n);

    printf("%d\n",n);

    x = rand()%(n*10);


    QueryPerformanceFrequency((LARGE_INTEGER *) & freq);
    QueryPerformanceCounter((LARGE_INTEGER *) & inicio);
    j = verificaVetor(x,vet,n);
    QueryPerformanceCounter((LARGE_INTEGER *) & fim);
    tempo = ((double) fim - (double) inicio) / (double) freq;
    printf("Foi encontrado(1 - sim 0-nao) %d\n",j);
    printf("%lf\n",tempo);

    QueryPerformanceFrequency((LARGE_INTEGER *) & freq);
    QueryPerformanceCounter((LARGE_INTEGER *) & inicio);
    j = verificaVetor2(x,vet,n);
    QueryPerformanceCounter((LARGE_INTEGER *) & fim);
    printf("Foi encontrado(1 - sim 0-nao) %d\n",j);
    tempo = ((double) fim - (double) inicio) / (double) freq;
    printf("%lf\n",tempo);



    free(vet);
    }



}
