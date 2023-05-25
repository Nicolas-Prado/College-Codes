#include <stdio.h>
int main()
{
    int z = 4;
    int sus = 0;
    int C[z] = {1, 2, 3, 4};
    for (int i = z; i > 0; i--)
    {
        if (z - i == i - 1)
        {
            i = 0;
        }
        if (i == z / 2)
        {
            i=0;
        }
        else
        {
            sus = C[z - i];
            C[z - i] = C[i - 1];
            C[i - 1] = sus;
        }
    }
    for (int c = 0; c < z; c++)
    {
        printf("%d, ", C[c]);
    }
}