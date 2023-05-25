#include <stdio.h>

int main(){
	int n1, n2,  c, a=0, b=0;
	scanf("%d %d", &n2, &n1);
	if(n1<0){
		n1=-n1;
		a=1;
	}
	if(n2<0){
		n2=-n2;
		b=1;
	}
		
	while(n2-n1>=0){
		n2 = n2-n1;
		c++;
	}
	
	if((a==1 && b==1)||(a==0 && b==0))
		printf("%d", c);
	else
		printf("%d", -c);
	
	
	
}
