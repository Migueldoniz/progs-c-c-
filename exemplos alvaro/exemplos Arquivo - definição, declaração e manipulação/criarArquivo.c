#include <stdio.h>
int main(){
    int conta; /* numero da conta */
    char nome[30]; /* nome da conta */
    double saldo; /* saldo da conta */
    FILE *arquivo; /* ponteiro de arquivo*/
    if((arquivo = fopen("meuFile.unesp", "w")) == NULL){
            printf("Arquivo nao pode ser aberto\n");
    } 
    else{
        printf("Digite o numero de conta:\n");
        scanf("%d", &conta);         
        printf("Digite o nome:\n");
        scanf("%s", &nome);
        printf("Digite o saldo.\n");
        scanf("%lf", &saldo);
        fprintf(arquivo, "%d %s %lf \n", conta, nome, saldo);
        fclose(arquivo); /* fclose fecha arquivo */
    } /* fim do else */
    return 0; 
} /* fim do main */
