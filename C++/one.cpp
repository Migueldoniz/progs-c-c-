#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,i,j,max;
    cin >> a;
    for (i=1;i<=a;i++){
        cin>>b;
        max=0;
        for(j=0;j<b;j++){
            cin>>c;
            if(c>max)
            max=c;
        }
        cout<< "Case "<< i << ": "<< max << endl;

    }
}