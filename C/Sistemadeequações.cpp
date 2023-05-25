#include <stdio.h>
int main()
{
    int n = 0;
    printf("Digite quantas icognitas o sistema tem \n");
    scanf("%d", &n);
    float v[n][n + 1];
    float r[n];
    for (int i = 0; i < n; i++)
    {
        printf("Digite os coeficientes da %d equacao, e por fim o resultado dela \n", i + 1);
        for (int c = 0; c < n + 1; c++)
        {
            scanf("%f", &v[i][c]);
        }

        r[i] = 0;
    } // pega os valores e inicia o vetor r com todos 0

    for (int x = 0; x < n - 1; x++)
    {
        for (int z = 1; z < n; z++)
        {
            if (v[x + z][x] == 0) // esse if pode ta zuando, coloquei ele por ultimo as 01:00 da madrugada lulll
            {
            }
            else
            {
                float m = -v[x][x] / v[x + z][x];
                for (int j = 0; j + x < n + 1; j++)
                {
                    v[x + z][j + x] = v[x][x + j] + (m * v[x + z][j + x]);
                }
            }
        }
    } // calcula os coeficientes da matriz

    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c < n + 1; c++)
        {
            printf("%f ", v[i][c]);
        }
        printf("\n");
    } // devolve os coeficientes pos escalonamento

    for (int w = n - 1; w >= 0; w--)
    {
        if (w == n - 1)
        {
            r[w] = v[w][n] / v[w][w];
        }

        else
        {
            for (int a = n - 1; a - w > 0; a--)
            {
                v[w][n] = v[w][n] - (v[w][a] * r[a]);
            }

            r[w] = v[w][n] / v[w][w];
        }
    } // calcula os valores das icognitas, e coloca no vetor r
    for (int k = 0; k < n; k++)
    {
        printf("A %d icognita e: ", k + 1);
        printf("%f\n", r[k]);
    } // printa o valor das icognitas pelo vetor r
}