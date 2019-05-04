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

int n, m, h;
vector<int> a;
vector<int> b;
int c[110][110];
int ans[110][110];

void init() {
  cin >> n >> m >> h;
  a.resize(m + 1);
  b.resize(n + 1);
  for (int i = 0; i < m; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> c[i][j];
}

void solve() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (c[i][j] == 0)
        ans[i][j] = 0;
      else
        ans[i][j] = min(b[i], a[j]);
}

int main() {
  init();
  solve();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << ans[i][j] << " ";
    cout << endl;
  }
}