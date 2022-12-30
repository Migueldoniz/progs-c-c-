#include <stdio.h>
#include <string.h>

int main() {
    int tam=0;
    printf("Insira o tamanho da maior sequÃªncia de DNA: ");
    scanf("%d",&tam);
    int tamres=tam*2;
    char seq1[tam];
    char seq2[tam];
    char res1[tamres];
    char res2[tamres];
    int score=0;
    int gap=-1;
    int tammenor=0;
    int tamfinal=0;
    tam=tam-1;
    printf("Insira a primeira sequencia: ");
    scanf(" %s",seq1);
    
    printf("Insira a segunda sequencia: ");
    scanf(" %s",seq2);

    if(strlen(seq1)>strlen(seq2)){
      tammenor=strlen(seq2);
    }
    else{
      tammenor=strlen(seq1);
    }

    for(int i=0,j=0,k=0;(i<tam || j<tam) && k<tamres;i++,j++,k++){

    if(i==tam){
      res1[k]='-';
        res2[k]=seq2[j];
        score=-(score-gap);
        gap=gap-1;
        i--;
    }
    if(j==tam){
      res1[k]=seq1[i];
        res2[k]='-';
        score=-(score-gap);
        gap=gap-1;
        j--;
    }
    else if(seq1[i]==seq2[j]){
        res1[k]=seq1[i];
        res2[k]=seq2[j];
        score=score+2;
      }
    else{
       //mismatch
      
      if(score-4>(-(score-gap))){
        res1[k]=seq1[i];
        res2[k]=seq2[j];
        score=score-4;
      }
      //gap
      else{
      res1[k]='-';
        res2[k]=seq2[j];
        score=-(score-gap);
        gap=gap-1;
        
        i--;
        

      }
    }

    }


    tamfinal=strlen(res1);
    printf("Sequencia 1: ");
     for(int i=0;i<tamfinal;i++){
        printf("%c",res1[i]);
    
    }
    printf("\n");
     printf("Sequencia 2: ");
    for(int i=0;i<tamfinal;i++){
        printf("%c",res2[i]);
    
    }

}