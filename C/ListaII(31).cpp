#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    float A, B, C;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a)
    {
        A = -((a * a - b * b - c * c) / 2 * b * c);
        B = -((b * b - a * a - c * c) / 2 * a * c);
        C = -((c * c - a * a - b * b) / 2 * a * b);
        if (A > 0 && B > 0 && C > 0)
        {
            printf("Triangulo acutangulo");
        }
        else
        {
            if (A == 0 || B == 0 || C == 0)
                printf("Triangulo retangulo");

            else
                printf("Triangulo obtusangulo");
        }
    }
    else
        printf("Nao e triangulo");

    return 0;
}