
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data{
 int dia; 
 int mes;
 int ano;
 long int amd;
}DATA;

void data_str(DATA *d, char *data_txt_ddmmaaaa){
    char str_ano[5], str_mes[3], str_dia[3];
    char concatena[9], texto[11];

    strcpy(texto, strtok(data_txt_ddmmaaaa, "/"));
    strcpy(str_dia, texto);
    d->dia = atoi(str_dia);

    strcpy(texto, strtok(NULL, "/"));
    strcpy(str_mes, texto);
    d->mes = atoi(str_mes);

    strcpy(texto, strtok(NULL, "/"));
    strcpy(str_ano, texto);
    d->ano = atoi(str_ano);

    strcpy(concatena, str_ano);
    strcat(concatena, str_mes);
    strcat(concatena, str_dia);

    d->amd = atol(concatena);
}

int main(){
    char texto[11];
    DATA *d = malloc(sizeof(DATA));

    printf("Entre com a data (DD/MM/AAAA): ");
    scanf("%s", texto); 
    data_str(d, texto);

    printf("Dia = %d\n", d->dia);
    printf("Mes = %d\n", d->mes);
    printf("Ano = %d\n", d->ano);
    printf("AAAAMMDD = %ld\n", d->amd);

    return 0;
}
//210225006419 protocolo lenovo