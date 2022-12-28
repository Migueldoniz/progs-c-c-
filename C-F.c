#include "stdio.h"
#include "stdlib.h"

float Celsiusfaren(){
    float aux, C;
    puts("Digite o Valor de graus em celsius");
    scanf("%f",&C);
    aux= (C*(9/5))+32;
    printf("%.2f celsius são %.2f fahrenheit\n\n", C, aux);

}
float Farencelsius(){
    float aux,F;
    puts("Digite o Valor de graus em fahrenheit");
    scanf("%f",&F);
    aux= (F-32)*(5/9);
    printf("%.2f fahrenheit são %.2f celsius", F, aux);
}

int main(void){

    float F,C;
    int graus;

    do{
        puts("Se quer converter Celsius para Fahrenheit, Digite 1\nSe quer converter Fahrenheit para Celsius, Digite 2\nSe quiser encerrar, Digite 0");
        scanf("%d", &graus);
        switch (graus){
        case 1:
            Celsiusfaren();
            break;
        case 2:
            Farencelsius();

        }

    }while(graus!=0);
     return(0);



}
