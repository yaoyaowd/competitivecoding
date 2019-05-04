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
#define maxn 10100
#define inf 1000000000
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m, d;
int p[maxn], c[maxn], l[maxn], q[maxn], answer[maxn];
bool leave[maxn], vis[maxn];
vector<int> edge[maxn];

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  for (int i = 1; i <= m; ++i) l[i] = -1;
  scanf("%d", &d);
  for (int i = 1; i <= d; ++i) {
    scanf("%d", &q[i]);
    leave[q[i]] = 1;
  }
}

bool dfs(int u) {
  if (vis[u])
    return false;
  vis[u] = 1;
  for (auto v : edge[u]) {
    if (l[v] == -1 || dfs(l[v])) {
      l[v] = u;
      return true;
    }
  }
  return false;
}

void solve() {
  for (int i = 1; i <= n; ++i) {
    if (!leave[i]) {
      edge[p[i]].pb(c[i]);
    }
  }

  int mex = -1;
  for (int i = d; i >= 1; --i) {
    while (true) {
      memset(vis, 0, sizeof(vis));
      if (!dfs(mex + 1))
        break;
      mex += 1;
    }
    answer[i] = mex + 1;
    edge[p[q[i]]].pb(c[q[i]]);
  }

  for (int i = 1; i <= d; ++i)
    cout << answer[i] << endl;
}

int main() {
  init();
  solve();
}