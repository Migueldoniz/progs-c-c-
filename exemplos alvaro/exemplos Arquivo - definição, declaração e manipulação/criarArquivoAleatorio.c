#include <stdio.h>
/*definicao da estrutura dadosCliente*/
struct dadosCliente{
    int conta; /* numero da conta*/
    char nome[10]; /*nome da conta*/
    char sobrenome[15]; /* sobrenome da conta*/
    double saldo; /*saldo da conta*/
}; /*fim da estrutura dadosCliente*/
int main(){
    FILE *arquivo; /* ponteiro do arquivo banco.unesp*/
    struct dadosCliente cliente = {0,"","", 0.0}; /*cria dadosCliente*/
    /*fopen abre o arquivo; sai se nao puder abrir arquivo*/
    if ((arquivo = fopen("banco.unesp", "wb")) == NULL){
            printf("Arquivo nao pode ser aberto.\n");
    } 
    else{
        for(int i = 1; i<=100; i++){  /* envia 100 registros vazios para arquivo */
            fwrite(&cliente, sizeof(struct dadosCliente), 1, arquivo);
        } 
        fclose(arquivo); /* fclose fecha o arquivo */
    } /* fim do else */
    return 0; /* indica conclusao bem-sucedida */
} /* fim do main */
