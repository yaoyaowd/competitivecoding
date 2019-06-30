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

int n;
int a[maxn];
int b[maxn];
int p[maxn];

int main() {
  freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int j = 0; j < n; ++j) {
    scanf("%d", &b[j]);
    p[b[j]] = j + 1;
  }

  for (int i = 0; i < n; ++i)
    if (b[i] == 1) {
      bool sats = true;
      for (int j = i; j < n; ++j)
        if (b[j] != j - i + 1)
          sats = false;
      if (sats) {
        for (int j = n; j < i + n; ++j) {
          int v = j - i + 1;
          if (j - p[v] < n)
            sats = false;
        }
      }
      if (sats) {
        cout << i << endl;
        return 0;
      }
    }

  int ans = n;
  for (int i = 0; i < n; ++i) {
    if (b[i] == 0)
      continue;
    ans = max(n + i + 2 - b[i], ans);
  }
  cout << ans << endl;
  return 0;
}