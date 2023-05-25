#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, erros = 0, h, acabo = 0, i, c = 0, j=0;
    char p[50], letra, mostra[50], jaforam[50];
    printf("Palavra: ");
    gets(p);
    system("cls");
    printf("+-----------+\n");
    printf("|           |\n");
    printf("|            \n");
    printf("|            \n");
    printf("|            \n");
    printf("|            \n");
    printf("|            \n");
    printf(" ");

    for (i = 0; i < strlen(p) * 2; i = i + 2)
    {
        mostra[i] = '_';
        mostra[i + 1] = ' ';
    }
    mostra[i] = '\0';

    for (h = 0; h < strlen(p); h++)
    {
        if (p[h] == ' ')
        {
            mostra[2 * h] = ' ';
        }
    }

    printf("%s", mostra);
    printf("\n");
    while (erros < 6 && acabo != 1)
    {
        printf("Letras que ja foram: %s\n\n", jaforam);
        printf("Digite a letra: ");
        scanf("%c", &letra);
        fflush(stdin);
        
        for (h = 0; h < strlen(p); h++)
        {
            if (p[h] == letra || p[h] == toupper(letra) || p[h] == tolower(letra))
            {
                c++;
                if (h == 0)
                    mostra[h] = letra;
                else
                    mostra[2 * h] = letra;
            }
            else{
                if(strchr(jaforam, letra)!=NULL || strchr(jaforam, toupper(letra))!=NULL || strchr(jaforam, tolower(letra))!=NULL){
                    c++;
                }
            }
        }
        if (c == 0){
            erros++;
            jaforam[j]=letra;
            jaforam[j+1]='-';
            jaforam[j+2]='\0';
            j=j+2;
        }
        c = 0;
        system("cls");
        switch (erros)
        {
        case 0:
            printf("+-----------+\n");
            printf("|           |\n");
            printf("|            \n");
            printf("|            \n");
            printf("|            \n");
            printf("|            \n");
            printf("|            \n");
            printf(" ");
            break;
        case 1:
            printf("+-----------+\n");
            printf("|           |\n");
            printf("|           O\n");
            printf("|            \n");
            printf("|            \n");
            printf("|            \n");
            printf("|            \n");
            printf(" ");
            break;
        case 2:
            printf("+-----------+\n");
            printf("|           |\n");
            printf("|           O\n");
            printf("|           |\n");
            printf("|           |\n");
            printf("|            \n");
            printf("|            \n");
            printf(" ");
            break;
        case 3:
            printf("+-----------+\n");
            printf("|           |\n");
            printf("|           O\n");
            printf("|          /|\n");
            printf("|           |\n");
            printf("|            \n");
            printf("|            \n");
            printf(" ");
            break;
        case 4:
            printf("+-----------+\n");
            printf("|           |\n");
            printf("|           O\n");
            printf("|          /|\\ \n");
            printf("|           |\n");
            printf("|            \n");
            printf("|            \n");
            printf(" ");
            break;
        case 5:
            printf("+-----------+\n");
            printf("|           |\n");
            printf("|           O\n");
            printf("|          /|\\ \n");
            printf("|           | \n");
            printf("|          /  \n");
            printf("|             \n");
            printf(" ");
            break;
        }
        printf("%s \n", mostra);
        for (h = 0; h < strlen(mostra); h++)
        {
            if (mostra[h] == '_')
                h = strlen(mostra) + 1;
        }
        if (h == strlen(mostra))
        {
            acabo = 1;
            printf("\n");
            printf("Win");
        }
    }

    if (acabo != 1)
    {
        system("cls");
        printf("+-----------+\n");
        printf("|           |\n");
        printf("|           O\n");
        printf("|          /|\\ \n");
        printf("|           | \n");
        printf("|          / \\ \n");
        printf("|             \n");
        printf(" ");
    }
}
