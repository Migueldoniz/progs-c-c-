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
    if ((arquivo = fopen("banco.unesp", "rb+")) == NULL){
            printf("Arquivo nao pode ser aberto.\n");
    } 
    else{
        /*exige que usuario especifique numero de conta */
        printf("\nDigite numero de conta (1 a 100, 0 para encerrar entrada): ");
        scanf("%d", &cliente.conta);
        /*usuario entra informacoes, copiadas para o arquivo*/
        while (cliente.conta != 0) {
            /*usuario digita sobrenome, nome e saldo */
            printf("\nDigite o nome: ");
            scanf(" %s", &cliente.nome);
            printf("\nDigite o sobrenome: ");
            scanf(" %s", &cliente.sobrenome);
            printf("\nDigite o saldo: ");
            scanf("%lf", &cliente.saldo);
            /*busca posicao no arquivo para registro especificado pelo usuario */
            fseek(arquivo,(cliente.conta-1)*sizeof(struct dadosCliente), SEEK_SET);
            /*grava informacao especificada pelo usuario no arquivo */
            fwrite( &cliente, sizeof( struct dadosCliente ), 1, arquivo);
            /*permite que usuario informe outro numero de conta */
            printf("\nDigite numero de conta (1 a 100, 0 para encerrar entrada): ");
            scanf("%d", &cliente.conta);
        } /* fim do while */
        fclose(arquivo); /* fclose fecha o arquivo */
    } /* fim do else */
    return 0; /* indica conclusao bem-sucedida */
} /* fim do main */
