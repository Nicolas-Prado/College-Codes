#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *extracaoTexto(char *);
void calculaQuantidade(int *, int *, int *, char *);
int calculaTamArquivo(FILE *);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero de paremetros incorreto");
        return 0;
    }
    //Tornar este malloc abaixo realmente dinamico, com o tamanho do documento la
    char *texto = (char *)malloc(255 * sizeof(char));

    texto = extracaoTexto(argv[1]);

    int qtCaracteres = 0, qtPalavras = 1, qtLinhas = 1;
    calculaQuantidade(&qtCaracteres, &qtPalavras, &qtLinhas, texto);

    printf("Quantidade de caracteres: %d\nQuantidade de palavras: %d\nQuantidade de linhas: %d", qtCaracteres, qtPalavras, qtLinhas);
}

char *extracaoTexto(char *filename)
{
    //Precisamos mudar nossa ideia de pegar o tamanho, ta tendo numero negativo e os krl, esse é o problema, precisamos so mudar como chegamos no maximo acho eu
    char *texto;
    int tamArquivo;
    FILE *fp;

    fp = fopen(filename, "r");

    tamArquivo=calculaTamArquivo(fp);

    fseek(fp, 0, SEEK_SET);

    if (tamArquivo == 0){

        texto = (char *)malloc(sizeof(char));
        texto[0] = '\0';

        fclose(fp);
        return texto;
    }

    else
    {
        texto = (char *)malloc(tamArquivo * sizeof(char));
        for (int c = 0; c < tamArquivo; c++)
        {
            texto[c] = getc(fp);
        }
        fclose(fp);
        return texto;
    }
}

void calculaQuantidade(int *qtCaracteres, int *qtPalavras, int *qtLinhas, char *texto)
{
    for (unsigned int c = 0; c < strlen(texto); c++)
    {
        if (texto[c] != '\n' && texto[c] != ' '){
            *qtCaracteres = *qtCaracteres + 1;
            if(c-1>-1 && texto[c-1]=='\n')
                *qtLinhas=*qtLinhas+1;
        }
        else{
            if(*qtCaracteres!=0){
                if (texto[c] == ' ')
                    *qtPalavras = *qtPalavras + 1;
            }
        }
    }
    if (*qtCaracteres == 0)
    {
        *qtPalavras = 0;
        *qtLinhas = 0;
    }
}

int calculaTamArquivo(FILE *fp){
    int tamArquivo=0;
    while(1==1){
        if(getc(fp)==EOF)
            break;
        else
            tamArquivo++;
    }
    return tamArquivo;
}