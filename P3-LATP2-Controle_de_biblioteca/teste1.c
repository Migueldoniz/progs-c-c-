#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct data{ //struct para o tratamento da data e analise de qual será devolvido mais rapido
    int dia; 
    int mes;
    int ano;
    int dateord;    //data em inteiro ao contrario para analise
    int diadev;
    int mesdev; 
    int anodev;
    }DATA;
    
typedef struct liv{         //lista de livros
    char Nome[40],Autor[40];    
    int Quant;
    long int cod;
    int datanalise;
    char datadev[11];
    char proxuser[60];
}Livros;

typedef struct usu{ //lista de usuarios
    char Nome[60];
    int idade;
    char datadev[11];
    int datanalise; //data para analisar a devolução
    char saida[11];
    struct usu *prox;
    Livros livrosuser[100];
    int quantLivuser;
}usuarios;



int data_str(DATA *d, char *diamesano){ //função para o tratamento da data
    char ano[5], mes[3], dia[3];
    char data_strcerta[9], data_strnormal[11];
    int aux;

    strcpy(data_strnormal, strtok(diamesano, "/")); //aqui ele recebe o dia , e através do comando strtok ele le até o /
    strcpy(dia, data_strnormal);
    d->dia = atoi(dia); //aqui transforma o dia em inteiro

    strcpy(data_strnormal, strtok(NULL, "/")); //como explicado acima mas com o mes
    strcpy(mes, data_strnormal);
    d->mes = atoi(mes);

    strcpy(data_strnormal, strtok(NULL, "/")); //como explicado acima mas com o ano
    strcpy(ano, data_strnormal);
    d->ano = atoi(ano);

    strcpy(data_strcerta, ano); //concatenação da string de data para a ordenação
    strcat(data_strcerta, mes);
    strcat(data_strcerta, dia);

    d->dateord = atol(data_strcerta); //transformação dessa string para inteiro
    

    if ((d->dia+7)>31 && (d->mes == 1 || d->mes ==3 || d->mes ==5 || d->mes ==7 || d->mes ==8 || d->mes ==10 || d->mes ==12)){
        
        aux=(31-(d->dia));  //analise para que os meses de 31 dias não marquem errado o acrescimo de 7 dias para a devolução
        d->diadev= 7-aux;
        
        if (d->mes==12){ //caso para o ano em que muda o mes e o ano
            d->mesdev=1;
            d->anodev=d->ano+1;
        }
        else{
            d->mesdev= d->mes+1;
            d->anodev=d->ano;
        }
    }

    else if((d->dia+7)>30 && (d->mes == 2 || d->mes ==4 || d->mes ==6 || d->mes ==9 || d->mes ==11 )){
        aux=(30-(d->dia)); //caso para os meses com 30 dias, no mesmo molde do de 31
        d->diadev=7-aux;
        if (d->mes==12){
            d->mesdev=1;
            d->anodev=d->ano+1;
        }
        else{
            d->anodev=d->ano;
            d->mesdev= d->mes+1;
        }
    }

    else if(d->dia+7==30){ //casos para os dias 30 de cada mês
        d->diadev=30;
        d->mesdev=d->mes;
        d->anodev=d->ano;
    }

    
    else{
        d->diadev=d->dia+7;
        d->mesdev=d->mes;
        d->anodev=d->ano;
    }
    return d->dateord;
}





void imprime (Livros estante[],usuarios *Lista,int quantLiv){ //função para impressão dos dados em um arquivo
    usuarios *aux1=Lista;
    FILE *livr;
    int i=0;
    livr=fopen("Livros_cadastrados.txt","W");
    while (aux1!=NULL && i<quantLiv){
        fprintf(livr,"%-6s %-26s %-36ld %-41d %-48s", estante[i].Nome,estante[i].Autor,estante[i].cod,estante[i].Quant,aux1->datadev);
        aux1=aux1->prox;
        i++;
    }
    printf("\n");
    fclose(livr);

}




//função para cadastro de livros
void cad_livros(Livros estante[],int quantLiv){    
    
    printf("\n\tInsira o Nome do livro a ser cadastrado: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]", estante[quantLiv].Nome);
    printf("\n\tInsira o Nome do Autor de %s: ", estante[quantLiv].Nome);
    setbuf(stdin,NULL);
    scanf("%[^\n]", estante[quantLiv].Autor);
    printf("\n\tInsira o Código ISBN(código numérico de 14 digitos localizado acima do código de barras do livro) do livro %s: ", estante[quantLiv].Nome);
    setbuf(stdin,NULL);
    scanf("%ld", &estante[quantLiv].cod);
    printf("\n\tInsira quantos livros %s você está cadastrando: ", estante[quantLiv].Nome);
    setbuf(stdin,NULL);
    scanf("%d", &estante[quantLiv].Quant);
    printf("\n\tLivro cadastrado com sucesso!\n\n");
    
}



