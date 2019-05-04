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

ll n, k;
ll a, b;

ll gcd(ll a, ll b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

int main() {
  cin >> n >> k;
  cin >> a >> b;
  ll min_ans = n * k + 1;
  ll max_ans = 1;
  for (int i = 0; i <= n; ++i) {
    ll l = 0;
    if (i == 0) {
      l = k - b - a;
    } else
      l = k * i - b - a;
    if (l > 0) {
      ll ans = n * k / gcd(n * k, l);
      min_ans = min(min_ans, ans);
      max_ans = max(max_ans, ans);
    }
    if (i == 0) {
      l = b - a;
    } else {
      l = k * i + b - a;
    }
    if (l > 0) {
      ll ans = n * k/ gcd(n * k, l);
      min_ans = min(min_ans, ans);
      max_ans = max(max_ans, ans);
    }
  }
  cout << min_ans << " " << max_ans << endl;
}