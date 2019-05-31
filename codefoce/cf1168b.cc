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

int n;
string s;
vector<int> a;

int main() {
  freopen("in.txt", "r", stdin);
  cin >> s;
  n = s.length();
  a.resize(n);
  a[0] = -1;
  a[1] = -1;
  for (int i = 2; i < n; ++i) {
    a[i] = a[i - 1];
    for (int k = 1; i - k * 2 >= 0; ++k) {
      if (i - k * 2 < a[i - 1])
        break;
      if (s[i] == s[i - k] && s[i] == s[i - 2 * k]) {
        a[i] = i - k * 2;
        break;
      }
    }
  }

  ll ans = 0;
  ll c = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= c) {
      ll l = (a[i] - c + 1);
      ll r = (n - i);
      ans = ans + l * r;
      c = a[i] + 1;
    }
  }
  cout << ans << endl;
  return 0;
}