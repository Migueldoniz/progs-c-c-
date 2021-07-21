#include <bits/stdc++.h>
using namespace std;

typedef struct no{
    struct no* prox;
    int num;
}no;

int main(){
    int i, num;
    int cont=0;
    no *inicio=NULL, *prox=NULL, *novo, *ant, *fim;
    srand(time(NULL));
    
    
    for(i=0; i<25; i++){
        num = (rand()%10000)+1;
        novo = (no*)malloc(sizeof(no));
        novo->num = num;
        novo->prox = NULL;
        
        if(inicio==NULL){
            inicio = novo;
            fim = novo;
              novo->prox = NULL;
        }
        else{
            ant = NULL;
            prox = inicio;
            while(prox != NULL && novo->num > prox->num){
                ant = prox;
                prox= prox->prox;
            }
            
            if(ant == NULL){
                novo->prox = inicio;
                inicio = novo;
            }else if(prox == NULL){
                fim->prox = novo;
                fim = novo;
                fim->prox = NULL;
            }else{
                ant->prox = novo;
                novo->prox = prox;
            }
            
        }
    }
    
    prox = inicio;
    while(prox!=NULL){
        cout<<prox->num;
        cont += prox->num;
        prox = prox->prox;
    }
    cout<<"\n\nMenor num "<<inicio->num;
    cout<<"\n\nMaior num "<<fim->num;
    cout<<"\n\nSoma total "<<cont;
}





#include <bits/stdc++.h>
using namespace std;

struct list{
    int num;
    struct list *prox;
};

struct list find(struct list inicio, int num){
    struct list *aux = inicio;
    if (aux->num == num){
        return aux;
    }
            else if(aux->prox == NULL){
                return NULL;
            }
                    else{
                        return find(aux->prox, num);
                    }
}