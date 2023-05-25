#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct {
   char **players;
   int *pontuacao;        
} esquema;

char **criarTabuleiro(int, int);
char **criaAcertos(int, int);
int jogo(char**, char**, char***, int*, int);
esquema retornaEsquemaAtual(char**, int);
int* verificaIgualdadeEntreEsquemas(char**, char**, int*);
void salvaEsquema(esquema, int);
void colocaEsquema(esquema*, esquema, int, int);

int main(int argc, char *argv[])
{
    srand(time(NULL));  // Faz parte da função rand
    char ***tabuleiros = (char***) malloc(2*sizeof(char**)); // Declara os tabuleiros como uma matriz de 3 dimensões(sistematicamente um ponteiro de ponteiros de ponteiros de chars). x=0 significa o tabuleiro real enquanto x=1 significa o tabuleiro que fica na frente, o visual
    char **acertos = criaAcertos(argc-2, (int)((atoi(argv[argc-1]) * atoi(argv[argc-1])) / 2));
    int *pontuacao,vez;
    esquema esquemaAtual;

    for (int i = 0; i < 2; i++) // Inicializa os tabuleiros x=0 e x=1
        tabuleiros[i] = criarTabuleiro(atoi(argv[argc-1]), i);
    

    esquemaAtual.players = (char**) malloc((argc-2)*sizeof(char*));
    for(int i=0; i<argc-2; i++){
        esquemaAtual.players[i] = (char*) malloc(100*sizeof(char));
    }
    esquemaAtual.pontuacao = (int*) malloc((argc-2)*sizeof(int));


    strcpy(esquemaAtual.players[0],"String");
    strcpy(esquemaAtual.players[1],"Teste");

    esquemaAtual.pontuacao[0] = 1;
    esquemaAtual.pontuacao[1] = 0;

    salvaEsquema(esquemaAtual, argc-2);

    printf("Teste");

    esquemaAtual = retornaEsquemaAtual(argv, argc-2);

    /*
    for(int i=-1; i!=0 && i!=1; i=i) //Começa e da andamento ao jogo, que ira parar quando a função jogo retornar o numero do jogador vencerdor, o player0 ou o player1
        i = jogo(argv, acertos, tabuleiros, pontuacao, vez);
    */
}

//TRATAMENTO NAS FUNÇÕES salvaEsquema e colocaEsquema. Temos de conserta-las ai é so salvar e testar o retornaEsquemaAtual na linha 49 

void salvaEsquema(esquema esquemaAtual, int qtPlayers){
    FILE *fp;
    int qtEsquemas, *ordem = (int*) malloc(qtPlayers*sizeof(int));
    esquema *esquemas, esquemaPassageiro;

    fp = fopen("Jogadoresbd.txt", "r");

    fseek(fp,0,SEEK_END);
    qtEsquemas = ftell(fp) / sizeof(esquema);
    fseek(fp,0,SEEK_SET);

    esquemas=(esquema*) malloc((qtEsquemas+1)*sizeof(esquema));

    for(int i=0; i<qtEsquemas; i++){
        fread(&esquemaPassageiro, sizeof(esquema), 1, fp);
        ordem=verificaIgualdadeEntreEsquemas(esquemaAtual.players, esquemaPassageiro.players, ordem);
        colocaEsquema(esquemas, esquemaPassageiro, i, qtPlayers);
        if(ordem[qtPlayers-1]!=99)
            colocaEsquema(esquemas, esquemaAtual, i, qtPlayers);
    }

    if(ordem[qtPlayers-1]==99)
        colocaEsquema(esquemas, esquemaAtual, qtEsquemas, qtPlayers);

    fclose(fp);

    fp = fopen("Jogadoresbd.txt", "w");

    for(int i=0;i<qtEsquemas; i++)
      fwrite(&esquemas[i], sizeof(esquema), 1, fp);
    
    fclose(fp);

}

void colocaEsquema(esquema *esquemas, esquema esquemaAtual, int posicao, int qtPlayers){

    esquemas[posicao].players = (char**) malloc(qtPlayers*sizeof(char*));
    for(int i=0; i<qtPlayers; i++){
        esquemas[posicao].players[i] = (char*) malloc(100*sizeof(char));
    }
    esquemas[posicao].pontuacao = (int*) malloc(qtPlayers*sizeof(int));

    for(int i=0; i<qtPlayers; i++){
        strcpy(esquemas[posicao].players[i], esquemaAtual.players[i]);
        esquemas[posicao].pontuacao[i] = esquemaAtual.pontuacao[i];
    }
}

