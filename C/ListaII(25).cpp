#include <stdio.h>

int main()
{
    int idade;
    printf("Digite sua idade para determinar sua categoria na confederacao brasileira de natacao: ");
    scanf("%d", &idade);
    if (idade > 5)
    {
        if (idade > 7)
        {
            if (idade > 10)
            {
                if (idade > 13)
                {
                    if (idade > 17)
                    {
                        printf("Sua categoria e Senior");
                    }
                    else
                        printf("Sua categoria e Juvenil B");
                }
                else
                    printf("Sua categoria e Juvenil A");
            }
            else
                printf("Sua categoria e Infantil B");
        }
        else
            printf("Sua categoria e Infantil A");
    }
    return 0;
}