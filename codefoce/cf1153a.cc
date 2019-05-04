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

int n, t;
int s, d;

int main() {
  cin >> n >> t;
  int ans = 1;
  int tt = t + 200000;
  for (int i = 0; i < n; ++i) {
    cin >> s >> d;
    int x = s - t;
    if (x < 0)
      x = ((x % d) + d) % d;
    if (x < tt) {
      ans = i + 1;
      tt = x;
    }
  }
  cout << ans << endl;
}