char **criarTabuleiro(int tamanho, int modo)
{
    char **tabuleiro; // Declaramos um ponteiro de ponteiros char qualquer

    tabuleiro = (char **)malloc(tamanho * sizeof(char *)); // Aloca um espaço para o ponteiro tabuleiro, sendo que este espaço será de ponteiros de char

    for (int i = 0; i < tamanho; i++)
        tabuleiro[i] = (char *)malloc(tamanho * sizeof(char)); // Para cada espaço que o ponteiro tabuleiro esta apontando alocamos espaços, fazendo assim vetores para cada ponteiro
    
    for (int i = 0; i < tamanho; i++) //Inicializa o tabuleiro com valores 'O'
            for (int j = 0; j < tamanho; j++)
                tabuleiro[i][j] = 'O';

    if (modo == 0) // Modo 0 = tabuleiro real(com rand). Substitui os 'O' por valores rand
    {
        int n = 0, m = 0;
        for (int i = 0; i < (int)((tamanho * tamanho) / 2); i++)
            for (int j = 0; j < 2; j++)
            {
                n = (rand() % (tamanho-1 - 0 + 1)) + 0;
                m = (rand() % (tamanho-1 - 0 + 1)) + 0;
                if (tabuleiro[n][m] == 'O')
                    tabuleiro[n][m] = (i + 65);
                else
                    j--;
            }
    }

    return tabuleiro;
}

char **criaAcertos(int qtPlayers, int qtLetras){
    char **acertos;

    acertos=(char**) malloc(qtPlayers*sizeof(char*));
    for(int i=0; i<qtPlayers; i++){
        acertos[i]=(char*) malloc(qtLetras*sizeof(char));
        for(int j=0; j<qtLetras; j++)
            acertos[i][j]='0';
    }

    return acertos;
}

esquema retornaEsquemaAtual(char **players, int qtPlayers){
    FILE *fp;
    esquema esquemaAtual;//, esquemaPassageiro, esquemaAtual;
    int qtEsquemas;
    int *ordem = (int*) malloc(qtPlayers*sizeof(int));
    ordem[qtPlayers-1]=99;

    esquemaAtual.players = (char**) malloc(qtPlayers*sizeof(char*));//Inicializa players e pontuaocao do esquemaAtual
    for(int i=0; i<qtPlayers; i++)
        esquemaAtual.players[i] = (char*) malloc(100*sizeof(char));
    esquemaAtual.pontuacao = (int*) malloc(qtPlayers*sizeof(int));

    fp = fopen("Jogadoresbd.txt", "r");

    fseek(fp,0,SEEK_END);
    qtEsquemas = ftell(fp) / sizeof(esquema);
    fseek(fp,0,SEEK_SET);

    
    for(int i=0; i<qtEsquemas; i++){
        fread(&esquemaAtual, sizeof(esquema), 1, fp);
        ordem = verificaIgualdadeEntreEsquemas(players,esquemaAtual.players, ordem);

        if(ordem[qtPlayers-1]!=99){
            for(int i=0; i<qtPlayers; i++){
                esquemaAtual.players[i]=players[i+1];
                esquemaAtual.pontuacao[i]=esquemaAtual.pontuacao[ordem[i]];
            }
            //esquemaAtual.pontuacao[i]=esquemaPassageiro.pontuacao[i]; Vai da ruim, justamente pq a pontuacao do passageiro e atual nao estaram ordenas de mesma forma
        }
    }
    

    fclose(fp);
    return esquemaAtual;

}

int *verificaIgualdadeEntreEsquemas(char **listNomeUm, char **listNomeDois, int *ordem){
    int qtNomesUm=sizeof(listNomeUm)/sizeof(*listNomeUm), qtNomesDois=sizeof(listNomeDois)/sizeof(*listNomeDois);
    char aux[100];

    for(int i=1; i<qtNomesUm-1; i++)
        for(int j=0; i<qtNomesDois; j++)
            if(strcmp(listNomeUm[i],listNomeDois[j+i])==0){
                //strcpy(dest, scr);
                strcpy(aux, listNomeDois[i]);
                strcpy(listNomeDois[i], listNomeDois[i+j]);
                strcpy(listNomeDois[i+j], aux);
                ordem[i-1]=i+j;
            }
    return ordem;
}

int jogo(char **player, char **acertos, char ***tabuleiros, int *pontuacao, int vez){
    //windows(cls)
    // Printa o nome dos jogadores

    // Vai chamar a função printarJogo, que sera da seguinte forma:
    //printarJogo(player,acertos,tabuleiros)

    // Ai vai pedir o scanf
    
    // Vai verificar se o bateu as variaveis, ou seja, se tabuleiros[0][l][a]==tabuleiros[0][n][m]
    // Se sim, ira entrar no if que ira adicionar na string acertos[vez] a letra acertada
    // Logo apos isto ira preencher o tabuleiro ficticio com os valores preenchidos
    // E entao ira verificar se a pontuacao[vez] e igual o numero de letras que tem no tabuleiro, se sim, o player[vez] ganhou, retornando o numero do player na funcao jogo
    // Se nao, so ira aumentar a pontucao[vez] por 1 e mudar a vez

    
    //E assim finaliza a funcao, retornando -1 caso ninguem venceu mudando a vez para o proximo player
    return 0;
}



















// Ate no maximo 52 pontos no tabuleiro
// atoi() string->int
// int c=65;
// printf("%c", c);