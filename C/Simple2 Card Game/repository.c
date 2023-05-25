#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

char cards[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '-'};

char **getNewBoard(int, int **, int *);
int existSavedBoard();
char **getSavedBoard(int *, int **, int *, int *);
void saveBoard(char **, int, int *, int, int);
void deleteSavedBoard();
void saveScore(char *, int);
int getScore();
void setFilename(char *);
void setBoardName(char *);
void saveInRating(char *, int);
char **getScores(long int, int);

char filename[100] = "scores/";
char boardname[100];

char **getNewBoard(int difficult, int **discoveredCards, int *sizeofDiscoveredCards)
{
    srand(time(NULL));
    char **board = (char **)malloc(difficult * sizeof(char *));
    for (int c = 0; c < difficult; c++)
        board[c] = (char *)malloc(difficult * sizeof(char));

    int i, j;
    if (difficult % 2 != 0)
    {
        i = (rand() % (difficult - 1 - 0 + 1)) + 0;
        j = (rand() % (difficult - 1 - 0 + 1)) + 0;
        board[i][j] = '-';
        *discoveredCards = (int *)malloc(sizeof(int));
        **discoveredCards = i * difficult + j;
        *sizeofDiscoveredCards = 1;
    }
    int skip;
    for (int indexLetter = 0; indexLetter < (difficult * difficult) / 2; indexLetter++)
    {
        for (int whichCard = 0; whichCard < 2; whichCard++)
        {
            i = (rand() % (difficult - 1 - 0 + 1)) + 0;
            j = (rand() % (difficult - 1 - 0 + 1)) + 0;
            skip = 0;
            for (int c = 0; c < 27; c++)
            {
                if (board[i][j] == cards[c])
                {
                    skip = 1;
                    printf("sus");
                    break;
                }
            }
            if (skip == 1)
                whichCard--;
            else
                board[i][j] = cards[indexLetter];
        }
    }
    return board;
}

int existSavedBoard()
{
    FILE *fp = fopen(boardname, "r");
    if (fp == NULL)
        return -1;
    int verify;
    return fscanf(fp, "%d", &verify);
}

char **getSavedBoard(int *difficult, int **discoveredCards, int *sizeofDiscoveredCards, int *life)
{
    *difficult = 0;
    FILE *fp;
    fp = fopen(boardname, "r");

    char finded;
    while (finded != '\n')
    {
        finded = getc(fp);
        *difficult = *difficult + 1;
    }
    *difficult = (*difficult) / 2;
    fseek(fp, 0, SEEK_SET);

    char **board = (char **)malloc((*difficult) * sizeof(char *));
    for (int c = 0; c < *difficult; c++)
        board[c] = (char *)malloc((*difficult) * sizeof(char));

    for (int i = 0; i < *difficult; i++)
    {
        for (int j = 0; j < *difficult - 1; j++)
        {
            fscanf(fp, "%c ", &board[i][j]);
        }
        fscanf(fp, "%c\n", &board[i][(*difficult) - 1]);
    }

    long int position = ftell(fp);
    finded = ' ';
    while (finded != '\n')
    {
        finded = getc(fp);
        *sizeofDiscoveredCards = *sizeofDiscoveredCards + 1;
    }
    *sizeofDiscoveredCards = (*sizeofDiscoveredCards) / 2;
    fseek(fp, position, SEEK_SET);

    *discoveredCards = (int)malloc((*sizeofDiscoveredCards) * sizeof(int));

    for (int i = 0; i < (*sizeofDiscoveredCards) - 1; i++)
    {
        fscanf(fp, "%d ", &(*discoveredCards)[i]);
    }
    fscanf(fp, "%d\n", &(*discoveredCards)[(*sizeofDiscoveredCards) - 1]);

    fscanf(fp, "%d\n", life);

    fclose(fp);
    return board;
}

