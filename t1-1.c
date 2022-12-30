#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int number;
  struct no *right;
  struct no *left;
}no;

no *newnode(int number){
  no *newn = (no*)malloc(sizeof(no));
    newn->number=number;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}

no *addNode(no *newn, int num) {
    if(newn == NULL)
        return newnode(num);
    if(num < newn->number)
        newn->left=addNode(newn->left, num);
    else    
        newn->right=addNode(newn->right, num);
    return newn;
}
no *findsmall(no *node) {
    no *thisn = node;
    while(thisn && thisn->left != NULL) {
        thisn = thisn->left;
    }
    return thisn;
}

no *buscaNo(no *raiz, int num) {
    if(raiz==NULL){
        return 0;
    }
    else if(num < raiz->number){
        return buscaNo(raiz->left,num);
    }
    else if(num > raiz->number){
        return buscaNo(raiz->right,num);
    }
    else{
        return raiz;
    }
}

void print(no *raiz) {
    if(raiz != NULL) {
        print(raiz->left);
        printf("%d -> ", raiz->number);
        print(raiz->right);
    }
}

no *deleteNo(no *raiz, int num) {
    if(raiz == NULL) 
        return raiz;
    //encontrou o no 
    if(num < raiz->number)
        raiz->left = deleteNo(raiz->left, num);
    else if(num > raiz->number)
        raiz->right = deleteNo(raiz->right, num);
    else {
        //se nao tem filho ou apenas um
        if(raiz->left == NULL) {
            no *aux = raiz->right;
            free(raiz);
            return aux;
        }
        else if(raiz->right == NULL) {
            no *aux = raiz->left;
            free(raiz);
            return aux;
        }
        //se tem dois filhos
        no *aux = findsmall(raiz->right);
        raiz->number = aux->number;
        raiz->right = deleteNo(raiz->right, aux->number);
    }
    return raiz;
}

int main(void) {
    no *raiz = (no*)malloc(sizeof(no));
    raiz=addNode(raiz, 50);
    addNode(raiz, 17);
    addNode(raiz, 12);
    addNode(raiz, 14);
    addNode(raiz, 23);
    addNode(raiz, 19);
    addNode(raiz, 72);    
    addNode(raiz, 76);
    addNode(raiz, 54);
    addNode(raiz, 67);
    addNode(raiz, 9);
    int aux;
    int op=1;
    while(op!=0){
        printf("Insira a opção que deseja:\n1- Para Inserir um elemento;\n2- Para Buscar um elemento;\n3- Para Excluir um elemento;\n4- Para Imprimir todos os elementos;\n5- Para encerrar.\nop: ");
        scanf("%d",&op);

        if(op==1){
          aux=0;
          printf("Insira o elemento a ser adicionado: ");
                scanf("%d", &aux);
                addNode(raiz, aux);     
                printf("\nElemento inserido com sucesso!\n\n");
        }
        else if(op==2){
          aux=0;
          printf("\nDigite o elemento a ser buscado: ");
                scanf("%d", &aux);
                no *busca = buscaNo(raiz, aux);
                if(busca != NULL)
                    printf("\nO elemento %d foi encontrado!\n\n", busca->number);
                else{
                  printf("\nElemento não encontrado!\n\n");
                }
        }
        else if(op==3){
          aux=0;
          printf("\nDigite o elemento a ser deletado: ");
                scanf("%d", &aux);
                deleteNo(raiz, aux);
                printf("\nElemento removido com sucesso!\n");
        }
        else if(op==4){
          printf("\n");
          print(raiz);
          printf("\n\n");
        }
        else if(op==0){
          return 0;
        }
        else{
          printf("\nOpção Inválida!\n\n\n");
        }
    
    }

}