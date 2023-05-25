#include <stdio.h>

int main()
{
    float maior3 = 0, maior2 = 0, maior1 = 0, var;
    do
    {
        printf("Escreva uma valor(<=0 para finalizar): ");
        scanf("%f", &var);

        if (var > maior1)
        {
            maior3 = maior2;
            maior2 = maior1;
            maior1 = var;
        }
        else if (var > maior2)
        {
            maior3 = maior2;
            maior2 = var;
        }
        else if (var > maior3)
            maior3 = var;

    } while (var > 0);
    if (maior2 == 0)
    {
        maior2 = maior1;
        maior3 = maior1;
    }
    if (maior3 == 0)
        maior3 = maior2;
    printf("\n1 Maior: %f\n2 Maior: %f\n3 Maior: %f\n", maior1, maior2, maior3);
    return 0;
}