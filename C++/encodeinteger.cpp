#include <bits/stdc++.h>
using namespace std;

int main(){
    int c;
    int d;
    int e;
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>c;
        d=c;

    if((c%2)==0){
        while(d%2==0){
        d=d/2; 
        }
            if((d%2)>1){
                cout<<"-1"<<endl;
                //break;
            }
                else{
                e=c/d;
                cout<<d<<e<<endl;
            }
    }
   
    else{
        if((c%2)>1){
            cout<<"-1"<<endl;
        }
        else
        cout<<d<<endl;
    }
}
}