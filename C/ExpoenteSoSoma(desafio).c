#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int base, expoe, res = 1;
    float r = 1;
    printf("Digite a base. Em seguida de um espaco digite o expoente: ");
    scanf("%d %d", &base, &expoe);
    if (base==0 && expoe<=0)
        printf("\nIndefinicao\n");
    else
    {
        for (int h = abs(expoe); h > 0; h--)
        {
            r = 0;
            for (int i = abs(base); i > 0; i--)
            {
                r = (int)r + res;
            }
            res = (int)r;
        }
        if(expoe<0)
            r = 1/r;
        if(base<0 && expoe%2!=0)
            printf("\nResultado: %.4f\n", -r);
        else
            printf("\nResultado: %.4f\n", r);
    }
    return 0;
}