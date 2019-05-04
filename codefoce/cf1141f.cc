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
#define maxn 2300000
#define inf 1000000000
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
vector<pair<int, int>> v[maxn];
vector<int> a;
unordered_map<int, int> m;
int ans = 0;
int num = 0;

int solve(int k, bool p=false) {
  int ret = 0;
  int prev = -1;
  for (int i = 0; i < v[k].size(); ++i) {
    if (v[k][i].second > prev) {
      if (p) {
        cout << v[k][i].second + 1 << " " << v[k][i].first + 1 << endl;
      }
      prev = v[k][i].first;
      ret++;
    }
  }
  return ret;
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    int s = 0;
    for (int j = i; j < n; ++j) {
      s += a[j];
      auto it = m.find(s);
      int c = 0;
      if (it == m.end()) {
        m[s] = m.size();
        c = m[s];
      } else {
        c = it->second;
      }
      v[c].push_back(mp(j, i));
    }
  }

  for (int i = 0; i < m.size(); ++i) {
    sort(v[i].begin(), v[i].end());
    int k = solve(i, false);
    if (k > num) {
      num = k;
      ans = i;
    }
  }
  cout << num << endl;
  solve(ans, true);
}