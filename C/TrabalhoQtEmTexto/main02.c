#include <stdio.h>
#include <stdlib.h>

int calculaTamStrings(char*);
char* extracaoTexto(char*, int);
void calculaQuantidades(int*,int*,int*, char*);

int main(int argc, char *argv[]){
    char *texto;
    int sumTamStrings=calculaTamStrings(argv[1]), qtCaracteres=0, qtPalavras=0, qtLinhas=1;

    texto=(char*) malloc(sumTamStrings*sizeof(char));

    texto=extracaoTexto(argv[1], sumTamStrings);

    calculaQuantidades(&qtCaracteres, &qtPalavras, &qtLinhas, texto);

    printf("Quantidade de caracteres: %d\nQuantidade de palavras: %d\nQuantidade de linhas: %d", qtCaracteres, qtPalavras, qtLinhas);

}

int calculaTamStrings(char *filename){
    FILE *fp;
    int sumTamStrings=0;

    fp=fopen(filename, "r");

    while(1==1)
        if(getc(fp)==-1)
            break;
        else
            sumTamStrings++;

    fclose(fp);

    return sumTamStrings;
}

char* extracaoTexto(char *filename, int sumTamStrings){
    char *texto=(char*)malloc(sumTamStrings*sizeof(char)), novoChar;
    FILE *fp;

    fp=fopen(filename,"r");

    for(int c=0; 1==1; c++){
        novoChar=getc(fp);
        if(novoChar==-1){
            texto[c]='\0';
            break;
        }
        fseek(fp, SEEK_CUR-1, SEEK_CUR);
        texto[c]=novoChar;
    }

    fclose(fp);

    return texto;
}

void calculaQuantidades(int *qtCaracteres,int *qtPalavras,int *qtLinhas, char *texto){
    for(int c=0; texto[c]!='\0'; c++){

        if(texto[c]!='\n' && texto[c]!=' '){
            *qtCaracteres=*qtCaracteres+1;
            if (c>0 && texto[c-1]=='\n' && *qtCaracteres!=0)
                *qtPalavras=*qtPalavras+1;
        }

        else
            if(texto[c]=='\n')
                *qtLinhas=*qtLinhas+1;
            else
                if(texto[c+1]!=' ' && texto[c+1]!='\n' && texto[c+1]!='\0' && *qtCaracteres!=0)
                    *qtPalavras=*qtPalavras+1;
    
    }

    if(*qtCaracteres!=0)
        *qtPalavras=*qtPalavras+1;

}