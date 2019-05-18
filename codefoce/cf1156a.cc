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

int n;

int main() {
  // freopen("in.txt", "r", stdin);
  cin >> n;
  int ans = 0;
  int p = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (ans != -1) {
      if (p == x) {
        ans = -1;
      } else if (p == 2 && x == 3) {
        ans = -1;
      } else if (p == 3 && x == 2) {
        ans = -1;
      } else if (p == 1) {
        if (x == 2)
          ans += 3;
        else
          ans += 4;
      } else if (p == 2) {
        ans += 3;
      } else if (p == 3) {
        ans += 4;
      }
    }
    p = x;
  }
  if (ans != -1) {
    cout << "Finite" << endl;
    cout << ans << endl;
  } else {
    cout << "Infinite" << endl;
  }
}