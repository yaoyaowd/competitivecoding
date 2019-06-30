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
vector<pair<ll, ll>> a;
vector<pair<ll, ll>> c;
ll ans;
bool check[maxn];

int countsetits(ll n) {
  if (n == 0) return 0;
  else return 1 + countsetits(n & (n - 1));
}

void solve(ll sum, ll bit) {
  ll tsum = 0;
  for (int i = 0; i < c.size(); ++i) {
    ll mask = c[i].first & ans;
    ll val = c[i].second;
    int cnt = countsetits(mask);
    if (cnt & 1) val = -val;
    tsum += val;
  }
  if (tsum == 0)
    return;
  if (sum > 0 && tsum > 0) {
    ans = ans | (1ll << bit);
  }
  if (sum < 0 && tsum < 0) {
    ans = ans | (1ll << bit);
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    ll mask, val;
    cin >> val >> mask;
    sum += val;
    a.pb(mp(mask, val));
  }
  ans = 0;
  memset(check, 0, sizeof(check));
  for (int i = 1; i <= 62; ++i) {
    c.clear();
    for (int j = 0; j < n; ++j)
      if (!check[j] && (a[j].first >> i) == 0) {
        c.pb(a[j]);
        check[j] = true;
      }
    solve(sum, i - 1);
  }
  cout << ans << endl;
  return 0;
}