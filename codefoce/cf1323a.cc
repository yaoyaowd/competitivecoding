#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const int inf = 1e8;
const int mod = 1000000007;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  int n;
  vector<int> a;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    a.resize(n);
    for (int j = 0; j < n; ++j) cin >> a[j];
    if (n == 1 && a[0] % 2 == 1) {
      cout << -1 << endl;
    } else {
      bool c = false;
      for (int j = 0; j < n; ++j)
        if (a[j] % 2 == 0) {
          cout << 1 << endl;
          cout << j + 1 << endl;
          c = true;
          break;
        }
      if (!c) {
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
      }
    }
  }

  return 0;
}
