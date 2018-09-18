#include "tp1.h"
void imprimeV(int *v,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",v[i]);
    }
}


int main()
{
    double tempo;
    int x,*vet,*vet2,n,i,j,k;
    __int64 freq, inicio, fim;
    FILE *arq,*arq2;
    arq = fopen("teste.txt","w+");

    arq2 = fopen("teste2.csv","a+");
    fprintf(arq2,"TamanhoDaEntrada,MergeSort,InsertSort,Algoritmo1,Algoritmo2\n");

    if(arq==NULL) printf("erro");
    else{
    for(k=0;k<30;k++){
    printf("%d",k);
    //Inicialização do Vetor
    for(n=10;n<1000000;n=n*10){

    srand( (unsigned)time(NULL) );


    fprintf(arq,"Tamanho da Entrada : %d\n",n);
    fprintf(arq2,"%d,",n);
    //printf("oi");

    //Ordenação Merge Sort
    vet = (int *) malloc(sizeof(int) * n);

    inicializaVetor(vet,n);
    QueryPerformanceFrequency((LARGE_INTEGER *) & freq);
    QueryPerformanceCounter((LARGE_INTEGER *) & inicio);

    mergeSort(vet,0,n-1);
    QueryPerformanceCounter((LARGE_INTEGER *) & fim);
    tempo = ((double) fim - (double) inicio) / (double) freq;
    fprintf(arq,"Tempo de execução - Ordenaçao MergeSort: %.15lf\n", tempo);
    fprintf(arq2,"%.20lf,",tempo);
    tempo = 0;


    //Ordenação Insertion Sort
    inicializaVetor(vet,n);
    QueryPerformanceFrequency((LARGE_INTEGER *) & freq);
    QueryPerformanceCounter((LARGE_INTEGER *) & inicio);
    insertionSort(vet,n);
    QueryPerformanceCounter((LARGE_INTEGER *) & fim);
    tempo = ((double) fim - (double) inicio) / (double) freq;
    fprintf(arq,"Tempo de execução - Ordenaçao InsertionSort: %.15lf\n", tempo);
    fprintf(arq2,"%.20lf,",tempo);


    x = rand()%(n);

    //Algoritmo1
    fprintf(arq,"Algoritmo 1\n");
    QueryPerformanceFrequency((LARGE_INTEGER *) & freq);
    QueryPerformanceCounter((LARGE_INTEGER *) & inicio);
    j = verificaVetor2(x,vet,n);
    QueryPerformanceCounter((LARGE_INTEGER *) & fim);
    tempo = ((double) fim - (double) inicio) / (double) freq;
    fprintf(arq,"Tempo Algoritmo 1: %.15lf\n",tempo);
    fprintf(arq,"Foi encontrado o numero?(1 - sim 0-nao) %d\n",j);
    fprintf(arq2,"%.20lf,",tempo);

    tempo = 0;

    //Algoritmo2
    fprintf(arq,"Algotimo 2(Otmizado)\n");
    QueryPerformanceFrequency((LARGE_INTEGER *) & freq);
    QueryPerformanceCounter((LARGE_INTEGER *) & inicio);
    j = verificaVetor(x,vet,n);
    QueryPerformanceCounter((LARGE_INTEGER *) & fim);
    //printf("Foi encontrado(1 - sim 0-nao) %d\n",j);
    tempo = ((double) fim - (double) inicio) / (double) freq;
    fprintf(arq,"Tempo Algoritmo 2(Otimizado): %.20lf\n",tempo);
    fprintf(arq,"Foi encontrado o numero?(1 - sim 0-nao) %d\n",j);
    fprintf(arq2,"%.20lf",tempo);
    tempo = 0;

    fprintf(arq,"\n\n\n");
    fprintf(arq2,"\n");


    free(vet);
    }
    }

    }

}
