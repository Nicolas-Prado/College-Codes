#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *texto=(char*)malloc(255*sizeof(char)), novoChar;
    FILE *fp;

    fp=fopen(argv[1],"r");

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

    printf("Com formatacao s: %s\n", texto);

    printf("Com formatacao d:");
    for(int c=0; texto[c]!='\0';c++)
        printf("%d", texto[c]);
    return 0;
}