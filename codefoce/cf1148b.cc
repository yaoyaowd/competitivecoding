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
#define maxn 300010
#define mod 1000000007
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

int n, m, ta, tb, k;
vector<int> a;
vector<int> b;

int main() {
  cin >> n >> m >> ta >> tb >> k;
  a.resize(n);
  b.resize(m);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int j = 0; j < m; ++j) cin >> b[j];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if (k >= n || k >= m) {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0;
  int j = 0;
  while (j < m && b[j] < a[0] + ta) {
    j++;
  }
  if (j + k >= m) {
    cout << -1 << endl;
    return 0;
  }
  ans = b[j + k] + tb;

  for (int i = 1; i < n; ++i) {
    if (i > k) {
      break;
    }
    while (j < m && b[j] < a[i] + ta) {
      j++;
    }
    if (j + k - i >= m) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, b[j + k - i] + tb);
  }

  cout << ans << endl;
  return 0;
}
