#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'n') {
            cout << "1"
                 << " ";
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'z') {
            cout << "0"
                 << " ";
        }
    }
}