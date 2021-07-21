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
    else {
            printf( "%-6s%-16s%-11s%10s\n", "Conta", "Nome", "Sobrenome", "Saldo" );
            /* le todos os registros do arquivo (ate eof) */
            while ( !feof(arquivo) ) {
                fread( &cliente, sizeof( struct dadosCliente ), 1, arquivo);
                /* mostra registro */
                if ( cliente.conta != 0 ) {
                printf( "%-6d%-16s%-11s%10.2f\n", cliente.conta, cliente.nome, cliente.sobrenome, cliente.saldo);
                } /* fim do if */
            } /* fim do while */
            fclose(arquivo); /* fclose fecha o arquivo */
    } /* fim do else */
    return 0; /* indica conclusao bem-sucedida */
} /* fim do main */
