#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define pb push_back
#define mp make_pair
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define EPS 1e-6
#define INF 1000000010
#define pi acos(-1.0)
#define mod 1000000007
// #define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 301000;
const ll inf = (ll)(1e18+7);

using namespace std;

int n, q;
// tree
vector<int> t[maxn];
// graph
vector<pair<int, ll>> g[maxn + maxn];

int sz[maxn];
bool die[maxn];
void dfs(int u, int fa) {
  sz[u] = 1;
  for (int v : t[u])
    if (v != fa && !die[v]) {
      dfs(v, u);
      sz[u] += sz[v];
    }
}

int center(int u, int fa, int need) {
  for (int v : t[u])
    if (v != fa && !die[v] && sz[v] > need / 2) {
      return center(v, u, need);
    }
  return u;
}

int who[maxn + maxn][20][2];
ll ans[maxn + maxn][20][2];

void prec(int v, int lg, int type)
{
  priority_queue <pair <ll, int>, vector <pair <ll, int> >, greater <pair <ll, int> > > q;
  q.push({0, v});
  ans[v][lg][type] = 0;
  int root = v;
  while (!q.empty())
  {
    int v = q.top().second;
    ll dist = q.top().first;
    q.pop();
    if (dist > ans[v][lg][type])
    {
      continue;
    }
    who[v][lg][type] = root;
    for (auto c : g[v])
    {
      int to = c.first;
      if (die[to / 2]) continue;
      if (ans[to][lg][type] > ans[v][lg][type] + c.second)
      {
        ans[to][lg][type] = ans[v][lg][type] + c.second;
        q.push({ans[to][lg][type], to});
      }
    }
  }
}

void build(int u, int lg) {
  dfs(u, -1);
  int x = center(u, -1, sz[u]);
  prec(2 * x, lg, 0);
  prec(2 * x + 1, lg, 1);
  die[x] = true;
  for (int v : t[x])
    if (!die[v]) {
      build(v, lg + 1);
    }
}

int main() {
  cin >> n;
  for (int i = 0; i < n + n; ++i)
    for (int j = 0; j < 20; ++j)
      for (int t = 0; t < 2; ++t)
        ans[i][j][t] = inf;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    g[i + i].pb({2 * i + 1, x});
    g[i + i + 1].pb({2 * i, x});
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    ll w1, w2;
    cin >> u >> v >> w1 >> w2;
    u--;
    v--;
    t[u].pb(v);
    t[v].pb(u);
    g[u + u].pb({v + v, w1});
    g[v + v].pb({u + u, w1});
    g[u + u + 1].pb({v + v + 1, w2});
    g[v + v + 1].pb({u + u + 1, w2});
  }
  build(0, 0);
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    ll out = inf;
    for (int i = 0; i < 20; ++i)
      for (int t = 0; t < 2; ++t)
        if (who[u][i][t] == who[v][i][t]) {
          out = min(out, ans[u][i][t] + ans[v][i][t]);
        }
    cout << out << endl;
  }
}