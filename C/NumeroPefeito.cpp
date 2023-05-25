#include <stdio.h>

int main(){
    int n, s=0, c;
    scanf("%d",&n);
    c=n;
    while(c>0){
        if(n%c == 0 && c!=n){
            s = s + c;
            c--;
        }
        else{
            c--;
        }
    }
    if(s == n){
        printf("E perfeito");
    }
    else{
        printf("Nao e perfeito");
    }
    
}