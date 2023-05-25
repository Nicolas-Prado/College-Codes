#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char frase[99999];
    int excesso=0, p=0;
    gets(frase);
    int t = strlen(frase);
    for(int i=0; i<strlen(frase); i++){
        if(frase[i]==' '){
            excesso++;
            for(int j=i; j<strlen(frase); j++)
                frase[j]=frase[j+1];
        }
    }
    for(int i=0; i<(strlen(frase)-excesso)/2; i++){
        if((frase[i]!=frase[t-1-i-excesso]) && (tolower(frase[i])!=frase[t-1-i-excesso]) && (frase[i]!=tolower(frase[t-1-i-excesso]))){
            p=1;
            break;
        }
    }
    if(p==0){
        printf("E");
    }
    else{
        printf("Nao");
    }
}