#include <stdio.h>

int main(){
    int n=5, vet[n], aux;
    for(int i = 0; i<n; i++)
        scanf("%d", &vet[i]);
    for(int k=0; k<n-1; k++)
        for(int i=k+1; i<n; i++)
            if(vet[i]<vet[k]){
                aux=vet[i];
                vet[i]=vet[k];
                vet[k]=aux;
            }
    for(int i=0; i<n; i++)
        printf("%d ", vet[i]);
}