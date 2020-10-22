#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;

int n;
vector<int> g[maxn];
int d[maxn];
int dp[maxn][2];

void dfs(int v, int p) {
  vector<int> dd;
  dp[v][1] = d[v] - 1;
  for (auto to : g[v]) {
    if (to == p)
      continue;
    dfs(to, v);
    dp[v][0] = max(dp[v][0], dp[to][0]);
    if (g[to].size() > 1) {
      dd.push_back(dp[to][1]);
      dp[v][1] = max(dp[v][1], d[v] + dp[to][1] - 1);
    }
  }

  sort(dd.rbegin(), dd.rend());
  int x = d[v] + 1;
  for (int i = 0; i < 2; ++i)
    if (i < dd.size())
      x += dd[i];
    dp[v][0] = max(dp[v][0], x);
}

void work() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    g[i].clear();
  memset(d, 0, sizeof(d));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  if (n <= 2) {
    cout << n << endl;
    return;
  }

  for (int v = 0; v < n; ++ v) {
    d[v] = g[v].size();
  }
  int r = -1;
  for (int v = 0; v < n; ++v)
    if (g[v].size() != 1) {
      r = v;
    }
  dfs(r, r);
  cout << dp[r][0] << endl;
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int q;
  cin >> q;
  for (int i = 0; i < q; ++ i) {
    work();
  }
  return 0;
}
