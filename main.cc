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
#include <assert.h>

#define pb push_back
#define mp make_pair
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define EPS 1e-6
#define INF 1000000010
#define pi acos(-1.0)
#define maxn 100010
#define mod 1000000007
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

int t, m;
vector<int> a[maxn];
vector<int> e[maxn];
int g[maxn];
int c[maxn];
int visited[maxn];
int color[maxn];
bool inloop[maxn];
bool unbound;

void init() {
  cin >> m;
  memset(a, 0, sizeof(a));
  memset(e, 0, sizeof(e));
  for (int i = 0; i < maxn; ++i) {
    a[i].clear();
    e[i].clear();
  }
  memset(g, 0, sizeof(g));
  memset(c, 0, sizeof(c));
  memset(visited, 0, sizeof(visited));
  memset(inloop, 0, sizeof(inloop));
  unbound = false;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    a[i + 1].pb(x);
    a[i + 1].pb(y);
    e[x].pb(i + 1);
    e[y].pb(i + 1);
  }
  for (int i = 0; i < m; ++i) {
    cin >> g[i + 1];
    c[i + 1] = g[i + 1] > 0;
  }
}

int dfs(int u) {
  if (u == 0) return 0;
  visited[u] = 1;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (!visited[v]) {
      dfs(v);
    } else {
      inloop[v] = true;
      inloop[u] = true;
    }
  }
  visited[u] = 0;
}

int acc(int u) {
  if (u == 0) return 0;
  visited[u] = 1;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (!visited[v]) {
      acc(v);
    }
    c[a[v][0]] = c[a[v][0]] || c[v];
    c[a[v][1]] = c[a[v][1]] || c[v];
    g[a[v][0]] = (g[a[v][0]] + g[v]) % mod;
    g[a[v][1]] = (g[a[v][1]] + g[v]) % mod;
    if (a[v][0] != v && a[v][1] != v) {
      g[v] = 0;
    }
  }
  if (inloop[u] && c[u]) {
    unbound = true;
  }
}

void solve() {
  dfs(1);
  memset(visited, 0, sizeof(visited));
  acc(1);
  if (unbound) {
    int cur = g[1];
    memset(visited, 0, sizeof(visited));
    acc(1);
    if (cur == g[1]) {
      unbound = false;
    }
    // cout << cur << " " << g[1] << endl;
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  cin >> t;
  for (int i = 0; i < t; ++i) {
    init();
    solve();
    if (unbound) {
      cout << "Case #" << i + 1 << ": UNBOUNDED" << endl;
    } else {
      if (g[1] < 0)
        g[1] += mod;
      cout << "Case #" << i + 1 << ": " << g[1] << endl;
    }
  }
  return 0;
}