usuarios* new_user (usuarios *Lista){ //função para o cadastro de novos usuarios
    usuarios *novo=Lista;
    novo=(usuarios*)malloc(sizeof(usuarios));

    printf("\n\tInsira o nome completo do usuário : ");
    setbuf(stdin,NULL);
    scanf("%[^\n]", novo->Nome);
    printf("\n\tInsira a idade do usuário %s: ", novo->Nome);
    setbuf(stdin,NULL);
    scanf("%d", &novo->idade);

    if (Lista == NULL){ //caso para a lista vazia
        Lista = novo;
    }
    else{
        novo->prox=Lista; //caso para a lista com itens
        Lista = novo;
    }
    printf("\n\tUsuário cadastrado com sucesso!\n\n");
    return Lista;

}
usuarios* alocarlivro (usuarios *Lista,Livros estante[],int quantLiv){ //função para a alocação de livros para um usuario
    usuarios *novo=Lista;
    char namelivro[40];
    char nameuser[60];
    char *aux= malloc(sizeof(char));
    char data_strnormal[11];
    int data,i=0;
    DATA *d=malloc(sizeof(DATA));

    printf("\n\tInsira o nome completo do usuário a ser alocado livros: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]", nameuser);
     
     if(novo==NULL){ //lista vazia
            printf("\n\t Usuário não cadastrado ou não encontrado!");
        }
        else{
        while(strcmp(novo->Nome,nameuser)!=0){ //procura do usuario para alocação
            novo=novo->prox;
        }
        
            printf("\n\tInsira o livro que %s irá alugar: ", nameuser); 
            setbuf(stdin,NULL);
            scanf("%[^\n]",namelivro);

            while(strcmp(namelivro,estante[i].Nome)!=0){ //pesquisa do livro
                i++;
            }
            
        
        if(i>quantLiv){ //livro não encontrado
            printf("\n\tLivro não cadastrado!");            
        }
        else{
                
        if (estante[i].Quant>0){ //se possui uma quantidade de livros para alocar
            estante[i].Quant=estante[i].Quant-1; //retira o livro da quantidade alocada
            novo->livrosuser[novo->quantLivuser+1]=estante[i]; //passa o livro para a lista de livros do usuario
            printf("\n\tInsira a data (ex: 05/03/2020) correspondente ao dia em que o livro foi emprestado: ");
            setbuf(stdin,NULL);
            scanf("%s", data_strnormal);
            novo->datanalise=data_str(d, data_strnormal); //conversão da data para um inteiro
            estante[i].datanalise=novo->datanalise; //passando a data de analise para o usuario
            strcpy(novo->saida,data_strnormal); 
            
            sprintf(aux,"%d",d->diadev);//daqui
            strcpy(novo->datadev,aux);
            strcat(novo->datadev,"/");
            sprintf(aux,"%d",d->mesdev);
            strcat(novo->datadev,aux);
            strcat(novo->datadev,"/");
            sprintf(aux,"%d",d->anodev);
            strcat(novo->datadev,aux); //até aqui junta o dia, ano e mes com as barras para exibir ao usuario
            strcpy(novo->livrosuser[novo->quantLivuser].datadev,novo->datadev); //alocando a data de devolução para o usuario
            strcpy(estante[i].datadev,novo->datadev); //pasando também para a estante de livros
            printf("\n\tLivro Alugado com sucesso!\n\t");
            novo->quantLivuser=novo->quantLivuser+1; //adicionando o livro ao usuario

         }
    
     
        else
            printf("\n\tAparentemente os exemplares de %s estão alugados, volte em breve!\n",namelivro);
        
    }}
        
    

    
    
    
    if (Lista == NULL){ //caso para a lista vazia
        Lista = novo;
    }
    else{
        novo->prox=Lista; //caso para a lista com itens
        Lista = novo;
    }

    return Lista;

}

