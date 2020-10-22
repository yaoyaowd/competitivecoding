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

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    for (int j = 0; j < n; ++j) cin >> a[j];

    int ans = 0, ar = 0;
    sort(a.begin(), a.end());
    for (int j = n - 1; j >= 0; --j) {
      if (a[j] - ar > 0 && (j == n - 1 || a[j] != a[j + 1])) {
        ans++;
        ar += r;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
