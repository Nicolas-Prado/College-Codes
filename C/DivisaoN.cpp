#include <stdio.h>

int main(){
    float n=0, s=0;
    scanf("%f", &n);
    while(n<1){
        printf("Digite valor valido \n");
        scanf("%d", &n);
    }
    while(n>0){
        s=s+(1/n);
        n--;
    }
    printf("%f", s);
    return 0;
}