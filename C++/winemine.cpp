#include<bits/stdc++.h> 
using namespace std; 
int main(){
    stack<int>pilha;
    //list<int>::iterator it;
    int n,i,trab=0  ,aux=0,trabf=0;
    cin>>n;
    
    while(n!=0){
        int num[n];
        for(i=0;i<n;i++){
        cin>>num[i];
        
        }
        for(i==n;i>0;i--){
            pilha.push(num[i]);
        }
        

        while(!pilha.empty()){
            trab=pilha.top();
            pilha.pop();
            aux=trab-fabs(pilha.top());
            pilha.pop();
            trabf+=trab+aux; 
        }
        cout<<trabf<<endl;
        cin>>n;

    }
    return 0;


}

/* lista.insert(it,2,11);
	for(it = lista.begin(); it!=lista.end();it++){
		//printa os numeros pares
		cout << *it << " ";
	}
	cout << endl;
	it--;

//retira o 4 da lista
lista.erase(it);

// printa o 3 que agora é o novo ultimo elemento da lista

cout << lista.back() << endl;
    // limpa a lista inteira
	lista.clear();
    // printará 0 pois a lista está vazia
	cout << lista.size() << endl;
}*/