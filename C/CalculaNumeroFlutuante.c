#include <stdio.h>
#include <math.h>

int expoente = 0, be, bm;
char tipo;

int *calculaMantissa(float num, int *man)
{
    while (num >= 2)
    {
        num = num / 2;
        expoente++;
    }
    num = num - 1;
    for (int c = 0; c < 32; c++)
    {
        num = num * 2;
        if (num >= 1)
        {
            man[c] = 1;
            num = num - 1;
        }
        else
            man[c] = 0;
    }
    return man;
}

int *calculaExpoente(int num, int *exp)
{
    switch (tipo)
    {
    case 's':
    case 'S':
        num += 127;
        break;
    case 'd':
    case 'D':
        num += 1023;
        break;
    case 'q':
    case 'Q':
        num += 16383;
    }

    for (int w = be - 1; w >= 0; w--)
    {
        if (num % 2 == 0)
            exp[w] = 0;
        else
            exp[w] = 1;

        num = num / 2;
    }

    return exp;
}

int main()
{
    int sinal = 0;
    double n;
    printf("Ola, seja bem vindo ao programa de numero 16!\n");
    printf("Digite o tipo de conversao em numero flutuante do tipo IEEE 754 voce deseja. Sendo elas: simples, dupla e quadrupla\n");
    printf("Atencao, digite S para simples, D para dupla e Q para quadrupla: ");
    
    scanf("%c", &tipo);
    switch (tipo)
    {
    case 's':
    case 'S':
        be = 8;
        bm = 23;
        break;
    case 'd':
    case 'D':
        be = 11;
        bm = 52;
        break;
    case 'q':
    case 'Q':
        be = 15;
        bm = 112;
    }
    int e[be], m[bm];

    printf("Agora digite o numero que voce quer converter: ");
    
    scanf("%lf", &n);
    
    if (n < 0)
        sinal = 1;
    
    int *mb, *eb;
    
    mb = calculaMantissa(sqrt(pow(n,2)), m);
    eb = calculaExpoente(expoente, e);

    printf("\nAqui esta o resultado!\n");

    printf("%d | ", sinal);

    for (int h = 0; h < be; h++)//Printa o expoente
    {
        if (h == be - 1)
            printf("%d | ", eb[h]);
        else
            printf("%d ", eb[h]);
    }

    for (int z = 0; z < bm; z++)//Printa a mantissa
        printf("%d ", mb[z]);
}