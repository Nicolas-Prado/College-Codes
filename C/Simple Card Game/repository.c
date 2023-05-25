#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char cards[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '-'};

char **getNewBoard(int, int **, int *);
int existSavedBoard();
char **getSavedBoard(int *, int **, int *, int *);
void saveBoard(char **, int, int *, int, int);
void deleteSavedBoard();
void saveScore(int);
int getScore();
void setFilename(char *);
void setBoardName(char *);
void saveInIndex(char *);
void getOrdenedRating(int *, char[100][100]);
void orderPlayer(char *, int *, char[][100], int);
void increaseSpace(int *, int , int );
void increaseSpaceStrings(char[][100], int, int);

char filename[100] = "scores/";
char boardname[100];

char **getNewBoard(int difficult, int **discoveredCards, int *sizeofDiscoveredCards)
{
    srand(time(NULL));
    char **board = (char **)malloc(difficult * sizeof(char *));
    for (int c = 0; c < difficult; c++)
        board[c] = (char *)malloc(difficult * sizeof(char));

    int i=0, j=0;
    if (difficult % 2 != 0)
    {
        i = (rand() % (difficult - 1 - 0 + 1)) + 0;
        j = (rand() % (difficult - 1 - 0 + 1)) + 0;
        board[i][j] = '-';
        *discoveredCards = (int *)malloc(sizeof(int));
        **discoveredCards = i * difficult + j;
        *sizeofDiscoveredCards = 1;
    }
    int skip=0;
    for (int indexLetter = 0; indexLetter < (difficult * difficult) / 2; indexLetter++)
    {
        for (int whichCard = 0; whichCard < 2; whichCard++)
        {
            i = (rand() % (difficult - 1 - 0 + 1)) + 0;
            j = (rand() % (difficult - 1 - 0 + 1)) + 0;
            for (int c = 0; c < 27; c++)
            {
                if (board[i][j] == cards[c])
                {
                    skip = 1;
                    //printf("%c", board[i][j]);
                    break;
                }
                else
                    skip = 0;
            }
            if (skip == 1){
                whichCard--;
            }
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

void saveScore(int score)
{
    FILE *fp;
    int oldScore;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        saveInIndex(filename);
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
    fclose(fp);
}

int getScore()
{
    FILE *fp;
    int totalScore = 0;
    fp = fopen(filename, "r");
    if (fp == NULL){
        saveScore(totalScore);
        return totalScore;
    }
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

void saveInIndex(char *filename){
    FILE *fp;
    fp=fopen("index.txt", "a");
    fprintf(fp, "%s\n", filename);
    fclose(fp);
}

void getOrdenedRating(int *nrPlayers, char rating[100][100]){
    FILE *fp;
    fp=fopen("index.txt", "r");
   
    *nrPlayers=0;
    char finded;
    while(!feof(fp)){
        finded=getc(fp);
        if(finded=='\n')
            *nrPlayers=*nrPlayers+1;
    }
   
    /*fclose(fp);
    fp=fopen("index.txt", "r");*/
    rewind(fp);
    int *scores = (int*) malloc((*nrPlayers)*sizeof(int));
    //char **players=(char**) malloc((*nrPlayers)*sizeof(char));
    //for(int c=0; c<*nrPlayers; c++)
    //    players[c]=(char*) malloc(100*sizeof(char));
    char players[100][100];
    //players = (char**) malloc(nrPlayers*sizeof(char*));
   
    char filename[100];
    for(int c=0; c<*nrPlayers; c++){
        fscanf(fp, "%s\n", filename);
        orderPlayer(filename, scores, players, c);
    }

    /*for(int c=0; c<*nrPlayers; c++){
        printf("%d - ", scores[c]);
        printf("%s\n", players[c]);
    }*/
   
    char intString[100];
    for(int i=0; i<*nrPlayers; i++){
        sprintf(intString, "%d", scores[i]);
        strcpy(rating[i], intString);
        strcat(rating[i], " - ");
        strcat(rating[i], players[i]);
    }
    return rating;
}

void orderPlayer(char *filename, int *scores, char players[][100], int nrPlayer){
    FILE *fp;
    fp=fopen(filename, "r");
   
    char playerName[100];
    int c;
    for(c=7; filename[c]!='.'; c++){
        playerName[c-7]=filename[c];
    }
    playerName[c-7]='\0';

    int score;
    fscanf(fp,  "%d", &score);
   
    if(nrPlayer==0){
        strcpy(players[0],playerName);
        scores[0]=score;
        return 0;
    }
   
    int i=0;
    do{
        if(score>scores[i]){
            increaseSpace(scores, i, nrPlayer);
            scores[i]=score;
            increaseSpaceStrings(players, i, nrPlayer);
            strcpy(players[i],playerName);
            return 0;
        }
    i++;
    }while(i<nrPlayer);
    scores[i]=score;
    strcpy(players[i],playerName);
    return 0;
}

void increaseSpace(int *scores, int i, int qtPlayers){
    int intUtil1, intUtil2;
    intUtil1 = scores[i];
    for(int c=i+1; c<qtPlayers+1; c++){
        if(c<qtPlayers)
            intUtil2 = scores[c];
        scores[c]=intUtil1;
        intUtil1=intUtil2;
    }
}

void increaseSpaceStrings(char players[][100], int i, int qtPlayers){
    char strUtil1[100], strUtil2[100];
    strcpy(strUtil1, players[i]);
    for(int c=i+1; c<qtPlayers+1; c++){
        if(c<qtPlayers)
            strcpy(strUtil2, players[c]);
        strcpy(players[c], strUtil1);
        strcpy(strUtil1, strUtil2);
    }
}
