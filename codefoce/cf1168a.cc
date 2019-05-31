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
#define mod 1000000007
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

int n, m;
vector<int> a;

bool solve(int k) {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    int c = 0;
    if (a[i] + k < m) {
      c = min(s, a[i] + k);
      if (c < a[i]) c = a[i];
    } else {
      c = max(s, a[i]);
      if (c >= s) {
        if ((a[i] + k) % m >= s) {
          c = s;
        }
      }
    }
    if (c < s) {
      return false;
    }
    s = c;
  }
  return true;
}

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int l = 0, r = m;
  while (l < r) {
    int ans = (l + r) / 2;
    if (solve(ans)) {
      r = ans;
    } else {
      l = ans + 1;
    }
  }
  cout << l << endl;
  return 0;
}