#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Este sistema deverá permitir que:
O usuário crie um arquivo:
Escreva um texto neste arquivo; ok
Salve o arquivo;
Edite o arquivo; ok?
Exclua o arquivo
Efetue uma busca de palavras no arquivo: ok
Buscar e substituir: procura por uma palavra e substitui por outra;ok
Apenas buscar: apenas informa quantas ocorrências e onde estão. ok*/
//https://www.geeksforgeeks.org/c-program-replace-word-text-another-given-word/
char* replaceWord(const char* s, const char* oldW, const char* newW){ 
  char* result; 
  int i, cnt = 0; 
  int newWlen = strlen(newW); 
  int oldWlen = strlen(oldW); 
  
  // Counting the number of times old word 
  // occur in the string 
  for (i = 0; s[i] != '\0'; i++) {
    if (strstr(&s[i], oldW) == &s[i]) { 
      cnt++; 
      // Jumping to index after the old word. 
      i += oldWlen - 1; 
    } 
  } 
    // Making new string of enough length 
  result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
  i = 0; 
  while (*s) { 
      // compare the substring with the result 
    if (strstr(s, oldW) == s) { 
      strcpy(&result[i], newW); 
      i += newWlen; 
      s += oldWlen; 
    } 
    else
      result[i++] = *s++; 
    } 
  
  result[i] = '\0'; 
  return result; 
}
/*********************************************************************************/
struct phrase{
  char frase[50];
  struct phrase *prox;
};
void add(struct phrase **head, struct phrase **tail, struct phrase **novo){//adiciona na lista
  if(*head==NULL){
    *head=*novo;
    *tail=*novo;
   (*novo)->prox=NULL;
  }
  else{
    (*tail)->prox=*novo;
    (*novo)->prox=NULL;
    *tail=*novo;
  }
}
int printar(struct phrase **head){//printa
  int i;
  struct phrase *aux=*head;
  for(i=1;aux!=NULL;i++){
    printf("%d: %s\n", i, aux->frase);
    aux=aux->prox;
  }
}
int gettotal(struct phrase **head){//pega o total de linhas
  int i;
  struct phrase *aux=*head;
  for(i=0;aux!=NULL;i++){
    aux=aux->prox;
  }
  return i;
}
int main(){
  FILE *fp;
  int op, i, alt=0, auxint, total;//alt é pra caso seja maior que zero ent houve alteração na lista e tem que atualizar o arquivo.
  char arquivo[20];
  struct phrase *head=NULL, *tail=NULL, *aux, *aux2;
  printf("Digite o nome do arquivo que deseja criar ou editar: ");
  scanf("%[^\n]", arquivo);
  fp=fopen(arquivo,"a");//criando arquivo.
  fp=fopen(arquivo,"r");//lendo arquivo.
  fseek (fp,0,SEEK_END);//taca o ponteiro pro final do arquivo
  if(ftell(fp)!=0){//se a posição do ponteiro for 0 então o arquivo estava vazio
    fseek(fp,0,SEEK_SET);//taca de volta pro começo
    while(!feof(fp)){
      struct phrase *novo;
      novo=malloc(sizeof(struct phrase));
      fscanf(fp, "%[^\n]\n", novo->frase);
      add(&head,&tail,&novo);
    }
  }
  printf("Digite:\n1 para printar\n2 para escrever no arquivo\n3 para buscar\n4 para buscar e substituir\n5 para apagar linha\n6 para salvar\n7 para excluir\n8 para sair.\n");
  while(op!=8){
    printf("OP: ");
    scanf("%d",&op);
    switch(op){
      case 1:{
        alt++;
        char straux[20];//auxuliar por causa do scopo
        printf("Digite *** em uma ultima linha para parar.\n");
        printar(&head);
        do{//assim sempre que der quebra de linha vai criar uma nova frase na memoria.
          struct phrase *novo;
          novo=malloc(sizeof(struct phrase));
          setbuf(stdin,NULL);
          scanf("%[^\n]", novo->frase);
          strcpy(straux,novo->frase);//passando pro auxiliar pois o while não consegue "ver" o novo->frase como parametro pq escopo.
          if(strcmp(straux,"FIM")!=0)//so vai adicionar a lista se não for o *** que indica que o usuario acabou de escrever.
            add(&head,&tail,&novo);
        }while(strcmp(straux,"FIM")!=0);
        break;
      }
      case 3:{
        char palavra[50];
        printf("Digite a palavra que deseja encontrar: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]",palavra);
        aux=head;
        for(i=0;aux!=NULL;i++){//i vai ser a linha
          if(strstr(aux->frase,palavra)!=NULL)
            printf("Palavra encontrada linha %d\n", i+1);
          aux=aux->prox;
        }
        break;
      }
      case 4:{
        alt++;
        char palavra[50];
        char subst[50];
        printf("Digite a palavra que deseja encontrar: ");
        setbuf(stdin,NULL);
        scanf("%[^\n]", palavra);
        printf("Digite a palavra que deseja colocar no lugar: ");
        setbuf(stdin,NULL);
        scanf("%[^\n]", subst);
        aux=head;
        while(aux!=NULL){
          if(strstr(aux->frase,palavra)!=NULL)
            strcpy(aux->frase,replaceWord(aux->frase, palavra, subst));//usando a função la q peguei da net sei d nada disso :D
          aux=aux->prox;
        }
        break;
      }
      case 5:
        total=gettotal(&head);
        printf("Digite a linha que deseja apagar: ");
        scanf("%d",&auxint);
        aux=head;
        for(i=1;aux!=NULL && i!=auxint;i++){//i vai ser contador de linhas
          aux2=aux;                         //aux2 vai ser a anterior a aux.
          aux=aux->prox;
        }
        if(aux==NULL)
          printf("Linha nao encontrada.\n");
        else{
          alt++;
          if(i==1 && i==total){//se for a ultima linha da lista
            free(head);
            head=NULL;
            tail=NULL;
            puts("Linha apagada, texto vazio.");
          }
          else if(i==1){//se for a primeira linha
            head=head->prox;
            free(aux);
            puts("Linha apagada.");
          }
          else if(i==total){//se for a ultima linha
            aux2->prox=NULL;
            free(aux);
            tail=aux2;
            puts("Linha apagada.");
          }
          else{//se for alguma linha entre essas
            aux2->prox=aux->prox;
            free(aux);
            puts("Linha apagada.");
          }
        }
      break;
      case 6:
        if(alt!=0){
          fp=fopen(arquivo,"w");
          aux=head;
          while(aux!=NULL){
            if(aux!=tail)
              fprintf(fp, "%s\n",aux->frase);
            else
              fprintf(fp, "%s",aux->frase);//pra n ter uma quebra de linha vazia no fim do arquivo pq dai tem q considera ela
            aux=aux->prox;                   //pra ler o arquivo feito dps e mo trampinho que na vdd n é trampinho mas é isto
          }
        }
      break;
      case 7://apagando tanto do prog quanto do arquivo
        aux=head;
        aux2=head->prox;
        while(aux!=tail){
          printf("%s\n",aux->frase);
          free(aux);
          aux=aux2;
          aux2=aux->prox;
        }
        free(tail);
        head=NULL;
        tail=NULL;
        fp=fopen(arquivo,"w");
        printf("Arquivo excluido.\n");
      break;
    }
  }
  fclose(fp);
  return 0;
}
