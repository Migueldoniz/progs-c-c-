#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

typedef struct { //struct onde irá conter todas as informações dos alunos
    int Matricula;
    float Notas[6];
    char Nome[40];
    float media;
} alunos;
alunos Cadastro[50];

int inserir(int mat, int quant){ //função para inserir notas à um aluno especifico
    int i, al;
    float aux;
    for (i=0;i<50;i++){
        if (mat==Cadastro[i].Matricula){ //busca do aluno que tem o mesmo numero de matrícula do indicado
            al=i;
            break;
        }
    }
    printf ("\n Insira as notas de %s:", Cadastro[al].Nome);
    for (i=0;i<quant;i++){      //inserção de notas
        scanf("%f", &Cadastro[al].Notas[i]);
        aux+=Cadastro[al].Notas[i];

    }
    Cadastro[al].media=aux/quant; //calculo da média individual para evitar fazer outra função 
    puts("\nTudo certo! Suas notas foram inseridas!");
}

int mediaind(int mat, int quant){ //função para informar a média individual referente ao numero de matricula informado
    int i,al;
    float media=0,aux;
    for (i=0;i<50;i++){
        if (mat==Cadastro[i].Matricula){ //busca do aluno referente ao numero de matricula
            al=i;
            break;
        }
    }
    printf ("\n\nA média do aluno %s foi: %.2f\n",Cadastro[al].Nome, Cadastro[al].media);
}

int mediageral(int contalunos){ //função onde é calculada a média geral de todos os alunos
    float aux,media;
    int i;
    for (i=0;i<contalunos;i++){ //aqui faz a soma de todas as médias
        aux+=Cadastro[i].media;
    }
    media=aux/contalunos; //aqui se faz a média das médias sem comédia
    printf("\nA média geral da turma é %.2f\n", media);

}  
void consem(float corte,int contalunos){ //enfim por fim mas não menos importante, função de conssolidação de semestre
    int i,j,k,aux=10000000,aux1;
    float media;
    FILE *alun;
    alun=fopen("Relação_de_Alunos.txt","w");
    fprintf(alun,"\tN° de matrícula \tNome do Aluno\tMédia do aluno\n"); //abre o arquivo para inserir seu cabeçalho
    fclose(alun);//ja fecha pois depois daqui tudo será um loop, e o cabeçalho é só um ;)

    FILE *dados; //aqui ele é aberto para inserir os dados no arquivo
    dados=fopen("Relação_de_Alunos.txt","a");
    for(i=0;i<contalunos;i++){
        for(j=1;j<contalunos;j++){ //como observado, um loop para organizar por número de matricula
            if(Cadastro[i].Matricula<Cadastro[j].Matricula && Cadastro[i].Matricula<aux){
                aux=Cadastro[i].Matricula;
            }
        }
        fprintf(alun, "\t\t\t%d\t\t\t\t\t%s\t\t\t\t%.2f\n",Cadastro[i].Matricula,Cadastro[i].Nome,Cadastro[i].media);

    }
    for (i=0;i<contalunos;i++){ //aqui faz a soma de todas as médias pra inserir no arquivo também
        aux1+=Cadastro[i].media;
    }
    media=aux1/contalunos;
    fprintf(alun,"\n\nMédia geral da sala: %.2f\n", media);
    fclose(dados);

    FILE *repet; //novamente é aberto para outra execução, informar os alunos repetentes, pq é tudo que o prof precisa rapa!!(brinks)
    repet=fopen("Relação_de_Alunos.txt","a");
    printf("\n\nA consolidação do semestre foi feita em seu arquivo, os alunos que não obtiveram notas suficientes foram: ");
    fprintf(repet, "Os alunos que estão com nota abaixo de %.2f são: ",corte);
    for(i=0;i<contalunos;i++){
        if(*Cadastro[i].Notas<corte){
            printf("\n%s", Cadastro[i].Nome);
            fprintf(repet, "\n\t%s\n\n",Cadastro[i].Nome); //aqui insere os alunos que estão abaixo da média no arquivo
        }
    }
    fclose(repet); //fechamo graças a deus, o coitado ta pedindo socorro de tanto abrir e fechar k

}


int main(){
    int X,i=0,mat,quant,contalunos=0; //variáveis que farei uso no switch logo abaixo
    float corte;
    setlocale(LC_ALL, "Portuguese"); //famosa função pra poder imprimir caracctéres especiais como acentos
    
    while(X!=0){ //aqui deixa o arquivo aberto enquanto não recebe um 0
    printf("\nOlá, insira o número correspondente a ação que deseja fazer:\n\t 1- Para cadastrar um aluno\n\t 2- Para inserção de notas de alunos\n\t 3- Para o cálculo da média aritmética dos alunos \n\t 4- Para ver a média aritmética de um aluno específico \n\t 5- Para consolidar semestre\n\n");
    scanf("%d", &X); //cabeçalho de utilidades para vc escolher uma

    switch (X){

        case 1: //caso para a inserção de alunos no vetor
        
        printf("\n\n Insira o nome do aluno que deseja cadastrar: ");
        scanf(" %[^\n]",Cadastro[i].Nome);
        getchar();
        puts("\n Insira o número de matrícula do aluno que está cadastrando: ");
        scanf("%d", &Cadastro[i].Matricula);
        i++;
        contalunos++; //detalhe que aqui o contador irá me dizer mais a frente quantos alunos possuem para os demais calculos
        break;

        case 2://caso para a inserção de notas para alunos referente a seu numero de matricula

        printf("\n\n Insira o número de matrícula do aluno pro qual deseja inserir notas: ");
        scanf("%d", &mat);
        printf("\n Insira a quantidade de notas que deseja inserir para o aluno (max 6 notas por aluno): ");
        scanf("%d",&quant);
        inserir(mat,quant); //chamada da função que faz o trampo todo pra main
        break;

        case 3: //caso para mostrar a média geral dos alunos
        mediageral(contalunos); // esse caso ta suave pq só passa um parametro e a função faz tudo
        break;

        case 4: //caso para mostrar a média individual de um aluno referente a seu numero de matrícula

        printf("\n\n Insira o número de matrícula do aluno pro qual deseja ver a média aritmética: ");
        scanf("%d", &mat);
        printf("\n Insira a quantidade de notas que inseriu para o aluno: ");
        scanf("%d",&quant);
        mediaind(mat,quant);//função fazendo tudo novamente
        break;

        case 5: //caso para fazer a consolidação do semestre

        printf("\nPara a correta consolidação de semestre, apresente a nota de corte que definirá os alunos que passaram e os que não passaram: ");
        scanf("%f",&corte);
        consem(corte,contalunos); //chamada de função de novo pra não perder o costume
        break;
        
    } 
    }
}
//é isso ai prof, se tiver algo que fiz errado ou que podia ser melhor é só falar, achei bem daora
//essa temática desse projeto e gostei bastante de faze-lo. tmj <3

    