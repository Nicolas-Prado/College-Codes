#include <stdio.h>

int numPerf(int numero, int h){
    if(h == 1){
        return 1;
    }
    else{
        if(numero%h==0){
            return h + numPerf(numero, h-1);
        }
        else{
            return numPerf(numero, h-1);
        }
    }

}

int main(){
    int n;
    scanf("%d",&n);
    if( n!=1 && numPerf(n, n-1) == n){
        printf("E perfeito");
    }
    else{
        printf("Nao e perfeito");
    }
}