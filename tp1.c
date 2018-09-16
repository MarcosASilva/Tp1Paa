#include "tp1.h"
int inicializaVetor(int *v,int n){
    srand( (unsigned)time(NULL) );
    int i;
    for(i=0;i<n;i++){
        v[i] = rand()%(n*10);
    }

}

int verificaVetor(int x,int *vet,int n)
{   printf("Numero a ser encontrado: %d\n",x);
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!=j)
            {
                if(vet[i]+vet[j]==x)
                {
                    printf("Vezes Executadas %d\n",i*j);
                    return 1;
                }
            }
        }
    }

    return 0;
}
int verificaVetor2(int x,int *vet,int n)
{
    int i,j,z=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!=j)
            {
                if(vet[i]+vet[j]==x)
                {

                    z=1;
                }
            }
        }
    }
    printf("Vezes Executadas %d\n",i*j);
    return z;
}

