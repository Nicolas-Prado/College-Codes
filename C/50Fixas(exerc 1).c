#include <stdio.h>

int main()
{
    int sex, cmas = 0, cfem = 0;
    float alt, somaltsfemin = 0, somaltsmas = 0, altmax = 0, altmin = 999;
    for (int c = 50; c > 0; c--)
    {
        printf("Digite a altura e em seguida(apos um espaco) o sexo: ");
        scanf("%f %d", &alt, &sex);
        if (alt > altmax || alt < altmin)
        {
            if (alt > altmax)
                altmax = alt;
            else
                altmin = alt;
        }
        if (sex == 1)
        {
            somaltsmas = somaltsmas + alt;
            cmas++;
        }
        else
        {
            somaltsfemin = somaltsfemin + alt;
            cfem++;
        }
    }
    printf("\nMaior altura: %f\nMenor altura: %f\nMedia da altura da turma: %f\n", altmax, altmin, (float)(somaltsmas + somaltsfemin) / (cfem + cmas));
    if (cmas != 0)
        printf("Media da altura dos homens: %f\n", (float)somaltsmas / cmas);
    else
        printf("Media da altura dos homens: 0\n");
    if (cfem != 0)
        printf("Media da altura das mulheres: %f", (float)somaltsfemin / cfem);
    else
        printf("Media da altura das mulheres: 0");
    return 0;
}