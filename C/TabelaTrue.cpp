#include <stdio.h>
#include <math.h>
//->  = c
//<-> = b

int main()
{
    int p = 1;
    printf("Ola, seja bem vindo ao programa de numero 15!\n");
    char pc[100]; // preposicaocomposta
    printf("Atencao, so e permitido haver negacao em preposicoes, nada de negacoes duplas e negacoes em todo um parenteses. Ou seja, isto ~(AvB) nao e permitido\n");
    printf("Siglas: \n Bicondicional = b\n Condicional = c\n Disjuncao = v\n Conjuncao = ^\n Negacao = ~\n");
    while (p == 1)
    {
        printf("\nDigite a preposicao que voce quer verificar a coluna resultado. Escreva desta forma(PvQ^E...): ");
        scanf("%s", &pc);
        int tampc = 0;
        while (pc[tampc] != '\0')
        { // Quantas linhas tem a preposição composta
            tampc++;
        }
        // Preposicao composta e seu tamanho

        int n = 0;
        char ps[20];
        printf("Digite quais sao as preposicoes simples desta composta, desta forma (PQR...): ");
        scanf("%s", &ps);
        while (ps[n] != '\0')
        {
            n++;
        }

        int n2 = pow(2, n);

        // Numero de preposições simples e seus "nomes"

        char tabelainicial[n2 + 1][n];
        int a = 1;
        int m = n2;
        for (int h = 0; h < n; h++)
        {
            tabelainicial[0][h] = ps[h];
            for (int c = 1; c < n2 + 1; c++)
            {
                if (a <= m / 2)
                {
                    tabelainicial[c][h] = 'V';
                    a++;
                }
                else
                {
                    tabelainicial[c][h] = 'F';
                    if (a == m)
                        a = 1;
                    else
                        a++;
                }
            }
            a = 1;
            m = m / 2;
        } // Inicializar e preencher a tabela inicial

        char tabela[n2][tampc];
        for (int h = 0; h < tampc; h++)
        {
            if (pc[h] != '(' && pc[h] != ')' && pc[h] != '~' && pc[h] != '^' && pc[h] != 'v' && pc[h] != 'c' && pc[h] != 'b')
            {
                int l = -1;
                for (int u = 0; u < n; u++)
                {
                    if (pc[h] == tabelainicial[0][u])
                    {
                        l = u;
                        u = n;
                    }
                }
                for (int c = 0; c < n2; c++)
                {
                    tabela[c][h] = tabelainicial[c + 1][l];
                }
            }
            else
            {
                for (int c = 0; c < n2; c++)
                {
                    tabela[c][h] = pc[h];
                }
            }
        } // Inicializa e declara a tabela
        printf("\n");
        for (int z = 0; z < n2; z++)
        {
            for (int w = 0; w < tampc; w++)
                printf("%c ", tabela[z][w]);
            printf("\n");
        } // Mostra a tabela
        printf("Esta e a tabela verdade informatizada inicial, observe as proximas que se referem a todos os processos que o algoritmo faz ate chegar na coluna final\n");

        while (tabela[0][1] != ' ')
        {
            int prio = 0, priopos = -1, parentesesinicial = -1, parentesesfinal = -1;
            for (int i = 0; i < tampc; i++)
            {
                if (tabela[0][i] == '~' && prio < 5)
                {
                    priopos = i;
                    prio = 5;
                }
                if (tabela[0][i] == '^' && prio < 4)
                {
                    priopos = i;
                    prio = 4;
                }
                if (tabela[0][i] == 'v' && prio < 3)
                {
                    priopos = i;
                    prio = 3;
                }
                if (tabela[0][i] == 'c' && prio < 2)
                {
                    priopos = i;
                    prio = 2;
                }
                if (tabela[0][i] == 'b' && prio < 1)
                {
                    priopos = i;
                    prio = 1;
                }
                if (tabela[0][i] == '(')
                {
                    parentesesinicial = i;
                    priopos = -1;
                    prio = 0;
                }
                if (tabela[0][i] == ')')
                {
                    parentesesfinal = i;
                    i = tampc;
                }
            } // Saimos daqui com a posicao de prioridade

            if (priopos == -1)
            {
                for (int q = 0; q < n2; q++)
                {
                    tabela[q][parentesesinicial] = tabela[q][parentesesinicial + 1];
                    tabela[q][parentesesinicial + 1] = ' ';
                    tabela[q][parentesesfinal] = ' ';
                    for (int y = parentesesfinal - 1; y < tampc; y++)
                    {
                        if (y == tampc - 2 || y == tampc - 1)
                            tabela[q][y] = ' ';
                        else
                            tabela[q][y] = tabela[q][y + 2];
                    }
                }
            }
            else
            {
                switch (prio)
                {
                case 5:
                    for (int q = 0; q < n2; q++)
                    {
                        if (tabela[q][priopos + 1] == 'V')
                        {
                            tabela[q][priopos] = 'F';
                            for (int y = priopos + 1; y < tampc; y++)
                            {
                                if (y == tampc - 1)
                                    tabela[q][y] = ' ';
                                else
                                    tabela[q][y] = tabela[q][y + 1];
                            }
                        }
                        else
                        {
                            tabela[q][priopos] = 'V';
                            for (int y = priopos + 1; y < tampc; y++)
                            {
                                if (y == tampc - 1)
                                    tabela[q][y] = ' ';
                                else
                                    tabela[q][y] = tabela[q][y + 1];
                            }
                        }
                    }
                    break;
                case 4:
                    for (int q = 0; q < n2; q++)
                    {
                        if (tabela[q][priopos - 1] == 'V' && tabela[q][priopos + 1] == 'V')
                        {
                            tabela[q][priopos - 1] = 'V';
                            for (int y = priopos; y < tampc; y++)
                            {
                                if (y == tampc - 2 || y == tampc - 1)
                                    tabela[q][y] = ' ';
                                else
                                    tabela[q][y] = tabela[q][y + 2];
                            }
                        }
                        else
                        {
                            tabela[q][priopos - 1] = 'F';
                            for (int y = priopos; y < tampc; y++)
                            {
                                if (y == tampc - 2 || y == tampc - 1)
                                    tabela[q][y] = ' ';
                                else
                                    tabela[q][y] = tabela[q][y + 2];
                            }
                        }
                    }
                    break;
                case 3:
                    for (int q = 0; q < n2; q++)
                    {
                        if (tabela[q][priopos - 1] == 'V' || tabela[q][priopos + 1] == 'V')
                        {
                            tabela[q][priopos - 1] = 'V';
                            for (int y = priopos; y < tampc; y++)
                            {
                                if (y == tampc - 2 || y == tampc - 1)
                                    tabela[q][y] = ' ';
                                else
                                    tabela[q][y] = tabela[q][y + 2];
                            }
                        }
                        else
                        {
                            tabela[q][priopos - 1] = 'F';
                            for (int y = priopos; y < tampc; y++)
                            {
                                if (y == tampc - 2 || y == tampc - 1)
                                    tabela[q][y] = ' ';
                                else
                                    tabela[q][y] = tabela[q][y + 2];
                            }
                        }
                    }
                    break;
                case 2:
                    for (int q = 0; q < n2; q++)
                    {
                        if (tabela[q][priopos - 1] == 'V' && tabela[q][priopos + 1] == 'F')
                        {
                            tabela[q][priopos - 1] = 'F';
                            for (int y = priopos; y < tampc; y++)
                            {
                                if (y == tampc - 2 || y == tampc - 1)
                                    tabela[q][y] = ' ';
                                else
                                    tabela[q][y] = tabela[q][y + 2];
                            }
                        }
                        else
                        {
                            tabela[q][priopos - 1] = 'V';
                            for (int y = priopos; y < tampc; y++)
                            {
                                if (y == tampc - 2 || y == tampc - 1)
                                    tabela[q][y] = ' ';
                                else
                                    tabela[q][y] = tabela[q][y + 2];
                            }
                        }
                    }
                    break;
                case 1:
                    for (int q = 0; q < n2; q++)
                    {
                        if ((tabela[q][priopos - 1] == 'V' && tabela[q][priopos + 1] == 'V') || (tabela[q][priopos - 1] == 'F' && tabela[q][priopos + 1] == 'F'))
                        {
                            tabela[q][priopos - 1] = 'V';
                            for (int y = priopos; y < tampc; y++)
                            {
                                if (y == tampc - 2 || y == tampc - 1)
                                    tabela[q][y] = ' ';
                                else
                                    tabela[q][y] = tabela[q][y + 2];
                            }
                        }
                        else
                        {
                            tabela[q][priopos - 1] = 'F';
                            for (int y = priopos; y < tampc; y++)
                            {
                                if (y == tampc - 2 || y == tampc - 1)
                                    tabela[q][y] = ' ';
                                else
                                    tabela[q][y] = tabela[q][y + 2];
                            }
                        }
                    }
                    break;
                }
            }
            printf("\n");
            for (int z = 0; z < n2; z++)
            {
                for (int w = 0; w < tampc; w++)
                    printf("%c ", tabela[z][w]);
                printf("\n");
            } // Mostra a tabela
        }
        printf("\nE esta e a coluna final\n\n");

        printf("Deseja fazer mais uma? Se sim digite 1, se nao digite 0\n");
        scanf("%d", &p);
        printf("======================================================================================================================================\n\n");
    }
    return 0;
}