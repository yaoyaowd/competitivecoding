#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 400010;
const int inf = 1e8;
const int mod = 1000000007;

int n;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    if (n == 1) {
      cout << -1 << endl;
    } else if (n == 2) {
      cout << 57 << endl;
    } else {
      cout << 2;
      for (int j = 1; j < n; ++j) {
        cout << 3;
      }
      cout << endl;
    }
  }
  return 0;
}
