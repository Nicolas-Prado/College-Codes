#include<stdio.h>

double fatorial(int t, int c){
	if(c==1){
		return t;
	}
	else{
		return t*fatorial(t-1, c-1);
	}
}

int main(){
	int n;
	printf("Digite o numero que vc quer o fatorial: ");
	scanf("%d",&n);
	printf("%lf", fatorial(n,n-1));
}
