#include <stdio.h>

void calcPrimo(int numero, int h)
{
    if (h == 1 || h == 0)
    {
        printf("E primo");
    }
    else
    {
        if (numero % h == 0)
        {
            printf("Nao e primo");
        }
        else
        {
            calcPrimo(numero, h - 1);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    calcPrimo(n, n-1);
}