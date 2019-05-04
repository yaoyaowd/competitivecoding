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
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 301000;
const ll inf = (ll)(1e18+7);

using namespace std;

int t;
int n;

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> n;
    int base = 1;
    int x = 0;
    int a = 0;
    int b = 0;
    while (n > 0) {
      x = n % 10;
      n /= 10;
      if (x == 4) {
        a = a + 2 * base;
        b = b + 2 * base;
      } else {
        a = a + x * base;
        b = b + 0 * base;
      }
      base *= 10;
    }
    if (b == 0) {
      if (x == 5) {
        b = a / 2;
        a = a - b;
      } else {
        b = 1;
        a = a - b;
      }
    }
    cout << "Case #" << i << ": " << a << " " << b << endl;
  }
}