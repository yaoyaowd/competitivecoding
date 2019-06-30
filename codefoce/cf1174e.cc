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
int dp[1000005][21][2];

int f(int x, int y) {
  int ret = (1 << x);
  if (y)
    ret *= 3;
  return n / ret;
}

int main() {
  cin >> n;
  int p = 0;
  while ((1 << p) <= n)
    p++;
  p--;
  
  dp[1][p][0] = 1;
  if (f(p - 1, 1) >= 1)
    dp[1][p - 1][1] = 1;

  for (int i = 1; i < n; ++i)
    for (int x = 0; x <= p; ++x)
      for (int y = 0; y <= 1; ++y) {
        dp[i + 1][x][y] = (dp[i + 1][x][y] + 1LL * dp[i][x][y] * (f(x, y) - i)) % mod;
        if (x)
          dp[i + 1][x-1][y] = (dp[i + 1][x-1][y] + 1LL * dp[i][x][y] * (f(x-1,y) - f(x, y))) % mod;
        if (y)
          dp[i + 1][x][y - 1] = (dp[i + 1][x][y - 1] + 1LL * dp[i][x][y] * (f(x, y - 1) - f(x, y))) % mod;
      }

  cout << dp[n][0][0] << endl;
  return 0;
}