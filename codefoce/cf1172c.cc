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
#define maxn 500010
#define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

int qpow(int x, int y) //calculate the modular multiplicative inverse
{
  int out = 1;
  while (y)
  {
    if (y & 1) out = (ll) out * x % mod;
    x = (ll) x * x % mod;
    y >>= 1;
  }
  return out;
}

int n, m, a[maxn], w[maxn], f[3010][3010], g[3010][3010], inv[3010 << 1], sum[3];

int main()
{
  int i,j;
  
  scanf("%d%d", &n, &m);
  
  for (i = 1; i <= n; ++i) scanf("%d", a + i);
  
  for (i = 1; i <= n; ++i)
  {
    scanf("%d", w + i);
    sum[a[i]] += w[i];
    sum[2] += w[i];
  }
  
  for (i = max(0, m - sum[0]); i <= 2 * m; ++i) inv[i] = qpow(sum[2] + i - m, mod - 2);
  
  for (i = m; i >= 0; --i)
  {
    f[i][m - i] = g[i][m - i] = 1;
    for (j = min(m - i - 1, sum[0]); j >= 0; --j)
    {
      f[i][j] = ((ll) (sum[1] + i + 1) * f[i + 1][j] + (ll) (sum[0] - j) * f[i][j + 1]) % mod * inv[i - j + m] % mod;
      g[i][j] = ((ll) (sum[1] + i) * g[i + 1][j] + (ll) (sum[0] - j - 1) * g[i][j + 1]) % mod * inv[i - j + m] % mod;
    }
  }
  
  for (i = 1; i <= n; ++i) printf("%d\n", int((ll) w[i] * (a[i] ? f[0][0] : g[0][0]) % mod));
  
  return 0;
}