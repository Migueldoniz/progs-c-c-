#include <stdio.h>
#include <stdlib.h>

int main(){
    float vet[3];
    float aux;
    int i;

    for (i=0;i<3;i++){
        scanf("%f",&vet[i]);
    }
    for(i=1;i<3;i++){
        if(vet[i]>vet[i-1]){
            aux=vet[i];
            vet[i]=vet[i-1];
            vet[i-1]=aux;
        }
        }
    
    for(i=0;i<3;i++){
        printf("%.2f\n",vet[i]);
    }
}