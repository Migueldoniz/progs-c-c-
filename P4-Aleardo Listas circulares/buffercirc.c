#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct no {
     char pal[20];
     int urg;
     struct no *prox; } Elem;

    Elem *lista;
         
void preencher(Elem **write, Elem **read, Elem *elem){

    if(!(*write)){ //preenche a lista com os nós se a lista esta com todos os lugares vazios
        (*write) = elem; //os dois apontam pro mesmo,
        (*read) = elem;  //sendo o primeiro
        elem->prox = elem;
    }
    else{
        (*read)->prox = elem;      //adequa os elementos as suas respectivas posições 
        elem->prox = (*write); //no caso da lista possuir nós
        (*read) = elem;
    }
}

Elem *newNo(char pal[20], int urg){
   Elem new = (Elem*)malloc(sizeof(Elem));//alocando a memória para o novo nó

    strcpy(new->pal, pal);//copia 
    new->urg = urg;       //os dados
    new->prox = NULL;     //para a struct
    return new; //retorna o endereço do novo nó
}

void newList(Elem **write, Elem **read){
    //inicializando as variaveis dos ponteiros como NULL
    int i;
    (*write) = NULL;
    (*read) = NULL;
    
    //preenche todos os campos da lista com 0
    for(i=0; i<40; i++)
    {
        preencher(write, read, newNo("0", 0));
    }
    //arruma os ponteiros de modo que a lista permaneça ligada
    (*read) = (*read)->prox;   
}

void adc(Elem **write, Elem **read, char pal[20], int urg){ //void para inserir elementos A=0

    Elem *aux = (*write)->prox; //aux recebe o próximo elemento de write para a comparação

    if(aux == *read)//write não pode se encontrar com read, precisa sempre estar antes
    return; 

    strcpy((*write)->pal, pal);//copia os dados para a struct
    (*write)->urg = urg;
    (*write) = aux;
}
void remover(Elem **write, Elem **read, Elem **removed){//void para remover os elementos A=1
    int i;
    int urge;

    Elem *aux = (*read)->prox;//aux simula o próximo elemento do read, para não haver a passagem indevida dos ponteiros
    if(*read == *write)
    return; 
    
    strcpy((*removed)->pal, (*read)->pal);//coloca os dados removidos no auxiliar removed
    (*removed)->urg = (*read)->urg;
    (*removed)->prox = NULL;

    if((strcmp((*read)->pal, "PRTY")) == 0){//avançando as urge posições a partir de prty
        urge = (*read)->urg; //valor de urge que é a quantidade de posições a pular
        for(i=0; i<urge; i++){
            if(*read == *write){ //caso os dois ponteiros chegem na mesma posição
                break;
            }
            (*read) = (*read)->prox;
        }
    }
    else //se não for prty, avança
        (*read) = aux;
}
void freebuff(Elem **write, Elem **read){
    Elem *livre = (*write);//livre recebe o valor de write
    Elem *aux;

    while(livre->prox != (*write)){//liberando espaço enquanto um ponteiro não atravessa o outro
        aux = livre->prox;//liberando a memória sem desconectar a lista

        free(livre);
        livre = aux;
    }
    //write e read como NULL
    (*write) = NULL;
    (*read) = NULL;
}

int main(){	
    Elem *write;//ponteiros do programa: write e read
    Elem *read;
    int intA;
    int intB;
	char palavra[20];
    Elem *anteR;//declarações para remoção
    Elem *removed = (Elem)malloc(sizeof(Elem));

    newList(&write, &read);//criação da lista vazia

    FILE *arqE = fopen("lidos.dat", "w");//abertura dos arquivos
    FILE *arqP;
    if((arqP = fopen("pacotes.dat", "r"))== NULL){
        fclose(arqP);
        return 0;
    }

    while(!feof(arqP)){ //leitura dos dados e registro nas varíaveis
    
        fscanf(arqP, "%d %s %d\n", &intA, palavra, &intB);

        if(strcmp(palavra, "NULL") == 0){//fechando arquivo no null        
            break;        
        }
        
        if(intA == 0)//selecionando as operações a serem feitas, 0 ou 1
            adc(&write, &read, palavra, intB);//adiciona nó na lista

        else{
            anteR = read;//recebe o endereço anterior da posição
            remover(&write, &read, &removed); //recebe o nó removido

            if(anteR != read)//printando no arquivo de saida
                fprintf(arqE, "%s\n", removed->pal);
        }
    }	

    fclose(arqP);//fecha os arquivos
    fclose(arqE);   

    freebuff(&write, &read);//liberando os espaços no bufffer

	return 0;
}
