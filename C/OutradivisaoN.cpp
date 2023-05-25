#include <stdio.h>

int main(){
    float s, n;
    scanf("%f", &n);
    while(n<1){
        printf("Digite valor valido! \n");
        scanf("%f", &n);
    }
    for(int c = 1; n>0; c++){
        s = s + c/n;
        n--;
    }
    printf("%f", s);
    return 0;
}