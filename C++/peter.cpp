#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	while(scanf("%d %d", &n, &k) == 2) {
		int sum = n, used = n;
		while(used >= k) {
			n = used/k;
			used = used%k + n;
			sum += n;
		}
		cout<<sum<<endl;
	}
    return 0;
}