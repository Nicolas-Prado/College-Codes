#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void criptografarDocumento(char*, int);
int arquivoNaoExiste(char*);
char* descriptografarTexto(char*);

int main(){
    int opc;
    char texto[255], filename[10];
    int key;
    do{
        printf("Escolha o numero da opcao que deseja: \n");
        printf("1. Criptografar texto \n");
        printf("2. Descriptografar documento \n");
        printf("0. Sair: \n");
        
        fflush(stdin);
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("Digite o texto que deseja criptografar: ");
            fflush(stdin);
            gets(texto);
            while(strlen(texto)==0){
                printf("Deve haver pelo menos um caracter! Digite: ");
                fflush(stdin);
                gets(texto);
            }
            printf("Digite a chave: ");
            fflush(stdin);
            scanf("%d", &key);

            criptografarDocumento(texto, key);

            break;
        
        case 2:
            printf("Digite o nome do arquivo(com sua extensao): ");
            fflush(stdin);
            gets(filename);

            printf("Seu texto descriptografado: \n");
            printf("%s\n", descriptografarTexto(filename));

            printf("Pressionar enter para continuar");
            getch();
            
            break; 

        default:
            break;
        }
    system("cls");
    }while(opc!=0);

}

void criptografarDocumento(char *texto, int key){
    char *textoCript=(char*) malloc (strlen(texto)*sizeof(char)), filename[10]="EPK0.txt", complemento[3];
    int ascii;
    FILE *fp;
    
    for(int c=0; 1==1; c++){
        if(arquivoNaoExiste(filename)){
            break;
        }
        else{
            itoa (c,complemento,10);
            //sprintf(complemento, "%d", c);
            strcpy(filename, "EPK");
            strcat(strcat(filename, complemento),".txt"); 
        }
    }

    printf("%d", strlen(texto));

    for(unsigned int c=0; c<strlen(texto); c++){
        ascii=key;
        ascii += (int)texto[c];
        while(ascii>126)
            ascii -= 95;
        while(ascii<32)
            ascii +=95;
        textoCript[c]=ascii;
    }

    textoCript[strlen(texto)]='\0';

    fp = fopen(filename, "w");
    fprintf(fp,"%d\n",key);
    fprintf(fp,"%s",textoCript);
    fclose(fp);
}

int arquivoNaoExiste(char *filename){
    FILE *fp;
    if ((fp = fopen(filename, "r")))
    {
        fclose(fp);
        return 0;
    }
    return 1;
}    
 
char* descriptografarTexto(char *filename){
    FILE *fp;
    char texto[255], *textoDescript=(char*) malloc(255*sizeof(char));
    int key, ascii;

    fp=fopen(filename, "r");
    
    fscanf(fp, "%d\n", &key);
    fscanf(fp, "%s", texto);

    fclose(fp);
    
    for(unsigned int c=0; c<strlen(texto); c++){
        ascii=key;
        ascii = (int)texto[c]-ascii;
        while(ascii<32)
            ascii += 95;
        while(ascii>126)
            ascii -= 95;
        textoDescript[c]=ascii;
        if (c==strlen(texto)-1)
            textoDescript[c+1]='\0';
    }

    return textoDescript;

}