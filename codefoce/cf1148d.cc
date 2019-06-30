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
vector<pair<int, pair<int, int>>> a;
vector<pair<int, pair<int, int>>> b;
vector<pair<int, int>> ans;
void solve(vector<pair<int, pair<int, int>>>& a) {
  for (int i = 0; i < a.size(); ++i) {
    ans.pb(mp(a[i].second.second, a[i].first));
  }
  if (a[0].second.first < a[0].second.second) {
    sort(ans.rbegin(), ans.rend());
  } else {
    sort(ans.begin(), ans.end());
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    if (i > 0) printf(" %d", ans[i].second);
    else printf("%d", ans[i].second);
  }
  printf("\n");
}

int main() {
  freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < y) {
      a.pb(mp(i + 1, mp(x, y)));
    } else {
      b.pb(mp(i + 1, mp(x, y)));
    }
  }
  if (a.size() > b.size()) {
    solve(a);
  } else {
    solve(b);
  }
  return 0;
}