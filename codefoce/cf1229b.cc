#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100010;
const ll mod = 1000000007;

vector<ll> a;
vector<int> e[maxn];
vector<pair<ll, ll>> b[maxn];
int n;
ll ans;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

void dfs(int u, int fa) {
  for (int i = 0; i < b[u].size(); ++i) {
    ans += (ll)b[u][i].first * (ll)b[u][i].second % mod;
    ans %= mod;
  }
  ans += a[u];
  ans %= mod;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (v != fa) {
      for (int j = 0; j < b[u].size(); ++j) {
        ll g = gcd(b[u][j].first, a[v]);
        b[v].push_back(make_pair(g, b[u][j].second));
      }
      ll g = gcd(a[u], a[v]);
      if (b[v].size() > 0 && b[v][b[v].size() - 1].first == g) {
        b[v][b[v].size() - 1].second += 1;
      } else {
        b[v].push_back(make_pair(g, 1));
      }
      dfs(v, u);
    }
  }
  b[u].clear();
}

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    e[x].push_back(y);
    e[y].push_back(x);
  }

  dfs(0, -1);
  cout << ans << endl;
  return 0;
}
