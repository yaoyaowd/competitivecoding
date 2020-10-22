#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
const ll mod = 1000000007;

int n;

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int c, m, x;
    cin >> c >> m >> x;
    if (x >= c && x >= m) {
      cout << min(c, m) << endl;
    } else {
      int a = min(c, m);
      if (a * 3 <= c + m + x) {
        cout << a << endl;
      } else {
        cout << (c + m + x) / 3 << endl;
      }
    }
  }
  return 0;
}
