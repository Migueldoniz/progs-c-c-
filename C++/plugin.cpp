#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<char> pilha;
    string pal;
    string c;
    getline(cin,pal);

    for(int i=0;i<pal.length();i++){
        //pilha.push(pal[i]);
        if(pilha.empty())
           pilha.push(pal[i]);
        else{
            if(pilha.top()==pal[i])
            pilha.pop();
            else
            pilha.push(pal[i]);
        }   
        

        }
        

    while(!pilha.empty()){
    c.push_back(pilha.top());
    pilha.pop();
    }
    reverse(c.begin(),c.end());
    cout<<c;
}