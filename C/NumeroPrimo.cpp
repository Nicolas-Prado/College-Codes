#include <stdio.h>

int main(){
    int n, c;
    scanf("%d",&n);
    if(n<=0){
        printf("Digite um numero valido");
    }
    else{
        c=n-1;
        while(c>1){
            if(n%c == 0){
                printf("Nao e primo");
                c=-1;
            }
            else{
                c--;
            }
        }
        if(c==1 || c==0){
            printf("E primo");
        }

    }
}