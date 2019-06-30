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
#define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

int n;
vector<int> a[maxn];
int d[maxn];
vector<int> deg[maxn]; 
vector<int> q;

bool check(int root) {
  for (int i = 0; i < n; ++i)
    if (deg[i].size() > 0) {
      for (int j = 1; j < deg[i].size(); ++j)
        if (d[deg[i][j]] == d[deg[i][0]])
          continue;
        else
          return false;
    }
  return deg[a[root].size()].size() == 1;
}

int main()
{
  freopen("in.txt", "r", stdin);
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    a[u].pb(v);
    a[v].pb(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i].size() == 1) {
      q.pb(i);
      d[i] = 1;
      deg[1].pb(i);
    }
  }

  int c = 0;
  while (c < q.size()) {
    int u = q[c];
    for (int v : a[u])
      if (d[v] == 0) {
        d[v] = d[u] + 1;
        q.pb(v);
        deg[a[v].size()].pb(v);
      }
    ++c;
  }

  if (check(q[q.size() - 1])) {
    cout << q[q.size() - 1] << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}