#include <bits/stdc++.h>
using namespace std;

void defmes(int mes){
    switch (mes){
        case 1:
        cout<<"Janeiro: ";
        break;

        case 2:
        cout<<"Fevereiro: ";
        break;

        case 3:
        cout<<"Março: ";
        break;

        case 4:
        cout<<"Abril: ";
        break;

        case 5:
        cout<<"Maio: ";
        break;

        case 6:
        cout<<"Junho: ";
        break;

        case 7:
        cout<<"Julho: ";
        break;

        case 8:
        cout<<"Agosto: ";
        break;

        case 9:
        cout<<"Setembro: ";
        break;

        case 10:
        cout<<"Outubro: ";
        break;

        case 11:
        cout<<"Novembro: ";
        break;

        case 12:
        cout<<"Dezembro: ";
        break;

        default:
        cout<<"Mês inválido";
        break;
    }
}

int main(){
    int L=12,C=4;
    float orc[12][4];
    int i,j;
    float totalano=0,aux=0;
    
    for (i=1;i<=L;i++){
        for(j=1;j<=C;j++){
            cout<<"Insira o valor vendido na "<<j<<"° "<<"semana de ";
            defmes(i);
            cin>>aux;
            fflush(stdin);
            orc[i][j]=aux;
            totalano=totalano+aux;
            aux=0;
            
        }
    }

    
    int op=1;
    while(op!=0){
    cout<<"\n\nOlá, insira qual opção deseja consultar:\n1 - Para mostrar o total vendido em cada mes do ano;\n2 - Para mostrar o total vendido em cada semana durante o ano;\n3 - Para mostrar o total vendido no ano;\n0 - Para sair;\nop: ";
    cin>>op;
    fflush(stdin);

    switch (op){
        case 0:
        break;

        case 1:
        int mes;
        float soma;
        cout<<"\nInsira o numero correspondente ao mês o qual deseja consultar o total de vendas (1-12).\n";
        scanf("%d",&mes);
        fflush(stdin);

        for (i=1,soma=0;i<=L;i++){
            if(i=mes){
            defmes(mes);
            for(j=1;j<=C;j++){
                soma=soma+orc[i][j];
            }
            
        }
        cout<<soma;
        break;
     }
        break;
        case 2:
        int sem;
        cout<<"\nInsira qual semana deseja consultar o total de vendas(1-4):\n";
        cin>>sem;
        fflush(stdin);
        if(sem<1 || sem>4){
            cout<<"Semana inexistente";
        }
        else{
        for(i=1;i<=L;i++){
            cout<<"Valor vendido na "<<sem<<"° semana "<<"do mês de ";
            defmes(i);
            cout<<orc[i][sem]<<"\n";
        }
        }
        break;

        case 3:
        cout<<"\nTotal vendido no ano: "<<totalano;
        break;
        default:
        cout<<"Opção Inválida";
        break;
    }

    }
}