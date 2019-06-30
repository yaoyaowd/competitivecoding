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
#define maxn 100010
#define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

int n, q, ma;
int a[maxn];
int b1[maxn];
int b2[maxn];
int c[maxn];

void prepare() {
  ma = a[0];
  for (int i = 0; i < n - 1; ++i) {
    b1[i] = ma;
    b2[i] = a[i + 1];
    c[i] = min(b1[i], b2[i]);
    if (a[i + 1] > ma) {
      ma = a[i + 1];
    }
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n >> q;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  prepare();
  for (int i = 0; i < q; ++i) {
    ll qq;
    cin >> qq;
    qq -= 1;
    if (qq < n-1) {
      cout << b1[qq] << " " << b2[qq] << endl;
    } else {
      cout << ma << " " << c[qq % (n - 1)] << endl;
    }
  }
  return 0;
}