usuarios* remov_user(usuarios *Lista){ //função para remoção do usuario
    usuarios *lista;
    lista=Lista;
    usuarios *aux1=malloc(sizeof(usuarios));
    char *userremove=malloc(sizeof(char));

    setbuf(stdin, NULL);
    printf("\n\t Insira o nome da pessoa a ser removida: ");
    scanf("%[^\n]",userremove);
    if(lista==NULL){ //caso de lista vazia
        printf("\n\tLista Vazia!\n");
    }
    else{
    while((strcmp(aux1->Nome,userremove)!=0)){ //busca o usuario a ser removido
        aux1=lista->prox;
    }
    }
    if(aux1==NULL){
        printf("\n\tUsuario não encontrado!\n");
    }
    else{
    lista->prox=aux1->prox; //remoçao do usuario
    free(aux1);  //libera o no da ram
    printf("\n\tUsuario removido com sucesso!\n");
    }
    return lista;
}

void selection(Livros estante[],int quantLiv){ //selection sort para ordenação dos livros
    int min;
    Livros aux;
    for(int i=0;i<quantLiv;i++){
        min=i;
        for(int j=i+1;j<quantLiv;j++){
            if(estante[j].datanalise<estante[min].datanalise)
            min=j;
        }
        aux=estante[i];
        estante[i]=estante[min];
        estante[min]=aux;

    }
}

void selectioncontrario(Livros estante[],int quantLiv){ //selection ao contrario para a ordenação ao contrario dos livros
    int min;
    Livros aux;
    for(int i=0;i<quantLiv;i++){
        min=i;
        for(int j=i+1;j<quantLiv;j++){
            if(estante[j].datanalise>estante[min].datanalise)
            min=j;
        }
        aux=estante[i];
        estante[i]=estante[min];
        estante[min]=aux;

    }
}

void consultauser(usuarios *Lista){ //função para consultar um usuario
    char nome[40];
    usuarios *aux;
    aux=Lista;
    int i;
    setbuf(stdin,NULL);
    scanf("%[^\n]",nome);

    if(aux==NULL){
        printf("\n\tLista vazia\n");
    }
    else{
    while(strcmp(nome,aux->Nome)!=0){ //busca do usuario
        aux=aux->prox;
    }
    if(aux==NULL){
        printf("\n\tUsuario não encontrado!");
    }
    else{ //impressão das informações do usuario
        printf("\n%-2s %-6d ",aux->Nome,aux->idade);
        for(i=0;i<=aux->quantLivuser;i++){
            printf("\n%-2s %-20s",aux->livrosuser[i].Nome,aux->livrosuser[i].datadev);
        }
        }
    }
}

void consultalivro(Livros estante[],int quantLiv){ //função para buscar um livros
    char nome[40];
    int i=0;
    setbuf(stdin,NULL);
    scanf("%[^\n]",nome);

     if(quantLiv==0){
        printf("\n\tLivro não cadastrado\n");

    }
    else{
    while(strcmp(nome,estante[i].Nome)!=0){ //busca o livro
        i++;
    }
   
    //imprime as infromações do livro
    printf("%-2s %-6s %-10d %-15ld %-20s",estante[i].Nome,estante[i].Autor,estante[i].Quant,estante[i].cod,estante[i].datadev);
    }
}

void reserva(Livros estante[],int quantLiv){ //reservar um livro
    char namelivro[60];
    char nameuser[40];
    int i=0;
    setbuf(stdin,NULL);
    printf("\n\t Insira o nome do livro que deseja reservar: ");
    scanf("%[^\n]",namelivro);
    while(strcmp(namelivro,estante[i].Nome)!=0){ //busca o livro a ser reservado
        i++;
    }
    if(i>quantLiv){
        printf("\n\tLivro não cadastrado!\n");
    }
    else{
        if(estante[i].proxuser==NULL){ //analisa se ja tem alguem que reservou
            printf("\n\tOps, o livro já está reservado, volte em breve!");
        }
        else{   //recebe o nome do usuario que deseja reservar
        printf("\n\tInsira o nome do usuário que deseja reservar o livro: ");
        setbuf(stdin,NULL);
        scanf("%[^\n]",nameuser);
        strcpy(estante[i].proxuser,nameuser);
        printf("\n\t Livro reservado com sucesso, volte no dia %s para retira-lo!\n",estante[i].datadev);
        }
    }
}

