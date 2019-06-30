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
pair<int, int> s[maxn];
int t[maxn];
vector<pair<int, int>> ans;
vector<int> ansd;

void solve() {
  int j = 0;
  for (int i = 0; i < n; ++i)
    if (t[i] < s[i].first) {
      printf("NO\n");
      return;
    } else if (t[i] > s[i].first) {
      while (t[i] > s[i].first) {
        while (j < n && t[j] >= s[j].first) {
          j++;
        }
        if (j == n || t[j] >= s[j].first) {
          printf("NO\n");
          return;
        }
        int d = min(s[j].first - t[j], t[i] - s[i].first);
        s[i].first += d;
        s[j].first -= d;
        ans.pb(mp(s[i].second, s[j].second));
        ansd.pb(d);
      }
    }
  printf("YES\n");
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d %d %d\n", ans[i].first, ans[i].second, ansd[i]);
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    s[i] = mp(x, i + 1);
  }
  for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
  sort(t, t + n);
  sort(s, s + n);
  ll st = 0;
  for (int i = 0; i < n; ++i) st += (ll)t[i];
  for (int i = 0; i < n; ++i) st -= (ll)s[i].first;
  if (st != 0 || t[0] < s[0].first || t[n-1]>s[n-1].first) {
    printf("NO\n");
    return 0;
  }
  solve();
  return 0;
}