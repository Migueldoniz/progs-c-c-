#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500000
#define MAX1 100000

struct timespec start,end;


/*double preenchevet(double dados[],double read[]){
    
    return dados[];
    return read[];
}*/




int buscaB(int i,int j,double D[],double dado){
    int mid;
    
        if (D[i]==dado){
            return i;
        }
        if (D[j]==dado){
            return j;
        }
        mid = (i+j)/2;
        while (i<j && D[mid]!=dado){
        if(dado<D[mid]){
            j=mid-1;
        }
        else{
            i=mid+1;
        }
        mid = (i+j)/2;
        if(D[mid]==dado){
            return mid;
        }
        else if (0){
            return (0);
        }
    }
}
void insertion(double vet[],int N){
    int i,j;
    double valor;
    
    for(i=1;i<N;i++){
    valor=vet[i];
    j=i;
    while (j>=0 && vet[j-1]>valor){
        vet[j]=vet[j-1];
        j=j-1;
    }
    if(j!=i){
        vet[j]=valor;
    }
    }

}
void shell(double vet[],int N){
    int i,j,k,l;
    double valor;

    k=1;
    while(k<N){
        k=3*k+1;

        while (k>0){
            k=(k-1)/3;
            for (l=0;l<k;l++){
                for(i=l+k;i<N;i=i+k){
                    valor=vet[i];
                    j=i;
                    while(j-k>=0 && vet[j-k]>valor){
                        vet[j]=vet[j-k];
                        j=j-k;
                    }
                    vet[j]=valor;
                }

            }
        }
    }
}

int separa(double vet[],int esq,int dir){
    double pivo=vet[dir],t;
    int j=esq;
    for(int k=esq;k<dir;k++){
        if(vet[k]<=pivo){
            t=vet[j];
            vet[j]=vet[k];
            vet[k]=t;
            j++;  
        }
    }
    t=vet[j];
    vet[j]=vet[dir];
    vet[dir]=t;
    return j;
}

void quicksort(double vet[],int esq, int dir){
    if(esq<dir){
        int j;
        j= separa(vet,esq,dir);
        quicksort(vet,esq,j-1);
        quicksort(vet,j+1,dir);
    }
}




int main(){
    
    double dado;
    int result;
    int N,j,k;
    int i=0;
    int aux;
    //double vet[N];
    //double dados[MAX];
    double read[MAX1];
    double *dados=malloc(MAX*sizeof(double));

    /*printf("\nDigite o tamanho e os valores do vet: ");
    scanf("%d",&N);

    for(k=0;k<N;k++){
        scanf("%lf",&vet[k]);
    }
    i=0;
    j=N-1;
    puts("\nmanda  o dado a ser buscado ae");
    scanf("%lf",&dado);
    shell(vet,N);
    result=buscaB(i,j,vet,dado);
    printf ("%d",result);*/
    //int i;
    FILE *dad;
    FILE *readi;
   if((dad=fopen("vetor.dat","r"))==NULL){
       printf("erradão mano");
   }
   else{

    do{
        fscanf(dad,"%lf\n",&dados[i]);
        printf("%d",i);
        i+1;
        
    }while(!feof(dad));
    aux=i;
	dados =(double*)realloc(dados,i*(sizeof(double))); 
    fclose(dad);
    /*readi=fopen("busca.dat","r");
    while(!feof(readi)){
        fscanf(readi,"%lf\n",&read[j]);
        j++;
    }
    fclose(readi);*/
    //preenchevet(dados,read);
    for(i=0;i=!NULL;i++){
        printf("\n%lf",dados[i]);
    }
   }
}