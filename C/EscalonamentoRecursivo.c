#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

float **alocarMatriz(int, int);
float **gerarIdentidade(int, int);
void printfMatriz(float **, int, int);
void printfMatrizGJ(float **, float **, int, int);
void copiarMatriz(float **, float **, int, int);

float **escalonar(float **, int, int, int, int, int);
float **calcularInversa(float **, float **, int, int, int, int);
void manipularInversa(float **, float, int, int, int);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m); // Numero de linhas e colunas

    float **matriz;
    matriz = alocarMatriz(n, m); // Aloca memoria pra matriz com n linhas e m colunas

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%f", &matriz[i][j]);
        }
    } // Preenche a tabela

    float **matrizescalonada;
    float **inversa;
    float **matrizinvertivel;

    int opcao = -1;
    do
    {

        system("cls");

        printf("MENU\n");
        printf("1 - Trocar a matriz\n");
        printf("2 - Matriz escalonada e seu posto (Eliminação de Gauss)\n");
        printf("3 - Inversa da matriz (Método de Gauss-Jordan)\n");
        printf("0 - Sair\n");

        opcao = getche();   // getche() retorna o codigo da tecla
        opcao = opcao - 48; // tranforma o codigo da tecla no numero correspondente, reduzindo seu codigo ASCII em 48
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            system("cls");
            scanf("%d %d", &n, &m);
            matriz = alocarMatriz(n, m);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    scanf("%f", &matriz[i][j]);
                }
            }
            break;
        case 2:
            system("cls");
            matrizescalonada = alocarMatriz(n, m);
            copiarMatriz(matriz, matrizescalonada, n, m);
            escalonar(matrizescalonada, 0, 0, n, m, 0);
            system("pause");
            break;
        case 3:
            system("cls");
            if (n != m)
            {
                printf("Nao e uma matriz quadrada, logo nao se tem inversa\n");
                system("pause");
                break;
            }
            else
            {
                matrizescalonada = alocarMatriz(n, m);
                copiarMatriz(matriz, matrizescalonada, n, m);
                escalonar(matrizescalonada, 0, 0, n, m, 0);
                system("cls");
                for (int i = 0; i < m; i++)
                {
                    if (matrizescalonada[i][i] == 0)
                    {
                        printf("Determinante = 0, nao ha inversa\n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        if (i == m - 1)
                        {
                            inversa = gerarIdentidade(n, m);
                            matrizinvertivel = alocarMatriz(n, m);
                            copiarMatriz(matriz, matrizinvertivel, n, m);
                            calcularInversa(matrizinvertivel, inversa, 0, 0, n, m);
                            system("pause");
                            break;
                        }
                    }
                }
            }
        }

    } while (opcao != 0);
}

float **alocarMatriz(int n, int m)
{
    float **matriz;
    matriz = (float **)malloc(n * sizeof(float *)); // Aloca um endereço na memoria, sendo que este tera o n vezes o tamanho de um ponteiro float. Este sera um ponteiro que aponta para ponteiros
    if (matriz == NULL)
        return NULL;
    for (int i = 0; i < n; i++)
    {
        matriz[i] = (float *)malloc(m * sizeof(float)); // Aloca um endereço na memoria para cada indice i, sendo que ele retorna este endereço para onde o ponteiro de ponteiros estava apontando, ou seja, para o ponteiro i que estava apontando
        if (matriz[i] == NULL)
            return NULL;
    }
    return matriz; // Retorna uma matriz com n linhas e m colunas
}

float **escalonar(float **matriz, int i, int j, int n, int m, int posto)
{
    if (j == m)
    {
        printf("Posto: %d\n", posto);
        return matriz; // Condição de parada da recursividade, quando acabou o escalonamento
    }
    else
    {
        if (matriz[i][j] == 0)
        {
            for (int h = i + 1; h < n; h++)
            { // Inicia o processo de troca de linhas, quando o valor "pivo" esta nulo
                if (matriz[h][j] != 0)
                {
                    float aux;
                    for (int a = 0; a < m; a++)
                    {
                        aux = matriz[i][a];
                        matriz[i][a] = matriz[h][a];
                        matriz[h][a] = aux;
                    } // Troca de linhas

                    printf("Trocando L%d pela L%d:\n", i + 1, h + 1);

                    printfMatriz(matriz, n, m); // Printa matriz

                    printf("\n");

                    return escalonar(matriz, i, j, n, m, posto); // Manda o resultado novamente para o escalonamento
                }
            }
            return escalonar(matriz, i, j + 1, n, m, posto); // Caso ele chegue neste return significa que toda a coluna é nula, entao ele manda o resultado novamente pro escalonamento somando +1 na coluna que usara como "pivo"
        }
        else
        {
            float c = 0;

            for (int z = 1; z < n - i; z++)
            {

                if (matriz[i + z][j] != 0)
                {

                    c = -(matriz[i + z][j] / matriz[i][j]); // Calcula o valor que ira usar para anular um valor pro escalonamento

                    for (int y = 0; y < m; y++)
                    {
                        matriz[i + z][y] = c * matriz[i][y] + matriz[i + z][y]; // Zera um valor pro escalonamento, trocando a linha toda por este processo
                    }

                    printf("Trocando a L%d pela soma dela(multiplicada por %.2f) com a L%d:\n", i + z + 1, c, i + 1);

                    printfMatriz(matriz, n, m); // Printa matriz

                    printf("\n");
                }
            }
            posto++;
            return escalonar(matriz, i + 1, j + 1, n, m, posto); // Terminou um "pivo", entao envia o resultado pro escalonamento novamente usando o proximo "pivo" da diagonal seguinte
        }
    }
}

