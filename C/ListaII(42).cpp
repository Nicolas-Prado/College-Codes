#include <stdio.h>

int main()
{
    int mes, numplaca;
    scanf("%d %d", &mes, &numplaca);

    for (int m = 9000; m != 0; m = m - 1000)
    {
        if (numplaca >= m)
            numplaca = numplaca - m;
    }
    for (int m = 900; m != 0; m = m - 100)
    {
        if (numplaca >= m)
            numplaca = numplaca - m;
    }
    for (int m = 90; m != 0; m = m - 10)
    {
        if (numplaca >= m)
            numplaca = numplaca - m;
    }

    if(mes==numplaca){
        printf("Ja e mes de pagar");
    }
    else{
        printf("Nao e mes de pagar");
    }
}