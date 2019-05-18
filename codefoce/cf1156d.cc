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
#define mod 1000000007
// #define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 201000;
const ll inf = (ll)(1e18+7);

using namespace std;

int n;
vector<pair<int, int>> a[maxn];
int64_t f[maxn][4];

int64_t dfs(int u, int fa) {
  int64_t ans = 0;
  for (auto it : a[u]) {
    int v = it.first;
    int c = it.second;
    if (v == fa) continue;
    ans += dfs(v, u);

    if (c == 0) {
      f[u][0] += f[v][0] + 1;
      f[u][2] += f[v][2] + f[v][1];
    } else {
      f[u][1] += f[v][1] + 1;
      f[u][3] += f[v][3] + f[v][0];
    }
  }
  
  ans += f[u][0] * 2 + f[u][1] * 2 + f[u][3];

  for (auto it : a[u]) {
    int v = it.first;
    int c = it.second;
    if (v == fa) continue;
    int64_t a0 = f[u][0];
    int64_t a1 = f[u][1];
    int64_t a2 = f[u][2];
    int64_t a3 = f[u][3];
    int64_t b0 = f[v][0];
    int64_t b1 = f[v][1];
    int64_t b2 = f[v][2];
    int64_t b3 = f[v][3];
    if (c == 0) {
      a0 = a0 - f[v][0] - 1;
      b0 += 1;
      a2 = a2 - f[v][2] - f[v][1];
    } else {
      a1 = a1 - f[v][1] - 1;
      b1 += 1;
      a3 = a3 - f[v][3] - f[v][0];
    }
    ans += a0 * b0;
    ans += a1 * (b0 + b1 + b3);
    ans += a3 * b0;
  }
  // cout << u << " " << ans << endl;
  return ans;
}

int main() {
  // freopen("in.txt", "r", stdin);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    a[x].pb(mp(y, c));
    a[y].pb(mp(x, c));
  }
  cout << dfs(1, 0) << endl;
}