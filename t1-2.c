#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int number;
  int high;
  struct node *right;
  struct node *left;
}no;

no *newnode(int number){
  no *newn = (no*)malloc(sizeof(no));
    newn->number=number;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}


int nodehigh(no *node) {
    if(node == NULL)
        return 0;
    return node->high;
}
int morehigh(int x, int y) {
    if(x > y)
        return x;
    return y;
}
int balance(no *node) {
    int aux;
    if(node == NULL) 
        return 0;
    aux=nodehigh(node->left)-nodehigh(node->right);
    return aux;
}

no *rotatingleft(no *X) {
    no *Y = X->right; 
    no *T2 = Y->left; 

    Y->left = X;
    X->right = T2;
    int xl = nodehigh(X->left);
    int xr = nodehigh(X->right);
    int yl = nodehigh(Y->left);
    int yr = nodehigh(Y->right);
    X->high = morehigh(xl, xr)+1;
    Y->high = morehigh(yl, yr)+1;

    return Y;
}

no *rotatingright(no *Y) {
    no *X = Y->left;
    no *T2 = X->right; 
    X->right = Y;
    Y->left = T2;
    int xl = nodehigh(X->left);
    int xr = nodehigh(X->right);
    int yl = nodehigh(Y->left);
    int yr = nodehigh(Y->right);
    X->high = morehigh(xl, xr) + 1;
    Y->high = morehigh(yl, yr) + 1;    
    return X;
}

no *addNode(no *newn, int num) {
    if(newn == NULL){
        return(newnode(num));
    }
    if(num < newn->number){
        newn->left=addNode(newn->left, num);
    }
    else if(num > newn->number){
        newn->right=addNode(newn->right, num);
    }
    else{
        return newn;
    }

    int highL = nodehigh(newn->left);
    int highR = nodehigh(newn->right);
    newn->high = morehigh(highL, highR) + 1;
    
    int aux = balance(newn);
    if(aux>1 && num< newn->left->number){
        return(rotatingright(newn));
    }
    if(aux<-1 && num>newn->right->number){
        return(rotatingleft(newn));
    }
    if(aux>1 && num>newn->left->number) {
        newn->left=rotatingleft(newn->left);
        return rotatingright(newn);
    }
    if(aux<-1 && num<newn->right->number) {
        newn->right=rotatingright(newn->right);
        return rotatingleft(newn);
    }
    return newn;
}
void print(no *raiz) {
    if(raiz != NULL) {
        print(raiz->left);
        printf("%d -> ", raiz->number);
        print(raiz->right);
    }
}
int main() {

    no *raiz = NULL;
    raiz = addNode(raiz, 50);
    raiz = addNode(raiz, 17);
    raiz = addNode(raiz, 76);
    raiz = addNode(raiz, 9);
    raiz = addNode(raiz, 23);
    raiz = addNode(raiz, 54);
    raiz = addNode(raiz, 14);
    raiz = addNode(raiz, 19);
    raiz = addNode(raiz, 72);
    raiz = addNode(raiz, 12);
    raiz = addNode(raiz, 67);
    printf("\nÁrvore Balanceada: \n");
    print(raiz);
}