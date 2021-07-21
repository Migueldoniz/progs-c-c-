#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases=0,soma=0,dif=0,one=0,two=0,aux=0;

    cin>>cases;
    for(int i=0;i<cases;i++){
        cin>>soma>>dif;
        //one
        one=soma+dif;
        //two
        two=soma-dif;

        if(soma<dif || (one%2!=0)||(two%2!=0)){
            cout<<"impossible"<<endl;
        }
        else
        cout<<one/2<<" "<<two/2<<endl;

    }


}