#include <stdio.h>
int main(){
    int conta; /* numero da conta */
    char nome[30]; /* nome da conta */
    double saldo; /* saldo da conta */
    FILE *arquivo; /* ponteiro de arquivo*/
    if((arquivo = fopen("meuFile.unesp", "r")) == NULL){
            printf("Arquivo nao pode ser aberto\n");
    } 
    else{
        printf("Iniciando a leitura do arquivo...\n");
        while(!feof(arquivo)){
            fscanf(arquivo, "%d %s %lf", &conta, &nome, &saldo);
        }
        fclose(arquivo); /* fclose fecha arquivo */
        printf("Conta: %d\nNome: %s\nSaldo: %lf\n", conta, nome, saldo);
    } /* fim do else */
    return 0; 
} /* fim do main */
