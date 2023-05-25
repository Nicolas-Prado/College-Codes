#include <stdio.h>

int* invertervetor(int n, int v[])
{
    int sus=0;
    for (int i = n; i > 0; i--)
    {
        if (n - i == i - 1)
        {
            i = 0;
        }
        if (n % 2 == 0)
        {
            if (i == n / 2)
            {
                i = 0;
            }
        }
        else
        {
            sus = v[n - i];
            v[n - i] = v[i - 1];
            v[i - 1] = sus;
        }
    }
    return v;
}

int main()
{
    int h = 5;
    int V[5] = {1, 2, 3, 4, 5};
    V=invertervetor(h, V);
    for (int c = 0; c < h; c++)
    {
        printf("%d, ", V[c]);
    }
}