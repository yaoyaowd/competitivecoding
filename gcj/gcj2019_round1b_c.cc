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
#define mod 1000000007
// #define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 301000;
const ll inf = (ll)(1e18+7);

using namespace std;

int n, k;
vector<int> c;
vector<int> d;

void init() {
  cin >> n >> k;
  c.clear();
  d.clear();
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    c.pb(x);
  }
  for (int i = 0; i < n; ++i) {
    cin >> x;
    d.pb(x);
  }
}

int64_t solve() {
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    int cmax = c[i];
    int dmax = d[i];
    for (int j = i; j < n; ++j) {
      cmax = max(cmax, c[j]);
      dmax = max(dmax, d[j]);
      if (abs(cmax - dmax) <= k) {
        ans += 1;
      }
    }
  }
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);
  std::cout.setf( std::ios_base::unitbuf );
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    init();
    cout << "Case #" << i + 1 << ": " << solve() << endl;
  }
}