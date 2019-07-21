#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e4 + 7;
const int mod = 998244353;

int n, m;
char a[int(4e5 + 7)];
int cx[maxn];
int cy[maxn];

int solve() {
    int ans = m + n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i * m + j] == '.') {
                cx[i]++;
                cy[j]++;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int c = cx[i] + cy[j];
            if (a[i * m + j] == '.' && c > 0)
                c--;
            ans = min(c, ans);
            if (ans == 0)
              return 0;
        }
    return ans;
}

int main() {
  freopen("in.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    scanf("%d%d\n", &n, &m);
    memset(cx, 0, sizeof(cx));
    memset(cy, 0, sizeof(cy));
    for (int j = 0; j < n; ++j) {
      for (int t = 0; t < m - 1; ++t)
        scanf("%c", &a[j * m + t]);
      scanf("%c\n", &a[j * m + m - 1]);
    }
    printf("%d\n", solve());
  }
  return 0;
}
