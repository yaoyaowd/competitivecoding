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

int p, q;
vector<int> wx, ex;
vector<int> ny, sy;
int ax, ay;

void init() {
  wx.clear();
  ex.clear();
  ny.clear();
  sy.clear();
  cin >> p >> q;
  int x, y;
  string d;
  for (int i = 0; i < p; ++i) {
    cin >> x >> y >> d;
    if (d == "S") {
      sy.pb(y);
    } else if (d == "N") {
      ny.pb(y);
    } else if (d == "E") {
      ex.pb(x);
    } else if (d == "W") {
      wx.pb(x);
    }
  }
}

int s(vector<int> l, vector<int> r) {
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  int best = 0;
  int lidx = l.size();
  int ridx = 0;
  best = l.size();
  int ans = 0;
  for (int i = 1; i <= q; ++i) {
    while (lidx > 0 && l[l.size() - lidx] <= i) {
      lidx--;
    }
    while (ridx < r.size() && r[ridx] < i) {
      ridx++;
    }
    if (lidx + ridx > best) {
      best = lidx + ridx;
      ans = i;
    }
  }
  return ans;
}

int solve() {
  ax = s(wx, ex);
  ay = s(sy, ny);
}

int main() {
  freopen("in.txt", "r", stdin);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    init();
    solve();
    cout << "Case #" << i << ": " << ax << " " << ay << endl;
  }
}