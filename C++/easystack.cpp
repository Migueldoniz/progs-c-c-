#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<int> pilha;
    int N,M,n;
    cin>>N;   
    for(int i=0;i<N;i++){
        cin>>M;
        switch (M){
            case 1:
            cin>>n;
            pilha.push(n);
            break;

            case 2:
            pilha.pop();
            break;

            case 3:
            if(pilha.empty()){
                cout<<"Empty!";
            }
            else
            cout<<pilha.top();
        }
        
    }
    



}