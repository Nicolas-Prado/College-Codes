#include<stdio.h>

int main(){
    float pesoterra;
    int planeta;
    printf("Digite o peso na terra e o planeta que voce deseja verificar o peso la(sendo, 1 mercurio, 2 venus, 3 marte, 4 jupiter, 5 saturno, 6 urano): ");
    scanf("%f %d", &pesoterra, &planeta);
    switch (planeta){
        case 1:
            printf("O peso no planeta mercurio sera: %f", pesoterra*0.37);
            break;
        case 2:
            printf("O peso no planeta venus sera: %f", pesoterra*0.88);
            break;
        case 3:
            printf("O peso no planeta marte sera: %f", pesoterra*0.38);
            break;
        case 4:
            printf("O peso no planeta jupiter sera: %f", pesoterra*2.64);
            break;
        case 5:
            printf("O peso no planeta saturno sera: %f", pesoterra*1.15);
            break;
        case 6:
            printf("O peso no planeta urano sera: %f", pesoterra*1.17);
            break;
    }
    return 0;
}