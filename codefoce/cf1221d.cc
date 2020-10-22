#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll mod = 1000000007;

int q;
int n;
ll a[maxn];
ll b[maxn];
ll f[maxn][3];

int main() {
  freopen("in.txt", "r", stdin);
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d", &n);
    int x, y;
    for (int j = 0; j < n; ++j) {
      scanf("%d %d", &x, &y);
      a[j] = x;
      b[j] = y;
    }

    memset(f, 0, sizeof(f));
    f[0][0] = 0;
    f[0][1] = b[0];
    f[0][2] = b[0] * 2;
    f[0][3] = b[0] * 3;

    for (int j = 1; j < n; ++j) {
      ll max_ans = max(f[j - 1][0], f[j - 1][1]);
      max_ans = max(f[j - 1][2], max_ans);
      max_ans = max(f[j - 1][3], max_ans);

      for (int t = 0; t < 4; ++t) {
        f[j][t] = max_ans + b[j] * t;
        for (int t2 = 0; t2 < 4; ++t2) {
          if (f[j - 1][t2] + b[j] * t < f[j][t] && a[j - 1] + t2 != a[j] + t)
            f[j][t] = f[j - 1][t2] + b[j] * t;
        }
      }
    }

    ll ans = min(f[n - 1][0], f[n - 1][1]);
    ans = min(ans, f[n - 1][2]);
    ans = min(ans, f[n - 1][3]);
    cout << ans << endl;
  }
  return 0;
}
