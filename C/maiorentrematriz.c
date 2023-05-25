#include <stdio.h>

int main(){
    int n=3, m=4;
    float matriz[n][m], vet[n];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++){
            printf("linha %d e coluna %d: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
            if(j==0)
                vet[i]=matriz[i][j];
            else
                if(matriz[i][j]>vet[i])
                    vet[i]=matriz[i][j];
        }
    for(int i = 0; i<n; i++){
        printf("%f ", vet[i]);
    }
}