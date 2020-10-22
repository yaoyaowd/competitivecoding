#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 500010;
const ll inf = 1e18;
const ll mod = 1000000007;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;

    if (x > y + 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