void saveBoard(char **board, int difficult, int *discoveredCards, int sizeofDiscoveredCards, int life)
{
    FILE *fp;
    fp = fopen(boardname, "w");
    for (int i = 0; i < difficult; i++)
    {
        for (int j = 0; j < difficult - 1; j++)
            fprintf(fp, "%c ", board[i][j]);
        fprintf(fp, "%c\n", board[i][difficult - 1]);
    }
    for (int i = 0; i < sizeofDiscoveredCards - 1; i++)
    {
        fprintf(fp, "%d ", discoveredCards[i]);
    }
    if (sizeofDiscoveredCards > 0)
        fprintf(fp, "%d\n", discoveredCards[sizeofDiscoveredCards - 1]);

    fprintf(fp, "%d\n", life);

    fclose(fp);
}

void deleteSavedBoard()
{
    fclose(fopen(boardname, "w"));
}

void saveScore(char *user, int score)
{
    FILE *fp;
    int oldScore;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fclose(fp);
        fp = fopen(filename, "w");
        fprintf(fp, "%d", 0);
        fclose(fp);
        fp = fopen(filename, "r");
    }
    fscanf(fp, "%d", &oldScore);
    fclose(fp);
    fp = fopen(filename, "w");
    fprintf(fp, "%d", score + oldScore);

    saveInRating(user, score);

    fclose(fp);
}

int getScore()
{
    FILE *fp;
    int totalScore = 0;
    fp = fopen(filename, "r");
    if (fp == NULL)
        return totalScore;
    else
        fscanf(fp, "%d", &totalScore);
    fclose(fp);
    return totalScore;
}

void setFilename(char *user)
{
    strcat(filename, user);
    strcat(filename, ".txt");
}

void setBoardName(char *user)
{
    strcpy(boardname, user);
    strcat(boardname, "Board");
    strcat(boardname, ".txt");
}

void saveInRating(char *user, int score)
{
    FILE *fp;
    fp = fopen("rating.txt", "r+");

    getc(fp);
    if (feof(fp))
    {
        fprintf(fp, "%d - %s\n", score, user);
        return 0;
    }
    fclose(fp);

    fp = fopen("rating.txt", "r+");

    int nmPlayers = 0;
    while (!feof(fp))
    {
        if (getc(fp) == '\n')
            nmPlayers++;
    }

    rewind(fp);

    int findedScore;
    char *findedPlayer;
    long int position;
    char **scores;
    int error = -10;
    for (int i = 0; i < nmPlayers; i++)
    {
        position = ftell(fp);
        fscanf(fp, "%d - %s\n", &findedScore, findedPlayer);
        if (score > findedScore)
        {
            fclose(fp);
            scores = getScores(position, nmPlayers - i);
            fp = fopen("rating.txt", "r+");
            fseek(fp, position, SEEK_SET);
            error = fprintf(fp, "%d - %s\n", score, user);
            // printf("%s e %d e %d", user, score, error);
            for (int j = 0; j < nmPlayers - i; j++)
            {
                fprintf(fp, "%s\n", scores[j]);
            }
            return 0;
        }
    }
    fprintf(fp, "%d - %s\n", score, user);
}

char **getScores(long int position, int nmPlayers)
{
    FILE *fp = fopen("rating.txt", "r");
    fseek(fp, position, SEEK_SET);
    char **scores = (char **)malloc(nmPlayers * sizeof(char *));
    int firstPartInt;
    char *firstPart, *secondPart, secondPartString[1000];
    for (int i = 0; i < nmPlayers; i++)
    {
        fscanf(fp, "%d - %s\n", &firstPartInt, secondPart);
        firstPart = (char *)malloc((floor(log10(abs(firstPartInt))) + 1) * sizeof(char));
        strcpy(scores[i], firstPart);
        strcat(scores[i], " - ");
        strcat(scores[i], secondPart); // nao ta funcionando pois o maldito ai nao tem \0 ou algo assim, essa parada so aceita string
        printf("%s", secondPart);
    }
    fclose(fp);
    return scores;
}

int main()
{
    saveInRating("prado", 126);
}