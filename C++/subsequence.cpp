#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i,j=1,k=1;
    cin>>n;
    int m[n];
    int mov[n][n];
    for(i=1;i<=n;i++){
        cin>>m[i];
    }
    for(i=2;i<=n;i++){
        if(m[i--]<m[i]){
        if(i==2){
            mov[j][k]=m[i--];
        }
        else{
            k++;
            moj[j][k]=m[i--];
        }
    }
  }
}