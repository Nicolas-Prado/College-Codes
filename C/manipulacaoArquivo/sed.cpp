#include <stdio.h>
#include <stdlib.h>

int main(){
	float *valores;
	char recebeChar;
	int contadordelinhas=0;
	FILE *fp;
	fp = fopen("produtost.csv", "r");
	
	
	while(1==1){
		recebeChar = getc (fp);
		if(recebeChar==';')
			contadordelinhas++;
		else
			if(recebeChar==EOF)
				break;
	}
	
	valores = (float*) malloc((contadordelinhas*3/2)*sizeof(float));
	
	fseek(fp,0,SEEK_SET);

	for(int c=0; c<(contadordelinhas*3/2)-2; c=c+3){
		fscanf(fp, "%f;%f;%f\n", &valores[c], &valores[c+1], &valores[c+2]);
	}

	fclose(fp);

	fp = fopen("produtosTotal.txt", "w");
	for(int c=0; c<(contadordelinhas*3/2)-2; c=c+3)
		fprintf (fp, "%.0f;%.2f\n", valores[c], valores[c+1]*valores[c+2]);
	
	
	return 0;
}
