#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    // N = ~
    // V = v
    // Y = ^
    // C = ->
    // G = <->

    int n = 0, tamequacao = 0, onde = 0, graudeimport[1000][2], conectivomaisimportante = 0;
    // graudeimport = matriz 1000x2 que guarda posição de um conectivo e seu grau de importancia. Nota: Ela esta contida no if dentro dos pareteses
    // conectivomaisimportante = posição do conectivo mais importante no pareteses. Nota: Ela esta contida no if dentro dos pareteses
    printf("Bem vindo ao revolucionario mais novo software da lab!\n Digite o numero de icognitas da sentenca: ");
    scanf("%d", &n);
    int numerodelinhas = pow(2, n);
    char equacao[1000], valor[1000][numerodelinhas + 1][0];
    // valor = nada mais é do que a matriz tridemensional que ira guardar em x os valores verdades da respectiva preposicao y, z guarda a posicao da preposicao y no array. Sendo o
    // y o A composto que sera feito durante o programa, ou apenas uma preposição simples
    printf("Digite agora a equacao em si: ");
    scanf("%s", equacao);

    for (int y = 0; y < n; y++)
    { // For que vai vendo o numero, compara com impar e completa V ou F, la por pow(2, n);
        for (int r = 1; r <= numerodelinhas + 1; r++)
        {
            if ((int)(r / (pow(2, (n-y))/2)) % 2 == 0)
            {   
                valor[y][r][]
            }
            else{

            }

        }
    }

    for (int z = 0; z < 1000; z++)
    { // Calcula o tamanho da equacao em quesito de string
        if (equacao[z] == '\0')
        {
            tamequacao == z;
            z = 999;
        }
    }

    for (int c = 0; c < tamequacao; c++) // Aqui comeca um contador, que vai passando de char a char da equacao. Seu papel, inicialmente, e encontrar '(', e então guardar sua posição
    // dentro deste for a outro if que vai guardar a posição de um ')', e quando encontrar um deste ele vai entrar em outro for
    {
        if (equacao[c] == '(')
        {
            onde = c;
        }
        if (equacao[c] == ')')
        {
            // ate=c;
            for (int h = onde; h < c; h++) // Este for vai simplesmente, dentro dos parenteses '(' e ')' encontrados, achar todos os conectivos, identificar suas posições no array
            // da equação e tambem seus respectivos graus de importancia, e colocara tudo isto na matriz graudeimport 1000x2
            {
                if (equacao[h] != 'N' && equacao[h] != 'V' && equacao[h] != 'Y' && equacao[h] != 'C' && equacao[h] != 'G')
                {
                }
                else
                {
                    if (equacao[h] == 'N')
                    {
                        graudeimport[h][0] = h;
                        graudeimport[h][1] = 1;
                    }
                    if (equacao[h] == 'Y')
                    {
                        graudeimport[h][0] = h;
                        graudeimport[h][1] = 2;
                    }
                    if (equacao[h] == 'V')
                    {
                        graudeimport[h][0] = h;
                        graudeimport[h][1] = 3;
                    }
                    if (equacao[h] == 'C')
                    {
                        graudeimport[h][0] = h;
                        graudeimport[h][1] = 4;
                    }
                    else
                    { // G
                        graudeimport[h][0] = h;
                        graudeimport[h][1] = 5;
                    }
                }
                if (h == c - 1) // So pra identificar onde acaba a matriz lista de importancia
                {
                    graudeimport[h][0] = 999;
                    graudeimport[h][1] = 999;
                }
            }

            for (int g = 0; graudeimport[g][0] != 999; g++)
            { // Aqui vamos usar a matriz graudeimport. Este for vai simplesmente achar a posição do conectivo mais importante da matriz
                // graudeimport pelo seu grau de importancia e colocara no final a posição do mais importante em uma variavel conectivomaisimportante. Nota: Este sera o conectivo mais
                // important do PARENTESES, lembre-se que ainda estamos no if dentro do pareteses. O que sera feito depois:
                // Agora sabendo onde ta o mais importanta a ideia é efetuar o conectivo entre os dois, e então substituir os 3, preposição + conectivo + preposição por uma so preposição,
                // que ja tem calculado seus valores e esta la no array tridimensional. Ai repetimos o processo, achamos o novo mais importante e usamos o conectivo nele, substituimos por
                // uma so preposição ate que no fim, no final do parenteses, so reste uma preposição feita A
                if (g == 0)
                {
                    conectivomaisimportante = graudeimport[g][0];
                }
                else
                {
                    if (graudeimport[g][1] > graudeimport[conectivomaisimportante][1])
                    {
                        conectivomaisimportante = graudeimport[g][0];
                    }
                }
            }
        }
    }
}