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
#define maxn 500010
#define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

vector<int> a[maxn];
int n;

ll dfs(int u, int fa, bool fixed) {
  ll ret = 1;
  ll count = 1;
  for (int v : a[u]) {
    if (v == fa)
      continue;
    ll ans = dfs(v, u, false);
    ret *= ans;
    ret %= mod;
    ret *= count;
    ret %= mod;
    count += 1;
  }
  if (!fixed) {
    ret *= a[u].size();
    ret %= mod;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x].pb(y);
    a[y].pb(x);
  }
  cout << (dfs(1, 0, true) * (ll)n) % mod << endl;
  return 0;
}