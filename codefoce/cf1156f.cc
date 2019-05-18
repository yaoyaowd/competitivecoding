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

int get_inv(int x, int b) {
  int res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (ll)res * (ll)x % mod;
    }
    x = ((ll)x * (ll)x) % mod;
    b /= 2;
  }
  return res;
}

int inv[maxn];
int n;
int a[maxn];
int cnt[maxn];
int suf[maxn];
int sum[maxn][maxn];
int f[maxn][maxn];

int main() {
  // freopen("in.txt", "r", stdin);
  for (int i = 1; i < maxn; ++i)
    inv[i] = pow(i, mod - 2);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  cnt[0] = 1;

  for (int i = maxn - 2; i >= 0; --i)
    suf[i] = suf[i + 1] + cnt[i];

  for (int i = n; i >= 0; --i)
    for (int j = n; j >= 0; --j) {
      if (cnt[i] == 0) {
        sum[i][j] = (sum[i][j] + sum[i + 1][j]) % mod;
        continue;
      }
      int s = n - j;
      if (s <= 0) {
        sum[i][j] = (sum[i][j] + sum[i + 1][j]) % mod;
        continue;
      }

      f[i][j] = (f[i][j] + (ll)(cnt[i] - 1) * (ll)inv[s] % mod) % mod;
      f[i][j] = (f[i][j] + (ll)sum[i + 1][j + 1] * (ll)inv[s] % mod) % mod;
      sum[i][j] = (sum[i][j] + sum[i + 1][j]) % mod;
      sum[i][j] = (sum[i][j] + (ll)cnt[i] * (ll)f[i][j] % mod) % mod;
    }

  cout << f[0][0] << endl;
  return 0;
}