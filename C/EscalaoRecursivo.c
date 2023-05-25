#include <stdio.h>
#include <stdlib.h>

int main()
{
    return 0;
}
float **escalonar(float **matriz, int i, int j, int n, int m)
{
    if (j == m)
        return matriz;
    else
    {
        if (matriz[i][j] == 0)
        {
            for (int h = i + 1; h < n; h++)
            {
                if (matriz[h][j] != 0)
                {
                    float aux;
                    for (int a = 0; a < m; a++)
                    {
                        aux = matriz[i][a];
                        matriz[i][a] = matriz[h][a];
                        matriz[h][a] = aux;
                    } // Troca de linhas

                    printf("Trocando linha %d pela linha %d\n", i + 1, h + 1);

                    for (int z = 0; z < n; z++)
                    {
                        for (int x = 0; x < m; x++)
                        {
                            printf("%.2f ", matriz[z][x]);
                        }
                        printf("\n");
                    } // Printa a matriz
                    printf("\n");
                    return escalonar(matriz, i, j, n, m);
                }
            }
            return escalonar(matriz, i, j + 1, n, m);
        }
        else
        {
            float c = 0;
            for (int z = 1; z < n - i; z++)
            {
                if (matriz[i + z][j] != 0)
                {
                    // c = -(matriz[i][j]/matriz[i+z][j]);
                    c = -(matriz[i + z][j] / matriz[i][j]);
                    for (int y = 0; y < m; y++)
                    {
                        matriz[i + z][y] = c * matriz[i][y] + matriz[i + z][y];
                    }
                    printf("Trocando a linha %d pela soma dela(multiplicada por %f) com a linha %d\n", i + z + 1, c, i + 1);
                    for (int z = 0; z < n; z++)
                    {
                        for (int x = 0; x < m; x++)
                        {
                            printf("%.2f ", matriz[z][x]);
                        }
                        printf("\n");
                    } // Printa a matriz
                    printf("\n");
                }
            }
            return escalonar(matriz, i + 1, j + 1, n, m);
        }
    }
}
