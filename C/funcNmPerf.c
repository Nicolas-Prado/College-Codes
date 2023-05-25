#include <stdio.h>
#include <stdlib.h>

int perfeito(int n){
    int h=n;
    for(int i=n-1; i>0; i--){
        if(h%i==0)
            n=n-i;
    }
    if(n==0)
        return 1;
    else
        return 0;
}

int main(){
    int h;
    printf("Escreva um numero: ");
    scanf("%d", &h);
    printf("1 Sera perfeito, 0 nao sera perfeito\n");
    printf("%d", perfeito(h));
}