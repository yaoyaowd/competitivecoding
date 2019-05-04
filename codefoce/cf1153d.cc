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

int n;
vector<int> a;
vector<int> e[maxn];
int maxv[maxn];
int childs[maxn];

void init() {
  cin >> n;
  int u;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i) {
    cin >> u;
    e[u - 1].push_back(i);
  }
}

int solve(int u) {
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    solve(v);
    childs[u] += childs[v];
  }
  if (e[u].size() == 0) {
    maxv[u] = 1;
    childs[u] = 1;
    return 1;
  }

  if (a[u] == 1) {
    int cur = childs[u];
    for (int i = 0; i < e[u].size(); ++i) {
      int v = e[u][i];
      int k = childs[v] - maxv[v];
      if (k < cur) {
        cur = k;
      }
    }
    maxv[u] = childs[u] - cur;
  } else {
    int cur = 0;
    for (int i = 0; i < e[u].size(); ++i) {
      int v = e[u][i];
      int k = childs[v] - maxv[v];
      cur += k + 1;
    }
    maxv[u] = childs[u] - cur + 1;
  }
  return maxv[u];
}

int main() {
  init();
  cout << solve(0) << endl;
}