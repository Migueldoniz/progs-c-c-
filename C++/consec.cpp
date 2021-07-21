#include <bits/stdc++.h>

using namespace std;

int main() {

  int t;
  cin >> t;
  int num = 0;
  while (t--) {
    string s;
    cin >> s;

    printf("Case %d:\n", ++num);;
    int num_query;
    scanf("%d", & num_query);

    for (int m = 0; m < num_query; m++) {
      int type;
      int i;
      scanf("%d%d", &type, &i);

      if (type == 1) {
        int left=i, right=i;
        while (left>=0 && s[left]==s[i]) {
          left--;
        }
        while (right <= (int)s.size()-1 && s[right] == s[i]) {
          right++;
        }

        int ans = left - right - 1;
        printf("%d\n", ans);
      }

      if (type == 2) {
        s[i] = '#';
      }
    }
  }

  return 0;
}