void salva_arquivos(usuarios *Lista,Livros estante[],int quantLiv){ //função para salvar em arquivo as informações
    FILE *pu;
    FILE *pl;

    pu=fopen("Relacao_de_usuarios.txt","w"); //cria um arquivo para os usuarios
    fprintf(pu," \t\t\tNome\t\t\t\t\tIdade\n");
    while(Lista!=NULL){
        fprintf(pu," \t\t\t%s\t\t\t\t\t%d\n",Lista->Nome,Lista->idade); //passa as informações
        if(Lista->quantLivuser!=0){
        for(int i=0;i<Lista->quantLivuser;i++){ //passa os livros
            fprintf(pu,"Livro: %s Data de Devolução: %s\n",Lista->livrosuser[i].Nome,Lista->livrosuser[i].datadev);
        }
        }
        Lista=Lista->prox;
    }
    fclose(pu);
    pl=fopen("Relacao_de_livros.txt","w"); //cria arquivo para livros
    fprintf(pl," \t\t\tNome\t\t\t\tAutor\t\t\tQuantidade\t\t\tData de devolução\n");
    for(int i=0;i<quantLiv;i++){// imprime no arquivo os livros
        fprintf(pl," \t\t%s\t\t\t\t%s\t\t\t%d\t\t\t%s\n",estante[i].Nome,estante[i].Autor,estante[i].Quant,estante[i].datadev);
    }
    fclose(pl);
}

//função para devolução de livros
void devolução(Livros estante[],int quantLiv){
    char name[60];
    int i;

    setbuf(stdin,NULL);
    scanf("%[^\n]",name);
    while(strcmp(name,estante[i].Nome)!=0){ //pesquisa pelo livro
        i+1;
    }
    estante[i].Quant=estante[i].Quant+1; //adiciona +1 a quantidade
}



int main(){
    
    DATA *d = malloc(sizeof(DATA)); 
    Livros estante[1000];
    int quantLiv=0;
    usuarios *Lista=NULL;
    int X;
    while(X=!0){
    printf("\n\tOlá, escolha as seguintes opções para as respectivas operações:\n\t0-Para encerrar o programa;\n\t1-Para registrar um livro;\n\t2-Para registrar um usuário;\n\t3-Para alocar um livro para o usuário;\n\t4-Para exibir livros ordenados em ordem crescente de data;\n\t5-Para exibir livros ordenados em ordem decrescente de data;\n\t6-Para exibir um usuário e os livros que ele possui alugados;\n\t7-Para exibir um livro especifico;\n\t8-Para remover um usuário;\n\t9-Para reservar um livro já alugado;\n\t10-Para devolver um livro.\n\t11-Para salvar nos arquivos;\n\top: ");
    scanf("%d",&X);
    switch (X){

        case 0: //função para fechar o programa
        return 0;
        break;

        case 1: //chamada para a função de cadastro de livros
        cad_livros(estante,quantLiv);
        quantLiv=quantLiv+1;
        break;
        
        case 2: //chamada de função para inserir novos usuarios
        Lista=new_user(Lista);
        break;

        case 3: //chamada para a função para alocar livros para um usuario
        Lista=alocarlivro(Lista,estante,quantLiv);
        break;
        
        case 4: //ordenação crescente
        selection(estante,quantLiv);
        printf("\n\tNome/Autor\t\tQuantidade\tCódigo\t\t Data de Devolução\tReservado\n");
        for(int n=0;n<quantLiv;n++){
            printf("%s,%s        %d              %ld          %s           %s\n",estante[n].Nome,estante[n].Autor,estante[n].Quant,estante[n].cod,estante[n].datadev,estante[n].proxuser);
        }
        break;

        case 5: //ordenação descrescente
        selectioncontrario(estante,quantLiv);
        printf("\n\tNome/Autor\t\tQuantidade\tCódigo\t\t Data de Devolução\tReservado\n");
        for(int n=0;n<quantLiv;n++){
            printf("%s,%s \t%d \t\t%ld \t%s \t%s\n",estante[n].Nome,estante[n].Autor,estante[n].Quant,estante[n].cod,estante[n].datadev,estante[n].proxuser);
        }
        break;

        case 6: //consulta de usuario
        consultauser(Lista);
        break;

        case 7: //função para consultar livro
        consultalivro(estante,quantLiv);
        break;

        case 8: //função para remover usuario
        Lista=remov_user(Lista);
        break;

        case 9: //função para reservar um livrp
        reserva(estante,quantLiv);
        break;
        
        case 10: //função para devolver um livro
        devolução(estante,quantLiv);
        break;

        case 11: //função para salvar em arquivo
        salva_arquivos(Lista,estante,quantLiv);
        break;

   }
    }

    return 0;
}

