#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200010;
const int inf = 1e8;
const int mod = 1000000007;

int n;
int m;
vector<int> a[maxn];
pair<int, int> b[maxn];
int d[maxn];
int f[maxn];

int dfs(int u, int fa) {
  f[u] = fa;
  d[u] = d[fa] + 1;
  for (int v : a[u]) {
    if (v != fa) {
      dfs(v, u);
    }
  }
}

bool check(int l) {
  int x = b[l - 1].second;
  for (int i = l - 2; i >= 0; --i) {
    // cout << x << " " << b[i].first << " " << b[i].second << endl;
    if (b[i].first == b[i + 1].first) {
      if (f[b[i].second] != f[b[i + 1].second]) {
        return false;
      }
    } else {
      while (x != 1 && x != b[i].second && x != f[b[i].second]) {
        x = f[x];
      }
      if (x != b[i].second && x != f[b[i].second])
        return false;
    }
  }
  return true;
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for  (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  dfs(1, 0);

  for (int i = 0; i < m; ++i) {
    int l;
    cin >> l;
    for (int j = 0; j < l; ++j) {
      int x;
      cin >> x;
      b[j].first = d[x];
      b[j].second = x;
    }
    sort(b, b + l);
    if (check(l)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
