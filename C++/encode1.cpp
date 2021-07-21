/* C - Encode Integer */
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>


using namespace std;

int main() {
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N = 0;
        cin >> N;

        if (N == 0) {
            cout << 10 << endl;
            continue;
        } else if (N <= 9) {
            cout << N << endl;
            continue;
        }

        vector<int> V;
        for (int i = 9; i >= 2 && N > 1; i--) {
            while (N % i == 0) {
                N /= i;
                V.push_back(i);
            }
        }

        if (N != 1) {
            cout << -1 << endl;
            continue;
        }

        reverse(V.begin(), V.end());

        for (auto &v : V) {
            cout << v;
        }

        cout << endl;
    }

    return 0;
}