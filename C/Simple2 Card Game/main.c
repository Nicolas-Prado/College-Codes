// Jogo de cartas...
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "repository.c"
#include "game.c"

char **gameConfigScreen(int *, int *, int **, int *, int *);
int gameScreen(int, char **, int *, int, int, int *);
int totalScore;
char userName[100];

int main()
{
    char **board;
    int repeat;
    int isSavedBoard;
    int difficult, life;
    int *discoveredCards, sizeofDiscoveredCards = 0;
    int seeScore;
    printf("Welcome to the game!\n");
    printf("User: ");
    gets(userName);
    setFilename(userName);
    setBoardName(userName);
    do
    {
        printf("Wanna see the ranking?(1 to yes and 0 to no)\n");
        scanf("%d", &seeScore);
        if(seeScore==1)
            scoreScreen();
        totalScore=getScore();
        sizeofDiscoveredCards = 0;
        printf("Accumulated score: %d\n", totalScore);
        board = gameConfigScreen(&isSavedBoard, &difficult, &discoveredCards, &sizeofDiscoveredCards, &life);
        system("cls");
        repeat = gameScreen(difficult, board, discoveredCards, sizeofDiscoveredCards, isSavedBoard, &life);
        system("cls");
    } while (repeat);
    exit(0);
}

char **gameConfigScreen(int *isSavedBoard, int *difficult, int **discoveredCards, int *sizeofDiscoveredCards, int *life)
{
    int opt;
    printf("Do you want play the last saved game or a new game?\n");
    printf("OBS: 1 for NEW GAME or 2 for SAVED GAME\n");
    scanf("%d", &opt);
    if (opt != 1 && opt != 2)
        exit(0);
    if (opt == 1)
    {
        printf("Choice the difficult. Choices: 3 = 3x3, 4 = 4x4, 5 = 5x5, 6 = 6x6 or 7 = 7x7\n");
        printf("What the difficult desire: ");
        scanf("%d", difficult);
        if (*difficult != 3 && *difficult != 4 && *difficult != 5 && *difficult != 6 && *difficult != 7)
            exit(0);
        *life=*difficult;
        return getNewBoard(*difficult, discoveredCards, sizeofDiscoveredCards);
    }
    else
    {
        *isSavedBoard = 1;
        if (existSavedBoard() == -1)
        {
            printf("Doesnt exist an board saved.");
            sleep(2);
            system("cls");
            return gameConfigScreen(isSavedBoard, difficult, discoveredCards, sizeofDiscoveredCards, life);
        }
        return getSavedBoard(difficult, discoveredCards, sizeofDiscoveredCards, life); // Caso tenha um oco tem que adicionar nas discoveredCards!
    }
}

int gameScreen(int difficult, char **board, int *discoveredCards, int sizeofDiscoveredCards, int isSavedBoard, int *life)
{
    int score = 0;
    startGame(board, difficult);
    int situation = runGame(difficult, board, &discoveredCards, &sizeofDiscoveredCards, life); // score=situation?
    if (situation == 1)
    {
        saveBoard(board, difficult, discoveredCards, sizeofDiscoveredCards, *life);
        printf("Game saved!\n");
    }
    else
    {
        if(situation==3){
            printf("You failed...\n");
            printf("Past total score: %d\n", totalScore);
            return overGame(difficult, score);
        }
        if (isSavedBoard == 1){
            deleteSavedBoard();
        }
        score = pow(2, difficult);
        saveScore(userName, score);
    }
    printf("Past total score: %d\n", totalScore);
    return overGame(difficult, score);
}

void scoreScreen(){
    system("cls");
    int qtScores;
    char **scores=getScores(&qtScores);
    for(int i=0; i<qtScores; i++)
        printf("%s", scores[i]);
    printf("Entre qualquer dado para continuar: ");
    scanf("%d", &qtScores);
    system("cls");
    //no save salvar um arquivo com os rating
}