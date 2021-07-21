#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 1500 //define a quantidade maxima de caracteres na matriz de string

int write(char arquivo[25]){ //função para escrita no arquivo
    int N,p; //N indica o indice das linhas e p as opçoes de continuar ou nao escrevendo
    char texto[MAX][MAX], aux[20]; //matriz para receber o texto
    FILE *farq;
   // farq = fopen(arquivo,"a");
    if((farq = fopen(arquivo,"a"))==NULL){
        printf("\n\tO arquivo é inexistente ou não pode ser aberto\n");
    }
    else{
        printf("\n\tDigite o texto que deseja, e ao final digite 'FIM'\n");
        do{
            setbuf(stdin,NULL);
        	printf ("%d: ",N+1); //exibindo o numero de linhas
        	scanf("%[^\n]",texto[N]);
            setbuf(stdin,NULL);
            if(strcmp(texto[N],"FIM")!=0){ //faz a analise para conferir a finalização da digitação
            fprintf(farq,"\n%s",texto[N]);
            N++;}
        }while((strcmp(texto[N],"FIM"))!=0);
        printf("\n\n\tExiste algo a mais a ser digitado? \n\tTecle 1 para Sim, ou 2 para Não:\n\t");
        scanf("%d",&p);
        if(p==1){ //chamada para a própria funçao para continuar a escrita
            fclose(farq);
            write(arquivo);
        }
        else{
        printf("\n\n\tO arquivo foi salvo com as alterações!\n\n");
        fclose(farq);
    }}
}
char delete(char arquivo[20]){ //função que era o caso do case 3
    int m;
    printf("\nExcluindo o arquivo %s", arquivo);
    m=(remove(arquivo));
   if(m==-1){
    printf("\nErro na exclusão do arquivo.");
   }
   printf("\nArquivo excluído!");
}

int main(){
    char arquivo[25],pesq[20]; //arquivo é o nome do arquivo a ser criado e pesq seria a palavra a ser pesquisada
    char auxi[20]; //auxi seria o nome do arquivo a ser deletado
    int X; //X é o valor a ser inserido para dar prosseguimento
    
    while(X!=0){
    printf("\tOlá, selecione as opções que deseja executar:\n\t0 - Para parar a execução do programa\n\t1 - Para criar um arquivo;\n\t2 - Para Escrever em um arquivo \n\t");
    scanf("%d", &X);

    switch (X){
        case 0:
        return 0;
        break;

        case 1: //case para criação do arquivo
        printf("\tInforme o nome arquivo (com o caminho desejado,ex: .txt, .oxt, .goku) que você deseja criar: \n");
        scanf(" %s", arquivo);
        FILE *fp;
        fp = fopen(arquivo , "w");
        printf("\n\tO Arquivo foi criado com sucesso!");
        fclose(fp);
        break;

        case 2: //case para escrita no arquivo
        printf("\tInforme o nome do arquivo na qual deseja escrever: \n\t");
        scanf(" %s", arquivo);
        write(arquivo);
        break;

        /*case 3:
        printf("\t\nInforme o nome do arquivo na qual deseja excluir:\n\t");
        scanf(" %s", auxi);
        delete(auxi);
        break;

        case 4:
        printf("\t\nInforme a palavra que deseja pesquisar:\n\t");
        scanf(" %s",pesq);*/
        
    } 
    }

}