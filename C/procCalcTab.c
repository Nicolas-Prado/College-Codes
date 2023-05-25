#include <stdio.h>
#include <stdlib.h>

int calcTabuada(int n){
    for(int i=0; i<=10; i++)
        printf("%d x %d = %d\n", n, i, n*i);
}
int main(){
    int n;
    printf("Digite o numero que deseja verificar a tabuada: ");
    scanf("%d", &n);
    calcTabuada(n);
}