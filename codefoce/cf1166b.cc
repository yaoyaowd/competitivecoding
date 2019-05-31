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

int k;
char *a = "aeiou";
string ans;

int main() {
  cin >> k;
  bool has_ans = false;
  for (int n = 5; n < k; ++n) {
    if (k % n == 0) {
      int m = k / n;
      if (m >= 5) {
        has_ans = true;
        for (int i = 0; i < k; ++i) {
          ans = ans + a[((i % m) + (i / m)) % 5];
        }
        cout << ans << endl;
      }
      break;
    }
  }
  if (!has_ans) 
    cout << -1 << endl;
  return 0;
}