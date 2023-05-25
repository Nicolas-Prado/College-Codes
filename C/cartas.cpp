#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int i, j, pontuacao=0, l1, c1, l2, c2, acerto=0;
	char cartas[9]="ABCDEFGH";
	char tabuleiro[4][4] = {
		{' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' '},
	};
	char tabuleirorevelado[4][4] = {
		{'O', 'O', 'O', 'O'},
		{'O', 'O', 'O', 'O'},
		{'O', 'O', 'O', 'O'},
		{'O', 'O', 'O', 'O'},
	};
	
	printf("Bem vindo ao jogo da memoria. Estamos gerando o tabuleiro, se prepare para decorar, voce tera 5 segundos ate ele sumir... \n\n");
	
	for(int u=0; u<8; u++){
		for(int h=0; h<2; h++){
			i = rand() % (7 + 1 - 0) + 0;
			j = rand() % (7 + 1 - 0) + 0;
			if(tabuleiro[i][j]==' ')
				tabuleiro[i][j] = cartas[u];
			else
				h--;
		}
	}// preenche o tabuleiro

	for(int n=0; n<4; n++){
		for(int m=0; m<4; m++){
			printf(" %c ", tabuleiro[n][m]);
		}
		printf("\n");
	}// printa o tabuleiro
	
	
	sleep(5);
	system("cls");
	
	while(pontuacao!=16){
		
		for(int n=0; n<4; n++){
			for(int m=0; m<4; m++){
				printf(" %c ", tabuleirorevelado[n][m]);
			}
			printf("\n");
		}// printa o tabuleiro revelado
		printf("\n");
	
		printf("Digite posicao na linha e coluna, respectivamente, das duas cartas iguais: \n");
		printf("Posicao da primeira carta: ");
		scanf("%d %d", &l1, &c1);
		l1--;
		c1--;
		printf("Posicao da segunda carta: ");
		scanf("%d %d", &l2, &c2);
		l2--;
		c2--;
		
		sleep(1);
		system("cls");

		if(((l1!=l2 || c1!=c2) && (tabuleiro[l1][c1]==tabuleiro[l2][c2])))
			acerto++;
		
		for(int n=0; n<4; n++){
			for(int m=0; m<4; m++){
					
				if((n==l1 && m==c1) || (n==l2 && m==c2)){
					printf(" %c ", tabuleiro[n][m]);
					if(acerto==1 && tabuleirorevelado[n][m] != tabuleiro[n][m]){
						tabuleirorevelado[n][m] = tabuleiro[n][m];
						pontuacao++;
					}
				}
				else
					printf(" %c ", tabuleirorevelado[n][m]);
				
			}
			printf("\n");
		}// printa o tabuleiro revelado
		
		acerto=0;
		printf("\n");
		
		printf("Digite posicao na linha e coluna, respectivamente, das duas cartas iguais: \n");
		printf("Posicao da primeira carta: ");
		printf("%d %d \n", l1+1, c1+1);
		printf("Posicao da segunda carta: ");
		printf("%d %d \n", l2+1, c2+1);
		
		sleep(3);
		
		system("cls");
	}
	system("cls");
	
	printf("W I N");
}

