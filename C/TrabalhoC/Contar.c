#include <stdio.h>
#include <string.h>

int Calcular(int a, int b){
    return a+b;
}

int main(){
    char frase[100000];
    int qpalavras=1, qletras=0, qvogala=0, qvogale=0, qvogali=0, qvogalo=0, qvogalu=0;
    printf("Frase: ");
    gets(frase);
    for(int i=0; i<strlen(frase); i++){
        if((frase[i]>64 && frase[i]<91) || (frase[i]>96 && frase[i]<123)){
            qletras++;
            if(frase[i]=='a'|| frase[i]=='A')
                qvogala++;
            else 
                if(frase[i]=='e'|| frase[i]=='E')
                    qvogale++;
                else   
                    if(frase[i]=='i'|| frase[i]=='I')
                        qvogali++;
                    else    
                        if(frase[i]=='o'|| frase[i]=='O')
                            qvogalo++;
                        else    
                            if(frase[i]=='u'|| frase[i]=='U')
                                qvogalu++;
        }
        else 
            if(frase[i]==' ')
                qpalavras++;
    }
    printf("\n");
    printf("Quant. Palavras: %d \nQuant. Letras: %d \nQuant. de vogal a: %d\nQuant. de vogal e: %d\nQuant. de vogal i: %d\nQuant. de vogal o: %d\nQuant. de vogal u: %d", qpalavras, qletras, qvogala, qvogale, qvogali, qvogalo, qvogalu);
}