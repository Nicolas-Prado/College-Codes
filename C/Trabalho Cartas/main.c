//Jogo de cartas...
#include <stdio.h>
#include "player.c"//Define typedef player and login/newAccount functions
#include "board.c"

Player loginScreen();
char **gameConfigScreen(Player, int*);

int main(){
    Player player;
    char **board;
    /*
    //Login ou Cadastro. Se for login perguntar login e senha. Se for cadastro o mesmo e cria outro registro... Tera o ranking junto
    //Cada usuario tera um arquivo referente ao seus tabuleiro salvo
    //Novo jogo ou jogo salvo
    //Gerar tabuleiro pelo nivel de dificuldade... 1 = 3x3, 2 = 4x4, 3 = 5x5, 4 = 6x6 ou 5 = 7x7 (2 cartas iguais)
    //Entrar no loop do jogo
    //Contabilizar resultado e, se necessario, substituir no maior score do usuario
    */
    printf("Welcome to the game!\n");
    player = loginScreen();
    system("cls");
    int isSavedBoard;//se for saved vai ter que deletar o arquivo ao terminar o jogo salvo dele
    int difficult;
    int *discoveredCards, sizeofDiscoveredCards=0;
    board = gameConfigScreen(player, &isSavedBoard, &difficult, discoveredCards, sizeofDiscoveredCards);
    system("cls");
    gameScreen(player, difficult, board, discoveredCards, sizeofDiscoveredCards, isSavedBoard);
}

Player loginScreen(){
    int opt;
    printf("New account or login?\n");
    printf("OBS: 1 for NEW ACCOUNT or 2 for LOGIN\n");
    scanf("%d", &opt);
    if(opt==1)
        return newAccount();
    else
        return login();
}

char **gameConfigScreen(Player player, int* isSavedBoard, int* difficult, int* discoveredCards, int* sizeofDiscoveredCards){
    int opt;
    printf("Hello player: %s\n", player.name);
    printf("Do you want play the last saved game or a new game?\n");
    printf("OBS: 1 for NEW GAME or 2 for SAVED GAME\n");
    scanf("%d", &opt);
    if(opt==1){
        printf("Choice the difficult. Choices: 3 = 3x3, 4 = 4x4, 5 = 5x5, 6 = 6x6 or 7 = 7x7\n");
        printf("What the difficult desire: ");
        scanf("%d", difficult);
        return newBoard(*difficult, discoveredCards, *sizeofDiscoveredCards);
    }
    else{
        *isSavedBoard=1;
        return savedBoard(player.name, difficult, discoveredCards, *sizeofDiscoveredCards);//Caso tenha um oco tem que adicionar nas discoveredCards!
    }
}

void gameScreen(Player player, int difficult, int **board, int *discoveredCards, int sizeofDiscoveredCards, int isSavedBoard){
    int isOver=-1;
    startGame(board, difficult);
    do{
        isOver=runGame(player, difficult, board, &discoveredCards, sizeofDiscoveredCards, isSavedBoard); //score=situation?
    }while (isOver==-1);
    if(isSavedBoard==1){
        deleteSave(player.name);
    }
}