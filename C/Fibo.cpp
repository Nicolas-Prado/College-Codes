#include <stdio.h>

int main()
{
    int n, s1 = 0, s2 = 1;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Este termo nao existe na sequencia");
    }
    else
    {
        while (n > 0)
        {
            s2 = s2 + s1;
            s1 = s2 - s1;
            n = n - 1;
        }
        printf("O termo sera: %d", s1);
    }
}