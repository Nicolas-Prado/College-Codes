#include <stdio.h>

int main(){
    int n=0, cem=0, cinq=0, dez=0, cinco=0;
    scanf("%d", &n);
    while(n<0){
        printf("Digite valor valido! \n");
        scanf("%d", &n);
    }
    while(n>=100){
        n=n-100;
        cem++;
    }
    if(n>=50){
        n=n-50;
        cinq++;
    }
    while(n>=10){
        n=n-10;
        dez++;
    }
    if(n>=5){
        n=n-5;
        cinco++;
    }
    printf("%d notas de 100, %d nota de 50, %d notas de 10, %d nota de 5 e %d notas de 1 real.", cem, cinq, dez, cinco, n);
    return 0;
}