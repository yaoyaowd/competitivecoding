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

int n;
int a[maxn];
int p[maxn];
vector<pair<int, int>> ans;

int main() {
  freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    p[a[i]] = i;
  }

  for (int i = 1; i <= n; ++i)
    if (a[i] != i) {
      int ca = i;
      int cb = p[i];
      if (2 * abs(cb - ca) >= n) {
        ans.emplace_back(ca, cb);
      } else if (cb <= n / 2) {
        ans.emplace_back(ca, n);
        ans.emplace_back(cb, n);
        ans.emplace_back(ca, n);
      } else if (ca > n / 2) {
        ans.emplace_back(ca, 1);
        ans.emplace_back(cb, 1);
        ans.emplace_back(ca, 1);
      } else {
        ans.emplace_back(ca, n);
        ans.emplace_back(cb, 1);
        ans.emplace_back(1, n);
        ans.emplace_back(ca, n);
        ans.emplace_back(cb, 1);
      }

      p[a[ca]] = ca;
      p[a[cb]] = cb;
    }

  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
