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
#define mod 1000000007
// #define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 201000;
const ll inf = (ll)(1e18+7);

using namespace std;

int n;
map<int, int> a;
vector<int> arr;

int64_t solve(map<int, int>& a, int l, int r) {
  if (l >= r) return 0;

  auto max_it = a.rbegin();
  int val = max_it->first;
  int pos = max_it->second;

  map<int, int> b;
  if (pos < (l + r) / 2) {
    for (int i = l; i < pos; ++i) {
      b[arr[i]] = i;
      a.erase(arr[i]);
    }
  } else {
    for (int i = pos + 1; i < r; ++i) {
      b[arr[i]] = i;
      a.erase(arr[i]);
    }
  }
  a.erase(val);

  int64_t ans = 0;
  for (auto it : b) {
    auto ait = a.find(val - it.first);
    if (ait != a.end()) {
      ans += 1;
    }
  }
  if (pos < (l +  r) / 2) {
    return ans + solve(b, l, pos) + solve(a, pos + 1, r);
  } else {
    return ans + solve(a, l, pos) + solve(b, pos + 1, r);
  }
}

int main() {
  // freopen("in.txt", "r", stdin);
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    a[arr[i]] = i;
  }
  cout << solve(a, 0, n) << endl;
}