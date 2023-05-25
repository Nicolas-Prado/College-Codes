#include <stdio.h>

int main(){
    char ele, per;
    int a[3], b[3], c[3];
    for(int i = 1; i<=50; i++){
        scanf("%c %c", &ele, &per);
        switch(ele){
            case 'A':
            case 'a':
                switch(per){
                    case 'M':
                    case 'm': 
                        a[0]++;
                        break;
                    case 'V':
                    case 'v':
                        a[1]++;
                        break;
                    default:
                        a[2]++;

                }
                break;
            case 'B':
            case 'b':
                switch(per){
                    case 'M':
                    case 'm': 
                        b[0]++;
                        break;
                    case 'V':
                    case 'v':
                        b[1]++;
                        break;
                    default:
                        b[2]++;

                }
                break;
            default:
                switch(per){
                    case 'M':
                    case 'm': 
                        c[0]++;
                        break;
                    case 'V':
                    case 'v':
                        c[1]++;
                        break;
                    default:
                        c[2]++;

                }
        }
    }
    if(a[0]+a[1]+a[2]>b[0]+b[1]+b[2] && a[0]+a[1]+a[2]>c[0]+c[1]+c[2]){
        printf("O elevador mais frequentado e o A.\n");
        if(a[0]>a[1] && a[0]>a[2]){
            printf("O periodo de maior fluxo desse elevador e o matutino.\n");
        }
        else{
            if(a[1]>a[2]){
                printf("O periodo de maior fluxo desse elevador e o vespertino.\n");
            }
            else
                printf("O periodo de maior fluxo desse elevador e o noturno.\n");
        }
    }
    else{
        if(b[0]+b[1]+b[2]>c[0]+c[1]+c[2]){
            printf("")
        }
    }
    
    }
    return 0;
}