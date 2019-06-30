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

int n;
int a[maxn];
int p[maxn];
int ans;
vector<int> v[maxn];
vector<int> q;

int dfs(int t) {
  p[t] = ans--;
  for (int i : v[t])
    dfs(i);
}

void solve() {
  cin >> n;
  for (int i = 0; i <= n; ++i)
    v[i].clear();
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
    if (a[i] == -2) a[i] = i + 1;
    v[a[i]].push_back(i);
  }
  ans = n;
  dfs(n);

  q.clear();
  for (int i = n - 1; i >= 0; --i) {
    while (!q.empty() && p[q.back()] < p[i])
      q.pop_back();
    if ((q.empty() && a[i] != n) || (!q.empty() && q.back() != a[i])) {
      cout << -1 << endl;
      return;
    }
    q.push_back(i);
  }
  for (int i = 0; i < n; ++i)
    cout << p[i] + 1 << " ";
  cout << endl;
}

int main()
{
  freopen("in.txt", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}