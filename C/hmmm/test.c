#include <stdio.h>
#include <string.h>

int main(){
    FILE *f;
    int* teste;
    f = fopen("Book1.xlsx", "rb");
    for(int i=0;i<98304; i++){
      fread(teste[i], 1, 1, f);
      if(i>=47 && (teste[i]==0 &&teste[i-1]==1 &&teste[i-2]==1 &&teste[i-3]==1 &&teste[i-4]==1 &&teste[i-5]==0 &&teste[i-6]==1 &&teste[i-7]==0 &&teste[i-8]==0 &&teste[i-9]==0 &&teste[i-10]==1 &&teste[i-11]==1 &&teste[i-12]==0 &&teste[i-13]==0 &&teste[i-14]==1 &&teste[i-15]==0 &&teste[i-16]==1 &&teste[i-17]==0 &&teste[i-18]==1 &&teste[i-19]==1 &&teste[i-20]==1 &&teste[i-21]==0 &&teste[i-22]==0 &&teste[i-23]==1 &&teste[i-24]==1 &&teste[i-25]==0 &&teste[i-26]==1 &&teste[i-27]==1 &&teste[i-28]==1 &&teste[i-29]==0 &&teste[i-30]==1 &&teste[i-31]==0 &&teste[i-32]==0 &&teste[i-33]==0 &&teste[i-34]==1 &&teste[i-35]==1 &&teste[i-36]==0 &&teste[i-37]==0 &&teste[i-38]==1 &&teste[i-39]==0 &&teste[i-40]==1 && teste[i-41]==0 &&teste[i-42]==0 &&teste[i-43]==1 &&teste[i-44]==1 &&teste[i-45]==0 &&teste[i-45]==0 &&teste[i-46]==0 && teste[i-47]==1 )){
        printf("sus");
      }
    }
}