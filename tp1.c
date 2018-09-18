#include "tp1.h"
#include <time.h>
void insertionSort(int* original, int length) {
	int i, j, atual;

	for (i = 1; i < length; i++) {
		atual = original[i];


		for (j = i - 1; (j >= 0) && (atual < original[j]); j--) {
			original[j + 1] = original[j];
        }

		original[j+1] = atual;
	}

}
void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}
int inicializaVetor(int *v,int n){
    srand((unsigned)time(NULL) );
    int i;
    for(i=0;i<n;i++){
        v[i] = rand()%n;
    }

}

int verificaVetor(int x,int *vet,int n){
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!=j)
            {
                if(vet[i]+vet[j]==x)
                {

                    return 1;
                }
            }
        }
    }

    return 0;
}
int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
/*int verificaVetor(int x,int *vet,int n)
{
    int i,j,z=0;
    int *item;
    for(i=0; i<n; i++)
    {
        j = vet[i] - x;
     item = (int*)bsearch(&j,vet,n,sizeof(int),cmpfunc);
     if(j!=NULL) return 1;
    }
    return z;
}*/


int verificaVetor2(int x,int *vet,int n)
{
    int i,j,z=0;
    int *item;
    for(i=0; i<n; i++)
    {
        j = vet[i] - x;
     item = (int*)bsearch(&j,vet,n,sizeof(int),cmpfunc);
     if(j!=NULL) z=1;
    }
    return z;
}

