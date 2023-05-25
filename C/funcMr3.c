#include <stdio.h>
#include <stdlib.h>

float maiorEntre(float a, float b, float c){
    if(a>=b && a>=c){
        return a;
    }
    else{
        if(b>=c)
            return b;
        else
            return c;
    }
}

int main(){
    float a,b,c;
    printf("Digite 3 numeros dos quais voce deseja saber o maior: ");
    scanf("%f %f %f", &a,&b,&c);
    printf("%f", maiorEntre(a,b,c));
}