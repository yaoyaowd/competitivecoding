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

int w;
vector<int64_t> a;
int64_t ans[10];

void init() {
}

bool check(int r1) {
  ans[1] = r1;
  int r3r4r5r6 = a[0] * 2 - a[1];
  ans[2] = a[0] - ans[1] * 2 - r3r4r5r6;
  ans[3] = a[2] - a[1] - ans[1] * 4;
  ans[4] = a[3] - a[2] - ans[2] * 2 - ans[1] * 8;
  ans[5] = a[4] - a[3] - ans[1] * 16;
  ans[6] = a[4] - ans[1] * 32 - ans[2] * 4 - ans[3] * 2 - ans[4] * 2 - ans[5] * 2;
  if (64 * ans[1] + 8 * ans[2] + 4 * ans[3] + 2 * ans[4] + 2 * ans[5] + 2 * ans[6] != a[5])
    return false;
  if (ans[1] >= 0 && ans[2] >= 0 && ans[3] >= 0 && ans[4] >= 0 && ans[5] >= 0 && ans[6] >= 0 &&
    ans[1] <= 100 && ans[2] <= 100 && ans[3] <= 100 && ans[4] <= 100 && ans[5] <= 100 && ans[6] <= 100 &&
    ans[1] + ans[2] + ans[3] + ans[4] + ans[5] + ans[6] > 0) {
    return true;
  }
  return false;
}

void bf(int64_t x54l, int64_t x162l) {
  for (int i = 0; i <= 100; ++i) {
    ans[5] = i;
    ans[6] = (x54l - (ans[5] << 10)) >> 9;
    if ((ans[5] << 10) + (ans[6] << 9) != x54l || (ans[5] << 32) + (ans[6] << 27) != x162l)
      continue;
    if (ans[5] >= 0 && ans[5] <= 100 && ans[6] >= 0 && ans[6] <= 100 &&
      ans[1] + ans[2] + ans[3] + ans[4] + ans[5] + ans[6] > 0) {
      break;
    }
  }
}

int64_t solve() {
  if (w == 6) {
    a.clear();
    for (int i = 0; i < 6; ++i) {
      cout << i + 1 << endl;
      cout.flush();
      int64_t x;
      cin >> x;
      a.pb(x);
    }
    for (int i = 0; i <= 100; ++i)
      if (check(i))
        break;
  } else {
    a.clear();
    cout << 54 << endl;
    cout.flush();
    int64_t x54;
    cin >> x54;
    cout << 162 << endl;
    cout.flush();
    int64_t x162;
    cin >> x162;
    ans[1] = x54 >> 54;
    // cout << ans[1] << endl;
    ans[2] = (x54 >> 27) - (ans[1] << 27);
    // cout << (x54 >> 27) << " " << ans[2] << endl;
    ans[3] = (x162 >> 54);
    ans[4] = (x162 >> 40) - (ans[3] << 14);
    int64_t x54l = x54 - (ans[1] << 54) - (ans[2] << 27) - (ans[3] << 18) - (ans[4] << 13);
    int64_t x162l = x162 - (ans[3] << 54) - (ans[4] << 40);
    bf(x54l, x162l);
  }
  return 0;
}

int main() {
  // freopen("in.txt", "r", stdin);
  std::cout.setf( std::ios_base::unitbuf );
  int t;
  cin >> t;
  cin >> w;
  for (int i = 0; i < t; ++i) {
    init();
    solve();
    cout << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << " " << ans[6] << endl;
    cout.flush();  
    int x;
    cin >> x;
    assert(x != -1);
  }
}