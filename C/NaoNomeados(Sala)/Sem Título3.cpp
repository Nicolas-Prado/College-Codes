#include <stdio.h>

int main(){
	int a,b,c,x;
	scanf("%d %d", &a, &b);
	c=1;
	while(c<=a && c<=b){
		if(a%c==0 && b%c==0)
			x=c;
		c=c+1;
	}
	printf("%d", x);
	return 0;	
}
