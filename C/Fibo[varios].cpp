#include <stdio.h>

int main()
{
    int n, s1 = 0, s2 = 1;
    printf("Digite qual termo quer saber: ");
    scanf("%d", &n);
    while(n>0){
    if (n <= 0)
    {
        printf("Este termo nao existe na sequencia\n");
    }
    else
    {
        while (n > 0)
        {
            s2 = s2 + s1;
            s1 = s2 - s1;
            n = n - 1;
        }
        printf("O termo sera: %d\n", s1);
    }
    s1 = 0; 
	s2 = 1;
	printf("Digite o proximo: ");
    scanf("%d", &n);
}
}
