#include "stdio.h"
#include "stdlib.h"


int main(){

    int P, C, i, j,cont=0,res;
    int W[C],R,S,t,u;

    scanf("%d", &P);
    scanf("%d", &C);

    int card[C];

    for(i=1;i<=C;i++){
        scanf("%d", &card[i]);
    }
    do{
    for(i=1;i<=C;i++){
        for (j=2;j<=C;j++){
            res=card[i]+card[j];
            if(res==P){
                R=i;
                S=j;
                cont++;
            }else {
                for(i=1;i<=C && i!=R && i!=S;i++){
                W[i]=i;
                }
            }
        }
    }
    }while(cont==0 && cont>0);

    if (cont==1){
            for (j=0;j<42;j++)
        printf("%d %d", W[i]);
    }
    else if(cont==0){
        puts("0");
    }
    else if(cont>1){
        puts("-1");
    }

    return(0);
}
