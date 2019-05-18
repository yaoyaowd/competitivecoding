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
const int maxn = 301000;
const ll inf = (ll)(1e18+7);

using namespace std;

int n, z;
vector<int> a;

bool check(int ans) {
  int st = ans;
  for (int i = 0; i < ans; ++i) {
    while (st < n && a[st] - a[i] < z) {
      st++;
    }
    if (st < n) {
      st++;
      continue;
    } else
      return false;
  }
  return true;
}

int main() {
  // freopen("in.txt", "r", stdin);
  cin >> n >> z;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  
  int min_ans = 0, max_ans = n / 2;
  int ans;
  while (min_ans < max_ans) {
    ans = (min_ans + max_ans + 1) >> 1;
    if (check(ans)) {
      min_ans = ans;
    } else {
      max_ans = ans - 1;
    }
  }
  cout << min_ans << endl;
}