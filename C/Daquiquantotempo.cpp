#include <stdio.h>
#include <math.h>

int main()
{
    int tempo, dia, ano, mes, d=0,m=0,a=0;
    char v[7];
    printf("Digite que dia/mes/ano atual: ");
    scanf("%d %d %d", &dia, &mes, &ano);
    printf("Digite em que base esta medindo(dias, semanas, meses ou anos): ");
    scanf("%s", &v);
    printf("Daqui quantos tempo nessa unidade o evento ocorrera: ");
    scanf("%d", &tempo);
    switch (v[0])
    {
    case 'd':
        d = mes*12;
        while(d+tempo>=365){
            a++;
            tempo = tempo - 365;
        }
        while(dia+tempo>=30){
            m++;
            tempo = tempo - 30;
        }
        d = tempo;

        dia = dia + d;
        ano = ano + a;
        mes = mes + m;

        printf("Sera no momento %d/%d/%d", dia, mes, ano);
         break;
    case 's':
         break;
    case 'm':
         break;
    case 'a':
         break;
    }
}