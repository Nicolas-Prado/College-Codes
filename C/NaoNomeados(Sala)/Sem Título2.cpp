#include <stdio.h>

int main(){
	int C,V,M1,M2;
	scanf("%d", &V);
	M1=V;
	for(int c=2; c<=10; c++){
		scanf("%d", &V);
		if(V>M1){
			M2=M1;
			M1=V;
		}
		else{
			if(V>M2 || C==2)
				M2=V;
		}
	}
	printf("%d %d", M1, M2);
	return 0;	
}
