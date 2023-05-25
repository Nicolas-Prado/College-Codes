#include <stdio.h>

int main(){
	int n1, n2, c=0, a, b;
	scanf("%d %d", &n1, &n2);
	if(n1<0){
		n1=-n1;
		a=1;
	}
	if(n2<0){
		n2=-n2;
		b=1;
	}
	if(n1<=n2){
		while(n1>0){
			c=c+n2;
			n1=n1-1;
		}
	}
	else{
		while(n2>0){
			c=c+n1;
			n2=n2-1;
		}
	}
	if((a==1 && b==1) || (a==0 && b==0)){
		printf("O produto e: %d", c);
	}
	else{
		printf("O produto e: %d", -c);
	}
	
}