void printfMatriz(float **matriz, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    } // Printa a matriz
}

float **calcularInversa(float **matriz, float **inversa, int i, int j, int n, int m)
{
    if (j == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("Dividindo a L%d por %.2f:\n", i + 1, matriz[i][i]);
            manipularInversa(inversa, matriz[i][i], i, 99999, m);
            matriz[i][i] = 1;
            printfMatrizGJ(matriz, inversa, n, m); // Printa matriz
            printf("\n");
        }
        return matriz; // Condição de parada da recursividade, quando acabou o escalonamento
    }
    else
    {
        if (matriz[i][j] == 0)
        {
            for (int h = i + 1; h < n; h++)
            { // Inicia o processo de troca de linhas, quando o valor "pivo" esta nulo
                if (matriz[h][j] != 0)
                {
                    float aux;
                    for (int a = 0; a < m; a++)
                    {
                        aux = matriz[i][a];
                        matriz[i][a] = matriz[h][a];
                        matriz[h][a] = aux;
                        manipularInversa(inversa, 0, i, a, h);
                    } // Troca de linhas

                    printf("Trocando L%d pela L%d:\n", i + 1, h + 1);

                    printfMatrizGJ(matriz, inversa, n, m); // Printa matriz

                    printf("\n");

                    return calcularInversa(matriz, inversa, i, j, n, m); // Manda o resultado novamente para o escalonamento
                }
            }
            return calcularInversa(matriz, inversa, i, j + 1, n, m); // Caso ele chegue neste return significa que toda a coluna é nula, entao ele manda o resultado novamente pro escalonamento somando +1 na coluna que usara como "pivo"
        }
        else
        {
            float c = 0;

            for (int z = 0; z < n; z++)
            {
                if (z == i)
                    ;
                else
                {
                    if (matriz[z][j] != 0)
                    {

                        c = -(matriz[z][j] / matriz[i][j]); // Calcula o valor que ira usar para anular um valor pro escalonamento

                        for (int y = 0; y < m; y++)
                        {
                            matriz[z][y] = c * matriz[i][y] + matriz[z][y]; // Zera um valor pro escalonamento, trocando a linha toda por este processo
                            manipularInversa(inversa, c, i, z, y);
                        }

                        printf("Trocando a L%d pela soma dela(multiplicada por %.2f) com a L%d:\n", i + z + 1, c, i + 1);

                        printfMatrizGJ(matriz, inversa, n, m); // Printa matriz

                        printf("\n");
                    }
                }
            }

            return calcularInversa(matriz, inversa, i + 1, j + 1, n, m); // Terminou um "pivo", entao envia o resultado pro escalonamento novamente usando o proximo "pivo" da diagonal seguinte
        }
    }
}

void manipularInversa(float **inversa, float c, int a, int b, int d)
{
    if (c == 0)
    {
        float aux = inversa[a][b];
        inversa[a][b] = inversa[d][b];
        inversa[d][b] = aux;
    }
    else
    {
        if (b == 99999)
            for (int j = 0; j < d; j++)
                inversa[a][j] = inversa[a][j] / c;
        else
            inversa[b][d] = c * inversa[a][d] + inversa[b][d];
    }
}

float **gerarIdentidade(int n, int m){
    float **inversa = alocarMatriz(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
                inversa[i][j] = 1;
            else
                inversa[i][j] = 0;
        }
    }
    return inversa;
}

void printfMatrizGJ(float **matriz, float **inversa, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 2 * m; j++)
        {
            if (j == m)
                printf("   |   ");
            else
            {
                if (j > m)
                    printf("%.2f ", inversa[i][j - m - 1]);
                else
                    printf("%.2f ", matriz[i][j]);
            }
        }
        printf("\n");
    } // Printa a matriz
}

void copiarMatriz(float **origem, float **destino, int n, int m){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            destino[i][j] = origem[i][j];
}