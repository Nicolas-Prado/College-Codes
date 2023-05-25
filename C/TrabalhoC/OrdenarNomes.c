#include <stdio.h>
#include <string.h>

int main(){
    char n1[160], n2[160], n3[160], aux[160];
    gets(n1);
    gets(n2);
    gets(n3);
    if(strcmpi(n3,n1)>0 && strcmpi(n3,n2)>0){
        if(strcmpi(n1,n2)>0){
                strcpy(aux, n2);
                strcpy(n2, n1);
                strcpy(n1, aux);
            }
    }
    else{
        if(strcmpi(n1,n3)>0){
            strcpy(aux, n1);
            strcpy(n1, n3);
            strcpy(n3, aux);
            if(strcmpi(n1,n2)>0){
                strcpy(aux, n2);
                strcpy(n2, n1);
                strcpy(n1, aux);
            }
            if(strcmpi(n2,n3)>0){
                strcpy(aux, n3);
                strcpy(n3, n2);
                strcpy(n2, aux);
            }
        }
        else{
            strcpy(aux, n3);
            strcpy(n3, n2);
            strcpy(n2, aux);
        }
    }
    printf("\n");
    puts(n1);
    puts(n2);
    puts(n3);
}
