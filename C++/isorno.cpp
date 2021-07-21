#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n=0,m=0;
    long long aux=0,aux1=0,cont=0;
    cin >>n>>m;
    long long arvore[n];
    for (int i=1;i<=m;i++){
        cin >>aux>>aux1;
        for(int j=aux;j<=aux1;j++){
            arvore[j]=1;
        }
    }
    for(int k=1;k<=n;k++){
    if(arvore[k]==0)
    {
        cont++;
    }
    }
    if(cont==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}