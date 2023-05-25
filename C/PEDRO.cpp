#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1, num2, result;
    char op;

    printf("Enter the first number\n");
    scanf("%f", &num1);
    getchar();

    printf("Enter the operation\n");
    scanf("%c", &op);

    printf("Enter the second number\n");
    scanf("%f", &num2);

    switch (op)
    {
    case '-':
        result = num1 - num2;
        printf("%f", result);
        break;

    case '+':
        result = num1 + num2;
        printf("%f", result);
        break;

    case '*':
        result = num1 * num2;
        printf("%f", result);
        break;

    case '/':
        result = num1 / num2;
        printf("%f", result);
        break;

    default:
        printf("The operation is not valid");
        break;
    }
    return 0;
}