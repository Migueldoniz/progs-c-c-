#include<bits/stdc++.h>
using namespace std;
    vector<set<int>> ladj(10001);
    set<int>visitados;
    bool ciclo = false;

void dfs(int vertice){
    visitados.insert(vertice);
    while(ladj[vertice].empty()==false){
        if(visitados.count(*ladj[vertice].begin())==1){
            ciclo == true;
            return;
        }
        ladj[*ladj[vertice].begin()].erase(vertice);
        dfs(*ladj[vertice].begin());
        ladj[vertice].erase(*ladj[vertice].begin());
    }
}
int main (){
    int no,vert;
    int x,y;
    cin>>no>>vert;
    if(no != vert+1){
        cout<<"NO";
        return 0;
    }
    for(int i=0;i<vert;i++){
        cin>>x>>y;
        ladj[x].insert(y);
        ladj[y].insert(x);
    }
    dfs(1);
    if((ciclo)||(visitados.size()<no)){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
}