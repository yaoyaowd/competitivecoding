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

int n, q;
vector<int> a;
int f[maxn][20];
int d[20][20];
int e[20];

void prepare() {
  for (int i = 0; i < 20; ++i)
    for (int j = 0; j < 20; ++j)
      d[i][j] = maxn;

  for (int i = n; i > 0; i--) {
    memset(e, 0, sizeof(e));
    int ne = 0;

    for (int j = 0; j < 20; ++j) {
      if (a[i] & (1 << j)) {
        f[i][j] = i;
        e[ne++] = j;
      } else {
        f[i][j] = maxn;
      }
    }

    for (int j = 0; j < 20; ++j)
      if (f[i][j] == maxn) {
        for (int t = 0; t < ne; ++t) {
          f[i][j] = min(f[i][j], d[e[t]][j]);
        }
      }

    for (int j = 0; j < ne; ++j)
      for (int t = 0; t < 20; ++t) {
        d[e[j]][t] = min(d[e[j]][t], f[i][t]);
      }
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n >> q;
  a.resize(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i + 1];
  }
  memset(f, 0, sizeof(f));
  memset(d, 0, sizeof(d));
  prepare();
  int x, y;
  for (int i = 0; i < q; ++i) {
    cin >> x >> y;
    bool shi = false;
    for (int j = 0; j < 20; ++j) {
      if (a[y] & (1 << j))
        if (f[x][j] <= y)
          shi = true;
    }
    if (shi)
      cout << "Shi" << endl;
    else
      cout << "Fou" << endl;
  }
  return 0;
}