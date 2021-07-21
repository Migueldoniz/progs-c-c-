#include <stdio.h>
#include <stdlib.h>

int main(){
    int N,i,A,B,soma;

    scanf("%d",&N);
        char result[N];

    for (i=0;i<N;i++){
        scanf("%d %d",&A,&B);
        soma=A+B;
        if(soma%2==0){
            result[i]='A';
        }
        else
        result[i]='B';
    }
    for (i=0;i<N;i++){
        printf("%c\n",result[i]);
    }
}