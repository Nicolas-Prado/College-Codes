#include <stdio.h>
#include <stdlib.h>

float **alocarMatriz(int, int);
float **escalonar(float**, int, int, int);
                        //diagonal/linhas/colunas
int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    float **matriz;
    matriz = alocarMatriz(n,m);

    for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf("%f", &matriz[i][j]);
		}
	}

    //float **matrizant = matriz;
    int ei=0,ej=0;
    while(ej<m){
        int c=0;
        for (int i=0; i<n; i++) {
		    for (int j=0; j<m; j++) {
			    if(j==ej && i>=ei){
                    c+=matriz[i][j];
                }
		}
        if(c==0)
            ej++;
        matriz = escalonar(matriz, ei, ej, n, m);
        for (int i=0; i<n; i++) {
		    for (int j=0; j<m; j++) {
			    printf("%f", matriz[i][j]);
		}
	}
    }
}
}

float **alocarMatriz(int n, int m){
    float **matriz;
    matriz=(float **) malloc(n*sizeof(float *));
    if (matriz==NULL) return NULL;
    for(int i=0; i<n; i++){
        matriz[i]=(float *) malloc(m*sizeof(float));
        if (matriz[i]==NULL) return NULL;
    }
    return matriz;
}

float **escalonar(float** matriz, int i, int j, int n, int m){
    if(matriz[i][j]==0){
        for(int h=i+1; h<n; h++){
            if(matriz[h][j]!=0){
                for(int a=0; a<m; a++){
                    matriz[i][a]=matriz[h][a];
                }
                printf("Trocando linha %d pela linha %d", i+1, h+1);
                return matriz;
            }
        }
    }
    else{
        for(int z=1; z<n-i; z++){
            if(matriz[i+z][j]!=0){
                int c = -(matriz[i][j]/matriz[i+z][j]);
                for(int y=0; y<m; y++){
                    matriz[i+z][y]=matriz[i][y]+c*matriz[i+z][y];
                }
                printf("Trocando a linha %d pela soma dela com a linha %d multiplicada por %d", i, i+z, c);
                return matriz;
            }
        }

    }
}



