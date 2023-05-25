#include <stdio.h>
#include <stdlib.h>
#include "player.c"
#include "board.c"

void startGame(char**,int);
void showFullBoard(char**, int);
void showDiscoveredBoard(char**, int, int*, int);
void showDiscoveringBoard(char**, int, int*, int, int, int);
int getCardBoardPosition(char*, int);
int addDiscoveredCard(int**, int, int);
int validatePositionCard(char*, int);
int runGame(Player, int, char**, int**, int);

void startGame(char **board, int difficult){
    int counter = 5;
    do
    {
        printf("Game starting in %d...\n", counter);
        showFullBoard(board, difficult);
        sleep(1);
        system("cls");
    } while (counter != 0);
}

void showFullBoard(char **board, int difficult){
    for (int i = 0; i < difficult; i++)
    {
        for (int j = 0; j < difficult; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void showDiscoveredBoard(char **board, int difficult, int *discoveredCards, int sizeofDiscoveredCards){
    for (int i = 0; i < difficult; i++)
    {
        for (int j = 0; j < difficult; j++)
        {
            int printed = 0;
            for (int k = 0; k < sizeofDiscoveredCards; k++){
                if (i * difficult + j == discoveredCards[k])
                {
                    printed = printf("%c ", board[i][j]);
                    break;
                }
            }
            if (printed==0)
                printf("0 ");
        }
        printf("\n");
    }
}

void showDiscoveringBoard(char **board, int difficult, int *discoveredCards, int sizeofDiscoveredCards, int firstCard, int secondCard){
    int *discoveredAndNewCards = (int *)malloc((sizeofDiscoveredCards + 2) * sizeof(int));
    for (int c = 0; c < sizeofDiscoveredCards; c++)
    {
        discoveredAndNewCards[c] = discoveredCards[c];
    }
    discoveredAndNewCards[sizeofDiscoveredCards] = firstCard;
    discoveredAndNewCards[sizeofDiscoveredCards+1] = secondCard;
    showDiscoveredBoard(board, difficult, discoveredAndNewCards, sizeofDiscoveredCards+2);
}

int getCardBoardPosition(char *rawPositionCard, int difficult){
    int cardPosition;
    for(int i=0; i<difficult;i++){
        if(rawPositionCard[0]==yPositions[i]){
            cardPosition=i*difficult;
            break;
        }
    }
    cardPosition=cardPosition+(rawPositionCard[1] - '0');
    return cardPosition;
}

int addDiscoveredCard(int **discoveredCards, int sizeofDiscoveredCards, int discoveredCard){
    int *newDiscoveredCards=(int*) malloc((sizeofDiscoveredCards+1)*sizeof(int));
    for(int c=0; c<sizeofDiscoveredCards; c++)
        newDiscoveredCards[c]=(*discoveredCards)[c];
    newDiscoveredCards[sizeofDiscoveredCards]=discoveredCard;
    *discoveredCards=newDiscoveredCards;
    return sizeofDiscoveredCards+1;
}

int validatePositionCard(char *rawPositionCard, int difficult){
    if(rawPositionCard[0]=='0'){
            return 1;
    }
    else{
        int c=0;
        for(int i=0; i<difficult; i++)
            if(rawPositionCard[0]!=yPositions[i])
                c++;
        if(c==difficult-1)
            return 0;
        c=0;
        for(int i=0; i<difficult; i++)
            if(rawPositionCard[1]!=xPositions[i])
                c++;
        if(c==difficult-1)
            return 0;
    }
    return 2;
}

int runGame(Player player, int difficult, char **board, int **discoveredCards, int sizeofDiscoveredCards){
    char *rawPositionCard = (char *)malloc(2 * sizeof(char));
    int firstCard, secondCard, situation;
    do
    {
        system("cls");
        printf("Game started...\n");
        printf("Difficult: %d\n", difficult);
        showDiscoveredBoard(board, difficult, *discoveredCards, sizeofDiscoveredCards);
        printf("First card: ");
        scanf("%s", rawPositionCard);
        situation=validatePositionCard(rawPositionCard, difficult);
        if(situation==0)
            continue;
        if(situation==1)
            return 1;
        firstCard = getCardBoardPosition(rawPositionCard, difficult);
        printf("Second card: ");
        scanf("%s", rawPositionCard);
        situation=validatePositionCard(rawPositionCard, difficult);
        if(situation==0)
            continue;
        if(situation==1)
            return 1;//salvar
        secondCard = getCardBoardPosition(rawPositionCard, difficult);
        system("cls");
        printf("Result: \n");
        showDiscoveringBoard(board, difficult, *discoveredCards, sizeofDiscoveredCards, firstCard, secondCard);
        for(int i=0; i<sizeofDiscoveredCards; i++)
            if(firstCard==discoveredCards[i] || secondCard==discoveredCards[i])
                printf("Bro, you putted a duplicate here!");
        else{
            if(board[firstCard/difficult][firstCard%difficult]==board[secondCard/difficult][secondCard%difficult]){
                printf("Nice! You got it!!");
                sizeofDiscoveredCards=addDiscoveredCard(discoveredCards, sizeofDiscoveredCards, firstCard);
                sizeofDiscoveredCards=addDiscoveredCard(discoveredCards, sizeofDiscoveredCards, secondCard);
            }
            else{
                printf("Brooo, you failed ;-;");
            }
        }
        sleep(3);
    } while (sizeofDiscoveredCards != difficult * difficult);
    printf("Finished!");
    return 2;//jogo completo
}

int main(){
    Player player;
    player.name="Subaru Natsuki";
    player.password="EAD";
    player.score=20;

    int difficult=4;

    char **board = (char**) malloc(4*sizeof(char*));
    for(int c=0; c<4; c++)
        board[c]= (char*) malloc(4*sizeof(char));
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            board[i][j]='A';
        }
    }

    int *discoveredCards;

    int sizeofDiscoveredCards=0;
    
    runGame(player, difficult, board, &discoveredCards, sizeofDiscoveredCards);
}