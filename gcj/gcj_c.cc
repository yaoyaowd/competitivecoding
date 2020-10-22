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
#define maxn 5010
#define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
// const int maxn = 201000;
const ll inf = (ll)(1e18+7);

using namespace std;

int n, t;
ll wa, wb;
bool has_ans;
vector<pair<ll, ll>> a;

void init() {
  cin >> n;
  a.clear();
  for (int i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;
    a.pb(mp(x, y));
  }
}

ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}

ll wc, wd;

void solve() {
  has_ans = true;
  for (int i = 1; i < 200; ++i)
    for (int j = 1; j < 200; ++j) {
      has_ans = true;
      for (int t = 1; t < n; ++t)
        if (a[t].first * i + a[t].second * j <= a[t - 1].first * i + a[t - 1].second * j) {
          has_ans = false;
          break;
        }
      if (has_ans) {
        wa = i;
        wb = j;
        return;
      }
    }
  /*has_ans = true;
  wa = 1000000000000;
  wb = 1;
  wc = 1;
  wd = 1000000000000;
  for (int i = 0; i < n - 1; ++i) {
    int j = i + 1;
    ll x = a[j].first - a[i].first;
    ll y = a[j].second - a[i].second;
    if (x <= 0 && y <= 0) {
      has_ans = false;
      return;
    }
    if (x >= 0 && y >= 0) continue;

    ll z = gcd(abs(x), abs(y));
    x /= z;
    y /= z;
    if (x < 0) {
      x = abs(x);
      if ((double)x / (double)y < (double)wa / (double)wb) {
        wa = y;
        wb = x;
      }
    } else {
      y = abs(y);
      if ((double)y / (double)x > (double)wc / (double)wd) {
        wd = x;
        wc = y;
      }
    }
  }
  // cout << wa << " " << wb << " " << wc << " " << wd << endl;
  double aa = (double)(wa) / (double)(wb);
  double bb = (double)(wc) / (double)(wd);
  if (aa <= bb) {
    has_ans = false;
    return;
  }
  aa = 1 / aa;
  bb = 1 / bb;
  for (wa = 1; wa < 1000000; ++wa) {
    wb = (ll)(wa * aa);
    if (wb <= wa * aa)
      wb++;
    if (wb <= wa * bb) {
      has_ans = true;
      return;
    }
  }*/

  /*has_ans = false;
  ll ans_min = 1;
  ll ans_max = 1000000000000LL;
  while (ans_min < ans_max) {
    ll mid = (ans_min + ans_max) / 2;
    ll test = (ll)(mid * aa);
    if (test < mid * aa)
      test++;
    if (test < mid * bb) {
      wa = mid;
      wb = test;
      ans_max = mid;
      has_ans = true;
    } else {
      ans_min = mid + 1;
    }
  }*/
}

int main() {
  freopen("in.txt", "r", stdin);
  cin >> t;
  for (int i = 0; i < t; ++i) {
    init();
    solve();
    if (!has_ans) {
      cout << "Case #" << i + 1 << ": IMPOSSIBLE" << endl;
    } else {
      cout << "Case #" << i + 1 << ": " << wa << " " << wb << endl;
    }
  }
  return 0;
}