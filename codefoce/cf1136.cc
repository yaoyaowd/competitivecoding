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
#define maxn 200100
#define inf 1000000000
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m;
int a[510][510];
int b[510][510];

unordered_map<int, int> aa;
unordered_map<int, int> bb;

bool not_same(const unordered_map<int, int>& a, const unordered_map<int, int>& b) {
  // cout << 'x' << endl;
  for (auto it : a) {
    // cout << it.first << " " << it.second << endl;
    auto c = b.find(it.first);
    if (c == b.end()) {
      return true;
    }
    if (c->second != it.second) {
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &a[i][j]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &b[i][j]);
  for (int i = 0; i < n + m; ++i) {
    aa.clear();
    bb.clear();
    if (i < m) {
      for (int j = 0; j <= min(i, m-1); ++j) {
        if (j >= n) break;
        aa[a[j][i-j]]++;
        bb[b[j][i-j]]++;
      }
    } else {
      for (int j = 0; j <= min(n - 1, m - 1); ++j) {
        // cout << i - m + 1  + j << " " << j << endl;
        if (i - m + 1 + j >= n) break;
        aa[a[i - m + 1 + j][m - j - 1]]++;
        bb[a[i - m + 1 + j][m - j - 1]]++;
      }
    }
    if (not_same(aa, bb)) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
