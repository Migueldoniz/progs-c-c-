#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>> n;
int a[n];
for(int i=0;i<n;i++)
    cin >>a[i];
int x=0;
    sort(a,a+n);
for(int i=0;i<n;i++)
{x=i;
    if(a[i+1]==a[n-1-i])
    break;
if(a[i]==a[n-1-i])
    break;
 
}
    cout<<a[x];
 
}
 
 
 
 
 
 