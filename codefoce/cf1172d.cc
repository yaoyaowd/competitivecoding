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

int n, a[maxn], b[maxn];
int c[maxn], d[maxn];
int ra[maxn], rb[maxn];
int rc[maxn], rd[maxn];

struct D {
  int x, y, p, q;
  D(int _x, int _y, int _p, int _q): x(_x), y(_y), p(_p), q(_q) {}
};
vector<D> ans;

int main()
{
  freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ra[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    rb[b[i]] = i;
  }
  for (int i = 1; i <= n; ++i) c[i] = d[i] = rc[i] = rd[i] = i;

  for (int i = 1; i <= n; ++i) {
    if (c[i] == ra[i] && d[i] == rb[i])
      continue;
    ans.emplace_back(i, rd[rb[i]], rc[ra[i]], i);
    int t1 = c[i];
    int t2 = d[i];
    swap(c[i], c[rc[ra[i]]]);
    swap(d[i], d[rd[rb[i]]]);
    swap(rc[ra[i]], rc[t1]);
    swap(rd[rb[i]], rd[t2]);
  }

  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d %d %d %d\n", ans[i].x, ans[i].y, ans[i].p, ans[i].q);
  return 0;
}